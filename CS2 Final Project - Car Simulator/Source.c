// Jonathan Winter
// 05/04/2017
// CS2 Final Project Car Simulation


/*

THIS IS A SNIPPET OF A PROGRAMMING PROJECT I WROTE IN COMPUTER SCIENCE II AT JWU.
THIS PROGRAM WILL RUN A TRAFFIC SIMULATER IN THE CONSOLE WINDOW BASED ON THE RULES
MADE IN THE PROJECT. EACH OF THE STREETS ARE NAMED A, B, BUP, C, CRIGHT, D, DDOWN,
AND E. THE MAP LOOKS SOMETHING LIKE THIS:
	
            ENTER/EXIT		    ENTER/EXIT
	       \  \		      /  /
	        \  \       A -->     /  /
		|   ----------------    | 
	^	|			|   ^
	|	|			|   |
	|	|			|   |
	D	|			|  BUP
  	DDOWN	|			|   B
	|	|	 E -->		|   |
	|	|-----------------------|   |
	v	|			|   v
		|			|
	     	 -----------------------
		     <-- C CRIGHT -->

RULES:
________|_____________________________________
A	|	CARS CAN ENTER A, OR LEAVE A TO B
B	|	CARS CAN LEAVE B TO C
BUP	|	CARS CAN EXIT THE SIMULATOR
C	|	CARS CAN LEAVE C TO D
CRIGHT	|	CARS CAN LEAVE CRIGHT TO BUP
D	|	CARS CAN EXIT THE SIMULATOR
DDOWN	|	CARS CAN LEAVE DDOWN TO CRIGHT OR E
E	|	CARS CAN LEAVE E TO BUP OR C

* CARS CAN RANDOMLY ENTER THE SIMULATION AT THE ENTER/EXITS
			
*/

#include <stdio.h>
#include <stdlib.h>
// time.h used for sleep functions
// to slow down console output
#include <windows.h>

typedef struct node {
	int age;
	struct node *forward;
}node;

struct head {
	int count; // Total Cars in the queue
	struct node *front;
	struct node *rear;
}head;

struct node nodes;
struct head header;

struct node nodesB;
struct head headerB;
struct node nodesBUp;
struct head headerBUp;

struct node nodesC;
struct head headerC;
struct node nodesCRight;
struct head headerCRight;

struct node nodesD;
struct head headerD;
struct node nodesDDown;
struct head headerDDown;

struct node nodesE;
struct head headerE;

void enqueue(struct node nodes2);
int dequeue(struct node nodes2);
void print(struct node nodes2);

void enqueueB(struct node nodes2);
int dequeueB(struct node nodes2);
void enqueueBUp(struct node nodes2);
int dequeueBUp(struct node nodes2);

void enqueueC(struct node nodes2);
int dequeueC(struct node nodes2);
void enqueueCRight(struct node nodes2);
int dequeueCRight(struct node nodes2);

void enqueueD(struct node nodes2);
int dequeueD(struct node nodes2);
void enqueueDDown(struct node nodes2);
int dequeueDDown(struct node nodes2);

void enqueueE(struct node nodes2);
int dequeueE(struct node nodes2);

