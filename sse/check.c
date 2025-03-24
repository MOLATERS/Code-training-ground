#include  <stdio.h>
int IsDaffodilNum(int num);
int main(void)
{
    int n;
    printf("Input n:");
    scanf("%d", &n);
    if (n % 3 != 0)
    {
        printf("%d is not a daffodil number\n", n);
    }
    else if (IsDaffodilNum(n))
    {
        printf("%d is a daffodil number\n", n);
    }
    return 0;
}
//函数功能：验证n是黑洞数
int IsDaffodilNum(int num)
{
    int temp;
    printf("%d\n", num);
    if(num == 153)
    {
        return 1;
    }
    while(num != 0)
    {
        temp += (num % 10) * (num % 10) * (num % 10);
        num /= 10;
    }
    return IsDaffodilNum(temp);
}
