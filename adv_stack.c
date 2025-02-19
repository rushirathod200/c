#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#define MAX_LINES 50
#define MAX_LEN 100

char a[MAX_LINES][MAX_LEN], b[MAX_LINES][MAX_LEN];
int top = 0, c = 0;

void undo() {
    if (top > 0) {
        top--;
        strcpy(b[c], a[top]);
        c++;
        printf("\nUndo successful: Removed \"%s\"\n", b[c - 1]);
    } else {
        printf("\nNothing to undo\n");
    }
}

void handle(int sig) {
    undo();
    printf("\n> ");
    fflush(stdout);
}

int main() {
    char input[MAX_LEN];

    signal(SIGTSTP, handle);

    printf("Enter text (Press Cmd + Z for Undo, type 'exit' to quit):\n");

    while (1) {
        printf("> ");
        
        if (fgets(input, sizeof(input), stdin) == NULL) {  
            continue;
        }

        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, "exit") == 0) {
            break;
        }

        if (top < MAX_LINES) {
            strcpy(a[top], input);
            top++;
            c = 0;
        }
    }

    return 0;
}
