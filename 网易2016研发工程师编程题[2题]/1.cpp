/*(c/c++)
只需满足平均成绩大于等于avg即可，不管单科成绩。
所以先从花时间最少的课开始复习，使其满分。
伪码：
if(当前成绩 >= avg*n)
    cout << 0 << endl;
else{
    sort(时间花费)；
    for（时间花费从小到大）
         if 当前课程满分后不能获得奖学金
             复习至满分，累加复习时间，然后复习下一门
        else if 当前课程满分后能获得奖学金
            所需时间 += （所需总分 - 当前分数）*在该课程上获得1分所需时间
            输出时间；
            退出循环。
}
*/
/*
#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
struct score_hour
{
    int score;
    int hour;
};
 
bool cmp(score_hour a, score_hour b)
{
    return a.hour < b.hour;
}
 
int main()
{
    int n,r,avg;
 
    while(cin >> n >> r >> avg){
        vector<score_hour> v;
        score_hour tmp;
 
        while(n--){
            cin >> tmp.score >> tmp.hour;
            v.push_back(tmp);
        }
 
        int target = v.size()*avg;
        int score_cur = 0;
        long time = 0;
        for(int i=0; i<v.size(); ++i){
            score_cur += v[i].score;
        }
        if(score_cur>=target)
            cout << 0 <<   endl;
        else{
            sort(v.begin(),v.end(),cmp);
            for(int i=0; i<v.size(); ++i){
                //该课程如果获得满分，求当前总分数
                score_cur += (r - v[i].score);
                if(score_cur >= target){
                    //当前分数超过目标成绩说明该课程不得满分也可满足奖学金条件
                    score_cur -= (r - v[i].score);
                    time += (target - score_cur)*v[i].hour;
                    cout << time << endl;
                    break;
                }
                else{
                    time += (r - v[i].score)*v[i].hour;
                }
            }
 
        }
 
    }
 
    return 0;
}
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Course{
	int score;
	int hour;
};

bool cmp(Course a, Course b) 
{
	return a.hour < b.hour;
}

int main() 
{
	int n,r,avg;
	while(cin >> n >> r >> avg) {
		vector<Course> v;
		Course tmp;
		for (int i = 0; i < n; i++) {
			cin >> tmp.score >> tmp.hour;
			v.push_back(tmp);
		}
		int needscore = 0;
		for (vector<Course>::iterator it = v.begin(); it != v.end(); it++) {
			needscore += avg - it->score;
		}
		if (needscore <= 0) {
			cout << 0 << endl;
		}
		else {	
			long addtime = 0;
			sort(v.begin(), v.end(), cmp); //对bi升序排序
			for (vector<Course>::iterator it = v.begin(); it != v.end(); it++) {
				int t = r - it->score; //如果当前课程取得满分可以增加的分数
				if (t >= needscore) {
					addtime += needscore * it->hour;
					cout << addtime << endl;
					break;
				}
				else {
					needscore -= t;
					addtime += t * it->hour;
				}
			}
		}
	}
	return 0;
}
/*
输入：
5 10 9
0 5
9 1
8 1
0 1
9 100
输出：
43
*/