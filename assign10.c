/*
    name : shaurya gupta
    roll no: 1601cs43
    date: 28/3/17
    objective: replicate a big integer data structure that supports addition and subtraction
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// circular double linked list
typedef struct node {
    int data;
    struct node* next;
    struct node* prev;
} node;
// min of 2 integers
int min(int a, int b) {
    return (a < b) ? a : b;
}
// absolute value
int abs(int a) {
    return (a>0) ? a : -a;
}
// gets a big integer and forms the linked list
node* getint() {
    char buff[1000], num[5]; // buffer
    scanf("%s%*c", buff); // get input
    int parts = 0, i, len = strlen(buff), j; // loop variables and length
    node *head = (node*) malloc(sizeof(node)), *end = head; // linked list
    int start = (buff[0] == '-') ? 1 : 0; // for minus sign
    for(i = len-1, j = 5; i>=start; i--) {
        num[j-1] = buff[i];
        j--;
        // form node
        if(!j || i==start) {
            parts++;
            end->next = (node*) malloc(sizeof(node));
            end->next->prev = end;
            end = end->next;
            end->data = atoi(num + j);
            j = 5;
        }
    }
    // circular
    head->prev = end;
    head->data = (start) ? -parts : parts;
    end->next = head;
    return head;
}
// compare 2 numbers
int compare(node* num1, node* num2) {
    node* r1 = num1-> prev, *r2 = num2-> prev;
    int n1 = abs(num1->data), n2 = abs(num2->data);
    // ignore leading zeroes
    while(r1!=num1 && !(r1->data)) {r1 = r1->prev; n1--; }
    while(r2!=num2 && !(r2->data)) {r2 = r2->prev; n2--; }
    // compare abs values initially
    if (n1==0 && n2==0) return 0;
    else if (!n1) return (num2->data < 0) ? 1 : -1;
    else if (!n2) return (num1->data < 0) ? -1 : 1;
    int ans = 0;
    if(n1>n2) ans = 1;
    else if(n1<n2) ans = -1;
    else {
        while(r1 != num1 && r2 != num2) {
            if(r1->data == r2->data) {
                r1 = r1->prev;
                r2 = r2->prev;
                continue;
           }
            ans = (r1-> data < r2-> data) ? -1 : 1;
            break;
        }
    }
    // now compare signs as well
    if(num1->data > 0 && num2-> data < 0) return 1;
    else if(num1->data <0 && num2->data > 0) return -1;
    else if(num2->data < 0) return -ans;
    else return ans;
}
// use this recursive function for carrying while subtracting
void carryOver(node* x) {
    if(x->data == 0) {
        carryOver(x->next);
        x->data = 99999;
    } else x->data = x->data - 1;
}
// subtracts two negative numbers
node* subt(node* num1, node* num2) {
    node* r1 = num1->next, *r2 = num2->next, *num3 = (node*) malloc(sizeof(node));
    node* end = num3;
    int a1, a2, parts = 0;
    do {
        if(r1 != num1) a1 = r1->data;
        else a1 = 0;
        if(r2 != num2) a2 = r2->data;
        else a2 = 0;
        end-> next = (node*) malloc(sizeof(node));
        end->next->prev = end;
        end = end-> next;
        if(a1 < a2) {
            carryOver (r1->next);
            a1 += 100000;
        }
        int val = a1 - a2;
        end -> data = val;
        parts++;
        if(r1 != num1) {r1 = r1-> next;}
        if(r2 != num2) {r2 = r2-> next;}
    } while(r1!=num1 || r2 != num2);
    num3->prev = end;
    num3->data = parts;
    end->next = num3;
    return num3;
}
// adds two numbers
node* add(node* num1, node* num2) {
    node* r1 = num1->next, *r2 = num2->next;
    node* num3 = (node*) malloc(sizeof(node)), *end = num3;
    int times = min(abs(num1->data), abs(num2->data));
    int i,a1,a2;    
    int leftOver = 0, parts = 0;
    do {
        if(r1 != num1) {a1 = r1->data;}
        else a1 = 0;
        if(r2 != num2) {a2 = r2->data;}
        else a2 = 0;
        end-> next = (node*) malloc(sizeof(node));
        end->next->prev = end;
        end = end-> next;
        int val = a1 + a2 +leftOver;
        leftOver = val/100000;
        val = val%100000;
        end -> data = val;
        parts++;
        if(r1 != num1) {r1 = r1-> next;}
        if(r2 != num2) {r2 = r2-> next;}
    } while(r1!=num1 || r2 != num2 || leftOver);
    num3->prev = end;
    num3->data = parts;
    end->next = num3;
    return num3;
}
// calls the add and subtract function depending on sign and which number is greater.
node* combine(node* num1, node* num2) {
    int n1 = num1-> data, n2 = num2->data;
    if(n1 < 0 && n2 < 0) {
        num1->data = -n1;
        num2->data = -n2;
        node* ans = add(num1, num2);
        ans->data = -ans->data;
        return ans;
    } else if(n1 > 0 && n2 > 0) return add(num1, num2);
    else {
        num1->data = abs(n1);
        num2->data = abs(n2);
        int greater = compare(num1, num2);
        node * ans = (greater > 0) ? subt(num1, num2) : subt(num2, num1);
        if(greater < 0) ans -> data = -ans->data;
        return ans;
    }
}
// print number
void print(node* num) {
    if(!num->data) {printf("0\n"); return;} // empty list
    node* r = num-> prev;
    // remove leading zeroes
    while(!r->data) r = r-> prev;
    if(r == num) {printf("0\n"); return;}
    if(num->data < 0) printf("-");
    printf("%d ", r->data);
    r = r-> prev;
    while(r != num) {
        printf("%05d ",r->data);
        r = r-> prev;
    }
    printf("\n");
}

int main(void) {
    char choice;
    while(1) {
        do {
        	printf("Enter c for compare, a for addition, s for subtraction and x for exit: ");
        	scanf("%c", &choice);
        } while(choice == '\n');
        while(getchar() != '\n') {}
        if(choice == 'x') break;
        if(choice == 'c') {
        	node *num1 = getint();
        	node *num2 = getint();
            int cmp = compare(num1, num2);
            if(!cmp) printf("The numbers are equal\n");
            else if(cmp > 0) printf("The first number is greater\n");
            else printf("The second number is greater\n");
        }
        else if(choice == 's' || choice == 'a') {
        	node *num1 = getint();
        	node *num2 = getint();
            if(choice == 's') {
            	num2->data = -(num2->data);
                printf("Difference is: ");
            }
            else printf("Sum is: ");
            print(combine(num1, num2));
        } else printf("Wrong input\n");
    }
}