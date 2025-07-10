CC = gcc
TARGET = jogadores
SOURCE = ./src
INCLUDE = ./includes
OBJETOS = ./objs

all: obj
	$(CC) $(OBJETOS)/tools.o $(OBJETOS)/menus.o $(OBJETOS)/arquivos.o $(OBJETOS)/cadJogador.o $(OBJETOS)/cadPartidas.o $(OBJETOS)/relatorios.o $(OBJETOS)/pesquisas.o $(OBJETOS)/main.o -o $(TARGET)


obj:
	$(CC) -c $(SOURCE)/tools.c -o $(OBJETOS)/tools.o
	$(CC) -c $(SOURCE)/menus.c -o $(OBJETOS)/menus.o
	$(CC) -c $(SOURCE)/arquivos.c -o $(OBJETOS)/arquivos.o
	$(CC) -c $(SOURCE)/cadJogador.c -o $(OBJETOS)/cadJogador.o
	$(CC) -c $(SOURCE)/cadPartidas.c -o $(OBJETOS)/cadPartidas.o
	$(CC) -c $(SOURCE)/relatorios.c -o $(OBJETOS)/relatorios.o
	$(CC) -c $(SOURCE)/pesquisas.c -o $(OBJETOS)/pesquisas.o
	$(CC) -c main.c -o $(OBJETOS)/main.o


cls:
	rm $(TARGET)
	rm $(OBJETOS)/*.o