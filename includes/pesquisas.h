#ifndef PESQUISAS_H
#define PESQUISAS_H

#include "types.h"


//Localizar jogador por nome
no_jogadores pesquisa_nome(string nome, no_jogadores *lista_jogadores);
//Localizar jogadores por posição em que atua
no_jogadores posicao_atua(string pos_atua , no_jogadores *lista_jogadores );
//Localizar jogos realizados pelo nome do time adversário
no_partidas time_adversario(string adversario , no_partidas *lista_partidas);
//Localizar jogador com maior salário
no_jogadores maior_salario(no_jogadores *lista_jogadores);
//Localizar jogadores por faixa salarial
no_jogadores faixa_salarial(float maior , float menor , no_jogadores *lista_jogadores);


#endif