int main()
{
	header.front = NULL;
	header.rear = NULL;
	header.count = 0;

	headerB.front = NULL;
	headerB.rear = NULL;
	headerB.count = 0;

	headerBUp.front = NULL;
	headerBUp.rear = NULL;
	headerBUp.count = 0;

	headerC.front = NULL;
	headerC.rear = NULL;
	headerC.count = 0;

	headerCRight.front = NULL;
	headerCRight.rear = NULL;
	headerCRight.count = 0;

	headerD.front = NULL;
	headerD.rear = NULL;
	headerD.count = 0;

	headerE.front = NULL;
	headerE.rear = NULL;
	headerE.count = 0;

	// MODIFY # OF (x < #) BELOW TO SET AMOUNT OF
	// CARS ON THE STREETS

	/*

	EACH OF THE FOLLOWING BELOW REPRESENT SECTIONS OF A STREET
	THAT HAVE A CERTAIN NUMBER OF CARS AT THE START OF THE
	SIMULATION. FOR TESTING PURPOSES, EACH STREET WILL BE
	GIVEN A SET NUMBER OF CARS PER STREET. FINAL PRODUCTION
	WILL ALWAYS HAVE A RANDOM NUMBER OF CARS ON EACH STREET.

	*/

	// Add cars to A
	for (int x = 0; x < 9; x++)
	{
		enqueue(nodes);
	}

	// Add cars to B
	for (int x = 0; x < 9; x++)
	{
		enqueueB(nodesB);
	}

	// Add cars to BUp
	for (int x = 0; x < 9; x++)
	{
		enqueueBUp(nodesBUp);
	}

	// Add cars to C
	for (int x = 0; x < 9; x++)
	{
		enqueueC(nodesC);
	}

	// Add cars to CRight
	for (int x = 0; x < 9; x++)
	{
		enqueueCRight(nodesCRight);
	}

	// Add cars to D
	for (int x = 0; x < 9; x++)
	{
		enqueueD(nodesD);
	}
	// Add cars to DDown
	for (int x = 0; x < 9; x++)
	{
		enqueueDDown(nodesDDown);
	}

	// Add cars to E
	for (int x = 0; x < 10; x++)
	{
		enqueueE(nodesE);
	}

	// VARIABLES

	int totalCars = header.count + headerB.count + headerC.count + headerD.count
		+ headerBUp.count + headerCRight.count + headerDDown.count + headerE.count;
	int a, b, bup, c, cright, d, ddown, e;
	int dice; // Random chance variable

	printf("Simulation Start Total Cars: %i\n\n", totalCars);

	// SIMULATION ENGINE
	while (totalCars != 0)
	{
		// USED LATER TO PRINT BEFORE AND AFTER
		a = header.count;
		b = headerB.count;
		bup = headerBUp.count;
		c = headerC.count;
		cright = headerCRight.count;
		d = headerD.count;
		ddown = headerDDown.count;
		e = headerE.count;

		// DETERMINE IF CARS ENTER THE SIMULATION
		dice = rand() % 10;
		// DOES NOT ENTER
		if (dice >= 5)
		{
			;// Do nothing
		}
		// DOES ENTER
		else if (dice < 5)
		{
			// DETERMINE IF ENTER A OR DDOWN
			if (dice % 2 == 0)
			{
				printf("Car enters A\n");
				enqueue(nodes);
			}
			else if (dice % 2 == 1)
			{
				printf("Car enters DDown\n");
				enqueueDDown(nodesDDown);
			}
		}


		// IF THERE ARE CARS IN A
		if (header.count != 0)
		{
			if (headerB.count > 10)
			{
				printf("TRAFFIC JAM AT B!\n");
			}
			else if (headerB.count < 10)
			{
				// CAR LEAVES A GOES TO B
				dequeue(nodes);
				enqueueB(nodesB);
			}
		}

		// IF THERE ARE CARS IN B
		if (headerB.count != 0)
		{
			if (headerC.count > 10)
			{
				printf("TRAFFIC JAM AT B!\n");
			}
			else if (headerC.count < 10)
			{
				// CAR LEAVES B GOES TO C
				dequeueB(nodesB);
				enqueueC(nodesC);
			}
		}

		// IF THERE ARE CARS IN C
		if (headerC.count != 0)
		{
			if (headerD.count > 10)
			{
				printf("TRAFFIC JAM AT B!\n");
			}
			else if (headerD.count < 10)
			{
				// CAR LEAVES C GOES TO D
				dequeueC(nodesC);
				enqueueD(nodesD);
			}
		}

		// IF THERE ARE CARS IN D
		if (headerD.count != 0)
		{
			// CARS WILL ALWAYS LEAVE D
			dequeueD(nodesD);
		}

		// IF THERE ARE CARS IN CRIGHT
		if (headerCRight.count != 0)
		{
			if (headerBUp.count > 10)
			{
				printf("TRAFFIC JAM AT BUP!\n");
			}
			else if (headerBUp.count < 10)
			{
				// CAR LEAVES CRIGHT GOES TO BUP
				dequeueCRight(nodesCRight);
				enqueueBUp(nodesBUp);
			}
		}

		// IF THERE ARE CARS IN BUP
		if (headerBUp.count != 0)
		{
			// CARS WILL ALWAYS LEAVE BUP
			dequeueBUp(nodesBUp);
		}

		// DETERMINE IF E CARS LEAVE TO BUP OR C
		// E WANTS TO GO TO BUP FIRST, BECAUSE
		// THAT IS THE PATH OF LEAST RESISTANCE

		// IF THERE ARE NO CARS IN E
		if (headerE.count == 0)
		{
			; // DO NOTHING
		}
		// THERE ARE CARS CARS IN E
		else if (headerE.count != 0)
		{
			// TRY TO TURN ONTO BUP

			// THERE IS ROOM IN BUP
			if (headerBUp.count < 10)
			{
				dequeueE(nodesE);
				enqueueBUp(nodesBUp);
			}

			//THERE IS NO ROOM IN BUP
			else if (headerBUp.count >= 10)
			{
				// TRY TO TURN ONTO C

				// THERE IS ROOM IN C
				if (headerBUp.count < 10)
				{
					dequeueE(nodesE);
					enqueueC(nodesC);
				}

				//THERE IS NO ROOM IN C
				else if (headerC.count >= 10)
				{
					; // CANNOT TURN ANYWHERE
				}
			}
		}

		// IF THERE ARE CARS IN DDOWN
		if (headerDDown.count != 0)
		{
			// DETERMINE IF DDOWN GOES TO CRIGHT OR E
			dice = rand() % 10;
			// CAR WILL GO TO CRIGHT IF THERE IS ROOM
			if (dice >= 5)
			{
				if (headerCRight.count > 10)
				{
					printf("TRAFFIC JAM AT CRIGHT!\n");
				}
				else if (headerCRight.count < 10)
				{
					// CAR LEAVES DDOWN GOES TO CRIGHT
					dequeueDDown(nodesDDown);
					enqueueCRight(nodesCRight);
				}
				dice = rand() % 10;
			}
			// CAR WILL GO TO E IF THERE IS ROOM
			else if (dice < 5)
			{
				if (headerE.count >= 10)
				{
					printf("TRAFFIC JAM AT E!\n");
				}
				else if (headerE.count < 10)
				{
					// CAR LEAVES DDOWN GOES TO E
					dequeueDDown(nodesDDown);
					enqueueE(nodesE);
					printf("E HAS : %i CARS NOW!!!\n", headerE.count);
				}
				dice = rand() % 10;
			}

		}


		totalCars = header.count + headerB.count + headerC.count + headerD.count
			+ headerBUp.count + headerCRight.count + headerDDown.count + headerE.count;

		// PRINT STATISTICS
		printf("BEFORE\tAFTER\n");
		printf("A: %i\t\tA: %i\n", a, header.count);

		printf("B: %i\t\tB: %i\n", b, headerB.count);
		printf("BUp: %i\t\tBUp: %i\n", bup, headerBUp.count);

		printf("C: %i\t\tC: %i\n", c, headerC.count);
		printf("CRight: %i\tCRight: %i\n", cright, headerCRight.count);

		printf("D: %i\t\tD: %i\n", d, headerD.count);
		printf("DDown: %i\tDDown: %i\n", ddown, headerDDown.count);
		printf("E: %i\t\tE: %i\n", e, headerE.count);


		printf("\nTotal Cars Left: %i\n\n", totalCars);
	}

}


