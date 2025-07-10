#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../includes/types.h"
#include "../includes/tools.h"
#include "../includes/relatorios.h"

//Relatório completo de jogadores
void listar_jogadores(no_jogadores *ptr_lista_jog){

    //laço responsável por percorrer a lista encadeada
    while (ptr_lista_jog) {
        mostrar_dados_jogadores(ptr_lista_jog);
        ptr_lista_jog = ptr_lista_jog->prox_jogador;
        printf("\n");
    }
}
//Relatório de jogadores por faixa de idade
void faixa_idade(int inicio , int fim , no_jogadores *jogador){
    no_jogadores *ptr_atual = jogador;
    int i = 0;

    printf("Jogadores com idade entre %d e %.d: \n\n", inicio, fim);

    //percorrer a lista
    while(ptr_atual)
    {   //verificar se a idade esta dentro da faixa
        if (ptr_atual->dados_jogador.idade_jogador >= inicio && ptr_atual->dados_jogador.idade_jogador <= fim)
        {
            mostrar_dados_jogadores(ptr_atual);
            printf("\n");
            i++;
        }
        ptr_atual = ptr_atual->prox_jogador;
    }

    if (i<1) printf("Nenhum jogador encontrado dentro desta faixa de idade\n"); 
}
//Relatório de resultado das partidas
void result_partidas(no_partidas *resultado){

    //laço responsável por percorrer a lista encadeada
    while (resultado) {
        mostrar_dados_partidas(resultado);
        resultado = resultado->prox_partida;
        printf("\n");
    }
}
//Relatório de confrontos com time adversário
void confrontos(no_partidas *confrontos , string nome_timeadv){
    no_partidas *ptr_atual = confrontos ;
    int i = 0;

    printf("Todos os jogos contra o time: %s\n\n", nome_timeadv);

    //percorrer a lista
    while(ptr_atual)
    {   //verifica todos os jogos com aquele time adversário
        if (strcmp( ptr_atual->dados_partida.timeAdversario , nome_timeadv) == 0)
        {
            mostrar_dados_partidas(ptr_atual);
            printf("\n");
            i++;
        }
        ptr_atual = ptr_atual->prox_partida;
    }

    if (i<1) printf("Nenhum jogo contra o time %s foi encontrado\n", nome_timeadv); 

}
//Relatório de jogadores vendidos
void jogadores_vendidos(no_jogadores *ptr_lista_jog , float soma_vendaJogadores){
    soma_vendaJogadores = 0;

    while(ptr_lista_jog){
        if (strcmp(ptr_lista_jog->dados_jogador.status.estado , "inativo") == 0) {
                if (strcmp(ptr_lista_jog->dados_jogador.status.motivo , "vendido") == 0) {
                    printf("Nome do jogador: %s\n", ptr_lista_jog->dados_jogador.nome_jogador);
                    printf("Valor do passe para venda do jogador: %.2f\n", ptr_lista_jog->dados_jogador.valor_passe);
                    soma_vendaJogadores += ptr_lista_jog->dados_jogador.valor_passe;
                    }
            }
        ptr_lista_jog = ptr_lista_jog->prox_jogador;
    }
        printf("\n");
        printf("Valor total dos jogadores vendidos: %.2f\n", soma_vendaJogadores);
}
//Relatório do valor do time em relação ao preço de venda dos jogadores
void valor_doTime(no_jogadores *ptr_lista_jog){
    float soma = 0 , soma_vendidos = 0;
    
    while (ptr_lista_jog){
        soma += ptr_lista_jog->dados_jogador.valor_passe;
    }
    jogadores_vendidos(ptr_lista_jog , soma_vendidos); 
    soma_vendidos = soma - soma_vendidos;
    
    printf("Valor do time em relação ao preço de venda dos todos jogadores que estão cadastrados: %.2f\n", soma);
    printf("\n");
    printf("Valor do time em relação ao preço de venda dos todos jogadores que não foram vendidos: %.2f\n", soma_vendidos);
    printf("\n");

}
//Relatório de aproveitamento do time (jogos vencidos pelo total de jogos realizados)
void aproveitamento(no_partidas *ptr_lista_ptd , time_cadastrado time){
    int qtd_vitorias = 0 , aproveitamento = 0 , total_ptds;

    total_ptds = qtd_partidas(ptr_lista_ptd);
        
    while (ptr_lista_ptd){
        if(strcmp(ptr_lista_ptd->dados_partida.vencedor , time.nome ) == 0) qtd_vitorias++;
            ptr_lista_ptd = ptr_lista_ptd->prox_partida;
        }
           printf("%d\n",qtd_vitorias);
            aproveitamento = (qtd_vitorias / total_ptds);
                        printf("%.2f\n", aproveitamento);
                        printf("\n"); 
}
 