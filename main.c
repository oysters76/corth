#define COMMAND_SIZE 100
#define NUMERIC_SIZE 20
#define PROGRAM_SIZE 100

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int check_int(char c) {
  return c >= 48 && c <= 57;
}

int check_token(char c) {
  return c == '+' || c == '-' || c == '.';
}

void push(int * stack, int num, int * pointer) {
  stack[*pointer] = num;
  *pointer = *pointer + 1;
}

int pop(int * stack, int * pointer) {
  int i = *pointer - 1;
  int p = stack[i];
  stack[i] = -1;
  *pointer = i;
  return p;
}

void usage(){
    printf("Welcome to corth!\n");
    printf("30 50 + . -> prints 80\n"); 
    printf("50 50 - . -> prints 0\n"); 
    printf("100 100 + . 200 150 - . -> prints 200 50\n"); 
    printf("type 'quit' or 'q' to quit anytime! :)\n");
}

int main(void) {
  while (1) {
    int program_stack[PROGRAM_SIZE];
    int p_pointer = 0;
    char command[COMMAND_SIZE];
    printf(">> ");
    fgets(command, COMMAND_SIZE, stdin);
    if ((strlen(command) > 0) && (command[strlen(command) - 1] == '\n'))
      {
        command[strlen(command) - 1] = '\0';
        if (strcmp(command, "quit") == 0 || strcmp(command, "q") == 0){
            break;
        }else if (strcmp(command, "help") == 0){
            usage();
            continue;
        }
      }
    int c_size = strlen(command);
    int is_int = 0;
    char numeric[NUMERIC_SIZE] = {
      '\0'
    };
    for (int i = 0; i < c_size; i++) {
      char c = command[i];
      if (check_int(c)) {
        char src[] = {
          c,
          '\0'
        };
        strcat(numeric, src);
      } else {
        if (check_token(c)) {
          if (c == '-' || c == '+') {
            int op1 = pop(program_stack, &p_pointer);
            int op2 = pop(program_stack, &p_pointer);
            int r = -1;
            if (c == '-') {
              r = op2 - op1;
            } else {
              r = op2 + op1;
            }
            push(program_stack, r, &p_pointer);
          } else if (c == '.') {
            int op = pop(program_stack, &p_pointer);
            printf("%d\n", op);
          }
        }
        if (strlen(numeric) > 0) {
          int p = atoi(numeric);
          numeric[0] = '\0';
          push(program_stack, p, &p_pointer);
        }
      }
    }
  }
  return 0;
}