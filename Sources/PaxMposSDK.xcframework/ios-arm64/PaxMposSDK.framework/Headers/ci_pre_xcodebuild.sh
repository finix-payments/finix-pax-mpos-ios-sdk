#!/bin/sh

#  ci_pre_xcodebuild.sh
#  PaxMposSDK
#
#  Created by Tom Nguyen on 3/7/25.
#  

set -e  # Exit immediately if any command fails

# Only execute if archiving using XCode Cloud
if ! [ "$CI_XCODE_CLOUD" == "TRUE" && "$CI_XCODEBUILD_ACTION" == "archive" ]; then
  echo "Skipping the process, isXCodeCloud=$CI_XCODE_CLOUD, xcodebuildAction=$CI_XCODEBUILD_ACTION"
  exit 0
fi

echo "Starting pre-xcodebuild process for SDK..."

# Archive for x86_64 simulator
echo "Archiving for x86_64 simulator..."
xcodebuild archive \
    -project "$CI_PROJECT_FILE_PATH" \
    -scheme "$CI_XCODE_SCHEME" \
    -arch x86_64 \
    -configuration Release \
    -archivePath "$SIMULATOR_ARCHIVE_PATH" \
    -sdk iphonesimulator \
    -derivedDataPath "$CI_DERIVED_DATA_PATH" \
    SKIP_INSTALL=NO BUILD_LIBRARIES_FOR_DISTRIBUTION=YES
