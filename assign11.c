/*
    Name: Shaurya Gupta
    Roll No: 1601CS43
    Date: 4/4/17
    Objective: Implement BST along with preorder printing and finding largest max level leaf and smallest minimum level leaf
*/

#include "stdio.h"
#include "stdlib.h"
struct _node{
    int data;
    struct _node *leftChild; //points to left child
    struct _node *rightChild; //points to right child
    struct _node *parent; //points to parent
};
typedef struct _node *NODEPTR;
typedef struct pair{
    int first;
    int second;
} pair; // pair of 2 integers
// print in preorder tabular form recursively
void printParent(NODEPTR root);
// returns pair containing largest leaf data and level
pair largest(NODEPTR root, int level);
// returns pair containing smallest leaf data and level
pair smallest(NODEPTR root, int level);

int n;
int main(void) {
    int x; //temp variable for storing each number
    int i; // loop variable
    do {
        // get input
        printf("Enter number of elements: ");
        scanf("%d", &n);
    } while(n <= 0);
    NODEPTR head = NULL, r, newNode;
    printf("Enter elements: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &x);
        r = head;
        // new node
        newNode = (NODEPTR)(malloc(sizeof(struct _node)));
        newNode -> data = x;
        newNode -> parent = newNode -> leftChild = newNode -> rightChild = NULL;
        // insert element
        while(r != NULL) {
            // go to left child
            if(x <= r-> data) {
                if(r->leftChild == NULL) {
                    r->leftChild = newNode;
                    newNode -> parent = r;
                    break;
                }
                r = r->leftChild; 
            }
            // go to right child
            else { 
                if(r->rightChild == NULL) {
                    r->rightChild = newNode;
                    newNode -> parent = r;
                    break;
                }
                r = r->rightChild;                 
            }
        }
        // get the real head
        if(head == NULL) head = newNode;
    }
    // print in pre order
    printParent(head);
    // largest leaf of max level
    pair largestLeaf = largest(head,0);
    printf("Largest leaf from maximum level: element %d level %d\n",largestLeaf.first, largestLeaf.second);
    // largest leaf of min level
    pair smallestLeaf = smallest(head,0);
    printf("Smallest leaf from minimum level: element %d level %d\n",smallestLeaf.first, smallestLeaf.second);
}

void printParent(NODEPTR root) {
    if(root == NULL) return; // nothing to print
    if(root->parent == NULL) {
        // print initial stuff if head
        printf("|Node  | Parent   |\n");
        printf("|%5d | ", root->data);
        printf("No parent|\n");
    }
    else
        printf("|%5d |%9d |\n",root->data, root->parent->data);
    // print recursively   
    printParent(root -> leftChild);
    printParent(root -> rightChild);
}

pair largest(NODEPTR root, int level) {
    // root is null, we return a pair that is always less since level is -1.
    if(root == NULL) {
        pair ret;
        ret.second = -1;
        return ret;
    }
    if(root->leftChild == NULL && root-> rightChild == NULL) {
        pair ret;
        ret.first = root->data;
        ret.second = level;
        return ret;  
    }
    // compare information from two child nodes of next level
    pair n1 = largest(root->leftChild, level+1);
    pair n2 = largest(root->rightChild, level+1);
    // compare level
    if(n1.second > n2.second) return n1;
    else if(n1.second < n2.second) return n2;
    // if same level compare data
    else if(n1.first > n2.first) return n1;
    else return n2;
}
pair smallest(NODEPTR root, int level) {
    // root is null, we return a pair that is always more since level is n+5.
    if(root == NULL) {
        pair ret;
        ret.second = n+5;
        return ret;
    }
    // if leaf
    if(root->leftChild == NULL && root-> rightChild == NULL) {
        pair ret;
        ret.first = root->data;
        ret.second = level;
        return ret;  
    }
    // compare information from two child nodes of next level
    pair n1 = smallest(root->leftChild, level+1);
    pair n2 = smallest(root->rightChild, level+1);
    if(n1.second < n2.second) return n1;
    else if(n1.second > n2.second) return n2;
    else if(n1.first < n2.first) return n1;
    else return n2;
}
