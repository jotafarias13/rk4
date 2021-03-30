# -*- Makefile -*-

_PATH = /Users/Jota/Sync/Jota/Acadêmico/Projetos/C_C++/Bibliotecas

APPS 			= ./apps
BIN 			= ./bin
DYLIB			= ./dylib
DYLIB_GLOBAL	= $(_PATH)/dylib
INCLUDE 		= ./include
INCLUDE_GLOBAL 	= $(_PATH)/include
LIB 			= ./lib
LIB_GLOBAL 		= $(_PATH)/lib
OBJ 			= ./obj
SRC 			= ./src

CC			= g++
FLAGS		= -Wall
LIBS		= -lrk4 -ltempo -lgnuplot -L $(LIB) -L $(LIB_GLOBAL)
INCLUDES	= -I $(INCLUDE) -I $(INCLUDE_GLOBAL)



all: obj lib app
	

dyall: dylib dyapp
	
	
obj: $(OBJ)/rk4.o


lib:
	ar -rcs $(LIB)/librk4.a $(OBJ)/*.o
	
	
app: $(BIN)/teste_rk4


$(OBJ)/%.o: $(SRC)/%.cpp $(INCLUDE)/%.h
	$(CC) $(FLAGS) -c $< $(INCLUDES) -o $@


$(BIN)/%: $(APPS)/%.cpp
	$(CC) $(FLAGS) $< $(LIBS) $(INCLUDES) -o $@
	

dylib: $(DYLIB)/libdyrk4.dylib
	
	
dyapp:
	$(CC) $(FLAGS) $(APPS)/teste_rk4.cpp -I $(INCLUDE) -I $(INCLUDE_GLOBAL) -ldyrk4 -ltempo -lgnuplot -L $(DYLIB_GLOBAL) -L $(LIB_GLOBAL) -o $(BIN)/teste_dyrk4
	
	
$(DYLIB)/libdyrk4.dylib:
	$(CC) $(FLAGS) -dynamiclib $(SRC)/rk4.cpp -I $(INCLUDE) -o $(DYLIB)/libdyrk4.dylib


run:
	$(BIN)/teste_rk4
	
	
dyrun: 
	$(BIN)/teste_dyrk4

	
allrun: all run
	
	
clean:
	rm $(OBJ)/* $(BIN)/*