#include <stdio.h>
int main()
{
  int a[10][10], i, j, k, c1, c2, arr[10];
  k = 0;
  c1 = 0;
  c2 = 0;
  printf("Enter the matrix\n");
  for (i = 0; i < 3; i++)
    for (j = 0; j < 3; j++)
    {
      scanf("%d", &a[i][j]);
    }
  for (i = 0; i < 3; i++)
    for (j = 0; j < 3; j++) 
    {
      if (a[i][j] == 0) 
      {

        c1++;
      } else 
      {
        c2++;
      }
    }
  if (c1 > c2) 
  {
    for (i = 0; i < 3; i++)
      for (j = 0; j < 3; j++) 
      {
        if (a[i][j] != 0) 
        {
          arr[k] = a[i][j];
          k++;
        }
      }
    printf("The non zero elements are :");
    for (i = 0; i < k; i++) 
    {
      printf("%d", arr[i]);
    }
  } 
  else 
  {
    printf("You have entered the wrong way ");
  }

  return 0;
}
