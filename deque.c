#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "deque.h"

// cria um deque vazio
Deque *createDeque() {
    Deque *deque = (Deque *)malloc(sizeof(Deque));
    if (!deque) {
        perror("Não foi possível alocar memória para o deque");
        exit(EXIT_FAILURE);
    }
    deque->front = deque->rear = NULL;
    deque->size = 0;
    return deque;
}

// testa se o deque está vazio
int isEmptyDeque(Deque *deque) {
    return deque->size == 0;
}

// Insere uma mensagem no início do deque
void pushFront(Deque *deque, const char *message) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode) {
        perror("Não foi possível alocar memória para o nó");
        exit(EXIT_FAILURE);
    }
    newNode->message = (char *)malloc(strlen(message) + 1);
    if (!newNode->message) {
        perror("Não foi possível alocar memória para a mensagem");
        free(newNode);
        exit(EXIT_FAILURE);
    }
    strcpy(newNode->message, message);
    newNode->next = deque->front;
    newNode->prev = NULL;

    if (isEmptyDeque(deque)) {
        deque->front = deque->rear = newNode;
    } else {
        deque->front->prev = newNode;
        deque->front = newNode;
    }
    deque->size++;
}

// insere uma mensagem no final do deque
void pushRear(Deque *deque, const char *message) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode) {
        perror("Não foi possível alocar memória para o nó");
        exit(EXIT_FAILURE);
    }
    newNode->message = (char *)malloc(strlen(message) + 1);
    if (!newNode->message) {
        perror("Não foi possível alocar memória para a mensagem");
        free(newNode);
        exit(EXIT_FAILURE);
    }
    strcpy(newNode->message, message);
    newNode->next = NULL;
    newNode->prev = deque->rear;

    if (isEmptyDeque(deque)) {
        deque->front = deque->rear = newNode;
    } else {
        deque->rear->next = newNode;
        deque->rear = newNode;
    }
    deque->size++;
}

// remove e retorna a mensagem no início do deque
char *popFront(Deque *deque) {
    if (isEmptyDeque(deque)) {
        printf("O deque está vazio.\n");
        return NULL;
    }
    Node *temp = deque->front;
    char *message = temp->message;
    deque->front = temp->next;

    if (deque->front) {
        deque->front->prev = NULL;
    } else {
        deque->rear = NULL;
    }
    free(temp);
    deque->size--;
    return message;
}

// Remove e retorna a mensagem no final do deque
char *popRear(Deque *deque) {
    if (isEmptyDeque(deque)) {
        printf("O deque está vazio.\n");
        return NULL;
    }
    Node *temp = deque->rear;
    char *message = temp->message;
    deque->rear = temp->prev;

    if (deque->rear) {
        deque->rear->next = NULL;
    } else {
        deque->front = NULL;
    }
    free(temp);
    deque->size--;
    return message;
}

// retorna a mensagem no início do deque sem removê-la
char *peekFront(Deque *deque) {
    if (isEmptyDeque(deque)) {
        printf("O deque está vazio.\n");
        return NULL;
    }
    return deque->front->message;
}

// retorna a mensagem no final do deque sem removê-la
char *peekRear(Deque *deque) {
    if (isEmptyDeque(deque)) {
        printf("O deque está vazio.\n");
        return NULL;
    }
    return deque->rear->message;
}

// libera a memória alocada para o deque
void freeDeque(Deque *deque) {
    while (!isEmptyDeque(deque)) {
        char *message = popFront(deque);
        free(message);
    }
    free(deque);
}
