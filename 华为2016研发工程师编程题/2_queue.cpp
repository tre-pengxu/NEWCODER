#include<cstdio>
#include<queue>
using namespace std;
 
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        queue<int>Q;
 
        for(int i=0;i<n;i++)
        {
            Q.push(i);
        }
        int cnt=0,tmp;
        while(!Q.empty())
        {
            ++cnt;
            tmp=Q.front();
            Q.pop();
            if(cnt==3){cnt=0;}
            else
            {
                if(Q.empty()) break;
                Q.push(tmp);
            }
        }
        printf("%d\n",tmp);
    }
    return 0;
}
