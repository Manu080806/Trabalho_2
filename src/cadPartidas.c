#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "../includes/cadPartidas.h"
#include "../includes/types.h"
#include "../includes/tools.h"

// confere se a lista de partidas está vazia
bool is_list_partidas_vazia(no_partidas *ptr_lista_ptd){
    if (ptr_lista_ptd) return false;  // Lista não vazia
    
    return true; // Lista vazia
}
//inicializa a lista de partidas
void inicializa_lista_partidas(lista_partidas *lista_ptd){
    lista_ptd->ptrlist_partida = NULL;
    lista_ptd->nr_nos_partida = 0;
}
// localiza o último registro de partida
no_partidas *localizar_ultimo_partidas(no_partidas *ptr_lista_ptd){
    
    while (ptr_lista_ptd->prox_partida) {
        ptr_lista_ptd = ptr_lista_ptd->prox_partida;
    }
    return ptr_lista_ptd;
}
// registra uma nova partida
no_partidas *nova_partida()
{
    no_partidas *novo;

    // Aloca um novo registro na heap
    novo = (no_partidas*)malloc(sizeof(no_partidas));

    if (!novo) return NULL;

    // Código (provisório)
    novo->dados_partida.codigo = 0;

    // Nome do time adversário
    getchar();
    printf("Nome do time adversário: ");
    fgets(novo->dados_partida.timeAdversario, T_STR, stdin);
    retirar_enter(novo->dados_partida.timeAdversario);

    // Data da partida
    printf("Data da partida: %d/%d/%d;", novo->dados_partida.dt_jogo.dia, novo->dados_partida.dt_jogo.mes, novo->dados_partida.dt_jogo.ano);
    scanf("%d/%d/%d", &novo->dados_partida.dt_jogo.dia, &novo->dados_partida.dt_jogo.mes, &novo->dados_partida.dt_jogo.ano);

    // Local onde ocorreu a partida
    printf("Local que ocorreu a partida: ");
    getchar();
    fgets(novo->dados_partida.local_jogo, T_STR, stdin);
    retirar_enter(novo->dados_partida.local_jogo);

    // Resultado da partida
    printf("Resultado da partida: ");
    getchar();
    fgets(novo->dados_partida.resultado, T_STR, stdin);
    retirar_enter(novo->dados_partida.resultado);

    // Vencedor da partida
    printf("Vencedor da partida: ");
    getchar();
    fgets(novo->dados_partida.vencedor, T_STR, stdin);
    retirar_enter(novo->dados_partida.vencedor);

    // Time escalado

    // Vencedor da partida
    printf("Vencedor da partida: ");
    scanf("%d",novo->dados_partida.qtd_substituicoes);

    // Inicializar o ponteiro proximo
    novo->prox_partida = NULL;

    return novo;
}
//insere a partida pelo inicio da lista
void insere_inicio_partidas(no_partidas *nova_partida, lista_partidas *lista_ptd){
    if (!nova_partida || !lista_ptd) {
        printf("Partida ou lista inválidos\n");
        return; 
    }

    // Define o codigo
    nova_partida->dados_partida.codigo = ++lista_ptd->nr_nos_partida;

    if (is_list_partidas_vazia(lista_ptd->ptrlist_partida)) {
        lista_ptd->ptrlist_partida = nova_partida;
        nova_partida->prox_partida = NULL;
        return;
    }

    nova_partida->prox_partida = lista_ptd->ptrlist_partida;
    lista_ptd->ptrlist_partida = nova_partida;
}
//insere a partida pelo fim da lista
void insere_fim_partidas(no_partidas *nova_partida, lista_partidas *lista_ptd){
     if (!nova_partida || !lista_ptd) {
        printf("Partida ou lista inválidos\n");
        return; 
    }

    nova_partida->dados_partida.codigo = ++lista_ptd->nr_nos_partida;
    nova_partida->prox_partida = NULL;

    if(is_list_partidas_vazia(lista_ptd->ptrlist_partida)){
        lista_ptd->ptrlist_partida = nova_partida; 
    } else {
        no_partidas *ultimo = localizar_ultimo_partidas(lista_ptd->ptrlist_partida);
        ultimo->prox_partida = nova_partida;
    }
}
