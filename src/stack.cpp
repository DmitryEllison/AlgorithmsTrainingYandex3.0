#include <iostream>
#include <cstdio>
#include <cstring>

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
    stack_t stack;
    stack.size = 0;

    std::string line;
    int temp;

    while (true) {
        /// Парсер команд
        std::cin >> line;

        if (line == "push"){
            std::cin >> temp;
            push(&stack, temp);
            printf("ok\n");
        } else if (line == "pop") {
            if (is_empty(&stack))
                printf("error\n");
            else
                printf("%d\n", pop(&stack));
        } else if ( line == "back") {
            if (is_empty(&stack))
                printf("error\n");
            else
                printf("%d\n", back(&stack));
        } else if ( line =="size") {
            printf("%zu\n", size(&stack));
        } else if ( line =="clear") {
            clear(&stack);
            printf("ok\n");
        } else if (line =="exit") {
            printf("bye");
            break;
        }
    }

}