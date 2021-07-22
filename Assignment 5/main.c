#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value, maxSupport;
    struct node * next;
} node;

// Function definitions
node * push(node * front, int value);
node* pop(node* head);
void stackCount(int count);
void printList(node * someNode);
void incrementOne(node* head);
int countListLength(node* head);

// Global variables to count
int chainsOnGround = 0;
int brokenLinks = 0;
int count = 0;
int inputCounter = 0;

int main()
{
    int value;
    node * front = NULL;
    node * end = NULL;

    scanf("%d", &value);

	// Scans input
    while(value >= 0)
    {
        count++;
        inputCounter++;
        //adding newest node
        front = push(front, value);


        scanf("%d", &value);

    }

    // Prints output in proper format
    printf("Ending chain height is: %d\n", count);
	printf("There are %d broken links and %d whole links on the floor\n", brokenLinks, chainsOnGround);


    return 0;
}


// Pushes values onto stack
node * push(node * front, int value)
{
    int nodeCounter = 1;
    int numDiff = 0;
    node* frontfront = front;
    node * lastNode = front;

	// Traverses stack until last element
    while (lastNode != NULL && lastNode->next != NULL)
    {
    	lastNode->value--;
        if (lastNode->value < 0)
        {
        	int tmp = 1;
 			chainsOnGround += (count - nodeCounter);
            while (tmp < (count - nodeCounter - 1))
            {
            	pop(frontfront);
            	incrementOne(frontfront);
            	count--;
            	tmp++;
            }

            count--;
            printf("Chain broken at link %d. New height is %d\n", inputCounter, nodeCounter + 1);
			brokenLinks++;
			return frontfront;
        }
        nodeCounter++;
        lastNode = lastNode->next;
    }

	// Creates node and starts the stack
	// Else, or adds to the top of the stack
    if (lastNode == NULL)
    {
        lastNode = (node *) calloc(1, sizeof(node));
        lastNode->value = value;
        lastNode->maxSupport = value;
        lastNode->next = NULL;

        return lastNode;
    }
    else
    {
        lastNode->value--;
        lastNode->next = (node *) calloc(1, sizeof(node));
        lastNode = lastNode->next;
    }

    lastNode->next = NULL;
    lastNode->value = value;
    lastNode->maxSupport = value;

    count = count - numDiff;
    return front;
}

// Recursively prints the stack, top to bottom
void printList(node * someNode)
{
    //recursive base case
    if (someNode == NULL)
    {
        //printf("Stack is empty");
        return;
    }
    printf("%d\n", someNode->value);
    printList(someNode->next);
 }


// Removes the last element of the stack
node* pop(node* head)
{
	// Base case 1: stack is empty
    if (head == NULL)
        return NULL;

  	// Base case 2: stack contains one element
    if (head->next == NULL)
    {
        free(head);
        return NULL;
    }


    node* before_last = head;

    while (before_last->next->next != NULL)
        before_last = before_last->next;

    free(before_last->next);

    before_last->next = NULL;
    return head;
}

// Increments all values by one
void incrementOne(node* head)
{
	node* tmp;
	tmp = head;

	if (tmp == NULL)
		return;

	while (tmp != NULL)
	{
		tmp->value++;
		tmp = tmp->next;
	}

	return;
}


