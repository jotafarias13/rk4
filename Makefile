# -*- Makefile -*-

_PATH = /Users/Jota/Sync/Jota/Acadêmico/Projetos/C_C++/Bibliotecas

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


obj: $(OBJ)/$(NAME).o


$(OBJ)/%.o: $(SRC)/%.c $(INCLUDE)/%.h
	$(CC) -c $< -I $(INCLUDE) -o $@


lib:
	ar -rcs $(LIB)/lib$(NAME).a $(OBJ)/*.o


static: obj lib


dynamic:
	$(CC) -dynamiclib $(SRC)/$(NAME).c -I $(INCLUDE) -o $(DYLIB)/lib$(NAME).dylib


app: $(BIN)/teste_rk4


run:
	$(BIN)/teste_rk4


clean:
	rm $(OBJ)/* $(LIB)/* $(DYLIB)/* $(BIN)/*
