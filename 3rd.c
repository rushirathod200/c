#include <stdio.h>
#include <stdlib.h>  
#include <time.h>

struct Item {
    int id;
    char name[50];
    float price;
    int quantity;
} orders[50];

int ordercount = 0, max = 50;
int f = 0, r = 0;

void addItem() {
    if (ordercount >= max) {
        printf("\n----------------------------------\n");
        printf(" Orders are full! Cannot add more items.\n");
        printf("----------------------------------\n\n");
        return;
    }

    orders[ordercount].id = ordercount + 100;
    printf("Enter Item Name: ");
    scanf("%s", orders[ordercount].name);

    printf("Enter Item Price: ");
    scanf("%f", &orders[ordercount].price);

    printf("Enter Item Quantity: ");
    scanf("%d", &orders[ordercount].quantity);

    ordercount++;
    r++;

    printf("\n----------------------------------\n");
    printf(" Item added successfully!\n");
    printf("----------------------------------\n\n");
}

void process() {
    if (f < 0) {
        printf("\n----------------------------------\n");
        printf(" Orders are empty!\n");
        printf("----------------------------------\n\n");
        return;
    }
    if (f == r) {
        f = 0;
        r = 0;
    } else {
        int y = orders[f].id;
        f++;
        ordercount--;

        printf("\n----------------------------------\n");
        printf(" Your order has been completed!\n Order ID: %d\n", y);
        printf("----------------------------------\n\n");
    }
}

void deleteitem(int id) {
    int i, flag = 0;
    for (i = 0; i < ordercount; i++) {
        if (orders[i].id == id) {
            flag = 1;
            break;
        }
    }
    if (flag == 1) {
        for (int j = i; j < ordercount - 1; j++) {
            orders[j] = orders[j + 1];
        }
        r--;
        ordercount--;

        printf("\n----------------------------------\n");
        printf(" Item deleted successfully!\n");
        printf("----------------------------------\n\n");
    } else {
        printf("\n----------------------------------\n");
        printf(" Item not found!\n");
        printf("----------------------------------\n\n");
    }
}

void search(int id) {
    int i, flag = 0;

    printf("\n----------------------------------\n");
    printf(" ID\tName\t\tPrice\tQuantity\n");
    printf("----------------------------------\n");

    for (i = 0; i < ordercount; i++) {
        if (orders[i].id == id) {
            flag = 1;
            printf(" %d\t%s\t\t%.2f\t%d\n", orders[i].id, orders[i].name, orders[i].price, orders[i].quantity);
            break;
        }
    }
    if (flag == 0) {
        printf("\n Item not found!\n");
    }

    printf("----------------------------------\n\n");
}

void display() {
    if (ordercount == 0) {
        printf("\n----------------------------------\n");
        printf(" Orders are empty!\n");
        printf("----------------------------------\n\n");
        return;
    }

    printf("\n----------------------------------\n");
    printf(" Current Orders:\n");
    printf(" ID\tName\t\tPrice\tQuantity\n");
    printf("----------------------------------\n");

    for (int i = f; i < r; i++) {
        printf(" %d\t%s\t\t%.2f\t%d\n", orders[i].id, orders[i].name, orders[i].price, orders[i].quantity);
    }

    printf("----------------------------------\n\n");
}

int main() {
    printf("\n==================================\n");
    printf("     Welcome to Order Management   ");
    printf("\n==================================\n");

    int val, id;

    while (1) {
        printf("\n----------------------------------\n");
        printf(" 1) Insert Order\n 2) Delete Order\n 3) Search Order\n 5) Display Orders\n 7) Process Order\n 6) Exit\n");
        printf("----------------------------------\n");
        printf(" Enter your choice: ");
        scanf("%d", &val);

        switch (val) {
            case 1:
                addItem();
                break;
            case 2:
                printf("\nEnter ID to delete order: ");
                scanf("%d", &id);
                deleteitem(id);
                break;
            case 3:
                printf("\nEnter ID to search order: ");
                scanf("%d", &id);
                search(id);
                break;
            case 5:
                display();
                break;
            case 6:
                printf("\n Exiting the program...\n");
                return 0;
            case 7:
                process();
                break;
            default:
                printf("\n Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
