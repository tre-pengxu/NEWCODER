/* 一个扫描透镜可以扫描出（3*3）方格中的所有蘑菇，
 问最多可清理多少个蘑菇就是求二维数组中哪一块（3*3）区域中的蘑菇数最多。
 有两个透镜，那么最多可清理的蘑菇数就是第一个透镜最多清理的加上第二个透镜
 最多清理的（将求最多清理蘑菇数写成函数）。
 需要注意的是对于每个方格如果其中有多个蘑菇那么一次扫描只能清理掉一个蘑菇。
 这要求我们在求出第一个最优解后要对二维数组中的相应方格中的蘑菇数进行减1操作。*/
#include <iostream>
#include <vector>
using namespace std;

void scan(vector<vector<int> > field,int N,int M,int result[])
{
    for(int i=0;i<N-2;++i){
        for(int j=0;j<M-2;++j){
            //统计3*3格子中的蘑菇数，如果一个格子中有多个只算一个
            int tmp = 0; //tmp:每个3*3区域中的蘑菇数
            for(int p=i;p<i+3;++p){
                for(int q=j;q<j+3;++q){
                    if(field[p][q] > 0){
                        ++tmp;
                    }
                }
            }
            if(result[0]<tmp){
                result[0] = tmp;
                result[1] = i;
                result[2] = j;
            }
        }
    }
}

int main()
{
    int N,M,K;
    int x,y;
    
    while(cin >> N >> M >> K){
        if(N<3)
            N = 3;
        if(M<3)
            M = 3;
        vector<vector<int> > field(N,vector<int>(M,0));
        while(K--){
            cin >> x >> y;
            ++field[x-1][y-1];
        }
        int first[3]={0};
        int second[3]={0};
        //int first[3]={0}; //0,1,2分别存放3*3格子中最多的蘑菇数，该3*3区域第一个格子的行号和列号
        scan(field,N,M,first);
        //将field中蘑菇数最多的3*3格子中的蘑菇数-1.第一次扫描清理掉了
        for(int i=first[1];i<first[1]+3;++i){
            for(int j=first[2];j<first[2]+3;++j){
                if(field[i][j]>0){
                    --field[i][j];
                }
            }
        }
        scan(field,N,M,second);
        cout << first[0]+second[0] << endl;
    }
    
    return 0;
}
