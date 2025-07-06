# Makefile for Virtual Memory Simulator
# Author: sangeeth_binu

CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g
TARGET = vm_simulator
SRCDIR = src
INCDIR = include
OBJDIR = obj
BINDIR = bin

# Source files
SOURCES = main.c page_table.c frame_table.c memory_manager.c storage_manager.c replacement_algorithms.c
OBJECTS = $(SOURCES:%.c=$(OBJDIR)/%.o)

# Include directory
INCLUDES = -I$(INCDIR)

# Default target
all: $(BINDIR)/$(TARGET)

# Create directories if they don't exist
$(OBJDIR):
	mkdir -p $(OBJDIR)

$(BINDIR):
	mkdir -p $(BINDIR)

# Link object files to create executable
$(BINDIR)/$(TARGET): $(OBJECTS) | $(BINDIR)
	$(CC) $(OBJECTS) -o $@

# Compile source files to object files
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# If source files are in current directory instead of src/
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean build artifacts
clean:
	rm -rf $(OBJDIR) $(BINDIR)
	rm -f *.o $(TARGET)
	rm -f virtual_storage.bin

# Run the program
run: $(BINDIR)/$(TARGET)
	./$(BINDIR)/$(TARGET)

# Debug version
debug: CFLAGS += -DDEBUG
debug: $(BINDIR)/$(TARGET)

# Help
help:
	@echo "Available targets:"
	@echo "  all     - Build the virtual memory simulator"
	@echo "  clean   - Remove build artifacts"
	@echo "  run     - Build and run the simulator"
	@echo "  debug   - Build with debug symbols"
	@echo "  help    - Show this help message"

.PHONY: all clean run debug help