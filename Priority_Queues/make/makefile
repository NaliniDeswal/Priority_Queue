###########################################################################
#	FILE NAME :	makefile					  #
#       PURPOSE   :	compile the code				  #
#	DATE      :	21/10/13					  #
#	TEAM 	  : 	Nalini Deswal 				  	  #
#			Narendra Nalli  				  #
#			Pankaj Kashyap   				  #
###########################################################################

OBJ = ../obj/
INC = ../include/
SRC = ../src/
BIN = ../bin/

all : $(BIN)heap

$(BIN)heap : $(OBJ)Binomial_Heap.o $(OBJ)Binary_Heap.o $(OBJ)main.o
	g++ -g -o $(BIN)heap $(OBJ)Binomial_Heap.o $(OBJ)Binary_Heap.o $(OBJ)main.o -I$(INC)

#$(BIN)heap : $(OBJ)Binomial_Heap.o $(OBJ)Fibonacci_Heap.o  $(OBJ)Binary_Heap.o $(OBJ)main.o
#	g++ -g -o $(BIN)heap $(OBJ)Binomial_Heap.o $(OBJ)Fibonacci_Heap.o $(OBJ)Binary_Heap.o $(OBJ)main.o -I$(INC)

$(OBJ)Binomial_Heap.o : $(SRC)Binomial_Heap.cpp $(INC)header.h
	g++ -g -o $(OBJ)Binomial_Heap.o -c $(SRC)Binomial_Heap.cpp -I$(INC)

#$(OBJ)Fibonacci_Heap.o : $(SRC)Fibonacci_Heap.cpp $(INC)header.h
#	g++ -g -o $(OBJ)Fibonacci_Heap.o -c $(SRC)Fibonacci_Heap.cpp -I$(INC)

$(OBJ)Binary_Heap.o : $(SRC)Binary_Heap.cpp $(INC)header.h
	g++ -o $(OBJ)Binary_Heap.o -c $(SRC)Binary_Heap.cpp -I$(INC)

$(OBJ)main.o : $(SRC)main.cpp $(INC)header.h
	g++ -o $(OBJ)main.o -c $(SRC)main.cpp -I$(INC)

clean :
	rm ../obj/*
	rm ../bin/*

#plot :
#	dot -Tps $(INPUT) -o input.ps
#	dot -Tps $(OUTPUT) -o output.ps

#display :
#	gv input.ps
#	gv output.ps
