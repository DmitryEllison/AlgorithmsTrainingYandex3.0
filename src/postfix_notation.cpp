#include <cstring>
#include <iostream>

#define STACK_MAX_SIZE 64
typedef int T;

typedef struct STACK_t_CREATE {
    T data[STACK_MAX_SIZE];
    size_t size;
} stack_t;

void push(stack_t* stack, T n) {
    /// Добавить в стек число n (значение n задается после команды). Программа должна вывести ok.
    stack->data[stack->size] = n;
    stack->size += 1;
}

T pop(stack_t* stack) {
    /// Удалить из стека последний элемент. Программа должна вывести его значение.
    if (stack->size > 0)
        return stack->data[stack->size-- - 1];
}

T back(stack_t* stack) {
    /// Программа должна вывести значение последнего элемента, не удаляя его из стека.
    if (stack->size > 0)
        return stack->data[stack->size-1];
}

size_t size(stack_t* stack) {
    /// Программа должна вывести количество элементов в стеке.
    return stack->size;
}

void clear(stack_t* stack) {
    /// Программа должна очистить стек и вывести ok.
    stack->size = 0;
}

bool is_empty(stack_t* stack) {
    return stack->size == 0;
}

int ma_test() {

}

int main() {
    return 0;
}