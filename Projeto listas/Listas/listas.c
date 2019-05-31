#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listas.h"
#define true 1
#define false 0


////////////////////////////////////////////////////////////////////////

int Menu()
{
    int button;

    printf("\nSelecione uma das opcoes\n");
    printf(" [1] Criar lista \n");
    printf(" [2] Destruir lista \n");
    printf(" [3] Inserir pessoas  \n");
    printf(" [4] Procurar pessoas \n");
    printf(" [5] Mostrar as pessoas \n");
    printf(" [6] Remover pessoa \n");

    scanf("%d",&button);

    return button;
}
//////////////////////////////////////////////////////////////////////// CRIAR LISTA

SLList *sllCreate()
{
    SLList *l;

    l = (SLList *)malloc(sizeof(SLList));
    if (l != NULL)
    {
        l->first = l->cur = NULL;
        return l;
    }
    return NULL;
}

//////////////////////////////////////////////////////////////////////// DESTRUIR LISTA
int sllDestroy(SLList *l)
{
    if (l != NULL)
    {
        if (l->first == NULL)
        {
            free(l);
            return true;
        }
    }
    return false;
}

//////////////////////////////////////////////////////////////////////// INSERIR COMO PRIMEIRO

int sllInsertFirst(SLList *l, void *data)
{
    SLLNode *newNode;

    if (l != NULL)
    {
        newNode = (SLLNode *) malloc (sizeof(SLLNode));
        if (newNode != NULL)
        {
            newNode->data = data;
            newNode->next = l->first;
            l->first = newNode;
            return true;
        }
    }
    return false;
}


//////////////////////////////////////////////////////////////////////// REMOVER O ITEM ESPECIFICADO

void *sllRemoveSpec(SLList *l, void *key, int (*cmp)(void *, void *))
{
    SLLNode *aux, *prev;
    void *data;
    int stat;

    if (l != NULL)
    {
        if (l->first != NULL)
        {
            prev = NULL;
            aux = l->first;
            stat = cmp(key, aux->data);
            while (stat != true && aux->next != NULL)
            {
                prev = aux;
                aux = aux->next;
                stat = cmp(key, aux->data);
            }
            if (stat == true)
            {
                if (prev != NULL)
                {
                    prev->next = aux->next;
                }
                else
                {
                    l->first = NULL;
                }
                data = aux->data;
                free(aux);
                return data;
            }
        }
    }
    return NULL;
}

////////////////////////////////////////////////////////////////////////

void flush_in()
{
    int ch;
    while( (ch = fgetc(stdin)) != EOF && ch != '\n' ) {}
}

////////////////////////////////////////////////////////////////////////
int RegistrarDados(SLList *c)
{
    pessoa *p = (pessoa*)malloc(sizeof(pessoa)*1);
    int valor;

    if (c!=NULL)
    {
        if (p!=NULL)
        {
            printf("Nome: \n");
            p->nome = (char*)malloc(sizeof(char)*20);
            if (p->nome!=NULL)
            {
                scanf("%s", p->nome);
                flush_in();

            }

            printf("Idade: \n");
            scanf("%d", &p->idade);

            printf("Numero de filhos: \n");
            scanf("%d", &p->numFilhos);

            printf("Numero do CPF: \n");
            p->numCpf = (char*)malloc(sizeof(char)*20);
            if (p->numCpf!=NULL)
            {
                scanf("%s", p->numCpf);
                flush_in();
            }
            printf("Valor do salario: \n");
            scanf("%f", &p->salario);

            valor = sllInsertFirst(c, p);

            if (valor==1)
            {

                return 1;

            }
        }
    }
    return 0;
}
////////////////////////////////////////////////////////////////////////
void *sllGetFirst(SLList *l)
{
    SLLNode *first;
    void *data;

    if (l != NULL)
    {
        if (l->first != NULL)
        {
            l->cur = l->first;
            first = l->first;
            data = first->data;
            return data;
        }
    }
    return NULL;
}
////////////////////////////////////////////////////////////////////////
void *sllGetNext(SLList *l)
{
    SLLNode *next;
    void *data;
    if (l != NULL)
    {
        if (l->cur != NULL)
        {
            next = l->cur;
            next = next->next;
            if (next != NULL)
            {
                l->cur = next;
                data = next->data;
                return data;
            }
        }
    }
    return NULL;
}

////////////////////////////////////////////////////////////////////////

void mostraPessoa(pessoa *p)
{
    if(p != NULL)
    {
        printf("Nome: %s\n",p->nome );
        printf("Idade: %d\n",p->idade);
        printf("Numero de filhos: %d\n",p->numFilhos);
        printf("Salario: %0.f\n",p->salario);
        printf("CPF: %s\n",p->numCpf);
    }
}

