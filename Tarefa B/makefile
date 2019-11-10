all: main.c Sources/Funcoes.c Sources/Menu.c
	gcc main.c -o EXEC Sources/Funcoes.c Sources/Menu.c

run: EXEC
	./EXEC

Mem: EXEC
	valgrind --tool=memcheck ./EXEC

CPU: EXEC
	command time -v ./EXEC

rm: EXEC
	rm EXEC
