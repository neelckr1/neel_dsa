#include <stdio.h>

#define MAX_LEN 10

typedef struct QUEUE{
    int ITEM[MAX_LEN];
    int rear;
    int front;
}queue;

void init_queue(queue *q){
    q->rear = -1;
    q->front = 0;
    printf("Queue has been initialized\n");
}

void enqueue(queue *q, int item){
    if(q->rear == MAX_LEN - 1){
        printf("QUEUE OVERFLOW\n");
    }else{
        q->ITEM[++(q->rear)] = item;
        printf("item: %d has been queued.\n",item);
    }
}

void display_queue(queue *q){
    if(q->rear == -1){
        printf("QUEUE UNDERFLOW\n");
    }else{
        int i = 0;
        while(i <= q->rear){
            printf("%d ",q->ITEM[i]);
            i++;
        }
        printf("\n");
    }
}

// void dequeue(queue *q)

int main(){
    queue q;
    init_queue(&q);

    enqueue(&q,1);

    enqueue(&q,2);

    display_queue(&q);




    return 0;
}