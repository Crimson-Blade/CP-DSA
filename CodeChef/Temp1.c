#include <stdio.h>
int main()
{
  int arr[100][100];
  int m, n;
  printf("Input n and m ");
  scanf("%d %d", &n, &m);
  int i, j, k;
  int sum = 0;
  int count;
  int countarr[100];
  for (i = 0; i < n; i++)
  {
    for (j = 0; j < m; j++)
    {
      printf("Enter value for arr[%d][%d]:", i, j);
      scanf("%d", &arr[i][j]);
    }
  }

  // Finding cumulative-zero-sum
  for (i = 0; i < n; i++)
  {
    sum = 0;
    countarr[i] = 0;
    for (j = 0; j < m; j++)
    {
      sum = 0;
      for (k = j; k < m; k++)
      {
        sum += arr[i][k];
        printf("%d \n", arr[i][k]);
        if (sum == 0)
        {
          count++;
          countarr[i]++;
          break;
        }
      }
    }
  }
  printf("1D array \n");
  for (i = 0; i < n; i++)
    printf("%d %d\n", i, countarr[i]);
}