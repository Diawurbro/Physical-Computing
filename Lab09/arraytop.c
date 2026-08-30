#include <stdio.h>
#include <stdlib.h>

void push_stack(char **stack, unsigned int *stack_size, int stack_capacity, char *input) {
    if (*stack_size >= (unsigned int) stack_capacity) {
        printf("ERROR: Stack Overflow\n");
        return;
    }

    char *p = input;
    int len = 0;
    while (*p != '\0') {
        len++;
        p++;
    }

    char *copy = (char *) malloc((len + 1) * sizeof(char));

    char *src = input;
    char *dst = copy;
    while (*src != '\0') {
        *dst = *src;
        src++;
        dst++;
    }
    *dst = '\0';

    *(stack + *stack_size) = copy;

    (*stack_size)++;
}

char* pop_stack(char **stack, unsigned int *stack_size) {
    if (*stack_size == 0) {
        printf("ERROR: Stack Underflow\n");
        return NULL;
    }

    (*stack_size)--;

    char *top = *(stack + *stack_size);

    return top;
}

char* get_stack_top(char **stack, unsigned int stack_size) {
    if (stack_size == 0) {
        printf("ERROR: Stack Underflow\n");
        return NULL;
    }

    char *top = *(stack + stack_size - 1);

    return top;
}

void print_stack(char **stack, unsigned int stack_size) {
    if (stack_size == 0) {
        printf("Stack is empty\n");
        return;
    }
    for (unsigned int i = 0; i < (stack_size) - 1; i++)
        printf("%s -> ", stack[i]);
    printf("%s\n", stack[stack_size - 1]);
}

int main() {
    unsigned int stack_capacity, stack_size = 0;
    scanf("%u", &stack_capacity);
    char **stack = (char**) malloc(sizeof(char*) * stack_capacity);
 
    char command, temp[101], *return_temp;
    while (1) {
        scanf(" %c: %[^\n]", &command, temp);
 
        if (command == 'q')
            break;
        else if (command == 'w')
            push_stack(stack, &stack_size, stack_capacity, temp);
        else if (command == 'p') {
            return_temp = pop_stack(stack, &stack_size);
            if (return_temp) {
                printf("Pop returns: %s\n", return_temp);
                free(return_temp);
            }
        }
        else if (command == 's')
            print_stack(stack, stack_size);
        else if (command == 't') {
            return_temp = get_stack_top(stack, stack_size);
            if (return_temp)
                printf("Stack Top: %s\n", return_temp);
        }
        else if (command == 'n')
            printf("Stack Size: %u\n", stack_size);
        else
            printf("ERROR: Invalid Command\n");
 
    }
    print_stack(stack, stack_size);
}