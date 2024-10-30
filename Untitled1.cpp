/*
  Name: Organizator.cpp
  Author: Lucas Oliveira
  Date: 20/oct/2024
  Description: Algoritmo utilizado para demonstrar como diferentes estruturas de dados funcionam, aqui mexeremos com pilha, fila e lista encadeada. Tambem contaremos com o algoritmo bubble sort para organizar 1,000 numeros.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/************************ SESSAO DE PROTOTIPACAO *************************************/
// Sessao publica
void DSSelector();
int size = 0;

void structureList();
void structureStack();
void structureQueue();

// Sessao stack
void push(int);
int pop();
int isFull_Stack();
int isEmpty_Stack();
void printStack();
int stack_top();
void conversorBinario(int);
void exibirNumBinario();

int topo = -1;
int pilha[10];

// Sessao queue
void pushQueue(int);
int popQueue();
int isEmpty_Queue();
int isFull_Queue();
void printAllQueue();

int inicio, fim, total;
int senhas[5];

// Sessao linked list
typedef struct No {
    char *nome;
    int idade;
    float altura;
    struct No *prox;
} No;

typedef struct {
    No *inicio, *fim;
    int tamanho;
} Lista;

Lista lista;

void init_list();
void inserir_inicio_lista(Lista *lista, char *n, int ida, float alt);
void inserir_fim_lista(Lista *lista, char *n, int ida, float alt);
void imprimir_lista(Lista *lista);
void remover_no_lista(Lista *lista, int ida);

// Sessao bubble sort
void sortearNumeros(int num[1000]);
void initBubbleSort();

/******************* FIM DA SESSAO DE PROTOTIPACAO ***********************************/


/********************************* SESSAO MAIN ***************************************/
int main() {
    while (1) {
        //system("cls") || system("clear");
        DSSelector();
    }
    return 0;
}

/**************************** FIM DA SESSAO MAIN *************************************/


/********************** SESSAO DE MODELAGEM DE FUNCAO ********************************/
// Funcao para selecionar a estrutura de dados que deseja mexer
void DSSelector() {
    int option = 0;
    puts("==========================");
    puts("Bem vindo ao programa!");
    printf("\n\nPara iniciarmos digite a opcao que preferir\n1) Lista\n2) Fila\n3) Pilha\n4) Ordenacao de dados\n5) Sair...\n");
    scanf("%d", &option);
    switch (option) {
        case 1:
            structureList();
            break;
        case 2:
            structureQueue();
            break;
        case 3:
            structureStack();
            break;
        case 4:
            initBubbleSort();
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("Opcao invalida...\n");
            break;
    }
}

void structureList(){
    int opcao, elem;
    while (1) {
        printf("\n1) Enfileirar\n2) Desenfileirar\n3) Imprimir fila\n4) Voltar\n");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                printf("Elemento: ");
                scanf("%d", &elem);
                pushQueue(elem);
                break;
            case 2:
                popQueue();
                break;
            case 3:
                printAllQueue();
                break;
            case 4:
                return;
            default:
                printf("Opcao invalida...\n");
                break;
        }
    }
}
void structureQueue(){

    inicio = 0;
    fim = 0;
    total = 0;

     int e;
     while(1){

        //system("cls") || system("clear");
        int opcao = 0;
        printf("1 - Inserir na Fila\n2 - Retirar na Fila\n3 - Exibir Fila\n4 - SAIR");
        printf("\nOpcao: ");
        scanf("%d", &opcao);

        switch(opcao){

        case 1: 
         e = 0;
         printf("digite um elemento na fila");
         scanf("%d", &e);
         pushQueue(e);
         break;

        case 2: 
         popQueue();
         break;

        case 3:
         printAllQueue();
         getchar();
         break;

         case 4:
          exit(0);

        default:
         puts("opcao invalida");

        }//fim do switch

     }//fim while

}// fim structureQueue

void structureStack() {
    int elem;
    char e;
    while(1){
        int menu = 0;
        printf("1 - Inserir na pilha\n2 - Retirar da pilha\n3 - Exibir a pilha\n4 - Conversor binario\n5 - Finalizar");
        printf("\nOpcao:	");
        scanf("%d", &menu);

        switch(menu){
            case 1: 
                e = ' ';
                printf("Digite um caracter que deseja inserir na pilha:	");
                scanf(" %c", &e);//Espaço antes do %c é para acumular o enter do teclado
                break;
            case 2: 
                pop();
                break;
            case 3:
                printStack();
                break;
            case 4: 
                elem = 0;
                printf("Digite um numero inteiro para converter em binario:	");
                scanf("%d", &elem);
                conversorBinario(elem);
                break;
            case 5:
                exit(0);
            default:
                puts("\nOpcao invalida!");
                break;
        }//Fim do switch
    }//Fim do while
}//Fim structureStack

