# Compiler and compilation flags
CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -g

# Identifies all source files in the current directory (main.cpp, PlayerClass.cpp, etc.)
SRC = $(wildcard *.cpp)

# The name of your final executable
TARGET = bin/main

# Default build target
all: $(TARGET)

# Rule: compiles ALL .cpp files together into a single executable
$(TARGET): $(SRC)
	@mkdir -p bin
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET) -lcurl

# Removes all compiled binaries
clean:
	rm -rf bin/*