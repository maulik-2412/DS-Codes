#include <stdio.h>
#include <stdlib.h>
struct vehicle {
  int mileage;
  struct vehicle *left;
  struct vehicle *right;
};
struct vehicle *root = NULL;
struct vehicle *insert(struct vehicle *root,struct vehicle *n)
{
    if(root == NULL)
    {
      return n;
    }
    else if(root -> mileage > n -> mileage)
    {
      root -> left = insert(root -> left, n);
    }
    else if(root -> mileage < n -> mileage)
    {
      root -> right = insert(root -> right, n);
    }
   return root;
} 
void inorder(struct vehicle *root)
{
  if(root == NULL)
  {
    return;
  }
  inorder(root->left);
  printf("%d \n",root -> mileage);
  inorder(root->right);
}
void preorder(struct vehicle *root)
{
  if(root == NULL)
  {
    return;
  }
  printf("%d \n",root -> mileage);
  inorder(root->left);
  inorder(root->right);
}
void postorder(struct vehicle *root)
{
    if(root == NULL)
  {
    return;
  }
  inorder(root->left);
  inorder(root->right);
  printf("%d \n",root -> mileage);
  
}
void deletion(struct vehicle *root,int k)
{
  struct vehicle *temp1 = root;
  struct vehicle *temp2 = root;
  while(temp1 -> mileage != k && temp1!=NULL)
    {
      if(k<temp1 -> mileage)
      {
        temp2 = temp1;
        temp1 = temp1 -> left;
      }
      else
      {
        temp2 = temp1;
        temp1 = temp1 -> right;
      }
    }
  if(temp1 == NULL)
  {
    printf("Element not found");
    return;
  }
  else if(temp1 -> right == NULL)
  {
    if(temp2 -> mileage > temp1 -> mileage)
    {
      temp2 -> left = temp1 -> left;
    }
    else
    {
      temp2 -> right = temp1 -> left;
    }
  }
  else if(temp1 -> left == NULL)
  {
     if(temp2 -> mileage > temp1 -> mileage)
    {
      temp2 -> left = temp1 -> right;
    }
    else
    {
      temp2 -> right = temp1 -> right;
    } 
  }
  else if(temp1 -> right != NULL && temp1 -> left != NULL)
{ 
  int a; 
  struct vehicle *temp3 = temp1;
   temp3 = temp3 -> right;
   while(temp3 -> left)
     {
       temp3 = temp3 -> left;
     }
  a = temp3 -> mileage;
  deletion(root, a);
  temp1 -> mileage = a;
}
}  
  
int main()
{
  
  int a,b;
  while(1)
    {
       printf("\n");
       printf("Enter option 1 to insert\n");
       printf("Enter option 2 for inorder trav\n");
       printf("Enter option 3 for preorder trav\n");
       printf("Enter option 4 for postorder trav\n");
       printf("Enter option 5 for deletion\n");
       scanf("%d",&a);
      if(a==1)
      {
        struct vehicle *n =((struct vehicle *)malloc(sizeof(struct vehicle)));  
        printf("Enter the mileage of the vehicle:");
        scanf("%d",&n -> mileage);
        root = insert(root,n);
        
      }
      else if(a==2)
      inorder(root);
      else if(a==3)
      {
        preorder(root);
      }
      else if(a==4)
      {
        postorder(root);
      }
      else if(a==5)
      {
        printf("Enter the number you wanna delete:");
        scanf("%d",&b);
        deletion(root,b);
      }
      else
      {
        return 0;
      }
      
    }  
}
