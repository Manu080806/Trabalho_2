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
    ler_jogadores_arqbin(&lista_jogadores);
    ler_partidas_arqbin(&lista_partidas);

    //ordenar_em_ordem_alfabetica 

    do{   
        printf("Qual time o sistema ira gerir? ");
        fgets(time.nome, T_STR, stdin);
        retirar_enter(time.nome);

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
                            aux_jog = novo_jogador();
                            insere_fim_jogadores(aux_jog  , &lista_jogadores);
                            break;

                        case 3:// cadastro partidas pelo início
                            aux_ptd = nova_partida();
                            insere_inicio_partidas(aux_ptd , &lista_partidas);
                            break;

                        case 4:// cadastro partidas pelo fim
                            aux_ptd = nova_partida();
                            insere_fim_partidas(aux_ptd , &lista_partidas);
                            break;
                        }
                    } while (sub_menu != 0);
                    break;

                case 2: do  {
                    string nome_timeadv;
                    float soma_vendaJogadores;
                    sub_menu = menu_relatorios();
                        switch (sub_menu)
                        {
                        case 1: //Relatório completo de jogadores
                            listar_jogadores(lista_jogadores.ptrlist_jogadores);
                            break;

                        case 2://Relatório de jogadores por faixa de idade
                            printf("Qual a idade inicial da faixa desejada? ");
                            scanf("%d", &inicio);
                            printf("Qual a idade final da faixa desejada? ");
                            scanf("%d", &fim);
                            faixa_idade(inicio , fim , lista_jogadores.ptrlist_jogadores);
                            break;

                        case 3://Relatório de resultado das partidas
                            result_partidas(lista_partidas.ptrlist_partida);
                            break;

                        case 4://Relatório de confrontos com time adversário
                            getchar();
                            printf("Contra qual time sao as partidas que desejas? ");
                            fgets(nome_timeadv, T_STR, stdin);
                            retirar_enter(nome_timeadv);
                            confrontos(lista_partidas.ptrlist_partida , nome_timeadv); 
                            break;

                        case 5://Relatório de jogadores vendidos
                            jogadores_vendidos(lista_jogadores.ptrlist_jogadores , soma_vendaJogadores);
                            break;

                        case 6://Relatório do valor do time em relação ao preço de venda dos jogadores
                            valor_doTime(lista_jogadores.ptrlist_jogadores);
                            break;

                        case 7://Relatório de aproveitamento do time (jogos vencidos pelo total de jogos realizados)
                            aproveitamento(lista_partidas.ptrlist_partida , time);
                            break;
                        }
                    } while (sub_menu != 0);
                    break;
                
                case 3:do  {
                    string nome , pos_atua , adversario;
                    float salario_min, salario_max;
                    sub_menu = menu_pesquisas();
                        switch (sub_menu)
                        {
                        case 1://Localizar jogador por nome
                            getchar();
                            printf("Qual o jogador que desejas localizar? ");
                            fgets(nome, T_STR, stdin);
                            retirar_enter(nome);
                            
                            *aux_jog = pesquisa_nome(nome, lista_jogadores.ptrlist_jogadores);

                            if (aux_jog != NULL) {
                                mostrar_dados_jogadores(aux_jog);
                            } else {
                                printf("Nenhum jogador com o nome %s foi encontrado\n", nome);
                            }
                            break;

                        case 2://Localizar jogadores por posição em que atua
                            getchar();
                            printf("Qual a posicao que desejas pesquisar? ");
                            fgets(pos_atua, T_STR, stdin);
                            retirar_enter(pos_atua);

                            *aux_jog = posicao_atua(pos_atua, lista_jogadores.ptrlist_jogadores);

                            if (aux_jog != NULL) {
                                printf("Codigo: %hhi\n" , aux_jog->dados_jogador.codigo);
                                printf("Nome: %s\n", aux_jog->dados_jogador.nome_jogador);
                                printf("Posicao que atua: %s\n" , aux_jog->dados_jogador.posicao_jogador);
                            } else {
                                printf("Nenhum jogador encontrado atuando na posicao %s\n", pos_atua);
                            }
                            break;

                        case 3://Localizar jogos realizados pelo nome do time adversário
                            getchar();
                            printf("Qual o time adversário? ");
                            fgets(adversario, T_STR, stdin);
                            retirar_enter(adversario);
                            time_adversario(adversario , lista_partidas.ptrlist_partida);
                            break;

                        case 4://Localizar jogador com maior salário
                            maior_salario(lista_jogadores.ptrlist_jogadores);
                            break;

                        case 5://Localizar jogadores por faixa salarial
                            printf("Qual o salario minimo da faixa desejada? ");
                            scanf("%d", &salario_min);
                            printf("Qual o salario maximo da faixa desejada? ");
                            scanf("%d", &salario_max);
                            faixa_salarial(salario_max , salario_min , lista_jogadores.ptrlist_jogadores);
                            break;
                        }
                    } while (sub_menu != 0);
                    break;

                case 4:do  {
                    string nome_arq;
                    sub_menu = arquivos();
                        switch (sub_menu)
                        {
                        case 1://exportar lista jogadores para arquivo texto
                            getchar();
                            printf("Digite o nome do arquivo e finalize com: .txt \n");
                            fgets(nome_arq, T_STR, stdin);
                            retirar_enter(nome_arq);
                            exportar_jogadores_arq_txt(nome_arq,lista_jogadores.ptrlist_jogadores);
                            break;

                        case 2://exportar lista partidas para arquivo texto
                            getchar();
                            printf("Digite o nome do arquivo e finalize com: .txt \n");
                            fgets(nome_arq, T_STR, stdin);
                            retirar_enter(nome_arq);
                            exportar_partidas_arq_txt(nome_arq, lista_partidas.ptrlist_partida);
                            break;

                        case 3://exportar lista jogadores para tabela
                            getchar();
                            printf("Digite o nome do arquivo e finalize com: .csv \n");
                            fgets(nome_arq, T_STR, stdin);
                            retirar_enter(nome_arq);
                            exportar_jogadores_arq_csv(nome_arq,lista_jogadores.ptrlist_jogadores);
                            break;

                        case 4://exportar lista partidas para tabela
                            getchar();
                            printf("Digite o nome do arquivo e finalize com: .csv \n");
                            fgets(nome_arq, T_STR, stdin);
                            retirar_enter(nome_arq);
                            exportar_partidas_arq_csv(nome_arq, lista_partidas.ptrlist_partida);
                            break;

                        case 5://exportar lista jogadores para arquivo html
                            getchar();
                            printf("Digite o nome do arquivo e finalize com: .html \n");
                            fgets(nome_arq, T_STR, stdin);
                            retirar_enter(nome_arq);
                            exportar_jogadores_html(nome_arq,lista_jogadores.ptrlist_jogadores);
                            break;

                        case 6://exportar lista partidas para arquivo html
                            getchar();
                            printf("Digite o nome do arquivo e finalize com: .html \n");
                            fgets(nome_arq, T_STR, stdin);
                            retirar_enter(nome_arq);
                            exportar_partidas_html(nome_arq, lista_partidas.ptrlist_partida);
                            break;
                        }
                    
                    } while (sub_menu != 0);
                    break;

                case 0:
                    //salvar lista jogadores em arquivo binário
                    salvar_jogadores_arqbin(lista_jogadores.ptrlist_jogadores);
                    //salvar lista partidas em arquivo binário
                    salvar_partidas_arqbin( lista_partidas.ptrlist_partida);
            }
    } while (opcao != 0);
    

    return 0;
}
