#pragma once

void printQueue() {
    int i=0;
    printf("head:\n");
    for (i = 0; i < head; ++i) {
      printf("-");
    }
    printf(">(%i)\n",head);

    printf("[ ");
    for (i = 0; i < QueueSIZE; ++i) {
        if (array[i] == NULL)
            printf("[*, *] ");
        else
            printf("[%d, %c] ", array[i]->priority, array[i]->data);
    }
    printf(" ]\n");

    printf("tail:\n");
    for (i = head; i < tail; ++i) {
      printf("-");
    }
    printf(">(%i)\n",tail);

}

