#include <stdio.h>
#include <stddef.h>
#include <string.h>

#include "./includes/arquivos.h"
#include "./includes/cadJogador.h"
#include "./includes/cadPartidas.h"
#include "./includes/menus.h"
#include "./includes/pesquisas.h"
#include "./includes/relatorios.h"
#include "./includes/tools.h"
#include "./includes/types.h"

int main(){

    uint8_t opcao, sub_menu;
    no_jogadores *aux_jog = NULL;
    no_partidas *aux_ptd = NULL;
    float salario_min, salario_max;
    string nome_arq, nome_pessoa, funcao;
    char resposta;
    data data;

    lista_jogadores lista_jogadores;
    lista_partidas lista_partidas;

    // Criar a lista
    inicializa_lista_jogadores(&lista_jogadores);
    inicializa_lista_partidas(&lista_partidas);

    // Carrega dados arquivo
    ler_jogadores_arqbin("dados_jogadores.bin", &lista_jogadores);
    ler_partidas_arqbin("dados_partidas.bin", &lista_partidas);

    //ordenar_em_ordem_alfabetica

    do{   
        opcao = menu_principal();
            switch (opcao)  {
                case 1: do  {
                    sub_menu = menu_cadastros();
                        switch (sub_menu)
                        {
                        case 1:
                            break;

                        case 2:
                            break;

                        case 3:
                            break;

                        case 4:
                            break;
                        }
                } while (sub_menu != 0);
                
                    break;

                case 2:do  {
                    sub_menu = menu_relatorios();
                        switch (sub_menu)
                        {
                        case 1:
                            break;

                        case 2:
                            break;

                        case 3:
                            break;

                        case 4:
                            break;
                        }
                } while (sub_menu != 0);
                    
                    break;
                
                case 3:do  {
                    sub_menu = menu_pesquisas();
                        switch (sub_menu)
                        {
                        case 1:
                            break;

                        case 2:
                            break;

                        case 3:
                            break;

                        case 4:
                            break;
                        }
                } while (sub_menu != 0);
                    
                    break;
                case 4:do  {
                    sub_menu = arquivos();
                        switch (sub_menu)
                        {
                        case 1:
                            break;

                        case 2:
                            break;

                        case 3:
                            break;

                        case 4:
                            break;
                        }
                } while (sub_menu != 0);
                    
                    break;
            
            }

    } while (opcao != 0);
    

    return 0;
}
