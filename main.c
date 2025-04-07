#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Debug

void pause() {
    printf("\nPressione Enter para continuar...");
    getchar();
}

//Funções Importantes;
int* criarVetor(int n) {
    int* v = (int*)malloc(n * sizeof(int));
    if (v == NULL) {
        printf("Erro ao alocar memória\n");
        exit(1);
    }

    for (int i = 0; i < n; i++)
        v[i] = rand() % 1001; // valores de 0 a 1000

    return v;
}

void embaralhar(int vetor[], int tamanho) {
    for (int i = tamanho - 1; i > 0; i--) {
        int j = rand() % (i + 1); // Gera um índice aleatório
        // Troca os elementos vetor[i] e vetor[j]
        int temp = vetor[i];
        vetor[i] = vetor[j];
        vetor[j] = temp;
    }
}

void imprime_vetor(int vetor[], int n, int dem){

    if (dem != 0 && n < 200) {
        //Auxiliar contador
        int cont;

        printf("\n");

        //Imprime o vetor
        for(cont = 0; cont < n; cont++){
            printf("|%d| ", vetor[cont]);
        }
    }

}

clock_t iniciar_contador() {
    return clock();
}

double finalizar_contador(clock_t inicio) {
    clock_t fim = clock();
    return ((double)(fim - inicio)) / CLOCKS_PER_SEC * 1000.0; // ms
}

//Algoritmos.
//Precisei colocar o tipo dos contadores de operações para long ao invez de int pq os numeros estavam imensos.
//"unsigned" significa que eu exclui todos os negativos"

void bubble_sort(int vetor[], int n, int dem){
    int x = 0,y,aux;
    unsigned long comp = 0, atrib= 0;
    imprime_vetor(vetor,n,1);
    clock_t CronometroInicial = iniciar_contador(); //Começa a contagem

    for(x = 0; x < n; x++){
        for(y = x + 1; y < n; y++){
            comp++;
            if( vetor[x] > vetor[y % n] ){
                aux = vetor[x]; atrib++;
                vetor[x] = vetor[y]; atrib++;
                vetor[y] = aux; atrib++;

            }
            imprime_vetor(vetor,n,dem);
        }
    }
    imprime_vetor(vetor,n,1);
    double FimCronometro = finalizar_contador(CronometroInicial); //Finaliza a contagem
    printf("\nComparações: %lu, Atribuições: %lu\n", comp, atrib);
    printf("Tempo decorrido: %.3f ms\n", FimCronometro);
}

void insertion_sort(int vetor[],int n, int dem){
    //esse algoritimo de ordenação é como se fosse eu organizando cartas, a cada carta nova eu vou comparando com as anteriores.
    unsigned long comp = 0, atrib = 0;
    int i, j, atual;
    imprime_vetor(vetor,n,1);
    //o i representa a "carta" nova e o J representa o valor ja obtido, como se o I fosse o novo e o J o anterior.
    clock_t CronometroInicial = iniciar_contador();
    for(i = 1; i < n; i++){

        //elemento atual a ser analisado.
        atual = vetor[i]; atrib++;

        //elemento anterior ao analisado
        j = i - 1;

        //analisando membros anteriores.
        while(j >= 0 && ++comp && atual < vetor[j]){

            //libera um espaço para o novo elemnto, "jogando" os elementos mundo para uma posição a frente.
            vetor[j + 1] = vetor [j]; atrib++;

            //andar para tras.
            j--;
        }
        //ja que agora foi liberado uma vaga para o novo elemento, vamos aloca-lo
        vetor[j + 1] = atual; atrib++;
        imprime_vetor(vetor,n,dem);
    }
    imprime_vetor(vetor,n,1);
    double CronometroFinal = finalizar_contador(CronometroInicial);
    printf("\nComparações: %lu, Atribuições: %lu\n", comp, atrib);
    printf("Tempo decorrido: %.3f ms\n", CronometroFinal);

}

void selection_sort(int vetor[],int n, int dem){


//bom para vetores pequenos!
unsigned long comp = 0, atrib = 0;
int i, j, min, aux;

    imprime_vetor(vetor,n,1);
    clock_t CronometroInicial = iniciar_contador();
    for(i = 0; i < n; i++){
    min = i;

        for(j = i + 1; j < n; j++){
            comp++;
            if(vetor[j] < vetor[min]){
                min = j;
            }
        }

    if(min != i){
        //significa q o cursor encontrou outro menor.

        aux = vetor[i]; atrib++;
        vetor[i] = vetor[min]; atrib++;
        vetor[min] = aux; atrib++;

        }
        imprime_vetor(vetor,n,dem);
    }
    double CronometroFinal = finalizar_contador(CronometroInicial);
    imprime_vetor(vetor,n,1);
    printf("\nComparações: %lu, Atribuições: %lu\n", comp, atrib);
    printf("Tempo decorrido: %.3f ms\n", CronometroFinal);
}

