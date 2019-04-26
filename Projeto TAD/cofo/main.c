#include <stdio.h>
#include <stdlib.h>
#include "cofo.h"





void main(void)
{

    int ask = 1, numero, button,dados;
    cofo *c;

    while (ask == 1)
    {
            button = Menu();



        switch(button)
        {


        case 1:
            printf("\n Numero de pessoas para serem cadastradas : \n");
            scanf("%d",&numero);
            c = cofCreate(numero);
            printf("\nCriado com sucesso\n");
            break;

        case 2:
            cofDestroy(c);

            break;

        case 3:
            printf("\n Insira o dado da pessoa : \n");
            dados = RegistrarDados(c);
            if (dados==1){
            printf("Dados inseridos \n");
            }

            break;

        case 4:

            opcaoDeProc(c);


            break;

        case 5:

            mostrarDados(c);


            break;

        case 6:

            removerPessoa(c);



            break;












        }
        printf("Continuar: SIM [1] / NÃO [qualquer tecla] \n");
            scanf("%d", &ask);
    }

}
