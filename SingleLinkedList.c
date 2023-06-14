#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *next;
}Node;

Node *head = NULL;

Node *createnode(int data){
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->data=data;
	newNode->next=NULL;
	return newNode;
}

void createList(){
	Node *newNode = (Node*)malloc(sizeof(Node));
	char resp;
	int data;
	int ctr = 1;
	
	head = newNode;
	if (head == NULL){
		head = newNode;
	}
	do{
		printf("\nNode No. %d\n",ctr);
		printf("Enter DATA:	");
		scanf(" %d", &newNode->data);
		printf("\nAdd another NODE [Y/N]?	");
		scanf(" %c", &resp);
		if(resp == 'Y' || resp == 'y'){
			newNode->next = (Node*)malloc(sizeof(Node));
			newNode = newNode->next;
		}
		ctr++;
	}while(resp == 'Y' || resp == 'y');
	newNode->next=NULL;
	newNode=NULL;
	printf("\n\nSuccessfully created Single\Singly Linked List");
}

void traversal(){
	Node *current = head;
	if(current == NULL){
		printf("Singly Linked List is Empty!");
	}
	else{
		do{
			printf(" %d", current->data);
			printf(" ");
			current = current->next;
		}while(current != NULL);
	}
}

void insertNodeAtStart(int data){
	Node* newNode = createnode(data);
	newNode->next=head;
	head=newNode;
	newNode=NULL;
	printf("\n\nSuccessfully inserted a DATA at the Start");
}

void deleteNodeAtStart(){
	Node* DelNode = head;
	head = head->next;
	DelNode->next=NULL;
	free(DelNode);
	DelNode=NULL;
	printf("\n\nSuccessfully deleted a DATA from the Start");
}

int main(int argc, char *argv[]) {
	printf("Create a Single/Singly Linked List\n");
	createList();
	
	printf("\n\nPress any key to continue....");
	getch();
	system("cls");

	int choice, data;
		do{
			system("cls");
			printf("1. Traverse the List\n");
			printf("2. Insert a NODE at the Start\n");
			printf("3. Delete a NODE at the Start\n");
			printf("0. To end\n");
			printf("\nEnter your choice: ");
			scanf(" %d", &choice);
			switch (choice){
				case 1: 
					printf("\nTraversing DATA: ");
					traversal();
					break;
				case 2: 
					printf("\nInserting NODE at the Start\n");
					printf("Enter DATA:	");
					scanf("%d",&data);
					insertNodeAtStart(data);
					break;
				case 3: 
					printf("\nDeleting NODE at Start\n");
					deleteNodeAtStart();
					break; 
					
				default:
					printf("\nTry again");
		}
		printf("\n\nPress any key to continue...");
		getch();
	}while (choice != 0);
		
	return 0;
}
