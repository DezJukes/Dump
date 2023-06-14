#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void createList();
void traversal();
void insertAtStart(int data);
void insertAtEnd(int data);
void insertBeforeNode();
void insertAfterNode();
void deleteNodeStart();
void deleteNodeEnd();
void deleteNodebyValue();
void deleteNodeAfterValue();
void deleteNodeBeforeValue();
void deleteList();
void yellow(){
	printf("\033[0;33m");
}
void reset(){
	printf("\033[0m");
}
int main(int argc, char *argv[]) {
	int choice, data;
	do{
		system("cls");
		yellow();
		printf("---SINGLY/SINGLE LINKED LIST MAIN MENU---\n\n");
		reset();
		printf("\0. To end\n");
		printf("1. Create Single Linked List\n");
		printf("2. Traverse the List\n");
		printf("3. Insert at the Beginning\n");
		printf("4. Insert at the End\n");
		printf("5. Insert Before a Node/Value\n");
		printf("6. Insert After a Node/Value\n");
		printf("7. Delete Node/Value at the Start\n");
		printf("8. Delete Node/Value at the End\n");
		printf("9. Delete Node by Value\n");
		printf("10. Delete Node before a Value\n");
		printf("11. Delete Node after a Value\n");
		printf("12. Delete the entire list\n");
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
				printf("\nInserting at the End\n");
				printf("Enter the data:	");
				scanf("%d",&data);
				insertAtEnd(data);
				break;
			case 5: 
				printf("\nInserting before a Node\n");
				insertBeforeNode();
				break;
			case 6: 
				printf("\nInserting after a Node\n");
				insertAfterNode();
				break;
			case 7: 
				printf("\nDeleting Node at Start\n");
				deleteNodeStart();
				break;
			case 8: 
				printf("\nDeleting Node at End\n");
				deleteNodeEnd();
				break;
			case 9: 
				printf("\nDeleting Node by Value\n");
				deleteNodebyValue();
				break;
			case 10: 
				printf("\nDeleting Node before a Value\n");
				deleteNodeBeforeValue();
				break;
			case 11: 
				printf("\nDeleting Node After a Value\n");
				deleteNodeAfterValue();
				break;
			case 12: 
				printf("\nDeleting Singly Linked List\n");
				deleteList();
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
		printf("Enter the data:	");
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

void insertAtEnd(int data){
	Node* newNode = createnode(data);
	Node* end = head;
	while(end->next != NULL)
	{
		end = end->next;
	}
	end->next=newNode;
	newNode=NULL;
	end=NULL;
	printf("\n\nSuccessfully inserted data at the End");
}

void insertBeforeNode(int data){
	Node* newNode = createnode(data), *current, *prev;
	int flag, value;
	printf("Enter the Data:	");
	scanf("%d",&newNode->data);
	printf("Enter the value/node: ");
	scanf("%d",&value);
	prev = NULL;
	current=head;
	do{
		if(value==current->data){
			flag=1;
		}
		else{
			prev=current;
			current=current->next;
		}
	}while(flag != 1 && current != NULL);
	if(flag==1){
		newNode->next=current;
		if(prev==NULL){
			head=newNode;
		}
		else{
			prev->next=newNode;
		}
		printf("\n\nSuccessfully inserted data before the value");
		newNode=NULL;
	}
	else{
		printf("The value where you want to insert the New Node before does no exist!");
		prev=current=NULL;
	}
}

void insertAfterNode(int data){
	Node* newNode = createnode(data), *current, *prev;
	int flag, value;
	printf("Enter the data: ");
	scanf("%d",&newNode->data);
	printf("Enter the value/node: ");
	scanf("%d",&value);
	prev = NULL;
	current=head;
	do{
		if(value==current->data){
			flag=1;
		}
		else{
			current=current->next;
		}
	}while(flag != 1 && current != NULL);
	if(flag==1){
		newNode->next=current->next;
		current->next=newNode;
		newNode=NULL;
		printf("\n\nSuccessfully inserted data after the value");
	}
	else{
		printf("The value whrere you want to insert the New Node before does no exist!");
		prev=current=NULL;
	}
}

void deleteNodeStart(){
	Node* DelNode = head;
	head = head->next;
	DelNode->next=NULL;
	free(DelNode);
	DelNode=NULL;
	printf("\n\nSuccessfully deleted data from the Start");
}

void deleteNodeEnd(){
	Node* DelNode = head, *prev;
	prev=NULL;
	while(DelNode->next != NULL)
	{
		prev = DelNode;
		DelNode=DelNode->next;
	}
	prev->next=NULL;
	prev=NULL;
	free(DelNode);
	DelNode=NULL;
	printf("\n\nSuccessfully deleted data from the End");
}

void deleteNodebyValue(){
	int value, flag;
	printf("Enter the value:	");
	scanf("%d",&value);
	Node* DelNode = head, *prev;
	while(flag != 1 && DelNode != NULL){
		if(value == DelNode->data){
			flag = 1;
		}else{
			prev = DelNode;
			DelNode = DelNode->next;
		}
	}
	if(flag==0){
		printf("Value not found");
	}
	else{
		if(DelNode == head){
			head=head->next;
			DelNode->next=NULL;
		}else{
			prev->next=DelNode->next;
			DelNode->next=NULL;
		}
		free(DelNode);
	}
	printf("\n\nSuccessfully deleted data");
	prev=DelNode=NULL;
}

void deleteNodeAfterValue(){
	int flag = 0, value;
	printf("Enter the value:	");
	scanf(" %d", &value);
	Node* current = head, *DelNode;
	while(flag != 1 && current != NULL){
		if(value == current->data){
			flag = 1;
		}
		else{
			current=current->next;
		}
	}
	if(flag==1 && current->next != NULL){
			DelNode=current->next;
			current->next=DelNode->next;
			DelNode->next=NULL;
			free(DelNode);
			printf("\n\nSuccessfully deleted data after Value");
	}else{
		printf("Value not found");
	}
}

void deleteNodeBeforeValue(){
	int flag = 0, value;
	printf("Enter the value:	");
	scanf(" %d", &value);
	Node *current = head, *prev = NULL;
	while(flag != 1 && current != NULL){
		if(value == current->data){
			break;
		}
		if(value == current->next->data){
			flag = 1;
		}else{
			prev = current;
            current = current->next;
		}
	}
	if (flag == 1){
        if (current == head){
            head = current->next;
        } else {
            prev->next = current->next;
        }
        printf("\n\nSuccessfully deleted data before Value");
        free(current);
    } else {
        printf("Node before value %d does not exist!", value);
    }
    prev = current = NULL;
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
