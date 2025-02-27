// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>  
#include <time.h>

struct Item {
    int id;
    char name[50];
    float price;
    int quantity;
}orders[50];
int ordercount = 0,max=50;
int f=0,r=0;

void addItem() {
    if (ordercount >= max) {
        printf("orders is full! cannot add more items.\n");
        return;
    }
    
    printf("Enter Item ID: ");
    scanf("%d", &orders[ordercount].id);

    printf("Enter Item Name: ");
    scanf("%s", orders[ordercount].name);

    printf("Enter Item Price: ");
    scanf("%f", &orders[ordercount].price);

    printf("Enter Item Quantity: ");
    scanf("%d", &orders[ordercount].quantity);

    ordercount++;
    r++;
    printf("Item added successfully!\n");
    
}

void process(){
    if (f < 0) {
        printf("orders is empty!\n");
        return;
    }
    if(f==r){
        f=0;
        r=0;
    }else{
    int y=orders[f].id;
    f++;
    printf("your order is completed,order id:%d\n",y);
    ordercount--;
    }

}


void deleteitem(int id){
    int i,flag=0;
    for(i=0;i<ordercount;i++){
        if(orders[i].id=id){
            flag=1;
            break;
        }
    }
    if(flag == 1) {
        for(int j = i; j < ordercount - 1; j++){
            orders[j] = orders[j + 1];
            
        }
        r--;
        ordercount--;
        printf("Item deleted successfully!\n");
    } else {
        printf("Item not found!\n");
    }
}

void search(int id){
    int i,flag=0;

    printf("ID\tName\tPrice\tQuantity\n");
    for(i=0;i<ordercount;i++){
        if(orders[i].id==id){
            flag=1;
        printf("%d\t%s\t%.2f\t%d\n", orders[i].id, orders[i].name, orders[i].price, orders[i].quantity);
        break;
    }
    }
    if(flag==0){
        printf("item not found\n");
    }
}

void display() {
    if (ordercount == 0) {
        printf("orders is empty!\n");
        return;
    }

    printf("\n Current orders:\n");
    printf("ID\tName\t\tPrice\tQuantity\n");
    printf("------------------------------------\n");

    for (int i = f; i < r; i++) {
        printf("%d\t%s\t\t%.2f\t%d\n", orders[i].id, orders[i].name, orders[i].price, orders[i].quantity);
    }
}



int main() {
    printf("welcome to orders managemnt\n");
    int val,id;

    while (1)
    {
        printf(" 1) insert orders\n 2) delete orders\n 3) serching orders\n 5) display orders\n7) process 6) exit\n ");
        scanf(" %d", &val);

        switch (val)
        {
        case 1:
            addItem();
            break;
        case 2:
            printf("enter id for delete orders\n");
            scanf("%d", &id);
            deleteitem(id);
            break;
        case 3:
            printf("enter id for search orders");
            scanf("%d", &id);
            search(id);
            break;

        case 5:
            display();
            break;
        case 6:
            return 0;
            break;
        case 7:
            process();
            break;
        default:
            printf("invalied");
        }
    }
    


    return 0;
}
