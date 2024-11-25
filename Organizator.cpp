/*
Name: Organizator.cpp
Author: Lucas Oliveira
Date: oct/26/2024
Description: Um algoritmo para unir todas as funcionalidades ministradas na disciplina de Estrutura de Dados, planejada e ministrada por Alexandre Cassiano.
Neste projeto abordaremos estruturas de dados como:

 - Lista
 - Pilha
 - Fila

 Também utilizaremos algoritmos para ordenação de dados:

 - Bubble Sort ()
 - Selection Sort ()
 - Insertion Sort ()
 - Shell Sort ()

*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000


/******************************** Sessao de prototipacao ****************************************************/
// Globais
void DSQuestion(); // Funcao principal 
void RandomizeArray(int array[], int size); // Ira randomizar o array com a constante MAX
void sortQuestion(); // Pergunta qual metodo sort para ordenar os dados
void structQuestion(); // Pergunta qual estrutura de dados sera ordenada
void clearPrompt(); // Limpa o prompt de comando atual
// int strLength(int *arr[]); // Retorna o tamanho de um determinado array

// stack, queue, list [0 -> false, 1 -> true]
int structureUsed[] = {0, 0, 0}; // Array binario para retornar qual strutura foi usada.

// Sessao pilha
int *stack = (int *)malloc(sizeof(stack) / sizeof(int)); // Pilha global

void StackQuestion(); // Prompt para adicao ou remocao de dado na pilha
void initStack(); // Inicia a estrutura pilha
int pop(); // Assume o valor da ultima posicao adicionada na pilha
void push(int num); // Adiciona um elemento na ultima posicao
void printAll(int *arr); // Imprime a pilha
void binaryConversor(int decNum); // Funcao para conversao de um numero de base decimal para base binaria

int peek = -1; // Topo da pilha

// Sessao fila
int *queue = (int *)malloc(sizeof(queue) / sizeof(int)); // Fila global
int first = -1; // Variavel que armazena o indice do primeiro elemento da fila

void QueueQuestion(); // Prompt da fila para adicicao ou remocao de dados

// Sessao lista
void ListQuestion(); // Prompt da lista encadeada, para adicao ou remocao de dados

typedef struct {
    int value;
    int *next, *prev;
} List;

//--------------------Big O Notation----------------
// :construction: Aqui a intencao eh que comparamos a eficiencia de dois algoritmos sort, usando o tempo de execucao e a quantidade de trocas e comparacao, para determinar a eficiencia e custo para o hardware

int comp, shift; // Variaveis que armazezam a quantidade de trocas e a quantidade que foram comparadas
void compareSortQuestion(/*void sortMethod(), void sortMethod2(), int structureUsed[]*/);/* Linha 64
* - Esta funcao void deve perguntar ao usuario dois metodos sort de ordenacao de dados (Estes nao podem se repetir, exemplo comparar um bubble sort com um bubble sort, ou qualquer outro). 
* - Provavelmente a funcao compareSort(*sort1(), *sort2(), bigONotation) devera receber dois ponteiros como parametros e/ou uma funcao para comparar a eficiencia, nomeado de Big O Notation mas pode ser que seja alterado.
*/

//---------------------------------------------------

// Sessao bubble sort
void initBuble(); // Inicia o bubble sort

// Sessao selection sort
void initSelection(); // Inicia o selection sort

/****************************** CONSTRUCTION ***********************************************/
// Sessao insertion sort

// Sessao shell sort
//

/*************************** Fim da sessao de prototipacao **************************************************/

/************************************* Sessao de Main *******************************************************/

int main() {
    if(stack == NULL){
        printf("\n!!!! Stack memory allocation failure !!!!");
        return 1;
    }
    if (queue == NULL){
       printf("\n!!!! Queue memory allocation failure !!!!");
        return 1;
    }
	DSQuestion();

    free(stack);
    free(queue);
}

