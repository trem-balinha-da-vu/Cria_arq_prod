#include <stdlib.h>
#include <stdio.h>
#include "interface.h"

void menu(char opcoes[][200], int quant){
    for(int i = 0; i < quant; i++){
        printf("\n\t\t\t\t%d - %s\n", i+1, opcoes[i]);
    }
    printf("\n\tDIGITE A OPCAO: ");
}

void limpaTela(){
    system("clear || cls");
}

void titulo(char titulos[]){
    printf("\n\n\t *************************** %s *************************** \n\n", titulos);
}
