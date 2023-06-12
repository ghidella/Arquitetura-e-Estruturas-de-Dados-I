CC = gcc
CFLAGS = -Wall -Wextra

all: ep1_matriz_13672126.exe ep1_lista_13672126.exe

ep1_matriz_13672126.exe: main.c grafo_matrizadj.c
	$(CC) $(CFLAGS) -o $@ $^

ep1_lista_13672126.exe: main.c grafo_listaadj.c
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f ep1_matriz_13672126 ep1_lista_13672126