/******************************** Fim da sessao de Main *****************************************************/

/**************************** Sessao de Modelagem de funcao ************************************************/
void DSQuestion(){
	comp = 0, shift = 0;
    int option = 0;
    puts("==========================");
    puts("Bem vindo ao programa!");
    printf("\n\nPara iniciarmos digite a opcao que preferir\n1) Lista\n2) Fila\n3) Pilha\n4) Ordenacao de dados\n0) Sair...\n");
    scanf("%d", &option);
    switch (option) {
        case 1: // Lista
            ListQuestion();
            break;
        case 2: // Fila
            QueueQuestion();
            break;
        case 3: // Pilha
            StackQuestion();
            break;
        case 4: // Ordenacao de dados
            structQuestion();
            break;
        case 0: // Sair
            exit(0);
            break;
        default:
            printf("Opcao invalida...\n");
            break;
    }
}

void clearPrompt() {
        system("cls") || system("clear");
}

void structQuestion(){
    int strUsed = arraySum(structureUsed);
    int opt = 0;

    while(1){
        clearPrompt();
        printf("\nPor favor escolha qual estrutura voce gostaria que fosse ordenada:\n");
        if(structureUsed[0]){
            printf("1 - Pilha\n");
            scanf("%d", &opt);
        };
        if(structureUsed[1]){
            printf("2 - Fila\n");
            scanf("%d", &opt);
        };
        if(structureUsed[2]){
            printf("3 - Lista\n");
            scanf("%d", &opt);
        };
        printf("4 - Um vetor com 1,000 numeros aleatorios\n0 - Voltar...");
        scanf("%d", &opt);
        
        switch(opt){
            case 1: // Stack
                if (structureUsed[0])
                    sortQuestion(0);
                else
                    printf("Pilha vazia...\nOpcao invalida!\n");
                break;
            case 2: // Queue
                if (structureUsed[1])
                    sortQuestion(1);
                else
                    printf("Fila vazia...\nOpcao invalida!\n");
                break;
            case 3: // List
                if (structureUsed[2])
                    sortQuestion(2);
                else
                    printf("Lista vazia...\nOpcao invalida!\n");
                break;
            case 4: // sort numbers
                // Aqui tem que decidir se vamos inserir um array ou se vamos chamar a funcao sortQuestion com uma trajeto para randomizar um array e usa-lo
                break;
            case 0: // Exit
                DSQuestion();
            default:
                printf("Opcao invalida!\n");
                break;
        }
    }
}

void sortQuestion(int strChose){
    int opt = strChose;
    int chose;
    int *auxArray = (int *)malloc(sizeof(auxArray) / sizeof(auxArray[0])); // Aqui criamos um bloco de memoria continuo, se comporta semelhante a um array, mas deixa de ser um... Então podemos nos referir aos proximos blocos como auxArray[]

    // Aqui a intencao eh criar um array auxiliar que ira armazenar as informacoes de acordo com a escolha de estrutura do usuario
    // Nao ha valor default porque ira receber da structQuestion (Precisa verificar se uma func void pode ser recursivaw)
    switch (opt){
    case 0: //Stack
        for(int j = 0; j < peek; j++){
            auxArray[j] = stack[j];
        }
        break;
    case 1: // Queue
        for(int j = 0; j < first /* Aqui eh apenas uma variavel tipo o pico de uma fila, mas este eh para fila */; j++){
            auxArray[j] = queue[j];
        }
        break;
    case 2: // List
            auxArray[j] ;// Ira receber o valor da lista, provavelmente terá que percorrer todas até que o valor de "Prox" seja NULL.
        break;
    case 3: // random numbers
        RandomizeArray(auxArray, 1000); // Esta funcao deve randomizar o array deste escopo
        break;
    }


    while(1){
        printf("\nEscolha como devemos organizar esta estrutura:\n1 - Comparar dois metodos\n2 - Bubble sort\n3 - Selection sort\n4 - Insertion sort\n5 - Shell sort");
        printf("\n0 - Voltar...");
        scanf("%d", chose);

        switch(chose){
            case 1:
                compareSortQuestion(); // Aqu
                break;
            case 2:
                initBuble();
                break;
            case 3:
                initSelection();
                break;
            case 4:
                /* Insertion sort */
                break;
            case 5:
                /* Shell sort */
                break;
            case 0:
                DSQuestion();
                break;
            default:
                printf("\nOpcao invalida...");
                break;
        }
    }
}

