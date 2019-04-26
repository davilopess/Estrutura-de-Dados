#include <stdio.h>
#include <stdlib.h>
#include "cofo.h"
#define true 1
#define false 0

//////////////////////////////////////////////////////////////////////// PROCURAR PELO NOME
int Menu(){
    int button;

    printf("\nSelecione uma das opcoes\n");
    printf(" [1] Adicionar pessoas \n");
    printf(" [2] Destruir cofo \n");
    printf(" [3] Inserir dados  \n");
    printf(" [4] Procurar pessoas \n");
    printf(" [5] Mostrar as pessoas \n");

    scanf("%d",&button);

    return button;
}

//////////////////////////////////////////////////////////////////////// CRIAR COFO
cofo *cofCreate( int nelms ){
    cofo *c;

    if (nelms > 0){
        cofo *c = ( cofo*)malloc( 1 * sizeof(cofo));
            if ( c != NULL){
                c->elms = (void**)malloc(nelms * sizeof(void*) );
                    if (c->elms != NULL){
                        c->nelms = 0;
                        c->max = nelms;
                        c->cur = -1;

                        return c;
                    }
            }
    }
    return NULL;
}

//////////////////////////////////////////////////////////////////////// DESTRUIR COFO
int cofDestroy( cofo *c ){
    if (c != NULL){
        if ( c->nelms == 0){
            free( c->elms );
            free(c);
            printf("\nDestruido com sucesso\n");
            return 1;
        }
    }
    printf("\nNao foi possivel destruir pois possui elementos\n");
    return 0;
}

//////////////////////////////////////////////////////////////////////// INSERIR NO COFO
int cofInsert ( cofo *c, void *elm){
    if(c != NULL){
        if( (c-> nelms) < (c->max)){
            c->elms[c->nelms] = elm;
            c->nelms++;

            return 1;
           }
    }
    return 0;
}

void flush_in(){
  int ch;
  while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){}
}
//////////////////////////////////////////////////////////////////////// REGISTRAR DADOS

int RegistrarDados(cofo *c){
    pessoa *p = (pessoa*)malloc(sizeof(pessoa)*1);
    int valor;

    if (c!=NULL) {
    if (p!=NULL) {
      if (c->nelms < c->max) {

        printf("Nome: \n");
        p->nome = (char*)malloc(sizeof(char)*20);
        if (p->nome!=NULL) {
          scanf("%s", p->nome);
            flush_in();

        }

        printf("Idade: \n");
        scanf("%d", &p->idade);

        printf("Numero de filhos: \n");
        scanf("%d", &p->numFilhos);

        printf("Numero do CPF: \n");
        p->numCpf = (char*)malloc(sizeof(char)*20);
        if (p->numCpf!=NULL) {
          scanf("%s", p->numCpf);
            flush_in();
        }
        printf("Valor do salario: \n");
        scanf("%f", &p->salario);

        valor = cofInsert(c , p);

        if (valor==1){

            return 1;

        }



        }
      }
    }
    return 0;
}

//////////////////////////////////////////////////////////////////////// LER DADOS

void mostrarDados(cofo *c){
        int i;
        if (c!=NULL){
            if (c->nelms > 0){
                pessoa *pm;

        for( i = 0 ; i < c->nelms ; i++){
            pm = (pessoa*)c->elms[i];
            printf("\nPessoa %d \n", i+1);

            printf("Nome : %s \n", pm->nome);
            printf("Idade: %d \n", pm->idade);
            printf("Numero de filhos : %d \n", pm->numFilhos);
            printf("Salario: %.2f \n", pm->salario);
            printf("CPF: %s \n", pm->numCpf);

        }
    }else{
        printf("Nao existe dados");
    }
}

}

//////////////////////////////////////////////////////////////////////// CMP nome

int cmpNome(void* elm1, void* elm2) {
  char *k1 = (char*) elm1;
  pessoa *k2 = (pessoa*) elm2;


  if (*k1==*k2->nome) {

    return 1;

  }else{

    return 0;
  }
}

//////////////////////////////////////////////////////////////////////// CMP CPF

int cmpCpf(void* elm1, void* elm2) {
  char *k1 = (char*) elm1;
  pessoa *k2 = (pessoa*) elm2;
    ;
  if (*k1==*k2->numCpf) {
    return 1;
  }
  else {
    return 0;
  }
}

