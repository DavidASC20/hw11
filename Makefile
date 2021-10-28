all: hw11.o
	gcc -o hw11 hw11.o

hw11.o: hw11.c
	gcc -c hw11.c

run:
	./hw11