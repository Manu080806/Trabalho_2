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
                        case 1: // cadastro jogadores pelo início
                            aux_jog = novo_jogador();
                            insere_inicio_jogadores(aux_jog , &lista_jogadores);
                            break;

                        case 2: // cadastro jogadores pelo fim
                            break;

                        case 3:// cadastro partidas pelo início
                        aux_ptd = nova_partida();
                        insere_inicio_partidas(aux_ptd , &lista_partidas);
                            break;

                        case 4:// cadastro partidas pelo fim
                            break;
                        }
                } while (sub_menu != 0);
                
                    break;

                case 2:do  {
                    sub_menu = menu_relatorios();
                        switch (sub_menu)
                        {
                        case 1: //Relatório completo de jogadores
                            void listar_jogadores(no_jogadores *ptr_lista_jog);
                            break;

                        case 2://Relatório de jogadores por faixa de idade
                            void faixa_idade(int inicio , int fim , no_jogadores *jogador);
                            break;

                        case 3://Relatório de resultado das partidas
                            void result_partidas(no_partidas *resultado);
                            break;

                        case 5://Relatório de confrontos com time adversário
                            void confrontos(no_partidas *confrontos);
                            break;
                        case 6://Relatório de jogadores vendidos
                            void jogadores_vendidos(no_jogadores *ptr_lista_jog);
                            break;
                        case 7://Relatório do valor do time em relação ao preço de venda dos jogadores
                            void valor_doTime(no_jogadores *soma);
                            break;
                        case 8://Relatório de aproveitamento do time (jogos vencidos pelo total de jogos realizados)
                            void aproveitamento(no_partidas *jogos);
                        
                            break;
                        }
                } while (sub_menu != 0);
                    
                    break;
                
                case 3:do  {
                    sub_menu = menu_pesquisas();
                        switch (sub_menu)
                        {
                        case 1://Localizar jogador por nome
                            no_jogadores pesquisa_nome(string nome, no_jogadores *lista_jogadores);
                            break;

                        case 2://Localizar jogadores por posição em que atua
                            no_jogadores posicao_atua(string pos_atua , no_jogadores *lista_jogadores );
                            break;

                        case 3://Localizar jogos realizados pelo nome do time adversário
                            no_partidas time_adversario(string adversario , no_partidas *lista_partidas);
                            break;

                        case 4://Localizar jogador com maior salário
                            no_jogadores maior_salario(no_jogadores *lista_jogadores);
                            break;

                        case 5://Localizar jogadores por faixa salarial
                            no_jogadores faixa_salarial(float maior , float menor , no_jogadores *lista_jogadores);
                            break;
                        }
                } while (sub_menu != 0);
                    
                    break;
                case 4:do  {
                    sub_menu = arquivos();
                        switch (sub_menu)
                        {
                        case 1://salvar lista jogadores em arquivo binário
                            void salvar_jogadores_arqbin(string nome_arq, no_jogadores *ptr_lista_jog);
                            break;

                        case 2://salvar lista partidas em arquivo binário
                            void salvar_partidas_arqbin(string nome_arq, no_partidas *ptr_lista_ptd);
                            break;

                        case 3://exportar lista jogadores para arquivo html
                            void exportar_jogadores_html(string nome_arq, no_jogadores *lista_jog);
                            break;

                        case 4://exportar lista partidas para arquivo html
                            void exportar_partidas_html(string nome_arq, no_partidas *lista_ptd);
                            break;

                        case 5://exportar lista jogadores para arquivo texto
                            void exportar_jogadores_arq_txt(string nome_arq, no_jogadores *lista_jog);
                            break;

                        case 6://exportar lista partidas para arquivo texto
                            void exportar_partidas_arq_txt(string nome_arq, no_partidas *lista_ptd);
                            break;

                        case 7://exportar lista jogadores para tabela
                            void exportar_jogadores_arq_csv(string nome_arq, no_jogadores *lista_jog);
                            break;

                        case 8://exportar lista partidas para tabela
                            void exportar_partidas_arq_csv(string nome_arq, no_partidas *lista_ptd);
                            break;
                        }
                } while (sub_menu != 0);
                    
                    break;
            
            }

    } while (opcao != 0);
    

    return 0;
}
