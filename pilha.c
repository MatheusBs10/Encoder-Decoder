#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

// cria uma pilha
Stack *createStack() {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    if (!stack) {
        perror("Não foi possível alocar memória para a pilha");
        exit(EXIT_FAILURE);
    }
    stack->top = NULL;
    stack->size = 0;
    return stack;
}

// verifica se a pilha está vazia
int isEmpty(Stack *stack) {
    return stack->top == NULL;
}

// insere uma mensagem na pilha
void push(Stack *stack, const char *message) {
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
    newNode->next = stack->top;
    stack->top = newNode;
    stack->size++;
}

// remove uma mensagem da pilha
char *pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("A pilha está vazia.\n");
        return NULL;
    }
    Node *temp = stack->top;
    char *message = temp->message;
    stack->top = temp->next;
    free(temp);
    stack->size--;
    return message;
}

// consulta a mensagem no topo da pilha sem removê-la
char *peek(Stack *stack) {
    if (isEmpty(stack)) {
        printf("A pilha está vazia.\n");
        return NULL;
    }
    return stack->top->message;
}

// libera a memória alocada pela pilha
void freeStack(Stack *stack) {
    while (!isEmpty(stack)) {
        char *message = pop(stack);
        free(message);
    }
    free(stack);
}
