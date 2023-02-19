#include <cstring>
#include <iostream>
#include <sstream>

#define STACK_MAX_SIZE 100000
typedef int T;

typedef struct STACK_t_CREATE {
    T data[INT16_MAX];
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
    stack_t stack;
    stack.size = 0;

    char temp;
    std::string line;
    std::getline(std::cin, line);
    std::istringstream iss(line);
    while(iss >> temp) {
        if ((int) temp >= 48 && (int) temp <= 57) {
            push(&stack, temp - 48);
        } else if (temp == '+') {
            push(&stack, pop(&stack) + pop(&stack));
        } else if (temp == '-') {
            int b = pop(&stack);
            int a = pop(&stack);
            push(&stack,  a - b);
        } else if (temp == '*') {
            push(&stack, pop(&stack) * pop(&stack));
        } else if (temp == '/') {
            push(&stack, 1. / pop(&stack) * pop(&stack));
        }
    }
    return pop(&stack);
}

int main() {
    printf("%d", ma_test());
}