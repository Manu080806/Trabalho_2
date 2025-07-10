#include <stdio.h>
#include <stdint.h>
#include "../includes/menus.h"
#include "../includes/tools.h"

// funçao que mostra o menu principal
uint8_t menu_principal(){
    uint8_t opcao;

        limpar_tela();

        printf("   Menu Principal\n");
        printf("\n");
        printf("1. Cadastros\n");
        printf("2. Menu de relatorios\n");
        printf("3. Menu de pesquisas\n");
        printf("4. Tipos de exportacao de arquivos\n");
        printf("0. Sair do programa\n");
        printf("Qual a sua opcao? ");
        scanf("%hhi", &opcao);

        return opcao;
}
// função que mostra o menu de cadastro
uint8_t menu_cadastros(){
    uint8_t opc;

        printf("   Menu de casdastros \n");
        printf("\n");
        printf("1.cadastro jogadores pelo inicio\n");
        printf("2.cadastro jogadores pelo fim\n");
        printf("3.cadastro partidas pelo inicio\n");
        printf("4cadastro partidas pelo fim.\n");
        printf("0.Voltar ao menu principal\n");
        printf("Qual a sua opcao? ");
        scanf("%hhi", &opc);

        limpar_tela();

        return opc;
}
// função que mostra o menu de relatórios
uint8_t menu_relatorios(){
    uint8_t opc;

        printf("   Menu de relatorios\n");
        printf("\n");
        printf("1. Relatorios completo de jogadores\n");
        printf("2. Relatorios de jogadores por faixa de idade\n");
        printf("3. Relatorios de resultado das partidas\n");
        printf("4. Relatorios de confrontos com time adversario\n");
        printf("5. Relatorios de jogadores vendidos\n");
        printf("6. Relatorios do valor do time em relacao ao preco de venda dos jogadores\n");
        printf("7. Relatorios de aproveitamento do time\n");
        printf("(jogos vencidos pelo total de jogos realizados)\n");
        printf("0.Voltar ao menu principal\n");
        printf("Qual a sua opcao? ");
        scanf("%hhi", &opc);

         limpar_tela();

        return opc;
}
// função que mostra o menu de pesquisas
uint8_t menu_pesquisas(){
    uint8_t opc;

        printf("   Menu de pesquisa\n");
        printf("\n");
        printf("1. Localizar jogadores por nome\n");
        printf("2. Localizar jogadores por posicao em que atua\n");
        printf("3. Localizar jogos realizados pelo nome do time adversario\n");
        printf("4. Localizar jogador com maior salario\n");
        printf("5. Localizar jogadores por faixa salarial\n");
        printf("0.Voltar ao menu principal\n");
        printf("Qual a sua opcao? ");
        scanf("%hhi", &opc);

        limpar_tela();

        return opc;
}
// função que mostra as opções de exportação 
uint8_t arquivos(){
    uint8_t opc;

        printf("  Menu opcoes de exportacao de arquivos\n");
        printf("\n");
        printf("1. Salvar lista jogadores em arquivo texto (.txt) \n");
        printf("2. Salvar lista de partidas em arquivo texto (.txt)\n");
        printf("3. Salvar lista jogadores em arquivo texto (.csv) \n");
        printf("4. Salvar lista de partidas em arquivo texto (.csv)\n");
        printf("5. Salvar lista jogadores em arquivo HTML \n");
        printf("6. Salvar lista de partidas em arquivo HTML\n");
        printf("0.Voltar ao menu principal\n");
        printf("Qual a sua opcao? ");
        scanf("%hhi", &opc);

        limpar_tela();

        return opc;
}
