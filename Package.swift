// swift-tools-version: 5.9
// The public package manifest. ci_scripts/ci_post_xcodebuild.sh copies it to the root of
// finix-pax-mpos-ios-sdk next to Sources/PaxMposSDK.xcframework and Sources/PaxMposSDKDatadog.

import PackageDescription

let package = Package(
    name: "PaxMposSDK",
    platforms: [
        .iOS("15.6"),
    ],
    products: [
        .library(
            name: "PaxMposSDK",
            targets: ["PaxMposSDKDatadog"]
        ),
    ],
    dependencies: [
        // A range, so SPM can settle on the version an app that already uses Datadog resolves.
        .package(url: "https://github.com/DataDog/dd-sdk-ios.git", from: "3.6.1"),
    ],
    targets: [
        .binaryTarget(
            name: "PaxMposSDK",
            path: "Sources/PaxMposSDK.xcframework"
        ),
        // Compiled in the app: connects the binary to the app's single copy of Datadog.
        .target(
            name: "PaxMposSDKDatadog",
            dependencies: [
                "PaxMposSDK",
                .product(name: "DatadogCore", package: "dd-sdk-ios"),
                .product(name: "DatadogLogs", package: "dd-sdk-ios"),
                .product(name: "DatadogCrashReporting", package: "dd-sdk-ios"),
            ]
        ),
    ]
)
