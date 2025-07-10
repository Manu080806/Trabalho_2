#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "../includes/types.h"
#include "../includes/tools.h"

//funçao que retira o enter no final da string
void retirar_enter(string str){
    *(str+strlen(str)-1) = '\0';
}
// função que limpa a tela
void limpar_tela(){
    system("cls"); // mudar cls para clear ao usar no linux
}
//função que mostra os jogadores cadastrados
void mostrar_dados_jogadores(no_jogadores *jogadores){
    
    printf("Codigo : %hhi\n", jogadores->dados_jogador.codigo);
    printf("Nome do jogador : %s\n", jogadores->dados_jogador.nome_jogador);
    printf("Idade do Jogador : %d\n", jogadores->dados_jogador.idade_jogador);
    printf("Peso do jogador : %.1f\n", jogadores->dados_jogador.peso);
    printf("Altura do jogador : %.1f\n", jogadores->dados_jogador.altura);
    printf("Posicao do jogador : %s\n", jogadores->dados_jogador.posicao_jogador);
    printf("Valor de passe do jogador : %.2f\n", jogadores->dados_jogador.valor_passe);
    printf("Valor de compra do jogador : %.2f\n", jogadores->dados_jogador.valor_compra);
    printf("Salario: %.2f\n", jogadores->dados_jogador.salario);
    printf("Estado : %s\n", jogadores->dados_jogador.status.estado);
    if (strcmp( jogadores->dados_jogador.status.estado , "inativo") == 0) {
        printf("Data da inativacao : %d/%d/%d\n;", jogadores->dados_jogador.status.dt.dia, jogadores->dados_jogador.status.dt.mes, jogadores->dados_jogador.status.dt.ano);
        printf("Motivo da inativacao : %s\n", jogadores->dados_jogador.status.motivo);
    }
    
}
//função que mostra as partidas cadastradas
void mostrar_dados_partidas(no_partidas *partida){
    
    printf("Codigo : %hhi\n", partida->dados_partida.codigo);
    printf("Nome do  time adversario : %s\n", partida->dados_partida.timeAdversario);
    printf("Data da partida : %d/%d/%d\n", partida->dados_partida.dt_jogo.dia, partida->dados_partida.dt_jogo.mes, partida->dados_partida.dt_jogo.ano);
    printf("Local onde foi realizado o jogo : %s\n", partida->dados_partida.local_jogo);
    printf("Resultado do jogo : %s\n", partida->dados_partida.resultado);
    printf("Nome do time vencedor : %s\n", partida->dados_partida.vencedor);
    printf("Time escalado: \n"); 
    for(int i = 0 ; i < 11 ; i ++){
        printf("    Codigo: %hhi", partida->dados_partida.time_escalado[i].codigo); 
        printf("    Jogador: %s", partida->dados_partida.time_escalado[i].nome_jogador); 
        printf("    Posicao: %s", partida->dados_partida.time_escalado[i].posicao_jogador); 
        printf("\n");
    }
    printf("Quantidade de substituicoes : %d\n", partida->dados_partida.qtd_substituicoes);
    
}
//função que conta a quantidade de partidas
int qtd_partidas(no_partidas *partidas){
     int i = 0;
    while (partidas){
        i++;
        partidas = partidas->prox_partida;
    }
    return i;
}
//time escalado
void escalamento(no_jogadores *jogadores , string nome , time_escalado *escalado){

    escalado = (time_escalado*)malloc(sizeof(time_escalado));

    while (jogadores){
        if(strcmp(jogadores->dados_jogador.nome_jogador , nome) == 0){
            escalado->codigo = jogadores->dados_jogador.codigo;
            escalado->nome_jogador = (char*)malloc(strlen(jogadores->dados_jogador.nome_jogador) + 1);
            strcpy(escalado->nome_jogador , jogadores->dados_jogador.nome_jogador); 
            escalado->posicao_jogador = (char*)malloc(strlen(jogadores->dados_jogador.posicao_jogador) + 1);
            strcpy(escalado->posicao_jogador , jogadores->dados_jogador.posicao_jogador); 
        }
    }
}
