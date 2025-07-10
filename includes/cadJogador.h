#ifndef CADJOGADOR_H
#define CADJOGADOR_H

#include <stdbool.h>
#include "types.h"

//confere se a lista jogadores está vazia
bool is_list_jogadores_vazia(no_jogadores *ptr_lista_jog);
//inicializa a lista jogadores
void inicializa_lista_jogadores(lista_jogadores *lista_jog);
//localiza o ultimo jogador
no_jogadores *localizar_ultimo_jogador(no_jogadores *ptr_lista_jog);
//registra um novo jogador
no_jogadores *novo_jogador();
//insere o jogador pelo inicio da lista
void insere_inicio_jogadores(no_jogadores *novo_jogador, lista_jogadores *lista_jog);
// insere o jogador pelo fim da lista
void insere_fim_jogadores(no_jogadores *novo_jogador, lista_jogadores *lista_jog);
//exclui o jogador da lista
void excluir_registro_jogadores(no_jogadores *registro_jog, lista_jogadores *lista_jog);

//inativaçáo do jogador e motivo
void inativo(no_jogadores *registro_jog , data data , string motivo);

#endif