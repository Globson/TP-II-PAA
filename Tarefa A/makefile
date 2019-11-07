all: main.c Sources/Funcoes.c Sources/Recursiva.c Sources/Memorization.c Sources/DeTrasPraFrente.c
	gcc main.c -o EXEC Sources/Funcoes.c Sources/Recursiva.c Sources/Memorization.c Sources/DeTrasPraFrente.c

run: EXEC
	./EXEC

Mem: EXEC
	valgrind --tool=memcheck ./EXEC

CPU: EXEC
	command time -v ./EXEC

rm: EXEC
	rm EXEC
