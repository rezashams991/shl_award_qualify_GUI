# ============================================================================
# Makefile for Stronghold Legends Award Unlocker (GUI + Console)
# Compiler: MinGW (msys64)
# ============================================================================

CC       = gcc
CFLAGS   = -Wall -Wextra -O2
LDFLAGS  = -lcomctl32 -luser32 -lgdi32 -lkernel32 -mwindows
LDFLAGS_CONSOLE = -lcomctl32 -luser32 -lgdi32 -lkernel32

# Directories
SRCDIR   = src
RESDIR   = resources
BUILDDIR = build
BINDIR   = .

# Source files (common to both builds)
COMMON_SRC = $(SRCDIR)/os_wrapper.c $(SRCDIR)/ms_funcs.c

# GUI specific
GUI_SRC   = $(SRCDIR)/gui_main.c $(SRCDIR)/award_actions.c
GUI_OBJ   = $(BUILDDIR)/gui_main.o $(BUILDDIR)/award_actions.o \
            $(BUILDDIR)/os_wrapper.o $(BUILDDIR)/ms_funcs.o

# Console specific (optional)
CONSOLE_SRC = $(SRCDIR)/main.c
CONSOLE_OBJ = $(BUILDDIR)/main.o $(BUILDDIR)/os_wrapper.o $(BUILDDIR)/ms_funcs.o

# Resource file (icon)
RC_FILE  = $(RESDIR)/resource.rc
RES_OBJ  = $(BUILDDIR)/resource.o

# Targets
TARGET_GUI     = $(BINDIR)/shl_award_gui.exe
TARGET_CONSOLE = $(BINDIR)/shl_award_console.exe

# ----------------------------------------------------------------------------
# Phony targets
.PHONY: all clean gui console

all: gui console

gui: $(TARGET_GUI)

console: $(TARGET_CONSOLE)

# ----------------------------------------------------------------------------
# Build GUI executable (with icon)
$(TARGET_GUI): $(GUI_OBJ) $(RES_OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

# Build Console executable (without icon, but you can add if you like)
$(TARGET_CONSOLE): $(CONSOLE_OBJ)
	$(CC) -o $@ $^ $(LDFLAGS_CONSOLE)

# ----------------------------------------------------------------------------
# Compile C source files to object files
$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(BUILDDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Compile resource file (.rc) to object file (.o)
$(RES_OBJ): $(RC_FILE) $(RESDIR)/icon.ico
	@mkdir -p $(BUILDDIR)
	windres $< -O coff -o $@

# ----------------------------------------------------------------------------
# Clean
clean:
	rm -rf $(BUILDDIR) $(TARGET_GUI) $(TARGET_CONSOLE)

# ----------------------------------------------------------------------------
# Show help
help:
	@echo "Targets:"
	@echo "  all      - Build both GUI and console versions (default)"
	@echo "  gui      - Build only the GUI version with icon"
	@echo "  console  - Build only the console version"
	@echo "  clean    - Remove all built files"
	@echo "  help     - Show this help"