// **************************** FUNCTIONS

void enqueue(struct node nodes2)
{
	//struct node *current;
	struct node *tempPtr;
	struct node *newPtr;

	// Empty Queue
	if (header.front == NULL)
	{
		//printf("Adding to the empty Queue...\n");
		newPtr = (struct node*)malloc(sizeof(struct node));
		newPtr->age = 20;
		newPtr->forward = NULL;

		header.front = newPtr;
		header.rear = newPtr;
		header.count++;
	}
	// At least one in the Queue
	else
	{
		//printf("Adding to a Queue with at least one item...\n");
		newPtr = (struct node*)malloc(sizeof(struct node));
		newPtr->age = 25;
		newPtr->forward = NULL;

		tempPtr = header.rear;
		header.rear = newPtr;
		tempPtr->forward = newPtr;
		header.count++;
	}

}

int dequeue(struct node nodes2)
{
	struct node *tempPtr;

	// Empty Queue
	if (header.front == NULL)
	{
		printf("Cannot Dequeue from an empty list\n");
		return(1);
	}
	// One Structure in the Queue
	else if (header.front == header.rear)
	{
		//printf("Dequeueing from a queue with only one item...\n\n");
		tempPtr = header.front;
		header.front = NULL;
		header.rear = NULL;
		// Save the address of tempPtr
		header.count--;
		return(tempPtr);
	}
	else
	{
		//printf("Dequeueing from a queue that has more than one item...\n\n");
		tempPtr = header.front;
		header.front = tempPtr->forward; //might replace below code
										 //header.front = head.front->forward;
		header.count--;
	}
}

