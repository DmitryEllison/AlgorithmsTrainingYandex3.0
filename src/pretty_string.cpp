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

bool in_compact(char a, char b, int k) {
    return (b >= a - k) && (b <= a + k);
}

int ma_test() {
    queue_t queue;
    clear(&queue);

    /// read K
    int K;
    std::cin >> K;

    int max = 0;
    int temp_max = 0;

    /// read string line
    for( char char_read = getchar(); char_read = std::getchar(), char_read != '\n'; ) {
        push(&queue, char_read);

        if (in_compact(elem_at(&queue, 0), char_read, K))
            ++temp_max;
        else {
            max = temp_max > max ? temp_max : max;
            temp_max = 0;
            pop(&queue);

            for (int i = 1; i < K && i < queue.size; ++i) {
                if (in_compact(elem_at(&queue, 0), elem_at(&queue, i), K))
                    ++temp_max;
                else {
                    max = temp_max > max ? temp_max : max;
                    temp_max = 0;
                    pop(&queue);
                    i = 1;
                }
            }
        }
    }
    return max;
}

int main() {
    printf("%d", ma_test());
}