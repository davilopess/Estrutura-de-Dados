#ifndef COFO_H_
#define COFO_H_



typedef struct _cofo_ {
  void  **elms;
  int max;
  int nelms;
  int cur;
}cofo;

typedef struct _pessoa_{
  char *nome;
  int idade;
  int numFilhos;
  float salario;
  char *numCpf;

}pessoa;


cofo *cofCreate(int nelms);
int cofDestroy(cofo *c);
int cofInsert(cofo *c, void* elm);
int RegistrarDados(cofo *c);
void flush_in();
void mostrarDados(cofo *c);
int cmpNome(void* elm1, void* elm2);
int cmpCpf(void* elm1, void* elm2);
void* cofQueryNome(cofo *c, void* key, int(*cmpNome)(void*, void*));
void* cofQueryCpf(cofo *c, void* key, int(*cmpCpf)(void*, void*));
void opcaoDeProc(cofo *c);
void* cofRemove(cofo *c, void* key, int (*cmpNome)(void*, void*));
void removerPessoa(cofo *c);
int Menu();


#endif // COFO_H_INCLUDED
