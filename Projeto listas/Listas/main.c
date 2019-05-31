#include <stdio.h>
#include <stdlib.h>
#include "listas.h"





void main(void)
{
    int ask = 1, numero, button, dados, exe;
    SLList *c;
    c = NULL;
    while (ask == 1)
    {
        button = Menu();

        switch(button)
        {


        case 1:
            if (c==NULL)
            {
                c = sllCreate();
                printf("\nCriado com sucesso\n");
            }
            else
            {
                printf("\nLista ja foi criada\n");
            }
            break;

        case 2:


            exe = sllDestroy(c);
            if(exe==1)
            {
                c = NULL;
                printf("\nLista destruida\n");
            }
            else
            {
                printf("\nRemova os elementos para poder destruir\n");
            }


            break;

        case 3:
            printf("\n Insira o dado da pessoa : \n");
            dados = RegistrarDados(c);
            if (dados==1)
            {
                printf("Dados inseridos \n");
            }

            break;

        case 4:
            opcaoProc(c);



            break;

        case 5:
            if(c!=NULL)
            {
                mostraTodos(c);
            }
            else
            {
                printf("\nLista nao existe");
            }


            break;

        case 6:
            opcaoRemove(c);


            break;
        }
        printf("Continuar: SIM [1] / NÃO [qualquer tecla] \n");
        scanf("%d", &ask);
    }
}
