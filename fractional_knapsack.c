#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
struct bag{
    long w,p;
    double r;
};
int cmp(const void *a, const void *b)
{
    struct bag*x=(struct bag*)a,*y=(struct bag*)b;
    if(y->r > x->r)return 1;
    else if(y->r < x->r)return -1;
    else return 0;
}
int main() {
    int n,m;scanf("%d%d",&n,&m);
    struct bag a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%ld %ld",&a[i].w,&a[i].p);
        a[i].r=a[i].p/(double)a[i].w;
    }
    qsort(a,n,sizeof(struct bag),cmp);
    double profit=0;int i=0;
    while(i<n && a[i].w<=m)
    {
        m=m-a[i].w;
        profit=profit+a[i].p;
        i++;
    }
    if(i<n && m>0) profit=profit+a[i].r * m;
    if(i==n && m>0)printf("-1");
    else printf("%.12lf",profit);
    return 0;
}