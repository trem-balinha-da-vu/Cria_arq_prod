#include <stdio.h>
#include <stdlib.h>
#include "produtos.h"
#include "interface.h"

/*
"Cria_arq_prod é um programa que salva em um arquivo binário chamado "Produtos.dat":
 - Codigo_Produto;
 - Nome_Produto;
 - Preço_Produto.

 dos produtos de um supermercado.
**/

int main()
{
    Produto produtos[50];
    int qtde = 0;
    char cont;

    titulo("PROGRAMA CRIA PRODUTOS");

    obtem_produto(produtos, &qtde);
    salva_produto(produtos, qtde);

    limpaTela();
    titulo("PRODUTO ADICIONADO");
    mostra_produto(produtos, qtde);
    printf("\n");

    printf("Deseja ver a lista completa de produtos <s/n>? ");
    scanf("%c", &cont);

    if(cont=='s')
    {
        titulo("LISTA COMPLETA DE PRODUTOS");
        mostra_produtos();
    }

    printf("\nFIM\n");
    return 0;
}
