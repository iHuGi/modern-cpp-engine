# Variables for compiler and flags
CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra

# The final executable name
TARGET = bin/main
# Rule to build the program
all:
	$(CXX) $(CXXFLAGS) *.cpp -o $(TARGET)

# Rule to clean up the trash
clean:
	rm -f bin/*