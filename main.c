// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>  
#include <time.h>

struct Item {
    int id;
    char name[50];
    float price;
    int quantity;
}inventory[50];
int itemcount = 0,max=50;

void addItem() {
    if (itemcount >= max) {
        printf("Inventory is full! cannot add more items.\n");
        return;
    }


    printf("Enter Item ID: ");
    scanf("%d", &inventory[itemcount].id);

    printf("Enter Item Name: ");
    scanf("%s", inventory[itemcount].name);

    printf("Enter Item Price: ");
    scanf("%f", &inventory[itemcount].price);

    printf("Enter Item Quantity: ");
    scanf("%d", &inventory[itemcount].quantity);

    itemcount++;
    printf("Item added successfully!\n");
}


void deleteitem(int id){
    int i,flag=0;
    for(i=0;i<itemcount;i++){
        if(inventory[i].id=id){
            flag=1;
            break;
        }
    }
    if(flag == 1) {
        for(int j = i; j < itemcount - 1; j++){
            inventory[j] = inventory[j + 1];  
        }
        itemcount--;
        printf("Item deleted successfully!\n");
    } else {
        printf("Item not found!\n");
    }
}

void search(int id){
    int i,flag=0;

    printf("ID\tName\tPrice\tQuantity\n");
    for(i=0;i<itemcount;i++){
        if(inventory[i].id==id){
            flag=1;
        printf("%d\t%s\t%.2f\t%d\n", inventory[i].id, inventory[i].name, inventory[i].price, inventory[i].quantity);
        break;
    }
    }
    if(flag==0){
        printf("item not found\n");
    }
}
void Update(int id){
    int i,ch,found=0;
    
    for(i=0;i<itemcount;i++){
        if(inventory[i].id==id){
            printf("what do you want to change\n");
    printf("1.name\n2.price\n3.quantity\n");
    scanf("%d",&ch);
        found = 1;

            switch(ch){
                case 1:
                    printf("Enter new name: ");
                    scanf("%s", inventory[i].name);
                    break;
                case 2:
                    printf("Enter new price: ");
                    scanf("%f", &inventory[i].price);
                    break;
                case 3:
                    printf("Enter new quantity: ");
                    scanf("%d", &inventory[i].quantity);
                    break;
            }
            printf("Item updated successfully!\n");
            return;
        }
}
if(found==0){
    printf("id not found ");
}
}
void display() {
    if (itemcount == 0) {
        printf("Inventory is empty!\n");
        return;
    }

    printf("\n Current Inventory:\n");
    printf("ID\tName\t\tPrice\tQuantity\n");
    printf("------------------------------------\n");

    for (int i = 0; i < itemcount; i++) {
        printf("%d\t%s\t\t%.2f\t%d\n", inventory[i].id, inventory[i].name, inventory[i].price, inventory[i].quantity);
    }
}



int main() {
    printf("welcome to inventory managemnt\n");
    int val,id;

    while (1)
    {
        printf(" 1) insert inventory\n 2) delete inventory\n 3) serching inventory\n 4) update inventory\n 5) display inventory\n 6) exit\n");
        scanf(" %d", &val);

        switch (val)
        {
        case 1:
            addItem();
            break;
        case 2:
            printf("enter id for delete inventory\n");
            scanf("%d", &id);
            deleteitem(id);
            break;
        case 3:
            printf("enter id for search inventory");
            scanf("%d", &id);
            search(id);
            break;
        case 4:
            printf("enter id for update inventory");
            scanf("%d", &id);
            Update(id);
            break;
        case 5:
            display();
            break;
        case 6:
            return 0;
            break;
        default:
            printf("invalied");
        }
    }
    


    return 0;
}