void print(struct node nodes2)
{
	struct node *tempPtr;
	tempPtr = header.front;
	int x = 0;
	printf("Printing all of the items in the Queue...\n");
	for (x = 0; x<header.count; x++)
	{
		printf("Age: %d | Count: %d\n", tempPtr->age, header.count);
		tempPtr = tempPtr->forward;
	}
}

// FUNCTIONS FOR B

void enqueueB(struct node nodes2)
{
	//struct node *current;
	struct node *tempPtr;
	struct node *newPtr;

	// Empty Queue
	if (headerB.front == NULL)
	{
		//printf("Adding to the empty Queue...\n");
		newPtr = (struct node*)malloc(sizeof(struct node));
		newPtr->age = 20;
		newPtr->forward = NULL;

		headerB.front = newPtr;
		headerB.rear = newPtr;
		headerB.count++;
	}
	// At least one in the Queue
	else
	{
		//printf("Adding to a Queue with at least one item...\n");
		newPtr = (struct node*)malloc(sizeof(struct node));
		newPtr->age = 25;
		newPtr->forward = NULL;

		tempPtr = headerB.rear;
		headerB.rear = newPtr;
		tempPtr->forward = newPtr;
		headerB.count++;
	}

}

int dequeueB(struct node nodes2)
{
	struct node *tempPtr;

	// Empty Queue
	if (headerB.front == NULL)
	{
		printf("Cannot Dequeue from an empty list\n");
		return(1);
	}
	// One Structure in the Queue
	else if (headerB.front == headerB.rear)
	{
		//printf("Dequeueing from a queue with only one item...\n\n");
		tempPtr = headerB.front;
		headerB.front = NULL;
		headerB.rear = NULL;
		// Save the address of tempPtr
		headerB.count--;
		return(tempPtr);
	}
	else
	{
		//printf("Dequeueing from a queue that has more than one item...\n\n");
		tempPtr = headerB.front;
		headerB.front = tempPtr->forward; //might replace below code
										  //header.front = head.front->forward;
		headerB.count--;
	}
}

// FUNCTIONS FOR B UP
void enqueueBUp(struct node nodes2)
{
	//struct node *current;
	struct node *tempPtr;
	struct node *newPtr;

	// Empty Queue
	if (headerBUp.front == NULL)
	{
		//printf("Adding to the empty Queue...\n");
		newPtr = (struct node*)malloc(sizeof(struct node));
		newPtr->age = 20;
		newPtr->forward = NULL;

		headerBUp.front = newPtr;
		headerBUp.rear = newPtr;
		headerBUp.count++;
	}
	// At least one in the Queue
	else
	{
		//printf("Adding to a Queue with at least one item...\n");
		newPtr = (struct node*)malloc(sizeof(struct node));
		newPtr->age = 25;
		newPtr->forward = NULL;

		tempPtr = headerBUp.rear;
		headerBUp.rear = newPtr;
		tempPtr->forward = newPtr;
		headerBUp.count++;
	}

}

int dequeueBUp(struct node nodes2)
{
	struct node *tempPtr;

	// Empty Queue
	if (headerBUp.front == NULL)
	{
		printf("Cannot Dequeue from an empty list\n");
		return(1);
	}
	// One Structure in the Queue
	else if (headerBUp.front == headerBUp.rear)
	{
		//printf("Dequeueing from a queue with only one item...\n\n");
		tempPtr = headerBUp.front;
		headerBUp.front = NULL;
		headerBUp.rear = NULL;
		// Save the address of tempPtr
		headerBUp.count--;
		return(tempPtr);
	}
	else
	{
		//printf("Dequeueing from a queue that has more than one item...\n\n");
		tempPtr = headerBUp.front;
		headerBUp.front = tempPtr->forward; //might replace below code
											//header.front = head.front->forward;
		headerBUp.count--;
	}
}

// FUNCTIONS FOR C

