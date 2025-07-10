#ifndef RELATORIOS_H
#define RELATORIOS_H

#include "types.h"
#include "tools.h"


//Relatório completo de jogadores
void listar_jogadores(no_jogadores *ptr_lista_jog);
//Relatório de jogadores por faixa de idade
void faixa_idade(int inicio , int fim , no_jogadores *jogador);
//Relatório de resultado das partidas
void result_partidas(no_partidas *resultado);
//Relatório de confrontos com time adversário
void confrontos(no_partidas *ptr_atual , string nome_timeadv);
//Relatório de jogadores vendidos
void jogadores_vendidos(no_jogadores *ptr_lista_jog , float soma_vendaJogadores);
//Relatório do valor do time em relação ao preço de venda dos jogadores
void valor_doTime(no_jogadores *soma);
//Relatório de aproveitamento do time (jogos vencidos pelo total de jogos realizados)
void aproveitamento(no_partidas *ptr_lista_ptd , time_cadastrado time);

#endif