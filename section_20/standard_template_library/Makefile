# Compiler and compilation flags
CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -g

# Identifies all source files in the current directory
SRC = $(wildcard *.cpp)

# Generates a corresponding binary target inside bin/ for each .cpp file
# Example: unique_ptr.cpp -> bin/unique_ptr
TARGETS = $(patsubst %.cpp, bin/%, $(SRC))

# Default build target: builds ALL individual executables
all: $(TARGETS)

# Pattern Rule: Compiles EACH individual .cpp file into its own binary in bin/
bin/%: %.cpp
	@mkdir -p bin
	$(CXX) $(CXXFLAGS) $< -o $@

# Removes all compiled binaries
clean:
	rm -rf bin/*

.PHONY: all clean