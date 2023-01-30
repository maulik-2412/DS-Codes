#include <stdio.h>
#include <stdlib.h>

struct listNode {
    int eno;
    struct listNode* next;
};
typedef struct listNode node;
node* head = NULL;
void insertionAtFront(int info){
    node* n;
    n = (node*)malloc(sizeof(node));
    if (n){
        n->eno = info;
        if (!head){
            n->next = n;
            head = n;
            return;
        }
        node* temp = head;
        do {
            temp = temp->next;
        } while (temp->next != head);
        temp->next = n;
        n->next = head;
        head = n;
    }
    else {
        printf("Overflow\n");
    }
    return;
}
void deletionAtEnd(){
    if (!head){
        printf("List Empty\n");
        return;
    }
    node* temp = head;
    if (head->next == head){
        free(temp);
        head = NULL;
        return;
    }
    do {
        temp = temp->next;
    } while (temp->next->next != head);
    node* temp2 = temp->next;
    temp->next = head;
    free(temp2);
    return;
}
void print(){
    if (!head){
        printf("List Empty\n");
        return;
    }
    node* temp = head;
    do {
        printf("%d ", temp->eno);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
    return;
}
int main(){
    int c,e;
    while (1){
        printf("Choice (1 - Inserion at Front, 2 - Deletion at End, 3 - Print, 4 - Exit) : ");
        scanf("%d",&c);
        if (c==4){
            printf("Fin!\n");
            break;
        }
        switch (c){
            case 1:
                printf("Enter the eno of new student : ");
                scanf("%d",&e);
                insertionAtFront(e);
                printf("Element Inserted!\n");
                break;
            case 2: 
                deletionAtEnd();
                printf("Element Deleted!\n");
                break;
            case 3:
                print();
                break;
        }
    }
    return 0;
}