void enqueueC(struct node nodes2)
{
	//struct node *current;
	struct node *tempPtr;
	struct node *newPtr;

	// Empty Queue
	if (headerC.front == NULL)
	{
		//printf("Adding to the empty Queue...\n");
		newPtr = (struct node*)malloc(sizeof(struct node));
		newPtr->age = 20;
		newPtr->forward = NULL;

		headerC.front = newPtr;
		headerC.rear = newPtr;
		headerC.count++;
	}
	// At least one in the Queue
	else
	{
		//printf("Adding to a Queue with at least one item...\n");
		newPtr = (struct node*)malloc(sizeof(struct node));
		newPtr->age = 25;
		newPtr->forward = NULL;

		tempPtr = headerC.rear;
		headerC.rear = newPtr;
		tempPtr->forward = newPtr;
		headerC.count++;
	}

}

int dequeueC(struct node nodes2)
{
	struct node *tempPtr;

	// Empty Queue
	if (headerC.front == NULL)
	{
		printf("Cannot Dequeue from an empty list\n");
		return(1);
	}
	// One Structure in the Queue
	else if (headerC.front == headerC.rear)
	{
		//printf("Dequeueing from a queue with only one item...\n\n");
		tempPtr = headerC.front;
		headerC.front = NULL;
		headerC.rear = NULL;
		// Save the address of tempPtr
		headerC.count--;
		return(tempPtr);
	}
	else
	{
		//printf("Dequeueing from a queue that has more than one item...\n\n");
		tempPtr = headerC.front;
		headerC.front = tempPtr->forward; //might replace below code
										  //header.front = head.front->forward;
		headerC.count--;
	}
}

// FUNCTIONS FOR C RIGHT

void enqueueCRight(struct node nodes2)
{
	//struct node *current;
	struct node *tempPtr;
	struct node *newPtr;

	// Empty Queue
	if (headerCRight.front == NULL)
	{
		//printf("Adding to the empty Queue...\n");
		newPtr = (struct node*)malloc(sizeof(struct node));
		newPtr->age = 20;
		newPtr->forward = NULL;

		headerCRight.front = newPtr;
		headerCRight.rear = newPtr;
		headerCRight.count++;
	}
	// At least one in the Queue
	else
	{
		//printf("Adding to a Queue with at least one item...\n");
		newPtr = (struct node*)malloc(sizeof(struct node));
		newPtr->age = 25;
		newPtr->forward = NULL;

		tempPtr = headerCRight.rear;
		headerCRight.rear = newPtr;
		tempPtr->forward = newPtr;
		headerCRight.count++;
	}

}

int dequeueCRight(struct node nodes2)
{
	struct node *tempPtr;

	// Empty Queue
	if (headerCRight.front == NULL)
	{
		printf("Cannot Dequeue from an empty list\n");
		return(1);
	}
	// One Structure in the Queue
	else if (headerCRight.front == headerCRight.rear)
	{
		//printf("Dequeueing from a queue with only one item...\n\n");
		tempPtr = headerCRight.front;
		headerCRight.front = NULL;
		headerCRight.rear = NULL;
		// Save the address of tempPtr
		headerCRight.count--;
		return(tempPtr);
	}
	else
	{
		//printf("Dequeueing from a queue that has more than one item...\n\n");
		tempPtr = headerCRight.front;
		headerCRight.front = tempPtr->forward; //might replace below code
											   //header.front = head.front->forward;
		headerCRight.count--;
	}
}

// FUNCTIONS FOR D

void enqueueD(struct node nodes2)
{
	//struct node *current;
	struct node *tempPtr;
	struct node *newPtr;

	// Empty Queue
	if (headerD.front == NULL)
	{
		//printf("Adding to the empty Queue...\n");
		newPtr = (struct node*)malloc(sizeof(struct node));
		newPtr->age = 20;
		newPtr->forward = NULL;

		headerD.front = newPtr;
		headerD.rear = newPtr;
		headerD.count++;
	}
	// At least one in the Queue
	else
	{
		//printf("Adding to a Queue with at least one item...\n");
		newPtr = (struct node*)malloc(sizeof(struct node));
		newPtr->age = 25;
		newPtr->forward = NULL;

		tempPtr = headerD.rear;
		headerD.rear = newPtr;
		tempPtr->forward = newPtr;
		headerD.count++;
	}

}