void push(int letra){
    if(isFull_Stack() == 1)
        puts("\nA pilha esta cheia! - Stack Overflow");
    else{
        topo++;
        pilha[topo] = letra;
    }
}//Fim push

int pop(){
    if(isEmpty_Stack() == 1)
        puts("==============> A pilha esta vazia!!");
    else{
        int elem;
        elem = pilha[topo];
        topo--;
        return elem;
    }
}//Fim pop

int isFull_Stack(){
    if(topo == 9)
        return 1;
    else
        return 0;
}//Fim isFull

int isEmpty_Stack(){
    if(topo == -1)
        return 1;
    else
        return 0;
}//Fim isEmpty

int stack_top(){
    return pilha[topo];
}

void printStack(){
    puts("\nConteudo da pilha:	");
    if(isEmpty_Stack() == 1)
        puts("\nPilha esta vazia!");
    else
        for(int i = 0; i <= topo; i++)
            printf("%d ", pilha[i]);
}

void conversorBinario(int numBaseDez){
    int quoc, resto;

    while(numBaseDez >= 2){
        quoc = numBaseDez/2;
        resto = numBaseDez-(quoc * 2);
        push(resto);
        numBaseDez = quoc;
    }
    push(numBaseDez);
    exibirNumBinario();
}

void exibirNumBinario() {
    puts("Equivalente binario:	");
    while(isEmpty_Stack() == 0){
        printf("%d", pop());
    }
    printf("\n\n");
}

void pushQueue(int elem){
    if(isFull_Queue() == 1){
     puts("A fila esta cheia");
     getchar();
    }

    else{
        senhas[fim] = elem;
        fim = (fim+1)%5;
        total++;

        //printf("digite um numero para entrar na fila")
    }

}

int popQueue(){

    if(isEmpty_Queue() == 1){
     puts("fila vazia");
     getchar();
    }

    else
    {
        int elemento; 
        elemento = senhas[inicio]; 
        inicio = (inicio+1)%5; 
        total--; 
        return elemento;
    }
}

int isEmpty_Queue(){

    if(total == 0)//true
    return 1;
    else 
    return 0; //false

}

int isFull_Queue(){
   if(total == 5)
   return 1;
   else
   return 0;
}

void printAllQueue(){
    int cont, i;

      puts("\nConteudo da fila");

    for(cont=0, i=inicio; cont<total; cont++)
    {
      printf("%d|", senhas[i++]);
    if(i == 5)
      i = 0;	
    }
}

void init_list() {
    lista.inicio = NULL;
    lista.fim = NULL;
    lista.tamanho = 0;
}

void inserir_inicio_lista(Lista *lista, char *n, int ida, float alt) {
    No *novo = (No *)malloc(sizeof(No));
    novo->nome = n;
    novo->idade = ida;
    novo->altura = alt;
    novo->prox = lista->inicio;
    lista->inicio = novo;
    if (lista->fim == NULL) {
        lista->fim = novo;
    }
    lista->tamanho++;
}

void inserir_fim_lista(Lista *lista, char *n, int ida, float alt) {
    No *novo = (No *)malloc(sizeof(No));
    novo->nome = n;
    novo->idade = ida;
    novo->altura = alt;
    novo->prox = NULL;
    if (lista->fim) {
        lista->fim->prox = novo;
    } else {
        lista->inicio = novo;
    }
    lista->fim = novo;
    lista->tamanho++;
}

void imprimir_lista(Lista *lista) {
    No *atual = lista->inicio;
    while (atual) {
        printf("Nome: %s, Idade: %d, Altura: %.2f\n", atual->nome, atual->idade, atual->altura);
        atual = atual->prox;
    }
}

void remover_no_lista(Lista *lista, int ida) {
    No *atual = lista->inicio;
    No *anterior = NULL;
    while (atual && atual->idade != ida) {
        anterior = atual;
        atual = atual->prox;
    }
    if (atual) {
        if (anterior) {
            anterior->prox = atual->prox;
        } else {
            lista->inicio = atual->prox;
        }
        if (atual == lista->fim) {
            lista->fim = anterior;
        }
        free(atual);
        lista->tamanho--;
    }
}


void sortearNumeros(int num[1000]) {
    srand(time(NULL));
    for (int i = 0; i < 1000; i++) {
        num[i] = rand() % 1000;
    }
}

void initBubbleSort() {
    int num[1000];
    sortearNumeros(num);
    for (int i = 0; i < 1000 - 1; i++) {
        for (int j = 0; j < 1000 - i - 1; j++) {
            if (num[j] > num[j + 1]) {
                int temp = num[j];
                num[j] = num[j + 1];
                num[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < 1000; i++) {
        printf("%d ", num[i]);
    }
    printf("\n");
}

/***************** FIM DA SESSAO DE MODELAGEM DE FUNCAO ******************************/