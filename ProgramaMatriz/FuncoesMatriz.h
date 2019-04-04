
//ALOCAR MATRIZ ------------------------------------------------
float *AlocaMatriz(int n, int m){


    float *vmat;

    vmat = (float *)malloc (sizeof(float) * n * m);

    if (vmat != NULL){
            return vmat;
    }

    return NULL;
}


//LER MATRIZ ---------------------------------------------------
float *LerMatriz(int n, int m, FILE *file){
int i, j;
float *vmatriz;

for (i = 0 ; i < n ; i++){
                    for (j = 0 ; j < m ; j++){

                        fscanf (file, "%f", &vmatriz[(m*i) + j]);
                    }

                }


                return vmatriz;
        }


//MULTIPLICAR MATRIZ ---------------------------------------------
float* Mult(int n,int m, int p, int q, float *ma, float*mb){

    float *mc , aux = 0;
    int i, j, x;

    if (m!=p){
        return NULL;

    }


    mc = (float *) malloc(n * q * sizeof(float));




    for( i = 0 ;  i < n ; i++){
        for( j = 0 ; j < q ; j++){
            mc[(m*i) + j] = 0;
            for ( x = 0 ; x < p ; x++){
             aux = aux + ( ma[(m*i) + x] * mb[(m*x) + j]);


            }
            mc[(m*i) + j] = aux;
            aux = 0;

        }
    }

    for (i = 0 ; i < n ; i++){
                    for (j = 0 ; j < q ; j++){
                    printf("%f ", mc[(m*i) + j]);
                }
                    printf("\n");
                }

    return mc;
}

// TRANSPOSTA DA MATRIZ   ---------------------------------------------------
float *MatrizTransposta(int n, int m, float *vmat){

    float *vmbT;
    int i, j;

    vmbT = AlocaMatriz(n, m);

    printf("\n");

    for (i = 0 ; i < m ; i++){
                for (j = 0 ; j < n ; j++){
                    vmbT[(m*i)+j] = vmat[(m*j) + i];


                }
                printf("\n");
            }

    return vmbT;

}

//MULTIPLICAR A COM MATRIZ TRANSPOSTA DE B ---------------------------------------------------
float* Mat(int n,int m, int p, int q, float *ma, float*mb){

    float *mc , aux = 0;
    int i, j, x;

    if (m!=q){
        return NULL;

    }


    mc = (float *) malloc(n * p * sizeof(float));

    mb = MatrizTransposta(p, q, mb);


    for( i = 0 ;  i < n ; i++){
        for( j = 0 ; j < p ; j++){
            mc[(m*i) + j] = 0;
            for ( x = 0 ; x < q ; x++){
             aux = aux + ( ma[(m*i) + x] * mb[(m*x) + j]);


            }
            mc[(m*i) + j] = aux;
            aux = 0;

        }
    }
    for(i = 0 ; i < n ;i++){
            for(j = 0 ; j < p ;j++){

                printf("%f ", mc[(m*i) + j]);


            }
            printf("\n");
    }

    return mc;


}
//LER MATRIZ  ---------------------------------------------------

float ImprimeMatriz(int n, int m, float *vmatriz){

    int i, j;
    for(i = 0 ; i < m ;i++){
            for(j = 0 ; j <n ;j++){

                printf("%f ", vmatriz[(m*j) + i]);


            }
            printf("\n");
    }





}


