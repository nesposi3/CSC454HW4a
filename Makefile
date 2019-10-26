CC=g++
FLAG=-c

all:	Main.o Main.o MemoryModel.o XORModel.o
	$(CC) Main.o MemoryModel.o XORModel.o -o out
Main.o:
	$(CC) $(FLAG) Main.cpp
MemoryModel.o:
	$(CC) $(FLAG) MemoryModel.cpp MemoryModel.h
XORModel.o:
	$(CC) $(FLAG) XORModel.cpp XORModel.h
clean:
	rm *.o out *.gch	
	
