#include <stdio.h>
int a[1005][1005],sol[1005][1005];
int n;
int issafe(int x,int y)
{
    if(x>=0&&x<n&&y>=0&&y<n&&a[x][y]==1)return 1;
    else return 0;
}
int solvemaze(int x,int y)
{
   if(x==n-1 && y==n-1){
       if(a[x][y]==1){sol[x][y]=1; return 1;}
       else return 0;
   }
   if(issafe(x,y)){
       sol[x][y]=1;
       if(solvemaze(x+1,y))return 1;
       if(solvemaze(x,y+1))return 1;
       sol[x][y]=0;
    }
    return 0;
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
          scanf("%d",&a[i][j]);
          
    if(solvemaze(0,0))
    {
        printf("\n");
        for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)printf("%d ",sol[i][j]);
        printf("\n");
        }
    }
    else printf("No Solution");
    return 0;
}