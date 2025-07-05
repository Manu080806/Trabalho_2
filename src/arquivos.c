#include <stdio.h>
#include <stdlib.h>
#include "../includes/arquivos.h"
#include "../includes/types.h"
#include "../includes/cadJogador.h"
#include "../includes/cadPartidas.h"

//salvar lista jogadores em arquivo binário
void salvar_jogadores_arqbin(string nome_arq, no_jogadores *ptr_lista_jog){
    // Abre arquivo
    FILE *fp = fopen(nome_arq, "wb");

    // Verifica se o arquivo foi aberto
    if (!fp) {
        printf("Erro ao tentar abrir o arquivo %s\n", nome_arq);
        return;
    }

    // Salvar dados para o arquivo binário
    while (ptr_lista_jog) {
        fwrite(ptr_lista_jog, sizeof(no_jogadores), 1, fp);
        ptr_lista_jog = ptr_lista_jog->prox_jogador;
    }

    // Fechar o arquivo
    fclose(fp);
}
//salvar lista partidas em arquivo binário
void salvar_partidas_arqbin(string nome_arq, no_partidas *ptr_lista_ptd){
    // Abre arquivo
    FILE *fp = fopen(nome_arq, "wb");

    // Verifica se o arquivo foi aberto
    if (!fp) {
        printf("Erro ao tentar abrir o arquivo %s\n", nome_arq);
        return;
    }

    // Salvar dados para o arquivo binário
    while (ptr_lista_ptd) {
        fwrite(ptr_lista_ptd, sizeof(no_partidas), 1, fp);
        ptr_lista_ptd = ptr_lista_ptd->prox_partida;
    }

    // Fechar o arquivo
    fclose(fp);
}

//ler arquivo binário jogadores
void ler_jogadores_arqbin(string nome_arq, lista_jogadores *lista_jog){
    // Abre arquivo
    FILE *fp = fopen(nome_arq, "rb");

     // Verifica se o arquivo foi aberto
    if(!fp) {
        printf("Falha ao abrir o arquivo!\n");
        return;
    }

    // lê os dados salvos no arquivo binário
    while(!feof(fp)) {
        no_jogadores *aux = (no_jogadores*)malloc(sizeof(no_jogadores));
        fread(aux, sizeof(no_jogadores), 1, fp);
        if (!feof(fp)) { 
            aux->prox_jogador = NULL;
            insere_inicio_jogadores(aux, lista_jog);
        }
        else {
            free(aux);
        }
    }

    // Fechar o arquivo
    fclose(fp);
}
//ler arquivo binário partidas
void ler_partidas_arqbin(string nome_arq, lista_partidas *lista_ptd){
    // Abre arquivo
    FILE *fp = fopen(nome_arq, "rb");

     // Verifica se o arquivo foi aberto
    if(!fp) {
        printf("Falha ao abrir o arquivo!\n");
        return;
    }

    // lê os dados salvos no arquivo binário
    while(!feof(fp)) {
        no_partidas *aux = (no_partidas*)malloc(sizeof(no_partidas));
        fread(aux, sizeof(no_partidas), 1, fp);
        if (!feof(fp)) { 
            aux->prox_partida = NULL;
            insere_inicio_jogadores(aux, lista_ptd);
        }
        else {
            free(aux);
        }
    }

    // Fechar o arquivo
    fclose(fp);
}

