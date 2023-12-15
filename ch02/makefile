# Define compiler and compiler flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11

# Define the target file
TARGET = main

# Define the source files
SRC = main.cc $(wildcard ./chapter-examples/*.cc)

# Define object files (replace .cpp with .o)
OBJ = $(SRC:.cc=.o)

# Default target
all: $(TARGET)

# Rule for linking the final executable
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Rule for compiling source files to object files
%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $<

# Clean target
clean:
	rm -f $(OBJ) $(TARGET)
