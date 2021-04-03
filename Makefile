# -*- Makefile -*-


NAME 	= rk4

INCLUDE = ./include
SRC 	= ./src
APPS 	= ./apps
OBJ 	= ./obj
LIB 	= ./lib
DYLIB	= ./dylib
BIN 	= ./bin
OUTPUT	= ./output

CC	= g++



.PHONY: obj lib static-app static dylib dynamic-app dynamic run-static run-dynamic clean install uninstall



obj:
	mkdir -p $(OBJ)
	$(CC) -c $(SRC)/$(NAME).cpp -I $(INCLUDE) -o $(OBJ)/$(NAME).o


lib:
	mkdir -p $(LIB)
	ar -rcs $(LIB)/lib$(NAME).a $(OBJ)/$(NAME).o


static-app:
	mkdir -p $(BIN)
	$(CC) $(APPS)/$(NAME)-test.cpp -l$(NAME) -L $(LIB) -I $(INCLUDE) -o $(BIN)/$(NAME)-test-static
	# $(CC) $(APPS)/$(NAME)-test.cpp -l$(NAME) -L $(LIB) ${HOME}/.lib/libgnuplot.dylib -I $(INCLUDE) -I ${HOME}/.include -o $(BIN)/$(NAME)-test-static


static: obj lib static-app


dylib:
	mkdir -p $(DYLIB)
	$(CC) -dynamiclib $(SRC)/$(NAME).cpp -I $(INCLUDE) -o $(DYLIB)/lib$(NAME).dylib


dynamic-app:
	mkdir -p $(BIN)
	$(CC) $(APPS)/$(NAME)-test.cpp $(DYLIB)/lib$(NAME).dylib -I $(INCLUDE) -o $(BIN)/$(NAME)-test-dynamic
	# $(CC) $(APPS)/$(NAME)-test.cpp $(DYLIB)/lib$(NAME).dylib ${HOME}/.lib/libgnuplot.dylib -I $(INCLUDE) -I ${HOME}/.include -o $(BIN)/$(NAME)-test-dynamic


dynamic: dylib dynamic-app


run-static:
	mkdir -p $(OUTPUT)
	$(BIN)/$(NAME)-test-static


run-dynamic:
	mkdir -p $(OUTPUT)
	$(BIN)/$(NAME)-test-dynamic


clean:
	rm -f $(OBJ)/* $(BIN)/* $(LIB)/* $(DYLIB)/* $(OUTPUT)/*


install:
	./install.sh $(NAME)


uninstall:
	./uninstall.sh $(NAME)
