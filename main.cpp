#include <stdio.h>
#include <algorithm>
//积分赛第一场E
#define I 500

using namespace std;
long long L,M,N;
long long A[I],B[I],C[I];
long long tmp[I*I];
long long l_tmp = 0;
int search_x(long long x)
{
   long long l = 0,r = l_tmp-1;
    while(l<=r)
    {
        long long mid = (l+r)/2;
        if(tmp[mid] == x)
            return 1;
        else if(tmp[mid]>x)
            r = mid-1;
        else
            l = mid+1;
    }
    return 0;
}
int main()
{
    long long i,j,k;
    long long s;
    long long d = 1;
    while(scanf("%I64d %I64d %I64d",&L,&M,&N)!=EOF)
    {
    for(i=0;i<M;i++)
    {
        scanf("%I64d",&A[i]);
    }
    for(j=0;j<M;j++)
    {
        scanf("%I64d",&B[j]);
    }
    for(k=0;k<N;k++)
    {
        scanf("%I64d",&C[k]);
    }
    sort(C,C+N);

    for(i=0;i<M;i++)
         {
             for(j=0;j<M;j++)
            {
                tmp[l_tmp] = A[i]+B[j];
                l_tmp++;
            }
         }
    sort(tmp,tmp+l_tmp);

    scanf("%I64d",&s);
    printf("Case %d:",d);
    while(s--)
    {
        int x;
        int flag = 0;
        scanf("%d",&x);
        if(x>(C[N-1]+tmp[l_tmp-1])||x<(C[0]+tmp[0]))
        {
            printf("NO\n");
            continue;
        }

        for(k=0;k<N;k++)
         {
             int tmp1 = x - C[i];
             if(search_x(tmp1)==1) flag =1;
             break;
         }
    if(flag == 1) printf("YES\n");
    else printf("NO\n");
    }
    d++;
    }

    return 0;
}
