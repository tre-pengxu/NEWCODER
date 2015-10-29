#include <iostream>
using namespace std;
int main()
{
    int p[1000];
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        p[i] = 1;
 
    int count = 0;
    int sum = 0;
    for (int j = 0; sum < n - 1 ; ++j)
    {
        if (p[j % n] == 0)
            continue;
        if ((count + 1) % 3 == 0)
        {   
            p[j % n] = 0;
            sum += 1;
        }
        count++;
    }
    for (int i = 0; i < n; i++)
    {
        if (p[i] == 1)
        {
            cout << i;
            break;
        }
    }
    return 0;
}