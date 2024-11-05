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

*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000


/******************************** Sessao de prototipacao ****************************************************/
// Globais
void DSQuestion();
void RandomizeArray();
void sortQuestion();
void structQuestion();

// stack, queue, list [0 -> false, 1 -> true]
int structureUsed[] = {0, 0, 0};

int strUsdLength = sizeof(structureUsed) / sizeof(structureUsed[0]);
int arraySum(int arr[]);

// Sessao pilha
void StackQuestion();

// Sessao fila
void QueueQuestion();

// Sessao lista
void listQuestion();

//--------------------Big O Notation----------------
int comp, trocas;
void compareSort();

//---------------------------------------------------

// Sessao bubble sort
void initBuble();

// Sessao selection sort
void initSelection();


/*************************** Fim da sessao de prototipacao **************************************************/

/************************************* Sessao de Main *******************************************************/

int main() {
	DSQuestion();
}

/******************************** Fim da sessao de Main *****************************************************/

/**************************** Sessao de Modelagem de funcao ************************************************/
void DSQuestion(){
	comp = 0, trocas = 0;
    int option = 0;
    puts("==========================");
    puts("Bem vindo ao programa!");
    printf("\n\nPara iniciarmos digite a opcao que preferir\n1) Lista\n2) Fila\n3) Pilha\n4) Ordenacao de dados\n5) Sair...\n");
    scanf("%d", &option);
    switch (option) {
        case 1: // Lista
            structureList();
            break;
        case 2: // Fila
            structureQueue();
            break;
        case 3: // Pilha
            structureStack();
            break;
        case 4: // Ordenacao de dados
            structQuestion();
            break;
        case 5: // Sair
            exit(0);
            break;
        default:
            printf("Opcao invalida...\n");
            break;
    }
}

void structQuestion(){
    int strUsed = arraySum(structureUsed);
    int opt = 0;

    while(1){
        system("cls") || system("clear");
        printf("\nIremos organizar seus dados com o algoritmo de sua preferencia, mas primeiro escolha qual das estrutura deseja organizar:\n");
        if(structureUsed[0]){
            printf("1 - Pilha\n");
            scanf("%d", &opt);
        }else if(structureUsed[1]){
            printf("2 - Fila\n");
            scanf("%d", &opt);
        }else if(structureUsed[2]){
            printf("3 - Lista\n");
            scanf("%d", &opt);
        }
        printf("4 - Um vetor com 1,000 numeros aleatorios\n5 - Sair...");
        scanf("%d", &opt);
        
        switch(opt){
            case 1: // Stack
                if (structureUsed[0] == 1)
                    sortQuestion(0);
                else
                    printf("Opcao invalida!\n");
                break;
            case 2: // Queue
                if (structureUsed[1] == 1)
                    sortQuestion(1);
                else
                    printf("Opcao invalida!\n");
                break;
            case 3: // List
                if (structureUsed[2] == 1)
                    sortQuestion(2);
                else
                    printf("Opcao invalida!\n");
                break;
            case 4: // sort numbers
                break;
            case 5: // Done
                exit(0);
            default:
                printf("Opcao invalida!\n");
                break;
        }
    }
}

void sortQuestion(int strChose){
    int opt = strChose;
    int chose;

    // Aqui a intencao eh criar um array auxiliar que ira armazenar as informacoes de acordo com a escolha de estrutura do usuario
    // Nao ha valor default porque ira receber da structQuestion (Precisa verificar se uma func void pode ser recursivaw)
    switch (opt)
    {
    case 0: //Stack
        break;
    case 1: // Queue
        break;
    case 2: // List
        break;
    case 3: // random numbers
        break;
    }


    while(10){
        printf("\nEscolha como devemos organizar esta estrutura:\n1 - Bubble sort\n2 - Selection sort\n3 - Comparar ambos\n4 - Voltar...");
        scanf("%d", chose);

        switch(chose){
            case 1:
                initBuble();
                break;
            case 2:
                initSelection();
                break;
            case 3:
                compareSort();
                break;
            case 4:
                structQuestion();
                break;
            default:
                printf("\nOpcao invalida...");
                break;
        }
    }
}

// Funcao para somar os valores que estao armazenados no array
int arraySum(int arr[]){
    int result = 0;
    for(int ind = 0; ind < strUsdLength; ind++){
        result += arr[ind];
    }
    return result;
}

/*********************** Fim da sessao de Modelagem de funcao **********************************************/
