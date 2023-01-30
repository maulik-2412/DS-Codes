#include <stdio.h>
#include <stdlib.h>

struct listNode {
	int rollno;
	struct listNode* next;
};

typedef struct listNode node;

node* head = NULL;

void llinsert(int info, int c, int pos){
	node* n;
	n = (node*)malloc(sizeof(node));
	if (n){
		n->rollno = info;
		if (!head){
			n->next = NULL;
			head = n;
			return;
		}
		node* temp;
		switch (c){
			case 1:
				n->next = head;
				head = n;
				break;
			case 2:
				temp = head;
				while (temp->rollno!=pos && temp){
					temp = temp->next;
					if (!temp){
						printf("Position not found\n");
						break;
					}
				}
				n->next = temp->next;
				temp->next = n;
				break;
			case 3:
			    temp = head;
				while (temp->next!=NULL){
					temp = temp->next;
				}
				temp->next = n;
				n->next = NULL;
				break;
		}
	}
	else {
		printf("Overflow\n");
	}
	return;
}

void lldelete(int c, int pos){
    if (!head){
        printf("List Empty\n");
		return;
	}
    node* temp = head;
    node *temp2;
    switch (c){
        case 1:
            head = head->next;
            free(temp);
            break;
        case 2:
            if (temp->rollno==pos){
                head = head->next;
                free(temp);
                break;
            }
            while (temp->next->rollno!=pos && temp){
                temp = temp->next;
				if (!temp->next){
					printf("Position not found\n");
					break;
				}
            }
            temp2 = temp->next;
            temp->next = temp2->next;
            free(temp2);
            break;
        case 3:
            if (!head->next){
	            head = head->next;
	            free(temp);
	            break;
	        }
            while (temp->next->next!=NULL){
				temp = temp->next;
			}
			temp2 = temp->next;
			temp->next = NULL;
			free(temp2);
	        break;
    }
}

void reverse(){
    if (!head || !head->next){
        return;
    }
	node* a = head;    
	node* b = NULL;    
	node* c = a->next;   
	while (c!=NULL){
	    c = a->next;
	    a->next = b;
	    b = a;
	    a = c;
	}
	head = b;
	return;
}

void print(){
	if (!head){
		printf("List Empty\n");
		return;
	}
	node* temp = head;
	while (temp){
		printf("%d ", temp->rollno);
		temp = temp->next;
	}
	printf("\n");
	return;
}

int main(){
    int choice, c, info, pos;
    do {
        printf("1 - Insert, 2- Delete, 3 - Reverse, 4 - Print, 5 - Exit : ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                while(1){
                    printf("1 - Front, 2 - Pos, 3 - End, 4 - Exit : ");
                    scanf("%d", &c);
                    if (c==4){
                        break;
                    }
                    pos = -1;
                    printf("Add Roll No. : ");
                    scanf("%d", &info);
                    if (c==2){
                        printf("Insert after Roll No. : ");
                        scanf("%d", &pos);
                    }
                    llinsert(info,c,pos);
                }
                break;
            case 2:
                while (1){
                    printf("1 - Front, 2 - Pos, 3 - End, 4 - Exit : ");
                    scanf("%d", &c);
                    if (c==4){
                        break;
                    }
                    pos = -1;
                    if (c==2){
                        printf("Delete Roll No. : ");
                        scanf("%d", &pos);
                    }
                    lldelete(c,pos);
                }
                break;
            case 3:
                reverse();
                break;
            case 4:
                print();
                break;
        }
    } while (choice!=5);
}
