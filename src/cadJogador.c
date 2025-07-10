#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "../includes/cadJogador.h"
#include "../includes/types.h"
#include "../includes/tools.h"

//confere se a lista jogadores está vazia
bool is_list_jogadores_vazia(no_jogadores *ptr_lista_jog){
    if (ptr_lista_jog) return false;  // Lista não vazia
    
    return true; // Lista vazia
}
//inicializa a lista jogadores
void inicializa_lista_jogadores(lista_jogadores *lista_jog){
    lista_jog->ptrlist_jogadores = NULL;
    lista_jog->nr_nos_jogadores = 0;
}
//registra um novo jogador
no_jogadores *localizar_ultimo_jogador(no_jogadores *ptr_lista_jog){
    while (ptr_lista_jog->prox_jogador) {
        ptr_lista_jog = ptr_lista_jog->prox_jogador;
    }
    return ptr_lista_jog;
}
//registra um novo jogador
no_jogadores *novo_jogador()
{
    no_jogadores *novo = NULL;
    char aux[T_STR]; 

    // Aloca um novo registro na heap
    novo = (no_jogadores*)malloc(sizeof(no_jogadores));
    if (!novo) return NULL;

    // Código (provisório)
    novo->dados_jogador.codigo = 0;

    // Nome
    getchar();
    printf("Nome do jogador: ");
    fgets(aux, T_STR, stdin);
    retirar_enter(aux);
    strcpy(novo->dados_jogador.nome_jogador, aux);

    // Idade
    printf("Idade do jogador: ");
    scanf("%d", &novo->dados_jogador.idade_jogador);
    getchar();

    // Peso
    printf("Peso do jogador: ");
    scanf("%f",&novo->dados_jogador.peso);
    getchar();    

    // Altura
    printf("Altura do jogador: ");
    scanf("%f", &novo->dados_jogador.altura);
    getchar(); 

    // Posição que o jogador atua
    printf("Posicao que o jogador atua: ");
    fgets(aux, T_STR, stdin);
    retirar_enter(aux);
    strcpy(novo->dados_jogador.posicao_jogador, aux);

    // Valor de compra
    printf("Valor de compra do jogador: ");
    scanf("%f", &novo->dados_jogador.valor_compra);
    getchar();
    
    // Valor de passe do jogador
    printf("Valor de passe do jogador: ");
    scanf("%f", &novo->dados_jogador.valor_passe);
    getchar();

    // Salario
    printf("Salario: ");
    scanf("%f", &novo->dados_jogador.salario);
    getchar();

    //Se o jogador está ativo ou inativo
    printf("Estado do jogador: ");
    fgets(aux, T_STR, stdin);
    retirar_enter(aux);
    strcpy(novo->dados_jogador.status.estado, aux);
        if (strcmp( novo->dados_jogador.status.estado , "inativo") == 0) {
            //data da inativação
            printf("Data da inativacao: \n");
            printf("Dia:");
            scanf("%d", &novo->dados_jogador.status.dt.dia);
            getchar();
            printf("Mes:");
            scanf("%d", &novo->dados_jogador.status.dt.mes);
            getchar();
            printf("Ano:");
            scanf("%d", &novo->dados_jogador.status.dt.ano);
            getchar();
           
            //motivo da inativação
            printf("Motivo da inativacao: ");
            fgets(aux, T_STR, stdin);
            retirar_enter(aux);
            strcpy(novo->dados_jogador.status.motivo, aux);
    }

    // Inicializar o ponteiro proximo
    novo->prox_jogador = NULL;

    return novo;
}

//insere o jogador pelo inicio da lista
void insere_inicio_jogadores(no_jogadores *novo_jogador, lista_jogadores *lista_jog){
    if (!novo_jogador || !lista_jog) {
        printf("Jogador ou lista inválidos\n");
        return; 
    } 
    novo_jogador->dados_jogador.codigo = ++lista_jog->nr_nos_jogadores;

    if (is_list_jogadores_vazia(lista_jog->ptrlist_jogadores)) {
        lista_jog->ptrlist_jogadores = novo_jogador;
        novo_jogador->prox_jogador = NULL;
        return;
    }

    novo_jogador->prox_jogador = lista_jog->ptrlist_jogadores;
    lista_jog->ptrlist_jogadores = novo_jogador;
}
// insere o jogador pelo fim da lista
void insere_fim_jogadores(no_jogadores *novo_jogador, lista_jogadores *lista_jog){
    if (!novo_jogador || !lista_jog) {
        printf("Jogador ou lista inválidos\n");
        return; 
    } 

    // Atribui o código ao novo jogador e incrementa o contador de nós da lista
    novo_jogador->dados_jogador.codigo = ++lista_jog->nr_nos_jogadores;
    novo_jogador->prox_jogador = NULL;

    if (is_list_jogadores_vazia(lista_jog->ptrlist_jogadores)) {
        lista_jog->ptrlist_jogadores = novo_jogador;
    } else {
        no_jogadores *ultimo = localizar_ultimo_jogador(lista_jog->ptrlist_jogadores);
        ultimo->prox_jogador = novo_jogador;
    }
}
 