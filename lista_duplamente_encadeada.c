#include<stdio.h>
#include<stdlib.h>

typedef struct No{
    int valor;
    struct No * prox;
    struct No * ant;
}No;

No * inicio = NULL;
No * fim = NULL;
int tam = 0;

//ALTERACAO AQUI AAAAAEEEIIIOOOUUUU
//MANJO MUITO DE GITHUB Ó PQP

void adicionar(int valor, int pos){
    if(pos>= 0 && pos<= tam){
        No * novo = malloc(sizeof(No));
        novo->valor = valor;
        novo->prox = NULL;
        novo -> ant = NULL;
        if(inicio == NULL){ //lista vazia!
            inicio = novo;
            fim = novo;
        }else if(pos == 0){ // posicao é 0 - inicio! :D
            novo->prox = inicio;
            inicio = novo;
        }else if(pos == tam){ //posicao é tam - fim! :D
            fim->prox = novo;
            novo -> ant = fim;
            fim = novo;
        }else{ //no meio! :'(
            //pedaco problematico!!!!!
            No * aux = inicio;
            for(int i = 0; i< pos - 1; i++){
                aux = aux->prox;
            }
            aux -> prox -> ant = novo;
            aux->prox = novo;       //ESTÁ INCOMPLETO;
        }
        tam++;
    }
}

int remover(int pos){ //tam == 1; pos == 0; pos == tam - 1; 
    if (pos >= 0 && pos < tam){
    No * aux;
        if (aux == NULL){
            printf("LISTA VAZIA");
        } else if (tam == 1){       //apenas um nó na lista e irei removê-lo kk;
            aux = inicio;
            inicio = NULL;
            fim = NULL;
            free(aux);
        } else if (pos == 0){       //inicio  
            aux = inicio;
            inicio = inicio -> prox;
            inicio -> ant = NULL;
            free(aux);
        } else if (pos == tam -1) {
            aux = fim;
            fim = fim -> ant;
            fim -> prox = NULL;
            free(aux);
        } else {                 //meio
            aux = inicio;
            for (int i = 0; i < pos; i++){
            aux = aux -> prox;  
            }
            aux -> ant -> prox = aux -> prox;
            aux -> prox -> ant = aux -> ant;
            free(aux);
        } 
        tam--;

    }

    }
//RETORNAR OS NUMEROS REMOVIDOS
   
void imprimir(){
    No * aux = inicio;
    for(int i = 0; i<tam; i++){
        printf("Valor = %d\n", aux->valor );
        aux = aux->prox;
    }
    
}


int main(){
    adicionar(1,0);
    adicionar(2,1);
    adicionar(3,2);
    adicionar(4,3);
    adicionar(5,4);
    adicionar(6,5);
    adicionar(7,6);
    imprimir();
    printf("\n");
    remover(0);
    imprimir();
    printf("\n");
    remover(3);
    imprimir();
    printf("\n");
    remover(4);
    imprimir();
    remover(6);
    remover(5);
    
return 0;
    
}
