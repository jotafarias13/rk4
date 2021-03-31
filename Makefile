# -*- Makefile -*-

_PATH = /Users/Jota/Sync/Jota/Academico/Projetos/C_C++/Bibliotecas

APPS 			= ./apps
BIN 			= ./bin
DYLIB			= ./dylib
INCLUDE 		= ./include
INCLUDE_GLOBAL 	= $(_PATH)/include
LIB 			= ./lib
LIB_GLOBAL 		= $(_PATH)/lib
OBJ 			= ./obj
SRC 			= ./src
NAME			= rk4 

CC		= g++
FLAGS		= -Wall
LIBS		= -lrk4 -ltempo -lgnuplot -L $(LIB) -L $(LIB_GLOBAL)
INCLUDES	= -I $(INCLUDE) -I $(INCLUDE_GLOBAL)



dir:
	mkdir $(OBJ) $(LIB) $(DYLIB) $(BIN)


obj: $(OBJ)/rk4.o


$(OBJ)/%.o: $(SRC)/%.cpp $(INCLUDE)/%.h
	$(CC) -c $< -I $(INCLUDE) -o $@


lib: $(LIB)/rk4.a


$(LIB)/%.a: $(OBJ)/%.o
	ar -rcs $(LIB)/librk4.a $(OBJ)/*.o


static: obj lib


dynamic:
	$(CC) -dynamiclib $(SRC)/rk4.cpp -I $(INCLUDE) -o $(DYLIB)/librk4.dylib


app: $(BIN)/rk4-test


$(BIN)/%: $(APPS)/%.cpp
	$(CC) $< -lrk4 -ltempo -lgnuplot -L $(LIB) -L $(LIB_GLOBAL) -I $(INCLUDE) -I $(INCLUDE_GLOBAL) -o $@


run:
	$(BIN)/rk4-test


clean:
	rm -f $(OBJ)/* $(LIB)/* $(DYLIB)/* $(BIN)/*