//Questões da lista

void Experimento1() {
    int n = 10;
    int* vetor_mae= criarVetor(n); //Modularizei a criação do vetor pois eu vou fazer isso varias vezes
    embaralhar(vetor_mae,n);
    int dem = 1; /* a variavel "dem" de demonstração é uma variavel
                que criei para eu escolher se eu quero mostrar todos os passos de um algoritmo ou nao*/

    // cada algoritimo recebe uma copia unica desse vetor, para que eu nao precise embaralhar toda hr
    int vetor_bubble[n], vetor_selection[n], vetor_insertion[n];
    for (int i = 0; i < n; i++) {
        vetor_bubble[i] = vetor_mae[i];
        vetor_selection[i] = vetor_mae[i];
        vetor_insertion[i] = vetor_mae[i];
    }

    printf("\ni) Algoritmos de ordenação basicos, com n = 10\n");



    printf("\nVetor com n = %d elementos embaralhados: ",n);
    imprime_vetor(vetor_mae,n,1);

    printf("\n\nBubble Sort:");
    bubble_sort(vetor_bubble, n, dem);

    printf("\nSelection Sort:");
    selection_sort(vetor_selection,n, dem);

    printf("\nInsertion Sort:");
    insertion_sort(vetor_insertion,n, dem);
}

void Experimento2p1() {
    int n = 50000;
    int* vetor_mae= criarVetor(n); //Modularizei a criação do vetor pois eu vou fazer isso varias vezes
    embaralhar(vetor_mae,n);
    int dem = 0; /* a variavel "dem" de demonstração é uma variavel
                que criei para eu escolher se eu quero mostrar todos os passos de um algoritmo ou nao*/

    // cada algoritimo recebe uma copia unica desse vetor, para que eu nao precise embaralhar toda hr
    int vetor_bubble[n], vetor_selection[n], vetor_insertion[n];
    for (int i = 0; i < n; i++) {
        vetor_bubble[i] = vetor_mae[i];
        vetor_selection[i] = vetor_mae[i];
        vetor_insertion[i] = vetor_mae[i];
    }

    printf("\nExperimento 2, Parte 1!\n");
    printf("\nii) Vetor aleatorio de tamanho n, para n suficientemente grande, n = %d\n",n);



    printf("\nVetor com n = %d elementos embaralhados: ",n);
    //imprime_vetor(vetor_mae,n,1);

    printf("\n\nBubble Sort:");
    bubble_sort(vetor_bubble, n, dem);

    printf("\nSelection Sort:");
    selection_sort(vetor_selection,n, dem);

    printf("\nInsertion Sort:");
    insertion_sort(vetor_insertion,n, dem);
}

void Experimento2p2() {
    int n = 100000;
    int* vetor_mae= criarVetor(n); //Modularizei a criação do vetor pois eu vou fazer isso varias vezes
    embaralhar(vetor_mae,n);
    int dem = 0; /* a variavel "dem" de demonstração é uma variavel
                que criei para eu escolher se eu quero mostrar todos os passos de um algoritmo ou nao*/

    // cada algoritimo recebe uma copia unica desse vetor, para que eu nao precise embaralhar toda hr
    int vetor_bubble[n], vetor_selection[n], vetor_insertion[n];
    for (int i = 0; i < n; i++) {
        vetor_bubble[i] = vetor_mae[i];
        vetor_selection[i] = vetor_mae[i];
        vetor_insertion[i] = vetor_mae[i];
    }

    printf("\nExperimento 2, Parte 2!\n");
    printf("\nii) Vetor aleatorio de tamanho n, para n suficientemente grande, n = %d\n",n);

    printf("\nVetor com n = %d elementos embaralhados: ",n);
    //imprime_vetor(vetor_mae,n,1);

    printf("\n\nBubble Sort:");
    bubble_sort(vetor_bubble, n, dem);

    printf("\nSelection Sort:");
    selection_sort(vetor_selection,n, dem);

    printf("\nInsertion Sort:");
    insertion_sort(vetor_insertion,n, dem);
}


int main(){

    srand(time(NULL)); // Inicializa o gerador de números aleatórios

    //Teste de Algoritmo com n = 10;
        Experimento1();
        printf("\nAperte enter para ir para o proximo experimento. (caso aperte e nada aconteça, aperte novamente)\n");
        printf("\n!!Capaz do programa demorar a mostrar os resultados devido ao tamanho de elementos!!\n");
        printf("\n!!Especificações da maquina podem alterar a contagem em ms!!\n");
        pause();

        Experimento2p1();
        Experimento2p2();



    return 0;




}
