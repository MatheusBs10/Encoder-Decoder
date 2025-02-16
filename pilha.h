// pilha.h
#ifndef PILHA_H
#define PILHA_H

#include <stddef.h>

// representar um nó na pilha
typedef struct Node {
    char *message;
    struct Node *next;
} Node;

// representar a pilha
typedef struct Stack {
    Node *top;
    int size;
} Stack;

// funções da pilha
Stack *createStack();
int isEmpty(Stack *stack);
void push(Stack *stack, const char *message);
char *pop(Stack *stack);
char *peek(Stack *stack);
void freeStack(Stack *stack);

#endif // PILHA_H
