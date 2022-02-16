/**
 * Implementasi ADT Queue (Queue menggunakan Linked List)
 *
 * Dibuat dan ditulis oleh Bayu Laksana
 * -- tanggal 22 Januari 2019
 * Struktur Data 2020
 * Implementasi untuk bahasa C
 *
 * !!NOTE!!
 * cara menggunakan lihat pada fungsi main()
 *
 *
 * Modifikasi program queue untuk menyimpan string
 * - soal 3 modul 1 struktur data 2021
 *
 * Dimodifikasi oleh luthfiyyah hanifah amari
 * -- tanggal 26 maret 2021
 *
 * kolom curhat :
 * Alhamdulillah lancar dan cepat
 *
 */

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#define MAX_STR 100

/* Struktur Node */

typedef struct queueNode_t {
    char data[MAX_STR];
    struct queueNode_t *next;
} QueueNode;

/* Struktur ADT Queue */

typedef struct queue_t {
    QueueNode   *_front,
                *_rear;
    unsigned _size;
} Queue;

/* Function prototype */

void queue_init(Queue *queue);
bool queue_isEmpty(Queue *queue);
void queue_push(Queue *queue, char value[MAX_STR]);
void queue_pop(Queue *queue);
int  queue_front(Queue *queue);
int  queue_size(Queue *queue);

/* Function definition below */

void queue_init(Queue *queue)
{
    queue->_size = 0;
    queue->_front = NULL;
    queue->_rear = NULL;
}

bool queue_isEmpty(Queue *queue) {
    return (queue->_front == NULL && queue->_rear == NULL);
}

void queue_push(Queue *queue, char value[MAX_STR])
{
    QueueNode *newNode = (QueueNode*) malloc(sizeof(QueueNode));
    if (newNode) {
        queue->_size++;
        strcpy(newNode->data, value);
        newNode->next = NULL;

        if (queue_isEmpty(queue))
            queue->_front = queue->_rear = newNode;
        else {
            queue->_rear->next = newNode;
            queue->_rear = newNode;
        }
    }
}

void queue_pop(Queue *queue)
{
    if (!queue_isEmpty(queue)) {
        QueueNode *temp = queue->_front;
        queue->_front = queue->_front->next;
        free(temp);

        if (queue->_front == NULL)
            queue->_rear = NULL;
        queue->_size--;
    }
}

int queue_front(Queue *queue)
{
    if (!queue_isEmpty(queue)) {
        return (queue->_front->data);
    }
    return (int)0;
}

int queue_size(Queue *queue) {
    return queue->_size;
}

int main(int argc, char const *argv[])
{
    // Buat objek QueueArray
    Queue myQueue;

    // PENTING! Jangan lupa diinisialisasi
    queue_init(&myQueue);

    // Operasi pada queue
    queue_push(&myQueue, "bismillah");
    queue_push(&myQueue, "alhamdulillah");
    queue_push(&myQueue, "masya Allah");

    // cetak isi queue
    while (!queue_isEmpty(&myQueue)) {
        printf("%s ", queue_front(&myQueue));
        queue_pop(&myQueue);
    }
    puts("");
    return 0;
}
