#include<stdio.h>
#define N 40
void ReadScore(int score[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &score[i]);
    }
}
void WriteScore(int score[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", score[i]);
    }
}
void Swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
void DataSort(int score[], int n)
{
    int i, j, k;
    for (i = 0; i < n; i++)
    {
        k = i;
        for (j = i + 1; j < n; j++)
        {
            if (score[j] > score[k])
            {
                k = j;
            }
        }
        if (k != i)
        {
            Swap(&score[k], &score[i]);
        }
    }
}
int  main()
{
    int score[N], aver, n;
    printf("Input n:\n");
    scanf("%d", &n);
    ReadScore(score, n);
    WriteScore(score, n);
    DataSort(score, n);
    WriteScore(score, n);
    return 0;
}