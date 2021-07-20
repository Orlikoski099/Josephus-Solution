#include "queue.h"

/*Função para criar uma fila vazia (não criar nenhum nó, só devolver NULL)!*/
Queue* create_queue (){
    return NULL;
}

/*Função para liberar uma fila nó por nó!*/
void free_queue (Queue *q) {
    Queue *aux = q;
    while(q != NULL){
        q = q->next;
        free (aux);
    }
}

/*Função para enfileirar um elemento (inserir na cauda da lista encadeada)!*/
Queue* enqueue (Queue *q, int elem) {
    Queue *aux = q;
    Queue *novo = (Queue *)malloc(sizeof(Queue));
    novo->info = elem;
    novo->next = NULL;
    if (q == NULL){
        novo->prv = NULL;
        q = novo;
        return q;
    }
    while(aux->next != NULL){
        aux = aux->next;
    }
    novo->prv = aux;
    aux->next = novo;
    return q;
}

/*Função para desenfileirar um elemento na posição desejada!*/
Queue* dequeue (Queue *q, int pos){
    Queue *aux = q;
    int i;
    if(!empty_queue(q)){
        for(i = 1; i < pos; i++){
            aux = aux->next;
        }
    }

    Queue *aux2 = aux;
    Queue *del = aux;
    aux2 = aux->next;
    aux = aux->prv;
    aux2->prv = aux;
    aux->next = aux2;

    printf("%d - ",del->info);
    free(del);

    return aux2;
}

/*Função para retornar o primeiro elemento da fila (cabeça da lista encadeada) sem desenfileirar!*/
int front (Queue *q) {
    return q->info;
}

/*Função para testar se uma fila está vazia!*/
int empty_queue (Queue *q){
    if(q == NULL){
        printf("Fila vazia!\n");
        return 1;
    }
    return 0;
}
/*Função que linka o começo no fim e o fim no começo!*/
Queue* linkStartEnd(Queue *q){
    Queue *aux = q;
    while(aux->next != NULL){
        aux = aux->next;
    }
    aux->next = q;
    q->prv = aux;
    return q;
}
/*Função para analisar existe apenas uma pessoa viva!*/
int lastOne (Queue *q){
    if(q->next == q){
        return 1;
    }
    return 0;
}

/*Fução que declara o ganhador!*/
void winner(Queue *q){
    printf("O ganhador foi o valor %d\n", front(q));
    free(q);
    exit (0);
}