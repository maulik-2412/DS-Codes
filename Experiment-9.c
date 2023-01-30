#include <stdio.h>
#include <stdlib.h>
struct listNode {
    int data;
    struct listNode* next;
    struct listNode* prev;
};
typedef struct listNode node;
node* head = NULL;
void insertAtFront(int info){
    node* n;
    n = (node*)malloc(sizeof(node));
    if (n){
        n->data = info;
        if (!head){
            n->next = n;
            n->prev = n;
            head = n;
        }
        else {
            head->prev->next = n;
            n->prev = head->prev;
            head->prev = n;
            n->next = head;
            head = n;
        }
    }
    else {
        printf("Overflow\n");
    }
}
void insertAtMid(int info, int pos){
    node* n;
    n = (node*)malloc(sizeof(node));
    if (n){
        n->data = info;
        if (!head){
            n->next = n;
            n->prev = n;
            head = n;
        }
        else {
            node* temp = head;
            while(temp->data!=pos) {
                temp = temp->next;
                if (temp == head){
                    printf("Element not found!\n");
                    return;
                }
            } 
            temp->next->prev = n;
            n->next = temp->next;
            n->prev = temp;
            temp->next = n;
        }
    }
    else {
        printf("Overflow\n");
    }
}
void insertAtEnd(int info){
    node* n;
    n = (node*)malloc(sizeof(node));
    if (n){
        n->data = info;
        if (!head){
            n->next = n;
            n->prev = n;
            head = n;
        }
        else {
            head->prev->next = n;
            n->prev = head->prev;
            head->prev = n;
            n->next = head;
        }
    }
    else {
        printf("Overflow\n");
    }
}
void deletionAtFront(){
    if (!head){
        printf("List Empty!\n");
        return;
    }
    if (head->next == head){
        node* temp = head;
        head = NULL;
        free(temp);
        return;
    }
    node* temp = head;
    head->prev->next = head->next;
    head->next->prev = head->prev;
    head = head->next;
    free(temp);
}
void deletionAtMid(int pos){
    if (!head){
        printf("List Empty!\n");
        return;
    }
    if (head->next == head){
        node* temp = head;
        head = NULL;
        free(temp);
        return;
    }
    node* temp = head;
    while(temp->data!=pos) {
        temp = temp->next;
        if (temp == head){
            printf("Element not found!\n");
            return;
        }
    } 
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
}
void deletionAtEnd(){
    if (!head){
        printf("List Empty!\n");
        return;
    }
    if (head->next == head){
        node* temp = head;
        head = NULL;
        free(temp);
        return;
    }
    node* temp = head->prev;
    head->prev->prev->next = head;
    head->prev = head->prev->prev;
    free(temp);
}
void display(){
    if (!head){
        printf("List Empty!\n");
        return;
    }
    node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while(temp!=head);
    printf("\n");
}
int main() {
    int c,e,d,p;
    while (1){
        printf("Choice (1 - Insert, 2 - Delete, 3 - Display, 4 - Exit) : ");
        scanf("%d",&c);
        if (c==4){
            printf("Fin!\n");
            break;
        }
        switch (c){
            case 1:
                printf("Choice (1 - Insertion at Front, 2 - Insertion at Middle, 3 - Insertion at End, 4 - Exit) : ");
                scanf("%d",&e);
                switch(e){
                    case 1:
                        printf("Enter data for new node : ");
                        scanf("%d",&d);
                        insertAtFront(d);
                        break;
                    case 2:
                        printf("Enter data for new node : ");
                        scanf("%d",&d);
                        printf("Position to insert after : ");
                        scanf("%d",&p);
                        insertAtMid(d, p);
                        break;
                    case 3:
                        printf("Enter data for new node : ");
                        scanf("%d",&d);
                        insertAtEnd(d);
                        break;
                    case 4:
                        break;
                }
                break;
            case 2: 
                printf("Choice (1 - Deletion at Front, 2 - Deletion at Middle, 3 - Deletion at End, 4 - Exit) : ");
                scanf("%d",&e);
                switch(e){
                    case 1:
                        deletionAtFront();
                        break;
                    case 2:
                        printf("Position to delete : ");
                        scanf("%d",&p);
                        deletionAtMid(p);
                        break;
                    case 3:
                        deletionAtEnd();
                        break;
                    case 4:
                        break;
                }
                break;
            case 3:
                display();
                break;
        }
    }
    return 0;
}
