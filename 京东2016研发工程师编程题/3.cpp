#include <iostream>
using namespace std;

class Apples {
public:
    int getInitial(int n)
    {
        for(int i = 1; i < INT_MAX; ++i)
        {
            int apple = i * n + 1;
            int tmp = apple;
            int j;
            for (j = n; j > 0; --j)
            {
                if (tmp % n != 1)
                    break;
                else
                    tmp = tmp - tmp/n - 1;
            }
            if (j == 0)
                return apple;
        }
        return 0;
    }
};

int main()
{
    Apples T;
    cout << T.getInitial(3) << endl;
    return 0;
}
