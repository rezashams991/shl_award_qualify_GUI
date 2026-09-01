# shl_award_qualify_GUI


This project is a **fork** of [shl_award_qualify](https://gitlab.com/Daerandin/shl_award_qualify) by **Daniel Jenssen**.  
It adds a **graphical user interface (GUI)** and an application icon to the original tool, making it easier to select and unlock multiple awards simultaneously.

For users who prefer the command line, the **console version** (`shl_award_console.exe`) is also provided alongside the GUI version.

---

## Table of Contents

- [Features](#features)
- [Technologies Used](#technologies-used)
- [File Structure](#file-structure)
- [Installation & Setup](#installation--setup)
- [Usage](#usage)
  - [GUI Version](#gui-version-shl_award_guiexe)
  - [Console Version](#console-version-shl_award_consoleexe)
- [Releases](#releases)
- [Disclaimer](#disclaimer)
- [License](#license)

---

## Features

- **Graphical User Interface** – Select awards with checkboxes and apply them with a single click.
- **Console Version** – Command‑line interface for users who prefer the original workflow.
- **Automatic Process Detection** – The tool waits for and detects the Stronghold Legends process.
- **Memory Patching** – Modifies game memory to unlock awards without altering game files.
- **Lightweight & Portable** – Single executable, no external dependencies.
- **Icon Embedded** – The GUI version includes a custom application icon.

---

## Technologies Used

- **C** – Core logic and memory manipulation.
- **Win32 API** – GUI implementation and system calls.
- **MinGW-w64** – Compiler toolchain (via MSYS2).
- **Make** – Build automation.
- **windres** – Resource compiler for embedding the icon.

---

## File Structure

```
project/
├── src/
│   ├── main.c               # Original console version
│   ├── gui_main.c           # GUI implementation (Win32 API)
│   ├── award_actions.c      # Award activation logic
│   ├── award_actions.h
│   ├── os_wrapper.c         # OS abstraction layer
│   ├── os_wrapper.h
│   ├── ms_funcs.c           # Windows-specific functions
│   └── ms_funcs.h
├── resources/
│   ├── resource.rc          # Resource script for icon
│   └── icon.ico             # Application icon
├── Makefile                 # Build script
├── LICENSE                  # GPLv3 license
└── README.md                # This file
```

---

## Installation & Setup

### Prerequisites

- [MSYS2](https://www.msys2.org/) installed.
- Open the **MSYS2 MinGW 64-bit** terminal and install the required tools:

```bash
pacman -S mingw-w64-x86_64-gcc mingw-w64-x86_64-make
```

### Build from Source

1. Clone or download the source code.
2. Ensure the directory structure matches the one above.
3. Navigate to the project root and run:

```bash
make
```

This will build both the GUI and console versions.

- Build only GUI: `make gui`
- Build only console: `make console`
- Clean build files: `make clean`

The compiled executables (`shl_award_gui.exe` and `shl_award_console.exe`) will appear in the project root.

> **Note:** If `resources/icon.ico` or `resource.rc` is missing, the GUI version will still compile but without the custom icon.

---

## Usage

### GUI Version (`shl_award_gui.exe`)

1. Run the executable.
2. Select awards by ticking the checkboxes.
3. Click **Apply** – the status bar will show: *"Waiting for Stronghold Legends to start..."*
4. **Launch Stronghold Legends** (if already running, detection is immediate).
5. The tool will patch the game memory and display: *"All selected awards have been unlocked."*
6. Return to the game and **finish any match, skirmish, or mission** (win or lose). After the results screen, the awards will be unlocked.
7. Click **Close** to exit.

> **Note:** You must select at least one award before clicking Apply.

---

### Console Version (`shl_award_console.exe`)

1. Run the console application (preferably before launching the game).
2. It will display: *"Starting to look for Stronghold Legends process..."*
3. **Launch Stronghold Legends**.
4. The tool will detect the game and show its PID and base address.
5. From the text menu, enter:
   - Award number (1–60) to unlock a specific award.
   - `61` to unlock all awards at once.
   - `62` to exit.
6. After confirmation, return to the game and finish any match – the selected awards will be unlocked.

---

## Releases

Pre‑built binaries are available in the **Releases** section:

- `shl_award_gui.exe` – GUI version with icon.
- `shl_award_console.exe` – Console version (original functionality).
- `SourceCode.zip` – Full source code for review and custom builds.

---

## Disclaimer

**This tool is provided for educational and personal use only.**  
It modifies the memory of the game *Stronghold Legends* (Steam Edition) to unlock in‑game awards. The author does **not** promote, support, or encourage cheating, hacking, or any form of unfair advantage in multiplayer or competitive environments.

- This project is **not affiliated with**, **endorsed by**, or **connected to** Firefly Studios, Valve Corporation (Steam), or any other related entity.
- The tool does **not** modify, patch, or redistribute any game files – it only alters runtime memory, which is reset when the game is closed.
- Users are solely responsible for how they use this tool. The author assumes **no liability** for any consequences, including but not limited to account restrictions, bans, or loss of game progress.
- **Always respect the game’s terms of service and community guidelines.**

By using this software, you acknowledge that you understand and accept these terms.


---

## License

This project is licensed under the **GNU General Public License v3.0**.  
See the `LICENSE` file for the full text.

- Original code copyright © 2023 **Daniel Jenssen**.
- Modifications (GUI, icon, restructuring) copyright © 2026 **Reza Shams** – released under the same GPLv3 terms.

---

Feel free to open an issue for suggestions, bug reports, or contributions.

---

*Built with ❤ by [Reza Shams](https://github.com/rezashams991)*
