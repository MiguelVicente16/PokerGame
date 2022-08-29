CC= gcc
CFLAGS= -Wall -std=c99 -O3

pokeristars: main.o shuffle.o Modos_d.o Linha_Comando.o
	$(CC) $(CFLAGS) -o pokeristars main.o shuffle.o Modos_d.o Linha_Comando.o

main.o:	main.c
	$(CC) -c $(CFLAGS) main.c

shuffle.o:	shuffle.c shuffle.h
	$(CC) -c $(CFLAGS) shuffle.c

Modos_d.o:	Modos_d.c Modos_d.h
	$(CC) -c $(CFLAGS) Modos_d.c

Linha_Comando.o:	Linha_Comando.c Linha_Comando.h
	$(CC) -c $(CFLAGS) Linha_Comando.c


clean:
		rm -f $(PROJECT_NAME) *.o
