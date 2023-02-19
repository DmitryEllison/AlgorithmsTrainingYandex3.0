#include <iostream>
#include <cstdio>
#include <cstring>

#define QUEUE_CAPACITY 16364
typedef int T;

typedef struct MA_QUEUE {
    T data[QUEUE_CAPACITY];
    size_t size;
    size_t first;
    size_t last;
} queue_t;

bool push(queue_t* queue, T elem) {
    /// Добавить в очередь число elem.
    if (queue->size >= QUEUE_CAPACITY) return false;
    queue->data[++queue->last % QUEUE_CAPACITY] = elem;
    ++queue->size;
    return true;
}

T pop(queue_t* queue) {
    /// Удалить из очереди первый элемент.
    if (queue->size == 0) return NULL;
    --queue->size;
    return queue->data[queue->first++ % QUEUE_CAPACITY];
}

T front(queue_t* queue) {
    /// Программа должна вывести значение первого элемента, не удаляя его из очереди.
    if (queue->size == 0) return NULL;
    return queue->data[queue->first % QUEUE_CAPACITY];
}

size_t size(queue_t* queue) {
    return queue->size;
}

bool is_empty(queue_t* queue) {
    return queue->size == 0;
}

bool clear(queue_t* queue) {
    /// Программа должна очистить очередь.
    queue->size = 0;
    queue->last = -1;
    queue->first = 0;
    return true;
}

int ma_test() {
    queue_t queue;
    clear(&queue);

    std::string line;
    int temp;

    while (true) {
        /// Парсер команд
        std::cin >> line;

        if (line == "push"){
            std::cin >> temp;
            push(&queue, temp);
            printf("ok\n");
        } else if (line == "pop") {
            if (is_empty(&queue))
                printf("error\n");
            else
                printf("%d\n", pop(&queue));
        } else if ( line =="size") {
            printf("%zu\n", size(&queue));
        } else if ( line =="front") {
            if (is_empty(&queue))
                printf("error\n");
            else
                printf("%d\n", front(&queue));
        } else if ( line =="clear") {
            clear(&queue);
            printf("ok\n");
        } else if (line =="exit") {
            printf("bye");
            break;
        }
    }
    return 0;
}

int main() {
    return ma_test();
}