//exportar lista jogadores para arquivo html
void exportar_jogadores_html(string nome_arq, no_jogadores *lista_jog){
    //abre o arquivo 
    FILE *fp = fopen(nome_arq , "w");

    // Verifica se o arquivo foi aberto
    if(!fp){
        printf("Erro ao tentar abrir o arquivo");
        return;
    }

    //salva os arquivos em HTML
    fprintf(fp , "<html> <body> <table> <tr> <td><h1> Código </h1></td> <td><h1> Nome do jogador </h1></td> <td><h1> Idade do jogador </h1></td> <td><h1> Peso do jogador </h1></td> <td><h1> Altura do jogador </h1></td> <td><h1> Posição em que atua </h1></td> <td><h1> Valor de compra do jogador </h1></td> <td><h1> Valor de passe do jogador </h1></td> <td><h1> Salário do jogador </h1></td> <td><h1> Status do Jogador </h1></td> <td><h1> Data da Inativação </h1></td> <td><h1> Motivo da inativação </h1></td> </tr>\n");
    while(lista_jog){
        fprintf(fp , "<tr> <td>%hhi</td> <td>%s</td> <td>%d</td> <td>%f</td> <td>%f</td> <td>%s</td> <td>%.2f</td> <td>%.2f</td> <td>%.2f</td> <td>%s</td> <td>%d/%d/%d</td> <td>$s</td> </tr>\n", lista_jog->dados_jogador.codigo , lista_jog->dados_jogador.idade_jogador , lista_jog->dados_jogador.peso , lista_jog->dados_jogador.altura , lista_jog->dados_jogador.posicao_jogador , lista_jog->dados_jogador.valor_compra , lista_jog->dados_jogador.valor_passe , lista_jog->dados_jogador.salario , lista_jog->dados_jogador.status.estado , lista_jog->dados_jogador.status.dt , lista_jog->dados_jogador.status.motivo);
        lista_jog = lista_jog->prox_jogador;
    }
    fprintf(fp , "</table> </body> </html>");

    //fecha o arquivo
    fclose(fp);
}
//exportar lista partidas para arquivo html
void exportar_partidas_html(string nome_arq, no_partidas *lista_ptd){
    //abre o arquivo 
    FILE *fp = fopen(nome_arq , "w");

    // Verifica se o arquivo foi aberto
    if(!fp){
        printf("Erro ao tentar abrir o arquivo");
        return;
    }

    //salva os arquivos em HTML
    fprintf(fp , "<html> <body> <table> <tr> <td><h1> Código </h1></td> <td><h1> Nome do time adversário </h1></td> <td><h1> Data do jogo </h1></td> <td><h1> Local do jogo </h1></td> <td><h1> Resultado do jogo </h1></td> <td><h1> Vencedor da partida </h1></td> <td><h1> Time escalado </h1></td> <td><h1> Quantidade de substituições que ocorreram </h1></td> </tr>\n");
    while(lista_ptd){
        fprintf(fp , "<tr> <td>%d</td> <td>%s</td> <td>%d/%d/%d</td> <td>%s</td> <td>%s</td> <td>%s</td> <td>%s</td> <td>%d</td> </tr>\n", lista_ptd->dados_partida.codigo , lista_ptd->dados_partida.timeAdversario , lista_ptd->dados_partida.dt_jogo , lista_ptd->dados_partida.local_jogo , lista_ptd->dados_partida.resultado , lista_ptd->dados_partida.vencedor , lista_ptd->dados_partida , lista_ptd->dados_partida.qtd_substituicoes);
        lista_ptd = lista_ptd->prox_partida;

    }
    fprintf(fp , "</table> </body> </html>");

    //fecha o arquivo
    fclose(fp);

}

//exportar lista jogadores para arquivo texto
void exportar_jogadores_arq_txt(string nome_arq, no_jogadores *lista_jog){
    //abri o arquivo
    FILE *fp = fopen(nome_arq, "w");

    //verifica se abriu o arquivo
    if (fp == NULL){
        printf("erro ao abrir o arquivo %s\n", nome_arq);
        return;
    }

    while(lista_jog) {
        fprintf(fp, "Codigo: %hhi\n", lista_jog->dados_jogador.codigo);
        fprintf(fp, "Nome do Jogador: %s\n", lista_jog->dados_jogador.nome_jogador);
        fprintf(fp, "Idade: %d\n", lista_jog->dados_jogador.idade_jogador);
        fprintf(fp, "Peso: %f\n", lista_jog->dados_jogador.peso);
        fprintf(fp, "Altura: %f\n", lista_jog->dados_jogador.altura);
        fprintf(fp, "Posição que atua: %s\n", lista_jog->dados_jogador.posicao_jogador);
        fprintf(fp, "Valor de compra: %.2f\n", lista_jog->dados_jogador.valor_compra);
        fprintf(fp, "Valor de passe:%.2f\n", lista_jog->dados_jogador.valor_passe);
        fprintf(fp, "Salário: %.2f\n", lista_jog->dados_jogador.salario);
        fprintf(fp, "Status do jogador: %d\n", lista_jog->dados_jogador.status.estado);
        if (lista_jog->dados_jogador.status.estado == "inativo") {
            fprintf(fp, "Data da inativação: %d/%d/%d\n", lista_jog->dados_jogador.status.dt.dia, lista_jog->dados_jogador.status.dt.mes, lista_jog->dados_jogador.status.dt.ano);
            fprintf(fp,"Motivo da inativação: %s\n" , lista_jog->dados_jogador.status.motivo);
        }

        fprintf(fp, "\n");
        
        
        lista_jog = lista_jog->prox_jogador;
    }

    //fecha o arquivo
    fclose(fp); 
}
//exportar lista partidas para arquivo texto
void exportar_partidas_arq_txt(string nome_arq, no_partidas *lista_ptd){
    //abri o arquivo
    FILE *fp = fopen(nome_arq, "w");

    //verifica se abriu o arquivo
    if (fp == NULL){
        printf("erro ao abrir o arquivo %s\n", nome_arq);
        return;
    }

    while(lista_ptd) {
        fprintf(fp, "Codigo: %hhi\n", lista_ptd->dados_partida.codigo);
        fprintf(fp, "Nome do Time adversário: %s\n", lista_ptd->dados_partida.timeAdversario);
        fprintf(fp, "Data do jogo:%d/%d/%d\n", lista_ptd->dados_partida.dt_jogo.dia,lista_ptd->dados_partida.dt_jogo.mes , lista_ptd->dados_partida.dt_jogo.ano);
        fprintf(fp, "Local do jogo: %s\n", lista_ptd->dados_partida.local_jogo);
        fprintf(fp, "Resultado do jogo: %s\n", lista_ptd->dados_partida.resultado);
        fprintf(fp, "Time vencedor: %s\n", lista_ptd->dados_partida.vencedor);
        //fprintf(fp, "Time escalado: %.\n", lista_ptd->dados_partida.);
        fprintf(fp, "Valor de passe:%.d\n", lista_ptd->dados_partida.qtd_substituicoes);

        fprintf(fp, "\n");
        
        lista_ptd = lista_ptd->prox_partida;
    }

    //fecha o arquivo
    fclose(fp); 
}

