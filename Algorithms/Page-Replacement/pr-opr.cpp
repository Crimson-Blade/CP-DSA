#include <stdio.h>
#include <stdbool.h>
// optimal
int main()
{
  int nf, np;
  printf("Enter the number of frames available : ");
  scanf("%d", &nf);
  printf("Enter the number of pages : ");
  scanf("%d", &np);
  int page[np], frame[nf], next[np];
  printf("Enter the pages : ");
  for (int i = 0; i < np; i++)
  {
    scanf("%d", &page[i]);
  }
  for (int i = 0; i < nf; i++)
  {
    frame[i] = -1;
  }
  int faults = 0;

  for (int i = 0; i < np; i++)
  {
    bool page_found = false;
    for (int j = 0; j < nf; j++)
    {
      if (frame[j] == page[i])
      {
        page_found = true;
        break;
      }
    }
    if (!page_found)
    {
      int max = -1, replace = -1;
      for (int j = 0; j < nf; j++)
      {
        bool found = false;
        for (int k = i + 1; k < np; k++)
        {
          if (frame[j] == page[k])
          {
            found = true;
            if (k > max)
            {
              max = k;
              replace = j;
            }
            break;
          }
        }
        if (!found)
        {
          replace = j;
          break;
        }
      }
      frame[replace] = page[i];
      faults++;
    }
    printf("Page %d : ", page[i]);
    for (int j = 0; j < nf; j++)
    {
      if (frame[j] == -1)
        printf("-- ");
      else
        printf("%d ", frame[j]);
    }
    printf("\n");
  }
  printf("\nNumber of page faults: %d\n", faults);
  return 0;
}