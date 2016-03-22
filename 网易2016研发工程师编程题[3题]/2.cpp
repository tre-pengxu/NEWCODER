#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    int R;
    while (cin >> R) {
        int x[4], y[4];
        double R2 = R * R;
        int ans = 0;
        double d = 0;
        for (int i = 1; i <= 3; i++) {
            cin >> x[i] >> y[i];
        }
        cin >> x[0] >> y[0];
        for (int i = 1; i <= 3; i++) {
            d = (x[i] - x[0]) * (x[i] - x[0]) + (y[i] - y[0]) * (y[i] - y[0]);
            if (R2 >= d) {
                ans++;
            }
        }
        cout << ans << 'x' << endl;
    }
    return 0;
}
/*
R,x1,y1,x2,y2,x3,y3,x0,y0
*/