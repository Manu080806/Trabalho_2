#ifndef TOOLS_H
#define TOOLS_H

#include "types.h"


void retirar_enter(string str);
void limpar_tela();
void mostrar_dados_jogadores(no_jogadores *jogadores);
void mostrar_dados_partidas(no_partidas *partida);
int qtd_partidas(no_partidas *partidas);
void escalamento(no_jogadores *jogadores , string nome , time_escalado *escalado);

#endif