#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char a[50][50], b[50][50];
int top = 0, c = 0;

void undo() {
    if (top > 0) {
        top--;
        strcpy(b[c], a[top]);
        c++;
        printf("Undo successful: Removed \"%s\"\n", b[c - 1]);
    } else {
        printf("Nothing to undo\n");
    }
}

void dis() {
  
    for (int i = 0; i < top; i++) {
        printf("%s\n", a[i]);
    }
}
void redo(){

        c--;
        strcpy(a[top],b[c]);
        top++;
        printf("redo successful: entered \"%s\"\n", a[top - 1]);
     
}

int main() {
    int val;
    
    while (1) {
        printf("\n1) Enter a string\n2) Undo\n3) Display\n4) Exit\n5) redo\n");
        printf("Choose an option: ");
        scanf("%d", &val);
        getchar();
        

        switch (val) {
            case 1:
                if (top < 50) {
                    printf("Enter a string: ");
                    fgets(a[top], sizeof(a[top]), stdin);
                    a[top][strcspn(a[top], "\n")] = '\0';
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
            case 5:
                redo();
                break;
            default:
                printf("Invalid option, try again.\n");
        }
    }
}
