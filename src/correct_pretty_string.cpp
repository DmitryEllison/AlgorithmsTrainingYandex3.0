#include <iostream>
#include <cstring>
#include <fstream>

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

/**
 * Считываем элемент в очередь и сравниваем i элемент с первым
 * находим для подстроки начиная с первого максимальную длину его "красоты"
 * удаляем первый элемент и продолжаем дальше
 */

int ma_test() {
    queue_t queue;
    clear(&queue);

    /// read K
    int K;
    std::ifstream stream;
    stream.open("./input.txt");
    if (!stream.is_open()) return -1;
    stream >> K;

    int temp_K = K;
    int max = 0;
    int temp_max = 0;
    char char_read;

    /// read string line
    while( stream.get(char_read)) {
        if (char_read == '\n') continue;
        push(&queue, char_read);

        /// if read char is equal first char in queue
        if (elem_at(&queue, 0) == char_read)
            ++temp_max;
        else if (temp_K-- > 0) {
            ++temp_max;
            continue;
        } else {
            max = temp_max > max ? temp_max : max;
            temp_max = 0;
            temp_K = K;
            pop(&queue);

            for (int i = 1; i < K && i < queue.size; ++i) {
                if (elem_at(&queue, 0) == elem_at(&queue, i))
                    ++temp_max;
                else if (temp_K-- > 0) {
                    continue;
                } else {
                    max = temp_max > max ? temp_max : max;
                    temp_max = 0;
                    temp_K = K;
                    pop(&queue);
                    i = 1;
                }
            }
        }
    }
    stream.close();
    return max;
}

int main() {
    printf("%d", ma_test());
}