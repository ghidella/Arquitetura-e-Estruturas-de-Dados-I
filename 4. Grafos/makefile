CC = gcc
CFLAGS = -Wall -Wextra

libgrafo_matrizadj: grafo_matrizadj.o

grafo_matrizadj.o: grafo_matrizadj.c grafo_matrizadj.h
	$(CC) $(CFLAGS) -c grafo_matrizadj.c

clean:
	rm -f libgrafo_matrizadj *.o
