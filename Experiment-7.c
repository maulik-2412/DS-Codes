#include <stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node*next;
};
struct Node*top=NULL;
void push(int value) {
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value; // assign value to the node
    if (top == NULL) {
        newNode->next = NULL;
    } else {
        newNode->next = top; // Make the node as top
    }
    top = newNode; // top always points to the newly created node
    printf("Node is Inserted\n");
}
int pop(){
    if(top==NULL){
        printf("Stack Underflow\n");
    }
   else {
        struct Node *temp = top;
        int temp_data = top->data;
        top = top->next;
        free(temp);
        return temp_data;
    }
}
void Traverse(){
    if(top==NULL){
        printf("stack is empty\n");
    }
       else {
        printf("The stack is \n");
        struct Node *temp = top;
        while (temp->next != NULL) {
            printf("%d--->", temp->data);
            temp = temp->next;
        }
        printf("%d--->NULL\n\n", temp->data);
    }
}
int peek(int pos){
    struct Node* ptr = top;
    if(ptr!=NULL){
        return ptr->data;
    }
    else{
        return -1;
    }
}
 int main() {
    int choice,value;
    printf("Implementation of stack using linked list\n");
    while(1){
    printf("1. Push\n2. Pop\n3. Traverse\n4. Peek\n5.Exit\n");
    printf

 ("Enter the choice of operation to perform\n");
    scanf("%d",&choice);
       switch(choice){
        case 1:
        printf("enter the value you want to push in stack\n");
        scanf("%d",&value);
        push(value);
        break;
        case 2:
        printf("Popped Element is %d\n",pop());
        break;
        case 3:
        printf("Traversing of the stack\n");
        Traverse();
        break;
        case 4:
        printf("Peek element of the stack is %d\n",peek(value));
        break;
        case 5:
        printf("Exit\n");
        break;
    }
    }
    return 0;
}
