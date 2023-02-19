#include <iostream>
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
    if (queue->size != 0) {
        --queue->size;
        return queue->data[queue->first++ % QUEUE_CAPACITY];
    }
}

/// очередь ибо FIFO сохраняется =)
T elem_at(queue_t* queue, size_t index) {
    /// Программа должна вывести значение элемента под индексом, не удаляя его из очереди.
    if (queue->size != 0 && index < QUEUE_CAPACITY)
        return queue->data[queue->first + index % QUEUE_CAPACITY];
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
