/*
	Name: Shaurya Gupta
	Roll No: 1601CS43
	Date: 14/3/2017
	Objective: Constructs and linkedlist and provide interface for printing, swapping nodes and reversing the list.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int found; // global variable for checking whether element found in linkedlist.
// definintion of node for linkedlist
typedef struct node{
	char roll[5];
	float cpi;
	float attendance;
	struct node* next;
} node;
node* head; // pointer to head node;
// this function adds a node at the end of linked list given the end node.
node* addNode(node* end) {
	// allocate new node and insert at end.
	node * newElement = (node*)malloc(sizeof(node));
	end->next = newElement;
	newElement->next = NULL;
	// get values of new node and add it to end node.
	printf("Enter elements of the node\n");
	printf("Enter the roll: ");
	scanf("%s", end->roll);
	printf("Enter the cpi: ");
	scanf("%f%*c",&(end->cpi));
	printf("Enter the attendance: ");
	scanf("%f%*c",&(end->attendance));
	// return pointer to new element.
	return newElement;
}
// given the starting node, this function prints a linked list.
void print() {
	node* r = head;
	int started = 0; // indicates whether we have started printing or not ( for comma purpose )
	// the last element of the linkedlist is useless and only marks the end.
	while(r->next != NULL) {
		if(started) printf(" , ");
		printf("<%s,%f,%f>", (r->roll), (*r).cpi, (*r).attendance);
		started = 1;
		r = r->next;
	}
	printf("\n\n");
}
// given a string and starting position in linked list, this searches for element with this roll no and returns addres to previous node.
node* search(char * s) {
	node* r = head;
	found = 0;
	node* prev = NULL;
	while(r-> next != NULL) {
		if(!strcmp(s,r->roll)) {
			found = 1;
			return prev;
		}
		prev = r;
		r = r->next;
	}
	return NULL;
}
// this swaps two nodes in linked list given their previous node pointers.
void swap(node* prev1, node* prev2) {
	if(prev1 == prev2) return; // if same do nothing
	node* node1 = (prev1 != NULL) ? prev1 -> next: head; // if prev is null, set node to head else set to next of prev
	node* node2 = (prev2 != NULL) ? prev2 -> next: head;
	node* tmp;
	// change arrows from prev1 and prev 2
	if (prev1 != NULL)
		prev1->next = node2;
	else head = node2;
	if (prev2 != NULL)
		prev2->next = node1;
	else head = node1;
	//change arrows from node1 and node 2
	tmp = node2 -> next;
	node2-> next = node1 -> next;
	node1 -> next = tmp;
}
// given the size of linkedlist and the starting node, this reverse the linkedlist.
void reverse(int size) {
	int i,j,k; // loop variable
	for(i = 0; i < size/2; i++) {
		node* n1 = head; // pointer to first node
		node* p1 = NULL;
		node* n2 = head;// pointer to second node;
		node* p2 = NULL;
		j = 0; k = 0;
		while (k != i) {
			k++;
			p1 = n1;
			n1 = n1->next;
		}
		// use the invariant that for reverse, i is moved to size - i - 1
		while (j != size - i - 1) {
			j++;
			p2 = n2;
			n2 = n2->next;
		}
		// once we have found node previous to the jth node correponding to ith node, swap.
		swap(p1,p2);
	} 
}

int main (void) {
	// char to store user response y/n
	char response;
	// stores instruction 0,1,2,3 and number of nodes in linkedlist
	int instruction, numNodes = 0;
	// string buffer
	char buffer[5];
	// head node pointer
	head = (node*) malloc(sizeof (node));
	// end node pointer
	node* end = head;
	head->next = NULL;
	// add nodes while response is 'y'
	// note that the end node doesn't store any roll number, only marks the end of linked list
	do {
		// get next node
		end = addNode(end);
		numNodes++; // increment number of nodes
		printf("\nAny more node (y/n): ");
		scanf("%c%*c", &response);
		// if user gives invalid input
		if(response != 'n' && response != 'y') {
			printf("invalid response. exiting.\n");
			return 0;
		}
	} while (response != 'n');
	// get instructions while not == 0
	do {
		printf("Enter 1 for print, 2 for swap ,3 for reverse, 0 for exit:");
		scanf("%d%*c", &instruction);
		if(instruction == 1)
			print(); // print linkedlist
		else if(instruction == 2) {
			printf("Enter roll of first node to be swapped: ");
			scanf("%s", buffer);
			node* prev1 = search(buffer); // search for first node
			printf("Enter roll of second node to be swapped: ");
			scanf("%s", buffer);
			node* prev2;
			// if first roll number found, search for second roll number.
			if(found) prev2 = search(buffer); // search for second node
			if(!found) printf("Not Found. Unable to swap.\n\n");
			else {
				swap(prev1, prev2);
				printf("Successfully swapped. \n\n");
			}
		} else if(instruction == 3) {
			// reverse
			reverse(numNodes);
			printf("Reverse operation is successfully done.\n\n");
		}
	} while(instruction != 0);
	printf("\n Program ends.\n"); // end program
	return 0;
}
