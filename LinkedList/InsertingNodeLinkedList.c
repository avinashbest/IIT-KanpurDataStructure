/*
Insertion a Node :
 	    ->Inserting a node at the beginning.
 	    ->Inserting a node at the end.
 	    ->Inserting a node at intermediate position.
*/
#include <stdio.h>
#include <stdlib.h>
void insert();
//Singly Linked List
void show();
void begining();
void intermediate();
void insertEnd();
//Structure of the Node
struct student
{
	int rollNo;
	struct student *next;
};

struct student *start = NULL, *node, *temp;

int main(void)
{
	int choice;
	do
	{
		printf("\nPress 0 to close.");
		printf("\nPress 1 to create list.");
		printf("\nPress 2 to display elements.");
		printf("\nPress 3 to add at begining.");
		printf("\nPress 4 to add at specific position.");
		printf("\nPress 5 to add at End.");
		printf("\nEnter Your Choice: ");
		scanf("%d", &choice);
		if (choice == 1)
		{
			insert();
		}
		else if (choice == 2)
		{
			show();
		}
		else if (choice == 3)
		{
			begining();
		}
		else if (choice == 4)
		{
			intermediate();
		}
		else if (choice == 5)
		{
			insertEnd();
		}
	} while (choice != 0);

	return 0;
}
//Taking one by one input from user.
void insert()
{
	node = (struct student *)malloc(sizeof(struct student));
	printf("Enter the Roll No: ");
	scanf("%d", &node->rollNo);
	node->next = NULL;
	if (start == NULL)
	{
		temp = node;
		start = node;
	}
	else
	{
		temp->next = node;
		temp = temp->next;
	}
}
//Printing Linked list function.
void show()
{
	struct student *t;
	t = start;
	for (; t != NULL; t = t->next)
	{
		printf("%d\t", t->rollNo);
	}
}

void begining()
{
	node = (struct student *)malloc(sizeof(struct student));
	printf("\nEnter the Roll No: ");
	scanf("%d", &node->rollNo);
	node->next = NULL; //Optional
	node->next = start;
	start = node;
	printf("\nElement is Added Successfully!\n");
}

void intermediate()
{
	// struct student *t;
	int position, count = 0;
	node = (struct student *)malloc(sizeof(struct student));
	printf("\nEnter the Roll No: ");
	scanf("%d", &node->rollNo);
	printf("\nEnter Position where you want to add: ");
	scanf("%d", &position);
	position--;
	temp = start;
	for (count = 2; count <= position - 1; count++)
	{
		temp = temp->next;
		if (temp == NULL)
		{
			break;
		}
	}
	if (temp != NULL)
	{
		node->next = temp->next;
		temp->next = node;
	}
}

void insertEnd()
{
	node = (struct student *)malloc(sizeof(struct student));
	printf("\nEnter the Roll No: ");
	scanf("%d", &node->rollNo);
	node->next = NULL; //Optional
	temp = start;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = node;
	printf("\nElement is Added Successfully!\n");
}