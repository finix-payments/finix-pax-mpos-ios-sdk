# PaxMposSDK

## Overview
This guide helps iOS developers integrate **FINIX PaxMposSDK** into their applications for communicating with mPOS devices.

## Table of Contents
- [Installation](#installation)
- [Pre-requisites](#pre-requisites)
- [Integration Guide](#integration-guide)
- [Sample App](#sample-app)

## Installation
Add the SDK to your project via Swift Package Manager using:
```
https://github.com/finix-payments/PaxMposSDK
```

## Pre-requisites
- iOS 17.6 or later
- Real iOS device (ARM64 simulator support coming soon)
- Add Bluetooth permission in Info.plist using key `Privacy - Bluetooth Always Usage Description`

## Integration Guide
### 1. Initialize the SDK
```swift
import PaxMposSDK

let finixClient = FinixClient(config: FinixConfig(
            environment: TEST_ENVIRONMENT,
            credentials: Finix.APICredentials(username: TEST_USERNAME, password: TEST_PASSWORD),
            application: TEST_APPLICATION,
            version: TEST_VERSION,
            merchantId: TEST_MERCHANT_ID,
            mid: TEST_MERCHANT_MID,
            deviceType: .Pax,
            deviceId: "")
)
finixClient.delegate = self
finixClient.interactionDelegate = self
```

### 2. Scan for devices
```swift
finixClient.startScan()

extension ViewController: FinixDelegate {
    func didDiscoverDevice(_ deviceInfo: DeviceInfo) {
        devices.append(deviceInfo)
    }
}
```

### 3. Connect to device
The device will display:
- Orange light: Ready for pairing
- Green light: Battery full
- After connection: Only green light remains
```swift
finixClient.connectDevice(device.id)

extension ViewController: FinixDelegate {
    func deviceDidConnect(_ deviceInfo: DeviceInfo) {
        connectedDevice = deviceInfo
    }
}
```

### 4. Start a Transaction
First, update the client with the device ID:
```swift
finixClient.update(deviceId: TEST_DEVICE_ID)
```
Then initiate the transaction:
```swift
let transactionAmount = Currency(amount: Int(amountDouble * 100), code: .USD)
finixClient.startTransaction(amount: transactionAmount, type: transactionType) { transferResponse, error in
    Task { @MainActor in
        // Handle using transferResponse and error
    }
}
```
Device status:
- Blue light: Waiting for card interaction
- Light turns off + beeping: Card detected

## Sample App
[PaxMposSDKDemo](https://github.com/finix-payments/PaxMposSDKDemo)
