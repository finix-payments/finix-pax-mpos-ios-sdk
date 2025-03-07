#!/bin/sh

#  ci_post_xcodebuild.sh
#  PaxMposSDK
#
#  Created by Tom Nguyen on 3/3/25.
#  

# This script needs to be signed as well

set -e  # Exit immediately if any command fails

# Only execute if archiving
if [ "$CI_XCODEBUILD_ACTION" != "archive" ]; then
  echo "Action is '$CI_XCODEBUILD_ACTION', not 'archive'"
  echo "Skipping post-archive process"
  exit 0
fi

echo "Starting post-archive process for SDK..."

# Check if the archive was successful
if [ ! -d "$CI_ARCHIVE_PATH" ]; then
  echo "Archive not found at $CI_ARCHIVE_PATH"
  exit 1
fi

# Create the xcframework
echo "Creating xcframework..."
XCFRAMEWORK_TEMP_PATH="$CI_WORKSPACE_PATH/xcframeworks/PaxMposSDK.xcframework"

xcodebuild -create-xcframework \
  -archive "$CI_ARCHIVE_PATH" \
  -framework PaxMposSDK.framework \
  -output "$XCFRAMEWORK_TEMP_PATH"

# Copy headers to the xcframework
echo "Copying header files to xcframework..."
cp -R "./Headers/" * "$XCFRAMEWORK_TEMP_PATH/ios-arm64/PaxMposSDK.framework/Headers/"

# Sign the xcframework
echo "Signing the xcframework..."
xcrun codesign --force --sign - --timestamp=none "$XCFRAMEWORK_TEMP_PATH"
echo "Checking signature after signing"
codesign -dv "$XCFRAMEWORK_TEMP_PATH" &> /dev/null

# Push to PaxMposSDK SPM repo
SPM_REPO_URL="https://x-access-token:${GITHUB_TOKEN}@github.com/finix-payments/PaxMposSDK"
SPM_REPO_TEMP_PATH="$CI_WORKSPACE_PATH/spm_repo"

echo "Cloning SPM repository..."
git clone "$SPM_REPO_URL" "$SPM_REPO_TEMP_PATH"

echo "Replacing xcframework in SPM repo..."
rm -rf "$SPM_REPO_TEMP_PATH/Sources/PaxMposSDK.xcframework"
cp -R "$XCFRAMEWORK_TEMP_PATH" "$SPM_REPO_TEMP_PATH/Sources/"

VERSION="$CI_TAG"
echo "Updating SPM repo with version $VERSION..."
cd "$SPM_REPO_TEMP_PATH"
git config user.name "XCode Cloud CI"
git config user.email "tom.nguyen@finix.com"
git add .
git commit -m "Update PaxMposSDK.xcframework to version $VERSION"
git push origin main

echo "Tagging new version..."
git tag -a "$VERSION" -m "Version $VERSION"
git push origin "$VERSION"

echo "Deployment complete! Version $VERSION is now available."

exit 0
