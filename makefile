project3Exe: main.o champion.o
	gcc main.o champion.o -o project3Exe
main.o: champion.h main.c
	gcc -c main.c -o main.o
champion.o: champion.h champion.c
	gcc -c champion.c -o champion.o
clean:
	rm *.o
	rm project3Exe

