#ifndef PRODUTOS_H_INCLUDED
#define PRODUTOS_H_INCLUDED

typedef struct TProduto {
    int codigo_produto;
    char nome_produto[50];
    float preco_produto;
}Produto;

void obtem_produto(Produto *produtos, int *qtde);

void salva_produto(Produto *produtos, int qtde);

void mostra_produto(Produto *produtos, int qtde);

void mostra_produtos();

#endif // PRODUTOS_H_INCLUDED
