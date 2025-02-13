#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
}*first;

int size;
//insert inbigning
void begininsert(int value)
{
	struct node *newnode , *avail;
	avail=(struct node*)malloc(sizeof(struct node));
	
	if(avail==NULL)
	{
		printf("memory not avalablity!!\n");
		return;
	}
	else
	{
		newnode=avail;
		avail=avail->next;
		newnode->data=value;
		printf("inserted value:%d\n",newnode->data);
		size++;
		
		if(first==NULL)
		{
			newnode->next=NULL;
		}
		else
		{
			newnode->next=first;
		}
		first=newnode;
		
	}
	
}

// insert at last
void insertlast(int value)
{
	struct node *avail,*newnode,*ptr;
	avail=(struct node*)malloc(sizeof(struct node));
	if(avail==NULL)
	{
		printf("underflow");
	}
	else
	{
		newnode=avail;
		avail=avail -> next;
		newnode->data=value;
		newnode->next=NULL;
		printf("inserted value:%d\n",newnode->data);
		size++;
	}
	if(first==NULL)
	{
		newnode=first;
	}
	else
	{
		ptr=first;
		while(ptr->next != NULL)
		{
			ptr=ptr->next;
		}
		ptr->next=newnode;
	}
}

//insert at specific position

void posinsert(int pos,int value)
{
	struct node *avail,*newnode,*ptr,*preptr;
	avail=(struct node*)malloc(sizeof(struct node));
	if(avail==NULL)
	{
		printf("underflow");
	}
	else
	{
		newnode=avail;
		avail=avail -> next;
		newnode->data=value;
		newnode->next=NULL;
	}
	if(pos==1)
	{
		newnode->next = first;
		first=newnode;
		printf("Inserted value:%d",newnode->data);
		size++;
		return;
	}
	int i=1;
	ptr=first;
//	preptr = NULL;
	while(ptr != NULL && i<pos-1)
	{	
		ptr=ptr->next;
//		preptr=ptr;
//		ptr=ptr->next;s
		i++;	
	}
	if(i!=pos-1)
	{
		printf("position is not found!!");
		return;
	}
	
	newnode->next=ptr->next;
	ptr->next=newnode;
//	newnode->next=ptr;
//	preptr->next=newnode;
	printf("Inserted value:%d\n",newnode->data);
	size++;
	
}

// display
void display()
{
	struct node *ptr;
	ptr=first;
	printf("display elements:\n");
	while(ptr!=NULL)
	{
		printf("%d\n",ptr->data);
		ptr=ptr->next;
	}
	printf("\t\t\t\t\tNo of node is : %d\n",size);

}

//Delete first
void deletefirst()
{
	struct node *ptr;
	ptr=first;
	if(first==NULL)
	{
		printf("list is empty!!");
		return;
	}
	if(first->next==NULL)
	{
		free(first);
		first=NULL;
	}
	else
	{	
		printf("deleted value:%d",first);
		first=ptr->next;
		free(ptr);
		size--;
		return;
	}
}

void deletelast(){
	
	if(first==NULL){
		printf("list is empty!!");
		return;
	}
	if(first->next==NULL)
	{
		free(first);
		first=NULL;
		size--;
	}
	else{
		
		struct node *ptr = first;
		struct node *preptr = first;
		
		while(ptr->next!=NULL){
			preptr = ptr;
			ptr=ptr->next;
		}
		
		preptr->next=NULL;
		free(ptr);
		size--;
	}
	
}

int search(int ele){
	
	
	if(first==NULL)
	{
		printf("list is empty!!");
		return 0;
	}else{
	struct node *ptr;
	ptr=first;
	int i=0;
	while(ptr!=NULL){
			if(ptr->data==ele){
			    printf("found it \n");
				return i;
			}
			
			ptr=ptr->next;
			i++;
		}
		printf("not found it\n ");
	    return 0;
	}
}

void deleteatspacific(int ind){
    if(first==NULL){
		printf("list is empty!!");
		return;
	}else{
	    struct node *ptr=first;
	    struct node *preptr=first;
	     while (ptr->data!=ind){
	         preptr=ptr;
	         ptr=ptr->next;
	         
	     }
	     
	     preptr->next=ptr->next;
	     free(ptr);
	     size--;
	}
    
    
}

void main()
{
	int choice,n,pos,x;
	while(1)
	{
		printf("Enter your choice:\n1)insert at bigning\n2)insert at last\n3)insert at specific position\n4)display\n5)delete first\n6)delete last\n7)find ele\n8)delete_at_spacific\n0)exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("entre insert value:");
				scanf("%d",&n);
				begininsert(n);
				display();
				break;
				
			case 2:
				printf("entre insert value:");
				scanf("%d",&n);
				insertlast(n);
				display();
				break;
				
			case 3:
				printf("enter position:");
				scanf("%d",&pos);
				printf("enter value:");
				scanf("%d",&n);
				posinsert(pos,n);
				display();
				break;
				
			case 4:
				display();
				break;
			case 5:
				deletefirst();
				display();
				break;
			case 0:
				return;
				break;
			case 6:
				deletelast();
				display();
				break;
			case 7:
				printf("enter value:");
				scanf("%d",&n);
				printf("index is %d\n",search(n));
				display();
				break;
			case 8:
				printf("enter value:");
				scanf("%d",&x);
				deleteatspacific(x);
				display();
				break;
				
			default:
				printf("entre valid choice!!");
		}
	}
}

