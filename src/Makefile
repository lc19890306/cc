# Makefile to create words_tweeted and median_unique
CC = clang
CXX = clang++
CFLAGS = -O3 -std=c++11
DBGFLAGS = -O0 -std=c++11 -g -ggdb
SRC = ./median_unique.cc
OBJ_DIR = ../build/
OBJ = $(OBJ_DIR)median_unique

all:
	mkdir -pv ${OBJ_DIR}
	$(CXX) $(CFLAGS) -o $(OBJ) $(SRC)

debug:
	mkdir -pv ${OBJ_DIR}
	$(CXX) $(DBGFLAGS) -o $(OBJ) $(SRC)

clean:
	rm -rf ${OBJ_DIR}