////////////////////////////////////////////////////////////////////////
void mostraTodos(SLList *c)
{
    if(c != NULL)
    {
        printf("\n_____________________\n");
        pessoa *p ;
        p = (pessoa*)sllGetFirst(c);
        while(p != NULL)
        {

            mostraPessoa(p);
            printf("\n_____________________\n");
            p = (pessoa*)sllGetNext(c);
        }

    }
}

//////////////////////////////////////////////////////////////////////// CMP nome

int cmpNome(void* elm1, void* elm2)
{
    char *k1 = (char*) elm1;
    pessoa *k2 = (pessoa*) elm2;


    if (strcmp(k2->nome, k1)==0)
    {

        return 1;

    }
    else
    {

        return 0;
    }
}

//////////////////////////////////////////////////////////////////////// CMP CPF

int cmpCpf(void* elm1, void* elm2)
{
    char *k1 = (char*) elm1;
    pessoa *k2 = (pessoa*) elm2;
    ;
    if (strcmp(k2->numCpf, k1)==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

////////////////////////////////////////////////////////////////////////Procurar na lista

void *sllQuery(SLList *l, void *key, int (*cmp)(void *, void *))
{
    SLLNode *cur;
    void *data;
    int stat;

    if (l != NULL)
    {
        if (l->first != NULL)
        {
            cur = l->first;
            stat = cmp(key, cur->data);
            while (stat != true && cur->next != NULL)
            {
                cur = cur->next;
                stat = cmp(key, cur->data);
            }
            if (stat == true)
            {
                data = cur->data;
                return data;
            }
        }
    }
    return NULL;
}

////////////////////////////////////////////////////////////////////////Procurar na lista pelo nome
int queryNome(SLList *c)
{
    pessoa *p;
    char *proc = (char*)malloc(sizeof(char)*20);
    printf("Digite o nome: \n");
    scanf("%s", proc);
    flush_in();

    p = (pessoa*)sllQuery(c, proc, cmpNome);
    if (p!=NULL)
    {
        mostraPessoa(p);
        return true;
    }
    else
    {
        return false;
    }

}

////////////////////////////////////////////////////////////////////////Procurar na lista pelo cpf

int queryCpf(SLList *c)
{
    pessoa *p;
    char *proc = (char*)malloc(sizeof(char)*20);
    printf("Digite o cpf: \n");
    scanf("%s", proc);
    flush_in();

    p = (pessoa*)sllQuery(c, proc, cmpCpf);
    if (p!=NULL)
    {
        mostraPessoa(p);
        return true;
    }
    else
    {
        return false;
    }

}


////////////////////////////////////////////////////////////////////////Procurar na lista pelo cpf

void opcaoProc(SLList *c)
{
    int exe, op;
    if (c!=NULL)
    {

        printf("Procurar por nome [1] \n");
        printf("Procurar por cpf  [2] \n");
        scanf("%d", &op);
        if (op==1)
        {
            exe = queryNome(c);
            if(exe==0)
            {
                printf("Pessoa nao existe\n");
            }
        }

        if (op==2)
        {
            exe = queryCpf(c);
            if(exe==0)
            {
                printf("Pessoa nao existe\n");
            }
        }
    }
}

////////////////////////////////////////////////////////////////////////Remover pelo nome
int removeNome(SLList *c)
{

    pessoa *p;
    char *proc = (char*)malloc(sizeof(char)*20);
    printf("Digite o nome: \n");
    scanf("%s", proc);
    flush_in();

    p = (pessoa*)sllRemoveSpec(c, proc, cmpNome);
    if (p!=NULL)
    {
        mostraPessoa(p);
        free(p);
        return true;
    }
    else
    {
        return false;
    }

}

////////////////////////////////////////////////////////////////////////Remover pelo cpf
int removeCpf(SLList *c)
{

    pessoa *p;
    char *proc = (char*)malloc(sizeof(char)*20);
    printf("Digite o nome: \n");
    scanf("%s", proc);
    flush_in();

    p = (pessoa*)sllRemoveSpec(c, proc, cmpCpf);
    if (p!=NULL)
    {
        mostraPessoa(p);
        free(p);
        return true;
    }
    else
    {
        return false;
    }

}

////////////////////////////////////////////////////////////////////////Procurar na lista pelo cpf

void opcaoRemove(SLList *c)
{
    int exe, op;
    if (c!=NULL)
    {

        printf("Remover pelo nome [1] \n");
        printf("Remover pelo cpf  [2] \n");
        scanf("%d", &op);
        if (op==1)
        {
            exe = removeNome(c);
            if(exe==0)
            {
                printf("Pessoa nao existe\n");
            }
        }

        if (op==2)
        {
            exe = removeCpf(c);
            if(exe==0)
            {
                printf("Pessoa nao existe\n");
            }
        }
    }
}












