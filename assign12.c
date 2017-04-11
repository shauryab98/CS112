/*
    Name: Shaurya Gupta
    Roll No: 1601CS43
    Date: 11/04/2017
    Objective: using files, get inorder and postorder and then write preorder
*/
#include "stdio.h"
#include "stdlib.h"
typedef struct node {
    struct node* left;
    struct node* right;
    char data;
} node;
typedef node* nodeptr;
// function to form tree given inorder and postorder as well as the indices of inorder that indicate subtree
nodeptr tree(int start, int end, int nodes, char* inorder, char *postorder) {
    // empty subtree
    nodeptr root = (nodeptr)(malloc(sizeof(node)));
    if(start > end) {
        return NULL;
    }
    // i is loop variable, splitAt is root of current subtree
    int i, highestIndex = 0, splitAt;
    // here we find the root of current subtree by finding the node that is farthest in postorder
    for(i = start; i <= end; i++) {
        int j;
        for(j = 1; j <= nodes; j++) {
            if(postorder[j] == inorder[i] && j > highestIndex) {
                highestIndex = j;
                splitAt = i;
                break;
            }
        }
    }
    // case when input is invalid tree
    if(!highestIndex) {
        printf("Tree cannot be formed\n");
        exit(0);    
    }
    // insert data into node and get left and right subtree
    root -> data = inorder[splitAt];
    root -> left = tree(start, splitAt - 1, nodes, inorder, postorder);
    root -> right = tree(splitAt + 1, end, nodes, inorder, postorder);
    return root;
}
void preorder(nodeptr head, FILE* out) {
    if(head == NULL)
        return;
    fprintf(out, "%c ", head->data);
    preorder(head->left, out);
    preorder(head->right, out);   
}
int main(void) {
    // store inorder and postorder
    char inorder[1000], postorder[1000];
    // number of nodes
    int nodes = 0;
    // temporary char storage variable
    char c;
    FILE *input = fopen("ipseq.txt", "r");
    if(input == NULL) {
        printf("ipseq can't be opened\n");
        return 0;
    }
    FILE *output = fopen("1601CS43.txt", "w");
    // get inorder
    while(1) {
        if(fscanf(input, "%c", &c) == EOF || c == '\n') break;
        if(c == ' ') continue;
        inorder[++nodes] = c;
    }
    // if first line has no nodes
    if(!nodes) {
        printf("invalid input file\n");
        return 0;
    }
    // tmp for checking whether inorder and postorder have same number of nodes
    int tmpNodeCount = 0;
    while(1) {
        if(fscanf(input, "%c", &c) == EOF || c == '\n') break;
        if(c == ' ') continue;
        postorder[++tmpNodeCount] = c;
    }
    if(tmpNodeCount != nodes) {
        printf("Invalid input file\n");
        return 0;
    }
    // get preorder
    nodeptr head = tree(1, nodes, nodes, inorder, postorder);
    preorder(head, output);
    fprintf(output, "\n");
    // close files
    fclose(input);
    fclose(output);
}
