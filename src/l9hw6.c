#include <stdio.h>
#include <stdlib.h>

#define QueueSIZE 10


#define T int
#define SIZE 100000
#define true 1 == 1
#define false 1 != 1

typedef int boolean;
int cursor = -1;
T Stack[SIZE];

boolean pushStack(T data) {
    if (cursor < SIZE) {
        Stack[++cursor] = data;
        return true;
    } else {
        printf("%s \n", "Stack overflow");
        return false;
    }
}

T popStack() {
    if (cursor != -1) {
        return Stack[cursor--];
    } else {
        //printf("%s \n", "Stack is empty");
        return -1;
    }
}

typedef struct {
    int priority;
    char data;
} PQ_ITEM;


PQ_ITEM * array[QueueSIZE];
int head;
int tail;
int items; // всего в очереди


#include "print_queue.h"

void printQueue();

void initQueue() {
    for (int i = 0; i < QueueSIZE; ++i) {
        array[i] = NULL;
    }
    head = 0;
    tail = 0;
    items = 0;
}

void toQueue(int priority, char data) {
    PQ_ITEM * pq_item = (PQ_ITEM *) malloc(sizeof(PQ_ITEM));
    pq_item->priority=priority;
    pq_item->data=data;
    if(items == 0) {
      array[tail++] = pq_item;
      items++;
    } 
    else if (items == QueueSIZE) {
        printf("%s \n", "Queue is full");
        return;
    } else {
        int index = 0;
        int i=0;
        for (i = head; i < tail; ++i) {
            index = i%QueueSIZE;
        }
        array[++index] = pq_item;
        items++;
        tail++;
    }
}

void reorder_queue(int index) {
    printf("index of element to remove: %i\n", index);
    for(int i=index;i<=tail;++i){
       if(i<QueueSIZE-1)
            array[i] = array[i+1];
        else break;
    }
    array[tail - 1] = NULL;
    tail--;
}

PQ_ITEM * fromQueue() {
    if (items == 0) {
        return NULL;
    } else {
        
        int index=head;
        int removal_index=index;
        PQ_ITEM * current_pq_item = array[head];
        while(index<tail) {
            if (index == QueueSIZE -1) {
               break;
            }
            if(array[index + 1] !=NULL ) {
               if (current_pq_item->priority < array[index + 1]->priority) {
                   current_pq_item=array[index + 1];
                   removal_index = index + 1;
                }
              index++;
              continue;  
            } else {
                break;
            }
         }
         reorder_queue(removal_index);
         items--;
         return current_pq_item;
    }
    
}

void printQueueItem(PQ_ITEM *item) {
    if (item == NULL)
        printf("[*, *]\n");
    else
        printf("[%d, %c]\n", item->priority, item->data);    
}

// будет корректно работать только на положительных числах
void toBinary(int x) {
   printf("%i in binary:\n",x);
   if (x==0){
       printf("0\n");
       return;
   } else if (x==1) {
       printf("1\n");
       return;
   }
   int to_divide;
   int remainder;
   do {
        to_divide=x/2;
        remainder=x%2;
        pushStack(remainder);
        x=to_divide;
   } while(to_divide !=1);
   pushStack(1);
   int bin = 0;
   while (bin != -1)
   {
       bin=popStack();
       if (bin != -1) 
            printf("%i",bin);
   }
   printf("\n");
}

int main(int argc, char** argv) {

    toBinary(2);
    toBinary(3);
    toBinary(4);
    toBinary(5);
    toBinary(6);

    printf("\npriority for exit in queue:\n");
    // самый большой приоритет выбирает выходящего
    initQueue();
    toQueue(7,'a');
    for(int i=0;i<3;++i) {
        toQueue(6,'b');
        toQueue(5,'c');
        toQueue(4,'d');
    }
    printQueue();
    for(int i=0;i<11;++i) {
        printf("======= Step %i:\n",i);
        printQueue();
        printQueueItem(fromQueue());
        printQueue();
    }

    printQueue();

    return 0;

}
