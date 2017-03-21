/*
    Name: Shaurya Gupta
    Roll No: 1601cs43
    Date: 21/3/2017
    Objective: Build a linkedlist and sort it based on two parameters simultaneously.
*/

#include "stdio.h"
#include "stdlib.h"

#define HEIGHT 1
#define WEIGHT 0
// node for linkedlist
typedef struct _node {
  char roll [11];
  int ht; 
  int wt; 
  struct _node *nextht; 
  struct _node *nextwt; 
} node;
// alias node* as list
typedef node *list;
// prints linkedlist l based on option = HEIGHT or WEIGHT
void printNameList(list L, int option);
// sort based on height
void sort_ht(list L);
// sort  based on weight
void sort_wt(list L);

// number of users in linked list
int numUsers;
int main (void) {
    int i; // loop variables
    scanf("%d", &numUsers);
    while(getchar() != '\n') {} // remove whitespace and newline
    list l = (node*) malloc(sizeof (node)); // dummy header
    list end = l;
    end->nextht = end->nextwt = NULL;
    for(i = 0; i < numUsers; i++) {
        end->nextwt = end->nextht = (list)malloc(sizeof(node)); // new node
        end = end->nextht; // move end pointer
        end->nextht = end->nextwt = NULL;
        // get info for the new node
        scanf("%*c%[^\"]%*c%d%d", end->roll, &(*end).ht, &(*end).wt);
        while(getchar() != '\n') {} // remove whitespace and newline
    }
    // sort
    sort_ht(l);
    sort_wt(l);
    // print
    printNameList(l,HEIGHT);
    printNameList(l,WEIGHT);
} 
// function to print the list
void printNameList(list L, int option) {
    list r = L; // node pointer 
    if(r->nextht==NULL) return; // empty list
    if(option == HEIGHT) { // print height
        r=r->nextht; 
        printf("Sort using height: ");
        while(1) {
            printf("%s",r->roll);
            // if at the end of the list
            if(r->nextht == NULL) {
                printf("\n");
                break;
            }
            printf(", ");
            r = r->nextht; // move iterator forward
        }
    }
    else if(option == WEIGHT) { // print weight
        r=r->nextwt;
        printf("Sort using weight: ");
        while(1) {
            printf("%s",r->roll);
            // if at the end of list
            if(r->nextwt == NULL) {
                printf("\n");
                break;
            }
            printf(", ");
            r = r->nextwt; // move weight iterator forward
        }
    }
}
// function to sort linkedlist based on height
void sort_ht(list L) {
    if(L->nextht==NULL) return; // if empty list
    int i,round;
    // bubble sort n-1 times
    for(round = 0; round < numUsers-1; round++) {
        list prev = L, curr = prev->nextht;
        // start from the first element that dummy head points to
        for(i = 0; i < numUsers-1; i++) {
            if(curr->ht < curr->nextht->ht) {
                // swap
                prev->nextht = curr->nextht;
                curr->nextht = curr->nextht->nextht;
                prev->nextht->nextht = curr;
                prev = prev->nextht;
                continue;
            }
            // move iterator forward
            prev = curr;
            curr = curr->nextht;
        }
    }
}
// function to sort linkedlist based on weight
void sort_wt(list L) {
    if(L->nextwt==NULL) return; // if empty list
    int i,round;
    // bubble sort n-1 times
    for(round = 0; round < numUsers-1; round++) {
        list prev = L, curr = prev->nextwt;
        // start from the first element that dummy head points to
        for(i = 0; i < numUsers-1; i++) {
            if(curr->wt < curr->nextwt->wt) {
                // swap
                prev->nextwt = curr->nextwt;
                curr->nextwt = curr->nextwt->nextwt;
                prev->nextwt->nextwt = curr;
                prev = prev->nextwt;
                continue;
            }
            // move iterator forward
            prev = curr;
            curr = curr->nextwt;
        }
    }
}

