#include <stdio.h>
#include <stdlib.h>
struct book
{
    char name_of_book[100]; //书名
    char author[25]; //作者
    char ISBN[15];
    float price;
};
struct book* sortBook(struct book* List, int n);

int main()
{
    struct book List[100];
    int i = 0;
    printf("please input name_of_book author ISBN price:");
    while(scanf("%s %s %s %f",List[i].name_of_book,List[i].author,List[i].ISBN,&List[i].price) == 4) i++;
    sortBook(List,i);
    for(int j = 0;  j < i; j++)
    {
        printf("%s,%s,%s,%.2f\n",List[j].name_of_book,List[j].author,List[j].ISBN,List[j].price);
    }
}

struct book* sortBook(struct book* List, int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(List[j].price < List[j+1].price)
            {
                struct book temp = List[j];
                List[j] = List[j+1];
                List[j+1] = temp;
            }
        }
    }
    return List;
}
