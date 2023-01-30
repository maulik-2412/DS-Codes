#include<stdio.h> 
int main(){ 
    int n; 
    printf("Enter the total size of two stacks :\n "); 
    scanf("%d", &n); 
    int a[n]; 
    int ind1 = 0; 
    int ind2 = n-1; 
    int l = (n+1)/2; 
    int u = l-1; 
    while (1){ 
        int c; 
        printf("Enter your choice (1 - Push in stack 1, 2 - Pop in stack 1, 3 - Push in stack 2, 4 - Pop in stack 2, 5 - Exit) : \n"); 
        scanf("%d", &c); 
        if (c==5){ 
            printf("Fin!"); 
            break; 
        } switch (c){ 
            case 1: 
                if (ind1 == l){ 
                    printf(" First Stack Overflow\n"); 
                    break; 
                } 
                printf("Enter the element to push :\n "); 
                scanf("%d", &a[ind1]); 
                ind1++; 
                printf("Element Pushed!\n"); 
                break; 
            case 2: 
                if (ind1 == 0){ 
                    printf("First Stack Underflow\n"); 
                } 
                printf("Element Popped : %d\n", a[ind1]); 
                ind1--; 
                break; 
            case 3: 
                if (ind2 == u){ 
                    printf("Second Stack Overflow\n"); 
                    break; 
                } 
                printf("Enter the element to push :\n "); 
                scanf("%d", &a[ind2]); 
                ind1--; 
                printf("Element Pushed!\n"); 
                break; 
            case 4: 
                if (ind1 == n-1){ 
                    printf("Second Stack Underflow\n"); 
                } 
                printf("Element Popped : %d\n", a[ind2]); 
                ind2++; 
                break; 
        } 
    } 
        return 0; 
}