#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define TAM 10

void embaralhar(int vetor[], int tamanho) {
    for (int i = tamanho - 1; i > 0; i--) {
        int j = rand() % (i + 1); // Gera um índice aleatório
        // Troca os elementos vetor[i] e vetor[j]
        int temp = vetor[i];
        vetor[i] = vetor[j];
        vetor[j] = temp;
    }
}

void imprime_vetor(int vetor[TAM]){

    //Auxiliar contador
    int cont;

    printf("\n");

     //Imprime o vetor
    for(cont = 0; cont < TAM; cont++){
        printf("|%d| ", vetor[cont]);
    }

}

void bubble_sort(int vetor[]){
    int x = 0,y,aux;

    for(x = 0; x < TAM; x++){
        for(y = x + 1; y < TAM; y++){
            if( vetor[x] > vetor[y % TAM] ){
                aux = vetor[x];
                vetor[x] = vetor[y % TAM];
                vetor[y % TAM] = aux;

            }
            imprime_vetor(vetor);
        }
    }
    imprime_vetor(vetor);
}

void insertion_sort(int vetor[]){
    //esse algoritimo de ordenação é como se fosse eu organizando cartas, a cada carta nova eu vou comparando com as anteriores.

    int i, j, atual;

    //o i representa a "carta" nova e o J representa o valor ja obtido, como se o I fosse o novo e o J o anterior.
    for(i = 1; i < TAM; i++){

        //elemento atual a ser analisado.
        atual = vetor[i];

        //elemento anterior ao analisado
        j = i - 1;

        //analisando membros anteriores.
        while(j >= 0 && atual < vetor[j]){

            //libera um espaço para o novo elemnto, "jogando" todo mundo para uma posição a frente.
            vetor[j + 1] = vetor [j];

            //andar para tras.
            j--;
        }
        //ja que agora foi liberado uma vaga para o novo elemento, vamos aloca-lo
        vetor[j + 1] = atual;
        imprime_vetor(vetor);
    }
}

void selection_sort(int vetor[]){


//bom para vetores pequenos!

int i, j, min, aux;

    for(i = 0; i < TAM; i++){
    min = i;

        for(j = i + 1; j < TAM; j++){
            if(vetor[j] < vetor[min]){
                min = j;
            }
        }

    if(min != i){
        //significa q o cursor encontrou outro menor.

        aux = vetor[i];
        vetor[i] = vetor[min];
        vetor[min] = aux;

        }
        imprime_vetor(vetor);
    }
}

int main(){

    int vetor[TAM] = {10,9,8,7,6,2,4,3,5,1};
    embaralhar(vetor,TAM);

    imprime_vetor(vetor);
    bubble_sort(vetor);

    imprime_vetor(vetor);
    return 0;




}
