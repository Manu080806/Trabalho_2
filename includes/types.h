#ifndef TYPES_H
#define TYPES_H

#include <stddef.h>
#include <stdint.h> 

#define T_STR   100

// Define tipo string
typedef char string[T_STR];

//define o nome do time que está sendo cadastrado
typedef struct time_cadastrado{
    string nome;
}   time_cadastrado;

// Define data
typedef struct data {
    int dia;
    int mes;
    int ano;
} data;

//motivo pelo qual o jogador se encontra inativo
typedef struct jogador_inativo{
    char* estado;
    data dt;
    char* motivo;  
}   jogador_inativo;

// define o tipo dados de cadastro dos jogadores
typedef struct cad_jogadores {
    uint8_t codigo;
    char* nome_jogador;
    int idade_jogador ;
    float peso , altura ;
    char* posicao_jogador ;
    float valor_passe , valor_compra , salario ;
    jogador_inativo status ; // se o jogador está ativo ou inativo
} cad_jogadores_t ; 

// Define membro da lista dos jogadores cadastrados
typedef struct no_jogadores {
    cad_jogadores_t dados_jogador;
    struct no_jogadores *prox_jogador;
}   no_jogadores;

// Define tipo lista dos jogadores
typedef struct lista_jogadores {
    no_jogadores *ptrlist_jogadores;
    uint8_t nr_nos_jogadores;
}   lista_jogadores;

// define o tipo dados de cadastro dos jogos realizados
typedef struct cad_jogosRealizados {
    uint8_t codigo;
    char* timeAdversario;
    data dt_jogo;
    char* local_jogo;
    char* resultado;
    char* vencedor;
    //time escalado
    int qtd_substituicoes;
} cad_jogosRealizados_t ;

// Define membro da lista dos jogos realizados
typedef struct no_partidas {
    cad_jogosRealizados_t dados_partida;
    struct no_partidas *prox_partida;
}   no_partidas;

// Define tipo lista dos jogos realizados
typedef struct lista_partidas {
    no_partidas *ptrlist_partida;
    uint8_t nr_nos_partida;
}   lista_partidas;


#endif