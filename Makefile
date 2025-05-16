# SFML Makefile for C++

# compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

# directories
SRC_DIR := src
OBJ_DIR := build/obj
BIN_DIR := build

# executable
BIN := $(BIN_DIR)/main

# find all .cpp files recursively
SOURCES := $(shell find $(SRC_DIR) -name '*.cpp')
OBJECTS := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SOURCES))

# default rule
all: $(BIN)

# rule to build the executable
$(BIN): $(OBJECTS)
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

# rule to compile .cpp into .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# clean
.PHONY: clean
clean:
	rm -rf $(OBJ_DIR) $(BIN)

.PHONY: run
run: all
	./$(BIN)
