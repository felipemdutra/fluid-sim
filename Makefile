# Compiler
CXX := g++
CXXFLAGS := -Wall -Wextra -Werror -std=c++17 -Iinclude/

# Directories
SRC_DIR := src
BUILD_DIR := build
BIN_DIR := bin
TARGET := $(BIN_DIR)/fluid-sim

# Find all .cpp files in src/
SRC_FILES := $(shell find $(SRC_DIR) -type f -name "*.cpp")
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRC_FILES))

# Default target
all: $(TARGET)

# Link the executable
$(TARGET): $(OBJ_FILES) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Compile each .cpp file separately
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Create necessary directories
$(BIN_DIR) $(BUILD_DIR):
	mkdir -p $@

# Clean build files
clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)

# Rebuild from scratch
rebuild: clean all

.PHONY: all clean rebuild

