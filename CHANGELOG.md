# Changelog

All notable changes to PaxMposSDK will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [Unreleased]

## [1.31.4] - 2026-11-09

### Changed

- Only `info`, `warn` and `error` logs go to Datadog. `debug` logs stay on the device
- RKI and device lifecycle logs (`[RKI]`, `[DEVICE]`, `[OS]`, `[EMV]`, `[PARAMS]`, `[RESET]`) moved from `debug` to `info`, so they reach Datadog
- The device ID no longer appears in the text of the EMV and CLSS version check logs
- Device reset logs no longer include the raw device response
- The Datadog console output is on in debug builds of the host app only. Release builds print no logs

## [1.31.3] - 2026-11-04

### Changed

- SDK version now reported correctly to Datadog via `PaxMposSDKMetadata.version`
- Added `sdk_version`, `merchant_id`, `username` as per-log attributes for Datadog queries (`@sdk_version:...`)
- Aligned logging with TTP and PaymentSheet SDKs

### Added

- `Scripts/bump-version.sh` for consistent version bumping
- CI validation for `PaxMposSDKMetadata.version` in deploy workflow

## [1.31.2] - 2026-10-28

### Changed

- Credential scrubbing: Authorization headers redacted in HTTP logs
- HTTP request/response logging now shows path only (no query params or full URLs)

## [1.31.1] - 2026-10-15

### Fixed

- Build compatibility with Xcode 16.3

## [1.31.0] - 2026-10-01

### Added

- Initial Datadog logging integration
- SDK version tracking via `PaxMposSDKMetadata`
