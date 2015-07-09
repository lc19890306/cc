# Makefile to create a twitter analyzer
CC = clang
CXX = clang++
CFLAGS = -O3 -std=c++11
CXXFLAGS = -O3 -std=c++11
DBGFLAGS = -O0 -std=c++11 -g -ggdb
LIBS = -lboost_program_options
SRC = ./twitter_analyzer.cc
OBJ_DIR = ../build/
OBJ = $(OBJ_DIR)twitter_analyzer

all:
	mkdir -pv ${OBJ_DIR}
	$(CXX) $(CXXFLAGS) -o $(OBJ) $(SRC) $(LIBS)

debug:
	mkdir -pv ${OBJ_DIR}
	$(CXX) $(DBGFLAGS) -o $(OBJ) $(SRC) $(LIBS)

clean:
	rm -rf ${OBJ_DIR}
