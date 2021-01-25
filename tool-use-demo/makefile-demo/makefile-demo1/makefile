# this is makefile

# target
main.out:max.o min.o main.c
	gcc max.o min.o main.c -o main.out

# middle
max.o:max.c
	gcc -c max.c -o max.o
min.o:min.c
	gcc -c min.c -o min.o


# clean
clean:
	rm -rf *.o *.out *.elf

