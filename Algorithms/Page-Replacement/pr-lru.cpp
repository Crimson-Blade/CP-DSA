#include <stdio.h>
#include <limits.h>
// lru
int main()
{
    int nf, np;
    printf("Enter the number of frames available: ");
    scanf("%d", &nf);
    printf("Enter the number of pages: ");
    scanf("%d", &np);
    int page[np], frame[nf], recent[np], time = 0;
    printf("Enter the pages: ");
    for (int i = 0; i < np; i++)
    {
        scanf("%d", &page[i]);
    }
    for (int i = 0; i < nf; i++)
    {
        frame[i] = -1;
        recent[i] = -1;
    }
    int faults = 0;

    for (int i = 0; i < np; i++)
    {
        int page_found = 0, replace = 0;
        for (int j = 0; j < nf; j++)
        {
            if (frame[j] == page[i])
            {
                page_found = 1;
                recent[j] = time++;
                break;
            }
        }
        if (!page_found)
        {
            int oldest = INT_MAX;
            for (int j = 0; j < nf; j++)
            {
                if (recent[j] < oldest)
                {
                    oldest = recent[j];
                    replace = j;
                }
            }
            frame[replace] = page[i];
            recent[replace] = time++;
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
// 3 2 1 3 4 1 6 2 4 3 4 2 1 4 5 2 1 3 4