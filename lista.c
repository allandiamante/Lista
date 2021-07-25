#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    char info;
    int *prox;

} Tcliente;
typedef struct
{
    Tcliente elementos[100];
    int prim,dispo,n,aux;
} Tlista;


void criarlista(Tlista *lista)
{
    lista->n=0;//QUANTIDADE DE ELEMENTOS DA LISTA
    lista->dispo=1;//INDICE DISPONIVEL DO VETOR
    lista->prim=1;//INDICE DO PRIMEIRO ELEMENTO DA LISTA


}

void inserir(Tlista *lista, char c)
{
    if (lista->n==0)// NÃO TIVER ELEMENTO NA LISTA
    {
        lista->elementos[lista->dispo].info=c;
        lista->elementos[lista->prim].prox=-1;
        lista->n++;
        lista->dispo++;

    }
    lista->elementos[lista->dispo].info=c;
    lista->elementos[lista->aux].prox=lista->elementos[lista->dispo].info;
    lista->elementos[lista->dispo].prox=-1;
    lista->aux=lista->dispo;
    lista->n++;
    lista->dispo++;


}

void buscar(Tlista *lista, char c)
{
    int i =lista->prim;
        for (i;i!=-1;i=lista->elementos[i].prox){
            if (lista->elementos[i].info==c)
                return i;//POSIÇÃO DO ELEMENTO NA LISTA

        }



}

void acessar(Tlista *lista, int i)
{
    int x = lista->prim;
        for (i;i>0;i--){
                x=lista->elementos[x].prox;
        }
        return lista->elementos[x].info;// INFORMAÇÂO DO ELEMENTO DE INDICE DA LISTA PEDIDO



}

void excluir (Tlista *lista,char c){
    int antes,pos=lista->prim;
    while (pos!=lista->elementos[pos].info!=c){
        antes=pos;
        pos=lista->elementos[pos].prox;
        if(pos=-1)
            return -1;
        else{
            lista->elementos[antes].prox=lista->elementos[pos].prox;
            lista->elementos[pos].prox=lista->dispo;
            lista->dispo=pos;
            lista->n=(lista->n)-1;
        }
    }

}


void tamanho(Tlista *lista){
    return lista->n;

    }




void exibir(Tlista *lista){
	int i,x;

	if(lista->n==0){
		printf("\n\tErro: Lista vazia!");
		return;
	}
    x=lista->prim;
	for(i=0;i<=lista->n;i++) {

		printf("\nElemento[ %d ] - lista %d ", lista->elementos[x].info);
    x=lista->elementos[x].prox;
	}
}













void menu() {
	printf("ACADEMICO: ALLAN DIAMANTE - RA:105423\n\n");
	printf("\n##############################################");
	printf("\n#           MENU - Lista Ordenada            #");
	printf("\n#                                            #");
	printf("\n#	Digite a op\207\706o desejada              #");
	printf("\n#                                            #");
	printf("\n#	 1 = Inserir elemento                #");
	printf("\n#	 2 = Remover elemento                #");
	printf("\n#	 3 = Buscar elemento                 #");
	printf("\n#	 4 = Exibir lista                    #");
	printf("\n#	 5 = Sair                            #");
	printf("\n#                                            #");
	printf("\n##############################################");
	printf("\n\n");
}

main() {
	int opcao,valor;
	menu();
	do {
		opcao = getche()-'0';

		switch(opcao) {
			case 1:
				system ("cls");
				menu();
				printf("\nDigite o valor a ser inserido ");
				scanf("%d", &valor);
				insere(valor);
				printf("\n\nEscolha outra op\207\706o para continuar...\n\n");
				break;
			case 2:
				system ("cls");
				menu();
				printf("\nDigite o valor a ser removido ");
				scanf("%d", &valor);
				remover(valor);
				printf("\n\nEscolha outra op\207\706o para continuar...\n\n");
				break;
			case 3:
				system ("cls");
				menu();
				printf("\nDigite o valor a ser buscado");
				scanf("%d", &valor);
				buscar(valor);
				printf("\n\nEscolha outra op\207\706o para continuar...\n\n");
				break;
			case 4:
				system ("cls");
				menu();
				exibir();
				printf("\n\nEscolha outra op\207\706o para continuar...\n\n");
				break;
			case 5:
				system ("cls");
				printf("\n\n\t\tAt\202 logo !!\n\n\n\n\n\n\n\n\n\n");
				i=false;
				break;
		}
	}
	while(i==true);
	system ("pause");
}
