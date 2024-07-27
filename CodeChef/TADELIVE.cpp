#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
  int N, // number of orders
      X, // Number of orders Andy can take
      Y; // Number of orders Bob can take

  scanf("%d %d %d", &N, &X, &Y);

  int A[N]; // Tip money array for Andy
  int B[N]; // Tip money array for Bob

  for (int i = 0; i < N; i++)
    scanf("%d", &A[i]);
  for (int i = 0; i < N; i++)
    scanf("%d", &B[i]);

  int tip = 0;

  int deltas[N];

  if (X < Y)
  {
    for (int i = 0; i < N; i++)
    {
      deltas[i] = A[i] - B[i];
      tip += B[i];
    }

    sort(deltas, deltas + N);

    for (int iX = N - 1; iX >= N - X && deltas[iX] > 0; iX--)
    {
      tip += deltas[iX];
    }
  }
  else
  {
    for (int i = 0; i < N; i++)
    {
      deltas[i] = B[i] - A[i];
      tip += A[i];
    }

    sort(deltas, deltas + N);

    for (int iY = N - 1; iY >= N - Y && deltas[iY] > 0; iY--)
    {
      tip += deltas[iY];
    }
  }

  printf("%d", tip);
  return 0;
}