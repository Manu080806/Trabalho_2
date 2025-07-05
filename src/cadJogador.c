#include <stdio.h>
#include <stdbool.h>
#include "../includes/cadJogador.h"
#include "../includes/types.h"

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
    no_jogadores *novo;

    // Aloca um novo registro na heap
    novo = (no_jogadores*)malloc(sizeof(no_jogadores));

    if (!novo) return NULL;

    // Código (provisório)
    novo->dados_jogador.codigo = 0;

    // Nome
    printf("Nome do jogador: ");
    fgets(novo->dados_jogador.nome_jogador, T_STR, stdin);
    retirar_enter(novo->dados_jogador.nome_jogador);

    // Idade
    printf("Idade do jogador: ");
    scanf("%d", &novo->dados_jogador.idade_jogador);

    // Peso
    printf("Peso do jogador: ");
    scanf("%f",novo->dados_jogador.peso);    

    // Altura
    printf("Altura do jogador: ");
    scanf("%f", &novo->dados_jogador.altura); 

    // Posição que o jogador atua
    printf("Posição que o jogador atua: ");
    fgets(novo->dados_jogador.posicao_jogador, T_STR, stdin);
    retirar_enter(novo->dados_jogador.posicao_jogador);

    // Valor de compra
    printf("Valor de compra do jogador: ");
    scanf("%2.f", &novo->dados_jogador.valor_compra);
    
    // Valor de passe do jogador
    printf("Valor de passe do jogador: ");
    scanf("%2.f", &novo->dados_jogador.valor_passe);

    // Salario
    printf("Salario: ");
    scanf("%2.f", &novo->dados_jogador.salario);

    //Se o jogador está ativo ou inativo
    printf("Estado do jogador: ");
    fgets(novo->dados_jogador.status.estado, T_STR, stdin);
    retirar_enter(novo->dados_jogador.status.estado);
        if (strcmmp( novo->dados_jogador.status.estado , inativo) == 0) {
            //data da inativação
            printf("Data da inativação: %d/%d/%d;", novo->dados_jogador.status.dt.dia, novo->dados_jogador.status.dt.mes, novo->dados_jogador.status.dt.ano);
            scanf("%d/%d/%d", &novo->dados_jogador.status.dt.dia, &novo->dados_jogador.status.dt.mes, &novo->dados_jogador.status.dt.ano);

            //motivo da inativação
            printf("Motivo da inativação: %s\n", novo->dados_jogador.status.motivo);
            fgets(novo->dados_jogador.status.motivo, T_STR, stdin);
            retirar_enter(novo->dados_jogador.status.motivo);
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