void structureStack() {
    int value, elem, option;

    while(1){
        int option = 0;
        clearPrompt();

        printf("\nPilha atual:  "); printAll(stack);
        printf("\n\n1 - Inserir na pilha\n2 - Retirar da pilha\n3 - Conversor binario\n5 - Finalizar");
        printf("\nOpcao:	"); scanf("%d", &option);

        switch(option){
            case 1: 
                while(1){
                    int newValue = 0;
                    clearPrompt();

                    printf("\nPilha atual:  "); printAll(stack);
                    printf("\n\nDigite um valor inteiro que deseja inserir: \nDigite 0 para parar de adicionar..."); scanf("%d", &newValue); 
                    if(newValue == 0)
                        break;
                    else
                        push(newValue);
                }
                structureUsed[0] = 1; //Atualiza o Array informando que usamos a estrutura pilha e que ha dados nela
                break;
            case 2: 
                if(stack[0] == NULL){
                    printf("\nA pilha esta vazia!"); 
                    structureUsed[0] = 0; // Atualiza o array informando que a estrutura pilha agora esta vazia
                }else
                    clearPrompt();
                    peek = -1 ? printf("Pilha vazia") : printf("%d Retirado!\n",pop());

                    printf("Digite qualquer tecla para continuar..."); getchar();
                break;
            case 3: 
                elem = 0;
                printf("Digite um numero inteiro para converter em binario:	");
                scanf("%d", &elem);
                binaryConversor(elem);
                break;
            case 5:
                DSQuestion();
            default:
                puts("\nOpcao invalida!");
                break;
        }
    }
}

void printAll(int *arr) {
    int size = sizeof(arr) / sizeof(int);
    if(size || NULL  == 0) // <!-- Verificar se vai dar certo, pode ser que ocorra algum erro de sintax -->
        printf("Vazia!\n"); 
    else
        for(int in = 0; in < size; in++)
            printf("%d", stack[in]);
}

int pop(){
    int elem;
    elem = stack[peek];
    --peek;
    return elem;
}

void push(int num){
    stack[++peek] = num;
}

void binaryConversor(int decNum){
    clearPrompt();

    printf("\n= = = = = = = = = EM CONSTRUCAO = = = = = = = = = =");
}

void QueueQuestion(){
    int opt = NULL;

    while(1){
        clearPrompt();
        printf("Valor da fila:  "); printAll(queue);
        printf("\nO que deseja fazer:\n1 - Inserir valores na fila\n2 - Retirar valores da fila\n0 - Finalizar");
        structureUsed[0] == 1 ? printf("\n3 - Importar valores da pilha (Valores estarão na ordem inversa!)") : printf("");
        
        scanf("%d", &opt);


        switch(opt){
            case 1: // Inserir
            break;
            case 2: // Retirar
            break;
            case 3: // Importar da stack
            break;
            case 0:
                DSQuestion();
            break;
            default:
                printf("\nOpcao invalida...");
            break;
        }
    }
    
}

// Funcao para somar os valores que estao armazenados no array
int arraySum(int *arr){
    int result = 0;
    int arraySize = sizeof(arr) / sizeof(arr[0]);

    for(int ind = 0; ind < arraySize; ind++){
        result += arr[ind];
    }
    return result;
}

//*********************************************************************************************************//

/*********************** Fim da sessao de Modelagem de funcao **********************************************/
