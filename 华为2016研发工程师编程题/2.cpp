#include <iostream>
#include <string>
using namespace std;
int main()
{
    string p;
    while (cin >> p)
    {
        int set[128] = {0};
        for (string::iterator i = p.begin(); i != p.end(); i++)
        {
            int n = int(*i);
            if (!set[n])
                set[n] = 1;
            else
                *i = '*'; //重复字符替换为'*'
        }
        for (string::iterator i = p.begin(); i != p.end(); i++)
        {
            if (*i == '*')
                continue;
            else
                cout << *i;
        }
        cout << endl;
    }
    return 0;
}