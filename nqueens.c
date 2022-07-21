#include <stdio.h>
int board[1005][1005],n;
int issafe(int i,int j)
{
    for(int a=0;a<j;a++) if(board[i][a])return 0;//queen same row
    for(int a=i,b=j;a>=0&&b>=0;a--,b--)if(board[a][b])return 0;//top left diagonal
    for(int a=i,b=j;a<n&&b>=0;a++,b--)if(board[a][b])return 0;
    return 1;
}
int nqueen(int col){
    if(col==n)return 1;
    for(int i=0;i<n;i++){
        if(issafe(i,col))
        {
            board[i][col]=1;
            if(nqueen(col+1))return 1;
            board[i][col]=0;
        }
    }
    return  0;
}
int main()
{
    scanf("%d",&n);
    if(nqueen(0))
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                printf("%d ",board[i][j]);
            }
            printf("\n");
        }
    }
    else printf("no solution");
}