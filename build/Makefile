# Makefile for Health Care Management System tests with GoogleTest
# Run this from the build/ directory

CXX = g++
CXXFLAGS = -std=c++17 -I../include -I../googletest/googletest/include -pthread
LDFLAGS = -L../googletest/build/lib -lgtest -lgtest_main

SRC_DIR = ../src
TEST_DIR = ../tests

SRC_FILES = $(SRC_DIR)/Medical_Case.cpp $(SRC_DIR)/Doctor.cpp $(SRC_DIR)/Patient.cpp $(SRC_DIR)/System.cpp
TEST_FILES = $(TEST_DIR)/test_system.cpp

OBJ_FILES = $(SRC_FILES:.cpp=.o) $(TEST_FILES:.cpp=.o)

TARGET = test_system.exe

all: $(TARGET)

$(TARGET): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) $^ $(LDFLAGS) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_FILES) $(TARGET)