#include <iostream>
#include <vector>
using namespace std;

int func(int a, int b) {
    if (a < b) {
        int t = a; a = b; b = t;
    }
    int r = b;
    while (r) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
int main(void) {
    int a, n;
    
    while (cin >> n >> a) {
        vector<int> vec;
        int c = a;
        for (int i = 0; i < n; i++) {
            int t;
            cin >> t;
            vec.push_back(t);
        }
        for (auto it = vec.begin(); it != vec.end(); it++) {
            if (c >= *it) {
                c += *it;
            }
            else {
                c += func(c, *it);
            }
        }
        cout << c << endl;
    }
     /*
    while (cin >> n >> a) {
        cout << func(n, a) << endl;
    }
     */
    return 0;
}
/*
 3 50
 50 105 200
 5 20
 30 20 15 40 100
*/