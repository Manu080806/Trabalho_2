#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../includes/types.h"
#include "../includes/tools.h"
#include "../includes/pesquisas.h"

//Localizar jogador por nome
no_jogadores pesquisa_nome(string nome, no_jogadores *lista_jogadores){
    while (lista_jogadores) {

        if (strcmp(nome, lista_jogadores->dados_jogador.nome_jogador) == 0) {
            return *lista_jogadores;
        }
        
        lista_jogadores = lista_jogadores->prox_jogador;
    }

    return *lista_jogadores;
}
//Localizar jogadores por posição em que atua
no_jogadores *posicao_atua(string pos_atua , no_jogadores *lista_jogadores ){
    if (lista_jogadores == NULL){
        return NULL;
    }
    if (strcmp(pos_atua, lista_jogadores->dados_jogador.posicao_jogador) == 0){
        return lista_jogadores;
    }
    return posicao_atua(pos_atua, lista_jogadores->prox_jogador);
}
//Localizar jogos realizados pelo nome do time adversário
no_partidas time_adversario(string adversario , no_partidas *lista_partidas){
    int i = 0;

    limpar_tela();

    printf("Todos os jogos contra o time: %s\n\n", adversario);

    //percorrer a lista
    while(lista_partidas)
    {   //verifica todos os jogos com aquele time adversário
        if (strcmp( lista_partidas->dados_partida.timeAdversario , adversario) == 0)
        {
            mostrar_dados_partidas(lista_partidas);
            printf("\n");
            i++;
        }
        lista_partidas = lista_partidas->prox_partida;
    }

    if (i<1) printf("Nenhum jogo contra o time %s foi encontrado\n", adversario); 
}
//Localizar jogador com maior salário
no_jogadores maior_salario(no_jogadores *lista_jogadores){
    float MaiorSalario = 0 ;
    no_jogadores *posMaiorSalario;

    while (lista_jogadores){
        if (lista_jogadores->dados_jogador.salario > MaiorSalario){
            MaiorSalario = lista_jogadores->dados_jogador.salario ;
            posMaiorSalario = lista_jogadores;
        }
    }
    mostrar_dados_jogadores(posMaiorSalario);

}
//Localizar jogadores por faixa salarial
no_jogadores faixa_salarial(float maior , float menor , no_jogadores *lista_jogadores){
    int i = 0;

    limpar_tela();

    printf("Jogadores com salário entre R$ %d e R$ %.d: \n\n", maior, menor);

    //percorrer a lista
    while(lista_jogadores)
    {   //verificar se o salário esta dentro da faixa
        if (lista_jogadores->dados_jogador.idade_jogador >= menor && lista_jogadores->dados_jogador.idade_jogador <= maior)
        {
            mostrar_dados_jogadores(lista_jogadores);
            printf("\n");
            i++;
        }
        lista_jogadores = lista_jogadores->prox_jogador;
    }

    if (i<1) printf("Nenhum jogador encontrado dentro desta faixa salarial\n"); 
}
 