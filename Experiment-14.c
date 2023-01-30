#include <stdio.h>
#define size 8
int arr[size];
void initialiseArray(){
    for(int i=0;i<size;i++){
        arr[i]=-1;
    }
}
void insert(int element){
    int key=element%size;
    if(arr[key]==-1){
        arr[key]=element;
        printf("Element %d inserted at arr[%d]\n",element,key);
    }
    else{
        printf("Collision: arr[%d] has element %d already\n",key,arr[key]);
    }
}
void delete(int element){
    int key=element%size;
    if(arr[key]==element){
        arr[key]=-1;
        printf("Element %d is deleted from position arr[%d]\n",element,key);
    }
    else{
        printf("Element %d is not present in Hash Table\n");
    }
}
void search(int element){
    int key=element %size;
    if(arr[key]==element){
        printf("Element found\n");
    }
    else{
        printf("Element not found\n");
    }
}
void print(){
    printf("Array is:\n");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int main() {
    initialiseArray();
    insert(7);
    insert(6);
    insert(3);
    insert(1);
    print();
    search(10);
    search(6);
    delete(3);
    print();
    return 0;
}

