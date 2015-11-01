#include <iostream>
#include <vector>
using namespace std;

class Bonus {
public:
    int getMost(vector<vector<int> > board) {
        int dp[7][7] = {0};
        for(int i = 1; i < 7; i++)
           for(int j = 1; j < 7; j++)
            {
                int tmp = max(dp[i-1][j], dp[i][j-1]);
                dp[i][j] = tmp + board[i-1][j-1];
            }
        return dp[6][6];
    }
};

int main()
{
    vector<vector<int> > board
    = {
        {1, 1, 3, 4, 5, 6},
        {1, 2, 3, 4, 5, 6},
        {1, 2, 3, 4, 5, 6},
        {1, 2, 3, 4, 5, 6},
        {1, 2, 3, 4, 5, 6},
        {1, 2, 3, 4, 5, 6}
    };

    Bonus p;
    cout << p.getMost(board) << endl;
    return 0;
}
