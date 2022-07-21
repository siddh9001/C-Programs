#include<stdio.h>//coin change
int c(int v[],int n,int p)
{
    if(p==0)return 0;
    int min=p;
    for(int i=0;i<n && v[i]<=p; i++)
    {
        int x=1+c(v,n,p-v[i]);
        if(x<min)min=x;
    }
    return min;
}
int main()
{
    int v[3]={1,2,5};
    int p=8;
    printf("%d",c(v,3,p));
}