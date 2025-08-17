// Demo code for a simple stack implementation in C

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STACK_MAX_SIZE 100

typedef struct {
    int items[STACK_MAX_SIZE];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

bool isFull(Stack *s) {
    return s->top == STACK_MAX_SIZE - 1;
}

bool isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, int item) {
    if (isFull(s)) {
        printf("Stack overflow! Cannot push %d\n", item);
        return;
    }
    s->items[++s->top] = item;
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow! Cannot pop from empty stack\n");
        return -1; // Indicating an error
    }
    return s->items[s->top--];
}

int peek(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty! Cannot peek\n");
        return -1; // Indicating an error
    }
    return s->items[s->top];
}

void display(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack contents: ");
    for (int i = 0; i <= s->top; i++) {
        printf("%d ", s->items[i]);
    }
    printf("\n");
}

int main() {
    Stack s;
    initStack(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    display(&s);

    printf("Top item is: %d\n", peek(&s));

    printf("Popped item: %d\n", pop(&s));
    display(&s);

    printf("Popped item: %d\n", pop(&s));
    display(&s);

    printf("Popped item: %d\n", pop(&s));
    display(&s);

    // Attempt to pop from an empty stack
    pop(&s);

    return 0;
}
// End of simple stack implementation in C
// This code demonstrates basic stack operations: push, pop, peek, and display.
// It also handles stack overflow and underflow conditions gracefully.
// The stack is implemented using a fixed-size array for simplicity.