int dequeueD(struct node nodes2)
{
	struct node *tempPtr;

	// Empty Queue
	if (headerD.front == NULL)
	{
		printf("Cannot Dequeue from an empty list\n");
		return(1);
	}
	// One Structure in the Queue
	else if (headerD.front == headerD.rear)
	{
		//printf("Dequeueing from a queue with only one item...\n\n");
		tempPtr = headerD.front;
		headerD.front = NULL;
		headerD.rear = NULL;
		// Save the address of tempPtr
		headerD.count--;
		return(tempPtr);
	}
	else
	{
		//printf("Dequeueing from a queue that has more than one item...\n\n");
		tempPtr = headerD.front;
		headerD.front = tempPtr->forward; //might replace below code
										  //header.front = head.front->forward;
		headerD.count--;
	}
}

// FUNCTIONS FOR D DOWN

void enqueueDDown(struct node nodes2)
{
	//struct node *current;
	struct node *tempPtr;
	struct node *newPtr;

	// Empty Queue
	if (headerDDown.front == NULL)
	{
		//printf("Adding to the empty Queue...\n");
		newPtr = (struct node*)malloc(sizeof(struct node));
		newPtr->age = 20;
		newPtr->forward = NULL;

		headerDDown.front = newPtr;
		headerDDown.rear = newPtr;
		headerDDown.count++;
	}
	// At least one in the Queue
	else
	{
		//printf("Adding to a Queue with at least one item...\n");
		newPtr = (struct node*)malloc(sizeof(struct node));
		newPtr->age = 25;
		newPtr->forward = NULL;

		tempPtr = headerDDown.rear;
		headerDDown.rear = newPtr;
		tempPtr->forward = newPtr;
		headerDDown.count++;
	}

}

int dequeueDDown(struct node nodes2)
{
	struct node *tempPtr;

	// Empty Queue
	if (headerDDown.front == NULL)
	{
		printf("Cannot Dequeue from an empty list\n");
		return(1);
	}
	// One Structure in the Queue
	else if (headerDDown.front == headerDDown.rear)
	{
		//printf("Dequeueing from a queue with only one item...\n\n");
		tempPtr = headerDDown.front;
		headerDDown.front = NULL;
		headerDDown.rear = NULL;
		// Save the address of tempPtr
		headerDDown.count--;
		return(tempPtr);
	}
	else
	{
		//printf("Dequeueing from a queue that has more than one item...\n\n");
		tempPtr = headerDDown.front;
		headerDDown.front = tempPtr->forward; //might replace below code
											  //header.front = head.front->forward;
		headerDDown.count--;
	}
}

void enqueueE(struct node nodes2)
{
	//struct node *current;
	struct node *tempPtr;
	struct node *newPtr;

	// Empty Queue
	if (headerE.front == NULL)
	{
		//printf("Adding to the empty Queue...\n");
		newPtr = (struct node*)malloc(sizeof(struct node));
		newPtr->age = 20;
		newPtr->forward = NULL;

		headerE.front = newPtr;
		headerE.rear = newPtr;
		headerE.count++;
	}
	// At least one in the Queue
	else
	{
		//printf("Adding to a Queue with at least one item...\n");
		newPtr = (struct node*)malloc(sizeof(struct node));
		newPtr->age = 25;
		newPtr->forward = NULL;

		tempPtr = headerE.rear;
		headerE.rear = newPtr;
		tempPtr->forward = newPtr;
		headerE.count++;
	}

}

int dequeueE(struct node nodes2)
{
	struct node *tempPtr;

	// Empty Queue
	if (headerE.front == NULL)
	{
		printf("Cannot Dequeue from an empty list\n");
		return(1);
	}
	// One Structure in the Queue
	else if (headerE.front == headerE.rear)
	{
		//printf("Dequeueing from a queue with only one item...\n\n");
		tempPtr = headerE.front;
		headerE.front = NULL;
		headerE.rear = NULL;
		// Save the address of tempPtr
		headerE.count--;
		return(tempPtr);
	}
	else
	{
		//printf("Dequeueing from a queue that has more than one item...\n\n");
		tempPtr = headerE.front;
		headerE.front = tempPtr->forward; //might replace below code
										  //header.front = head.front->forward;
		headerE.count--;
	}
}
