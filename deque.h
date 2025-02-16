#ifndef DEQUE_H
#define DEQUE_H

#include <stddef.h>

//  representa um nó no deque
typedef struct Node {
    char *message;
    struct Node *next;
    struct Node *prev;
} Node;

// representa o deque
typedef struct Deque {
    Node *front;
    Node *rear;
    int size;
} Deque;

// Declarações das funções
Deque *createDeque();
int isEmptyDeque(Deque *deque);
void pushFront(Deque *deque, const char *message);
void pushRear(Deque *deque, const char *message);
char *popFront(Deque *deque);
char *popRear(Deque *deque);
char *peekFront(Deque *deque);
char *peekRear(Deque *deque);
void freeDeque(Deque *deque);

#endif // DEQUE_H
