#ifndef ARQUIVOS_H
#define ARQUIVOS_H

#include "types.h"

//salvar lista jogadores em arquivo binário
void salvar_jogadores_arqbin(no_jogadores *ptr_lista_jog);
//salvar lista partidas em arquivo binário
void salvar_partidas_arqbin(no_partidas *ptr_lista_ptd);

//ler arquivo binário jogadores
void ler_jogadores_arqbin(lista_jogadores *lista_jog);
//ler arquivo binário partidas
void ler_partidas_arqbin(lista_partidas *lista_ptd);

//exportar lista jogadores para arquivo html
void exportar_jogadores_html(string nome_arq, no_jogadores *lista_jog);
//exportar lista partidas para arquivo html
void exportar_partidas_html(string nome_arq, no_partidas *lista_ptd);

//exportar lista jogadores para arquivo texto
void exportar_jogadores_arq_txt(string nome_arq, no_jogadores *lista_jog);
//exportar lista partidas para arquivo texto
void exportar_partidas_arq_txt(string nome_arq, no_partidas *lista_ptd);

//exportar lista jogadores para tabela
void exportar_jogadores_arq_csv(string nome_arq, no_jogadores *lista_jog);
//exportar lista partidas para tabela
void exportar_partidas_arq_csv(string nome_arq, no_partidas *lista_ptd);


#endif