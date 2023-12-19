# Define compiler and compiler flags
CXX = g++
CXXFLAGS = -Wall -Wextra

# Define the target file
TARGET = Main
OUT_DIR = ./out

# Define the source files
SRC = Main.cpp $(wildcard *.cpp)

# Define object files (replace .cpp with .o)
OBJ = $(patsubst %.cpp,$(OUT_DIR)/%.o,$(SRC))

# Default target
all: $(OUT_DIR)/$(TARGET)

# Rule for linking the final executable
$(OUT_DIR)/$(TARGET): $(OBJ)
	@mkdir -p $(OUT_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Rule for compiling source files to object files
$(OUT_DIR)/%.o: %.cpp
	@mkdir -p $(OUT_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean target
clean:
	rm -rf $(OUT_DIR)
