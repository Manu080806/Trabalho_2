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
    no_jogadores * jogador , *aux_jog = NULL;
    no_partidas *partidas , *aux_ptd = NULL;
    float salario_min, salario_max;
    string nome_arq, nome_pessoa, funcao;
    char resposta;
    data data;
    int inicio , fim ;
    time_cadastrado time;

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
                            getchar();
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
                    string nome_timeadv;
                    float soma_vendaJogadores;
                    sub_menu = menu_relatorios();
                        switch (sub_menu)
                        {
                        case 1: //Relatório completo de jogadores
                            listar_jogadores(jogador);
                            break;

                        case 2://Relatório de jogadores por faixa de idade
                            faixa_idade(inicio , fim , jogador);
                            break;

                        case 3://Relatório de resultado das partidas
                            result_partidas(partidas);
                            break;

                        case 5://Relatório de confrontos com time adversário
                            confrontos(partidas , nome_timeadv); 
                            break;
                        case 6://Relatório de jogadores vendidos
                            jogadores_vendidos(jogador , soma_vendaJogadores);
                            break;
                        case 7://Relatório do valor do time em relação ao preço de venda dos jogadores
                            valor_doTime(jogador);
                            break;
                        case 8://Relatório de aproveitamento do time (jogos vencidos pelo total de jogos realizados)
                            aproveitamento(partidas , time);
                        
                            break;
                        }
                } while (sub_menu != 0);
                    
                    break;
                
                case 3:do  {
                    string nome , pos_atua , adversario;
                    sub_menu = menu_pesquisas();
                        switch (sub_menu)
                        {
                        case 1://Localizar jogador por nome
                            pesquisa_nome(nome, jogador);
                            break;

                        case 2://Localizar jogadores por posição em que atua
                            posicao_atua(pos_atua , jogador );
                            break;

                        case 3://Localizar jogos realizados pelo nome do time adversário
                            time_adversario(adversario , partidas);
                            break;

                        case 4://Localizar jogador com maior salário
                            maior_salario(jogador);
                            break;

                        case 5://Localizar jogadores por faixa salarial
                            faixa_salarial(salario_max , salario_min , jogador);
                            break;
                        }
                } while (sub_menu != 0);
                    
                    break;
                case 4:do  {
                    string nome_arq;
                    sub_menu = arquivos();
                        switch (sub_menu)
                        {
                        case 1://salvar lista jogadores em arquivo binário
                            salvar_jogadores_arqbin(nome_arq,jogador);
                            break;

                        case 2://salvar lista partidas em arquivo binário
                            salvar_partidas_arqbin(nome_arq, partidas);
                            break;

                        case 3://exportar lista jogadores para arquivo html
                            exportar_jogadores_html(nome_arq,jogador);
                            break;

                        case 4://exportar lista partidas para arquivo html
                            exportar_partidas_html(nome_arq, partidas);
                            break;

                        case 5://exportar lista jogadores para arquivo texto
                            exportar_jogadores_arq_txt(nome_arq,jogador);
                            break;

                        case 6://exportar lista partidas para arquivo texto
                            exportar_partidas_arq_txt(nome_arq, partidas);
                            break;

                        case 7://exportar lista jogadores para tabela
                            exportar_jogadores_arq_csv(nome_arq,jogador);
                            break;

                        case 8://exportar lista partidas para tabela
                            exportar_partidas_arq_csv(nome_arq, partidas);
                            break;
                        }
                } while (sub_menu != 0);
                    
                    break;
            
            }

    } while (opcao != 0);
    

    return 0;
}
