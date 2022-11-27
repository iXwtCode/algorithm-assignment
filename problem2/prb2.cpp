#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
/*
*   2、求解下述两个序列的最小编辑距离。
*    1） ACTGTCGTGCAACTGCTTAC
*    2） AGCTCCTACTACGGAGCATA
*/

class MED {
public:
    MED() = default;
    int get_result() const {
        if(result < 0) {
            cout << "算法未运行" << endl;
        }
        else{
            return result;
        }
    }
    //运行算法
    int fit(const string &s1, const string &s2){
        return MinimumEditDistance(s1, s2);
    }
private:
    int result = -1;
    int MinimumEditDistance(const string &s1, const string &s2);
};

int main() {
    string s1{"ACTGTCGTGCAACTGCTTAC"};
    string s2{"AGCTCCTACTACGGAGCATA"};
    MED algo;
    algo.fit(s1, s2);
    cout << "最小编辑距离：" << algo.get_result() << endl;
    return 0;
}

int MED::MinimumEditDistance(const string &s1, const string &s2) {
    int n1 = s1.size(), n2 = s2.size();
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1));

    //初始化动态规划数组
    for(int i = 0; i <= n1; ++i) {
        dp[i][0] = i;
    }
    for(int i = 0; i <= n2; ++i) {
        dp[0][i] = i;
    }

    //遍历更新dp[i][j]
    for(int i = 1; i <= n1; ++i) {
        for(int j = 1; j <= n2; ++j) {
            int flag = s1[i - 1] == s2[j - 1] ? 0 : 1; 
            int left = dp[i - 1][j] + 1;
            int up = dp[i][j - 1] + 1;
            int left_up = dp[i - 1][j - 1] + flag ;
            dp[i][j] = min(min(left, up), left_up);
        }
    }
    result = dp[n1][n2];
    return result;
}