# Changelog

All notable changes to this project will be documented in this file.

## [1.0.0] - 2026-09-01

### Added
- Graphical user interface (GUI) using Win32 API
- Application icon embedded in the executable
- ListView with checkboxes for selecting awards
- Status bar to show progress and messages
- "Select All" and "Clear All" buttons
- Worker thread to keep the UI responsive during memory operations

### Changed
- Refactored award activation logic into `award_actions.c` and `award_actions.h`
- Restructured project files into `src/` and `resources/` directories
- Added Unicode support for the GUI version

### Fixed
- N/A (initial release)

### Removed
- N/A (initial release)

---

## [0.1.0] - 2023 (Original)

Original console version by Daniel Jenssen.  
See the original repository: [shl_award_qualify](https://gitlab.com/Daerandin/shl_award_qualify)