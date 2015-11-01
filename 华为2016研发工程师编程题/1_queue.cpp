#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        queue<int> Q;
        for(int i = 0; i < n; i++)
            Q.push(i);
        
        int num = 0, tmp = 0;
        while(Q.size() != 1)
        {
            ++num;
            tmp = Q.front();
            Q.pop();
            if(num % 3 == 0)
                continue;
            else
                Q.push(tmp);
        }
        cout << Q.front() << endl;
    }
    return 0;
}
