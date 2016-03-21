#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() 
{
	int n, len;
	while (cin >> n >> len) {	
		vector<int> pos;
		int max_len = 0;
		for (int i = 0; i < n; i++) {
			int t;
			cin >> t;
			pos.push_back(t);
		}
		sort(pos.begin(), pos.end());
		for (int i = 1; i < pos.size(); i++) {
			int d = pos[i] - pos[i - 1];
			if (d > max_len)
				max_len = d;
		}

		double ans = max_len / 2.0;
		//考虑首尾路灯位置
		double begin_len = pos[0];
		double end_len = len - pos[pos.size() - 1];
		ans = ans > begin_len ? ans :begin_len;
		ans = ans > end_len ? ans :end_len;
		printf("%.2f\n", ans); //注意输出格式，两位小数
	}

	return 0;
}
/*
7 15
15 5 3 7 9 14 0
*/