//////////////////////////////////////////////////////////////////////// QueryNome

void* cofQueryNome(cofo *c, void* key, int(*cmpNome)(void*, void*)) {
  void* aux;
  int stat, i;

  if (c!=NULL) {
    if (c->nelms>0) {

      for ( i=0; i<c->nelms; i++) {
        stat = cmpNome(key, c->elms[i]);


        if (stat==1) {
          aux = c->elms[i];
          return aux;
          break;
        }
      }
    }
  }
  return NULL;
}

//////////////////////////////////////////////////////////////////////// QueryNome

void* cofQueryCpf(cofo *c, void* key, int (*cmpCpf)(void*, void*)) {
  void* aux;
  int stat;

  if (c!=NULL) {
    if (c->nelms>0) {
      for (int i=0; i<c->nelms; i++) {
        stat = cmpCpf(key, c->elms[i]);
        if (stat==1) {
          aux = c->elms[i];
          return aux;
          break;
        }
      }
    }
  }
  return NULL;
}

//////////////////////////////////////////////////////////////////////// Procurar

void opcaoDeProc(cofo *c) {
  int op;
  char *proc = (char*)malloc(sizeof(char)*20);
  void* exe;

  if (c!=NULL) {
    if (c->nelms > 0) {

      printf("Procurar por nome [1] \n");
      printf("Procurar por cpf  [2] \n");
      scanf("%d", &op);
      if (op==1) {
        if (proc!=NULL) {
          printf("Digite o nome: \n");
          scanf("%s", proc);
          flush_in();

          exe = cofQueryNome(c, proc, cmpNome);
          if (exe!=NULL) {
            pessoa *c1 = (pessoa*) exe;
            printf("Nome : %s \n", c1->nome);
            printf("Idade: %d \n", c1->idade);
            printf("Numero de filhos : R$ %d \n", c1->numFilhos);
            printf("Salario: %f \n", c1->salario);
            printf("CPF: %s \n", c1->numCpf);
          }
          else {
            printf("Nenhum dado encontrado! \n");
          }
        }
      } else if (op==2) {
        if (proc!=NULL) {
          printf("Digite o cpf: \n");
          scanf("%s", proc);
          flush_in();
          exe = cofQueryCpf(c, proc, cmpCpf);
          if (exe!=NULL) {
            pessoa *c2 = (pessoa*) exe;
            printf("Nome : %s \n", c2->nome);
            printf("Idade: %d \n", c2->idade);
            printf("Numero de filhos : R$ %d \n", c2->numFilhos);
            printf("Salario: %f \n", c2->salario);
            printf("CPF: %s \n", c2->numCpf);
          }else {
            printf("Nenhum dado encontrado! \n");
          }
        }
      }
    }
    else {
      printf("Sem dados armazenados! \n");
    }
  }
}

//////////////////////////////////////////////////////////////////////// Remover


void* cofRemove(cofo *c, void* key, int (*cmpNome)(void*, void*)) {
  void* aux;
  int status;

  for (int i=0; i<c->nelms; i++) {
    status = cmpNome(key, c->elms[i]);
    if (status==1) {
      aux = c->elms[i];
      for (int j=i; j<c->nelms; j++) {
        c->elms[j] = c->elms[j+1];
      }
      c->nelms--;

      return aux;
    }
  }
  return NULL;
}

void removerPessoa(cofo *c) {
  char *proc = (char*)malloc(sizeof(char)*20);
  void* exe;

  if (c!=NULL) {
    if (c->nelms > 0) {
      printf("Qual pessoa quer remover?: \n");
      scanf("%s", proc);
      flush_in();
      exe = cofRemove(c, proc, cmpNome);
      if (exe!=NULL) {
        pessoa *pm2 = (pessoa*) exe;
            printf("Nome : %s \n", pm2->nome);
            printf("Idade: %d \n", pm2->idade);
            printf("Numero de filhos : %d \n", pm2->numFilhos);
            printf("Salario: %.2f \n", pm2->salario);
            printf("CPF: %s \n", pm2->numCpf);
      }
      else {
        printf("Nenhum dado encontrado! \n");
      }
    }
  }
}

