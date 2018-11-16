runner: fork.o
	gcc fork.o -o runner
fork.o: fork.c
	gcc -c fork.c
run: runner
	./runner
clean:
	rm *~* \#*\# *.o *.out runner
