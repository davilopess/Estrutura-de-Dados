#ifndef LISTAS_H_INCLUDED
#define LISTAS_H_INCLUDED

typedef struct SLLNode
{
    struct SLLNode *next;
    void *data;
} SLLNode;

typedef struct sllist
{
    struct SLLNode *first;
    struct SLLNode *cur;
} SLList;

typedef struct _pessoa_
{
    char *nome;
    int idade;
    int numFilhos;
    float salario;
    char *numCpf;

} pessoa;

SLList *sllCreate();
int sllDestroy(SLList *l);
int sllInsertFirst(SLList *l, void *data);
void *sllRemoveSpec(SLList *l, void *key, int (*cmp)(void *, void *));
void *sllGetFirst(SLList *l);
void *sllGetNext(SLList *l);
void mostraTodos(SLList *c);
void mostraPessoa(pessoa *p);
int RegistrarDados(SLList *c);
int cmpNome(void* elm1, void* elm2);
int cmpCpf(void* elm1, void* elm2);
void *sllQuery(SLList *l, void *key, int (*cmp)(void *, void *));
int queryNome(SLList *c);
int queryCpf(SLList *c);
int removeCpf(SLList *c);
int removeNome(SLList *c);
void opcaoRemove(SLList *c);
#endif // LISTAS_H_INCLUDED