//exportar lista jogadores para tabela
void exportar_jogadores_arq_csv(string nome_arq, no_jogadores *lista_jog){
    //abri o arquivo
    FILE *fp = fopen(nome_arq, "w");

    //verifica se abriu o arquivo
    if (fp == NULL){
        printf("erro ao abrir o arquivo %s\n", nome_arq);
        return;
    }
    
    fprintf(fp, "Código;Nome do jogador;Idade;Peso;Altura;Posição que atua;Valor de compra;Valor de passe;Salário;Estado;\n");

    while(lista_jog) {
        fprintf(fp, "%hhi;", lista_jog->dados_jogador.codigo);
        fprintf(fp, "%s;", lista_jog->dados_jogador.nome_jogador);
        fprintf(fp, "%d;", lista_jog->dados_jogador.idade_jogador);
        fprintf(fp, "%f;", lista_jog->dados_jogador.peso);
        fprintf(fp, "%f;", lista_jog->dados_jogador.altura);
        fprintf(fp, "%s;", lista_jog->dados_jogador.posicao_jogador);
        fprintf(fp, "%.2f;", lista_jog->dados_jogador.valor_compra);
        fprintf(fp, "%.2f;", lista_jog->dados_jogador.valor_passe);
        fprintf(fp, "%.2f;", lista_jog->dados_jogador.salario);
        fprintf(fp, "Status do jogador: %d;", lista_jog->dados_jogador.status.estado);
        fprintf(fp, "Status do jogador: %d;", lista_jog->dados_jogador.status.estado);
        if (lista_jog->dados_jogador.status.estado == "inativo") {
            fprintf(fp, "Data da inativação: %d/%d/%d;", lista_jog->dados_jogador.status.dt.dia, lista_jog->dados_jogador.status.dt.mes, lista_jog->dados_jogador.status.dt.ano);
            fprintf(fp,"Motivo da inativação: %s\n", lista_jog->dados_jogador.status.motivo);
        }
        printf("\n");
        
        lista_jog = lista_jog->prox_jogador;
    }    

    //fecha o arquivo
    fclose(fp); 
}
//exportar lista partidas para tabela
void exportar_partidas_arq_csv(string nome_arq, no_partidas *lista_ptd){
    //abri o arquivo
    FILE *fp = fopen(nome_arq, "w");

    //verifica se abriu o arquivo
    if (fp == NULL){
        printf("erro ao abrir o arquivo %s\n", nome_arq);
        return;
    }
    
    fprintf(fp, "Código;Time adversário;data do jogo;Local do jogo;Resultado;Time vencedor; ;quantidade de substituições\n");

    while(lista_ptd) {
        fprintf(fp, "%hhi;", lista_ptd->dados_partida.codigo);
        fprintf(fp, "%s;", lista_ptd->dados_partida.timeAdversario);
        fprintf(fp, "%d/%d/%d;", lista_ptd->dados_partida.dt_jogo.dia, lista_ptd->dados_partida.dt_jogo.mes, lista_ptd->dados_partida.dt_jogo.ano);
        fprintf(fp, "%s;", lista_ptd->dados_partida.local_jogo);
        fprintf(fp, "%s;", lista_ptd->dados_partida.resultado);
        fprintf(fp, "%s;", lista_ptd->dados_partida.vencedor);
        //time escalado
        fprintf(fp, "%d\n", lista_ptd->dados_partida.qtd_substituicoes);
        
        lista_ptd = lista_ptd->prox_partida;
    }    

    //fecha o arquivo
    fclose(fp); 
}