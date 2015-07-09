# Makefile to create a twitter analyzer
CC = clang
CXX = clang++
CFLAGS = -O3 -std=c++11 -fpermissive
CXXFLAGS = -O3 -std=c++11 -fpermissive
DBGFLAGS = -O0 -std=c++11 -g -ggdb -Wall
LIBS = -lboost_program_options
SRC_DIR = .
SRC = $(SRC_DIR)/median_unique.cc $(SRC_DIR)/words_tweeted.cc
OBJ_DIR = ../build
OBJ = $(OBJ_DIR)/twitter_analyzer

.PHONY:	all object target clean

all:	objects exe	

objects:	
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/*.cc $(LIBS)

exe:
	mkdir -pv ${OBJ_DIR}
	$(CXX) $(CXXFLAGS) -o $(OBJ) $(SRC_DIR)/*.o $(LIBS)

debug:
	$(CXX) $(DBGFLAGS) -c $(SRC_DIR)/*.cc $(LIBS)
	mkdir -pv ${OBJ_DIR}
	$(CXX) $(DBGFLAGS) -o $(OBJ) $(SRC_DIR)/*.o $(LIBS)

clean:
	rm -rf ${OBJ_DIR}
	rm -rf $(SRC_DIR)/*.o
