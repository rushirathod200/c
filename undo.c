#include <stdio.h>
#include <stdlib.h>

char a[50], b[50];
int top = 0, c = 0;

void undo() {
    if (top > 0) {
        top--;
        b[c] = a[top];
        c++;
        printf("Undo successful\n");
    } else {
        printf("Nothing to undo\n");
    }
}

void dis() {
    int i;
    for (i = 0; i < top; i++) {
        printf("%c", a[i]);
    }
}

int main() {
    int val;
    
    while (1) {
        printf("1) enter value\n2) undo\n3) display\n4) exit\n");
        scanf("%d", &val);
    
        switch (val) {
            case 1:
                if (top < 50) {
                    printf("Enter a character\n");
                    scanf(" %c", &a[top]);
                    top++;
                } else {
                    printf("Array is full\n");
                }
                break;
            case 2:
                undo();
                break;
            case 3:
                dis();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid option\n");
        }
    }
}

