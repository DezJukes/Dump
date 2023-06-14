#include <stdio.h>
#include <stdlib.h>

void createList();
void traversal();
void insertAtStart(int data);
void deleteNodeStart();

int main(int argc, char *argv[]) {
	int choice, data;
	do{
		system("cls");
		printf("---SINGLY/SINGLE LINKED LIST MAIN MENU---\n\n");
		
		printf("\0. To end\n");
		printf("1. Create Single Linked List\n");
		printf("2. Traverse the List\n");
		printf("3. Insert at the Beginning\n");
		printf("4. Delete Node/Value at the Start\n");
		printf("\nEnter your choice: ");
		scanf(" %d", &choice);
		switch (choice){
			case 1: 
				printf("\nCreating Single Linked List\n");
				createList();
				break;
			case 2: 
				printf("\nTraversing Data: ");
				traversal();
				break;
			case 3: 
				printf("\nInserting at the Beginning\n");
				printf("Enter the data:	");
				scanf("%d",&data);
				insertAtStart(data);
				break;
			case 4: 
				printf("\nDeleting Node at Start\n");
				deleteNodeStart();
				break;
			default:
				printf("\nTry again");
		}
		printf("\n\nPress any key to continue....");
		getch();
	}while (choice != 0);
	
	return 0;


}
typedef struct node {
	int data;
	struct node* next;
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
	if (head != NULL){
		printf("\nSingle Linked List Already Exist...\n");
		printf("Do you want to delete Single Linked List [Y/N]?");
		scanf(" %c", &resp);
		if(resp == 'Y' || resp == 'y'){
			printf("Deleting Single Linked List...");
			deleteList();
		}
		return;
	}
	head = newNode;
	if (head == NULL){
		head = newNode;
	}
	do{
		printf("Enter data:	");
		scanf(" %d", &newNode->data);
		printf("Add another node [Y/N]?	");
		scanf(" %c", &resp);
		if(resp == 'Y' || resp == 'y'){
			newNode->next = (Node*)malloc(sizeof(Node));
			newNode = newNode->next;
		}
	}while(resp == 'Y' || resp == 'y');
	newNode->next=NULL;
	newNode=NULL;
	printf("\n\nSuccessfully created Single Linked List");
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

void insertAtStart(int data){
	Node* newNode = createnode(data);
	newNode->next=head;
	head=newNode;
	newNode=NULL;
	printf("\n\nSuccessfully inserted data at the Start");
}

void deleteNodeStart(){
	Node* DelNode = head;
	head = head->next;
	DelNode->next=NULL;
	free(DelNode);
	DelNode=NULL;
	printf("\n\nSuccessfully deleted data from the Start");
}

void deleteList(){
	Node *current = head, *DelNode;
	while(current != NULL){
		DelNode=current->next;
		free(current);
		current=DelNode;
	}
	head=NULL;
	printf("\n\nSuccessfully deleted Single Linked List\n");
}
