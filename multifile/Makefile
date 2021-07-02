main: main.o fact.o hello.o
	gcc -o main main.o fact.o hello.o
%.o: %.c
	gcc -c $@.c
clean:
	rm -rf *.o
