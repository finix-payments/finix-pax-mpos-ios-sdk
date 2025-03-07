#!/bin/sh

#  ci_post_xcodebuild.sh
#  PaxMposSDK
#
#  Created by Tom Nguyen on 3/3/25.
#

set -e  # Exit immediately if any command fails

# Only execute if archiving using XCode Cloud
if ! [[ "$CI_XCODE_CLOUD" == "TRUE" && "$CI_XCODEBUILD_ACTION" == "archive" ]]; then
  echo "Skipping the process, isXCodeCloud=$CI_XCODE_CLOUD, xcodebuildAction=$CI_XCODEBUILD_ACTION"
  exit 0
fi

echo "Starting post-xcodebuild process for SDK..."

# Check if the archives were successful
if ! [[ -d "$CI_ARCHIVE_PATH" && -d "$SIMULATOR_ARCHIVE_PATH" ]]; then
  echo "Archive not found, CI_ARCHIVE_PATH=$CI_ARCHIVE_PATH, SIMULATOR_ARCHIVE_PATH=$SIMULATOR_ARCHIVE_PATH"
  exit 1
fi

# Create the xcframework
echo "Creating xcframework..."
XCFRAMEWORK_TEMP_PATH="$CI_WORKSPACE_PATH/xcframeworks/$CI_PRODUCT.xcframework"

xcodebuild -create-xcframework \
    -archive "$CI_ARCHIVE_PATH" -framework "$CI_PRODUCT.framework" \
    -archive "$SIMULATOR_ARCHIVE_PATH" -framework "$CI_PRODUCT.framework" \
    -output "$XCFRAMEWORK_TEMP_PATH"

# Copy headers to the xcframework
echo "Copying header files to xcframework..."
cp -R "./Headers/" * "$XCFRAMEWORK_TEMP_PATH/ios-arm64/$CI_PRODUCT.framework/Headers/"
cp -R "./Headers/" * "$XCFRAMEWORK_TEMP_PATH/ios-x86_64-simulator/$CI_PRODUCT.framework/Headers/"

# Remove ci_pre_xcodebuild.sh and ci_post_xcodebuild.sh files from the xcframework
echo "Removing script files..."
rm -rf "$XCFRAMEWORK_TEMP_PATH/ios-arm64/$CI_PRODUCT.framework/ci_pre_xcodebuild.sh"
rm -rf "$XCFRAMEWORK_TEMP_PATH/ios-arm64/$CI_PRODUCT.framework/ci_post_xcodebuild.sh"

rm -rf "$XCFRAMEWORK_TEMP_PATH/ios-x86_64-simulator/$CI_PRODUCT.framework/ci_pre_xcodebuild.sh"
rm -rf "$XCFRAMEWORK_TEMP_PATH/ios-x86_64-simulator/$CI_PRODUCT.framework/ci_post_xcodebuild.sh"

# Sign the xcframework
echo "Signing the xcframework..."
xcrun codesign --force --sign - --timestamp=none "$XCFRAMEWORK_TEMP_PATH"
echo "Checking signature after signing..."
codesign -dv "$XCFRAMEWORK_TEMP_PATH" &> /dev/null

# Push to PaxMposSDK SPM repo
SPM_REPO_URL="https://x-access-token:${GITHUB_TOKEN}@github.com/finix-payments/PaxMposSDK"
SPM_REPO_TEMP_PATH="$CI_WORKSPACE_PATH/spm_repo"

echo "Cloning SPM repository..."
git clone "$SPM_REPO_URL" "$SPM_REPO_TEMP_PATH"

echo "Replacing xcframework in SPM repo..."
rm -rf "$SPM_REPO_TEMP_PATH/Sources/$CI_PRODUCT.xcframework"
cp -R "$XCFRAMEWORK_TEMP_PATH" "$SPM_REPO_TEMP_PATH/Sources/"

VERSION="$CI_TAG"
echo "Updating SPM repo with version $VERSION..."
cd "$SPM_REPO_TEMP_PATH"
git config user.name "XCode Cloud CI"
git config user.email "tom.nguyen@finix.com"
git add .
git commit -m "Update $CI_PRODUCT.xcframework to version $VERSION"
git push origin main

echo "Tagging new version..."
git tag -a "$VERSION" -m "Version $VERSION"
git push origin "$VERSION"

echo "Deployment complete! Version $VERSION is now available."

exit 0
