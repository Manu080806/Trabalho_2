#ifndef CADPARTIDAS_H
#define CADPARTIDAS_H

#include <stdbool.h>
#include "types.h"

// confere se a lista de partidas está vazia
bool is_list_partidas_vazia(no_partidas *ptr_lista_ptd);
//inicializa a lista de partidas
void inicializa_lista_partidas(lista_partidas *lista_ptd);
// localiza o último registro de partida
no_partidas *localizar_ultimo_partidas(no_partidas *ptr_lista_ptd);
// registra uma nova partida
no_partidas *nova_partida();
//insere a partida pelo inicio da lista
void insere_inicio_partidas(no_partidas *nova_partida, lista_partidas *lista_ptd);
//insere a partida pelo fim da lista
void insere_fim_partidas(no_partidas *nova_partida, lista_partidas *lista_ptd);
//exclui a partida da lista
void excluir_registro_partidas(no_partidas *registro_ptd, lista_partidas *lista_ptd);


#endif