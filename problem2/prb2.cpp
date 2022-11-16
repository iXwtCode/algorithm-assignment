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
    void fit(string &s1, string &s2);
private:
    int result = -1;
};

int main() {
    string s1{"ACTGTCGTGCAACTGCTTAC"};
    string s2{"AGCTCCTACTACGGAGCATA"};
    MED algo;
    algo.fit(s1, s2);
    cout << "最小编辑距离：" << algo.get_result() << endl;
    return 0;
}

void MED::fit(string &s1, string &s2) {
    int n1 = s1.size(), n2 = s2.size();
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1));

    for(int i = 0; i <= n1; ++i) {
        dp[i][0] = i;
    }
    for(int i = 0; i <= n2; ++i) {
        dp[0][i] = i;
    }

    for(int i = 1; i <= n1; ++i) {
        for(int j = 1; j <= n2; ++j) {
            int flag;
            if(s1[i - 1] == s2[j - 1]) {
                flag = 0;
            }
            else {
                flag = 1;
            }
            int left = dp[i - 1][j] + 1;
            int up = dp[i][j - 1] + 1;
            int left_up = dp[i - 1][j - 1] + flag ;
            dp[i][j] = min(min(left, up), left_up);
        }
    }
    result = dp[n1][n2];
}