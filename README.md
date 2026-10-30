# PaxMposSDK iOS SDK

Binary distribution of the PaxMposSDK iOS SDK via Swift Package Manager.

## Installation

### Swift Package Manager

Add the following to your `Package.swift`:

```swift
dependencies: [
    .package(url: "https://github.com/finix-payments/finix-pax-mpos-ios-sdk.git", from: "1.31.3")
],
targets: [
    .target(
        name: "YourApp",
        dependencies: [
            .product(name: "PaxMposSDK", package: "finix-pax-mpos-ios-sdk")
        ]
    )
]
```

Or in Xcode:
1. File → Add Package Dependencies
2. Enter: `https://github.com/finix-payments/finix-pax-mpos-ios-sdk`
3. Select version `1.31.3` or later

## Requirements

- iOS 15.6+
- Xcode 26.3+

## Datadog

The package depends on Datadog's `dd-sdk-ios` for diagnostics. Swift Package Manager adds it for you.
If your app also uses Datadog, both share one copy, and the SDK logs to its own Datadog instance
without touching yours.

## Support

- Email: developers@finixpayments.com
- Documentation: https://www.finix.com/docs/guides/payments/
