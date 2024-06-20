#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produtos.h"

void obtem_produto(Produto *produtos, int *qtde)
{
    char cont = 's';
    while (cont=='s')
    {
        printf("Digite o codigo do produto: ");
        scanf("%d", &produtos[*qtde].codigo_produto);
        fflush(stdin);

        printf("Digite o nome do produto: ");
        gets(produtos[*qtde].nome_produto);
        fflush(stdin);

        printf("Digite o preco do produto: ");
        scanf("%f", &produtos[*qtde].preco_produto);
        fflush(stdin);


        *qtde = *qtde+1;
        printf("Deseja inserir mais um produto <s/n>? ");
        scanf("%c", &cont);
        fflush(stdin);
    }
}

void salva_produto(Produto *produtos, int qtde)
{
    FILE *fp;
    char nomearq[20] = "Produtos.dat";

    fp = fopen(nomearq, "ab");

    if (!fp) {
        fp = fopen(nomearq, "wb");
        if (!fp) {
            printf("FILE ERROR!!! Arquivo %s nao gravado\n", nomearq);
            return;
        }
    }

    fwrite(produtos, sizeof(Produto), qtde, fp);
    fclose(fp);
}

void mostra_produto(Produto *produtos, int qtde)
{
    int i;

    for(i=0; i<qtde; i++)
    {
        printf("\n%d\t\t%s\t\t%.2f", produtos[i].codigo_produto, produtos[i].nome_produto, produtos[i].preco_produto);
    }

    printf("\n");
}

void mostra_produtos()
{
    FILE *fp;
    char nomearq[20] = "Produtos.dat";
    Produto produto;

    fp = fopen(nomearq, "rb");

    if (!fp) {
        printf("FILE ERROR!!! Arquivo %s nao encontrado\n", nomearq);
        return;
    }

    printf("\nCodigo\t\tNome\t\tPreco\n");

    while (fread(&produto, sizeof(Produto), 1, fp)) {
        printf("%d\t\t%s\t\t%.2f\n", produto.codigo_produto, produto.nome_produto, produto.preco_produto);
    }

    printf("\n");

    fclose(fp);
}
