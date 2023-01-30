#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct TreeNode{
    int val;
    struct TreeNode *left,*right;
};
struct TreeNode* insert(struct TreeNode *root,int n){
    if(root==NULL){
        struct TreeNode* temp=(struct TreeNode*)malloc(sizeof(struct TreeNode));
        temp->val=n;
        temp->right=NULL;
        temp->left=NULL;
        root=temp;
    }
    else{
        if(root->val>n){
            if(root->left==NULL){
                struct TreeNode* temp=(struct TreeNode*)malloc(sizeof(struct TreeNode));
                temp->val=n;
                temp->right=NULL;
                temp->left=NULL;
                root->left=temp;
            }
            else
                root->left=insert(root->left,n);
        }
        else{
            if(root->right==NULL){
                struct TreeNode* temp=(struct TreeNode*)malloc(sizeof(struct TreeNode));
                temp->val=n;
                temp->right=NULL;
                temp->left=NULL;
                root->right=temp;
            }
            else
                root->right=insert(root->right,n);
        }
    
    }
    return root;
}
struct TreeNode* delete(struct TreeNode *root,int n){
    if(root==NULL){
        printf("Element Not Found!!!");
    }
    else{
        if(root->val=n){
            if(root->left==NULL){
                root=root->right;
            }
            else{
                
                struct TreeNode* temp=root->right;
                if(temp->left==NULL){
                    temp->left=root->left;
                    root=temp;
                    return root;
                }    
                while(temp->left!=NULL && temp->left->left!=NULL){
                    temp=temp->left;
                }
                if(temp->left->right==NULL){
                    root->val=temp->left->val;
                    temp->left=NULL;
                }
                else{
                    root->val=temp->left->val;
                    temp->left=temp->left->right;
                }
            }
        }
        else if(root->val>n)
            root->left=delete(root->left,n);
        else
            root->right=delete(root->right,n);
    }
    return root;
}
void inorder(struct TreeNode* root){
    if(root==NULL)
        return;
    inorder(root->left);
    printf("%d ",root->val);
    inorder(root->right);
}
void preorder(struct TreeNode* root) {
	if (root == NULL) {
    	return;
	}
	printf("%c ", root->val);
	preorder(root->left);
	preorder(root->right);
}

void postorder(struct TreeNode* root) {
	if (root == NULL) {
    	return;
	}
	postorder(root->left);
	postorder(root->right);
	printf("%c ", root->val);
}

int main(){
    system("cls");
    struct TreeNode* root=NULL;
    int c=0,n;
    printf("1.Insert element");
    printf("\n2.Delete element");
    printf("\n3.Inorder");
    printf("\n4.Preorder");
    printf("\n5.Postorder");
    printf("\n6.Exit\n");
    while(c<=4){
        printf("Enter your choice:");
        scanf("%d",&c);
        switch(c){
            case 1:
                {
                printf("Enter new element=");
                scanf("%d",&n);
                root=insert(root,n);
                break;
                }
            case 2:
                {
                printf("Enter element to delete=");
                scanf("%d",&n);
                root=delete(root,n);
                break;
                }
            case 3:
                {
                inorder(root);
                printf("\n");
                break;
                }
            case 4:
                {
                preorder(root);
                printf("\n");
                break;
                }
          case 5:
               {
                postorder(root);
                printf("\n");
                break;
               }
          case 6:
               {
                 exit(0);
            
               }    
        }
    }
    return 0;
}

