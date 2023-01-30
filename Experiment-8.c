#include <stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node
{
  int marks;
  struct Node *link;
};
struct Node *First;
void createEmptyList()
{
   First = NULL;
}

void display()
{
  struct Node*temp; 
  temp = First;
  printf("The list is\n");
  while(temp!=NULL)
    {
      printf("%d",temp -> marks);
      printf("\n");
      temp = temp -> link;
    }
  printf("\n");    
}
void insertAtEnd()
{
  struct Node*temp; 
  temp = First;
  struct Node *n = ((struct Node*)malloc(sizeof(struct Node)));
  
  printf("Enter the element:");
  scanf("%d",&n -> marks);
   if(n==NULL)
  {
    printf("Overflow");
    return;
  }
 
   else if(temp == NULL)
   {
     First = n;
     return;
   }
   else
   {
      while(temp->link!=NULL)
        {
           temp = temp -> link; 
        }
      temp -> link = n;
      n -> link = NULL;
   }
}
void deleteAtFirst()
{
  if(First == NULL)
  {
    printf("The list is empty\n");
    return;
  }
  else
  {
    struct Node*temp;
    temp = First;
    First = First -> link;
    free(temp);
    temp = NULL;
  }
}

int main() 
{
  int a;
  void createEmptyList();
  while(1)
    {
      printf("Enter 1 to display element\n");
      printf("Enter 2 to insert at end\n");
      printf("Enter 3 to delete at first\n");
      scanf("%d",&a);
    
       if(a==1)
      {
         display();
      }
      else if(a==2)
      {
        insertAtEnd();
      }
    
      else if(a==3)
      {
        deleteAtFirst();
      }
      else
      {
        return 0;
      }
    }
    
}

