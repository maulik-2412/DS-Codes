#include<stdio.h> 
int size = 10;
int stack[10]; 
int top = -1; 
int isempty() { 
    if(top == -1) 
     return 1; 
    else 
     return 0; 
} 
int isfull() { 
    if(top == size)
     return 1; 
    else 
     return 0; 
}
int peek() { 
    return stack[top];
} 
int pop() { 
    int data; 
        if(!isempty()) {
     data = stack[top]; 
     top = top - 1; 
     return data;
    } else { 
        printf("Stack Underflow.\n");
    }
} 
int push(int data) { 
    if(!isfull()) { 
        top = top + 1; 
         stack[top] = data; 
    }   else { 
         printf("Stack Overflow.\n"); 
        } 
} 
int main() { 
    // push items on to the stack 
    push(4); 
    push(6); 
   push(8); 
   push(10); 
    pop(); 
    printf("Element at top of the stack: %d\n" ,peek()); 
    printf("Elements in the stack are: \n"); 
    // print stack data 
    while(!isempty()) { 
        int data = pop(); 
        printf("%d ",data); 
    } 
    printf("\n"); 
    return 0; 
}
