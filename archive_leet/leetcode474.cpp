#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <stack>
#include <map>
#include <random>
#include <queue>
#include <list>
#include <numeric>
#include <algorithm>
#include <sstream>
#include <deque>


using namespace std;

void print_mat(vector<vector<int>> &m) {
    for (auto i: m) {
        for (auto j:i) {
            cout << j << " ";
        }
        cout << endl;
    }
}

class Solution {
public:
    static pair<int, int> cnt01(string &s) {
        int i = 0;
        int j = 0;
        for (char c: s) {
            if (c == '0') {
                i++;
            } else {
                j++;
            }
        }
        return make_pair(i, j);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (string s: strs) {
            auto num01 = cnt01(s);
            int num0 = num01.first;
            int num1 = num01.second;

            for (int i = m; i >= num0; i--) {
                for (int j = n; j >= num1; j--) {
                    dp[i][j] = max(dp[i][j], dp[i-num0][j-num1] + 1);
                }
            }
        }

        return dp[m][n];
    }
};


int main() {
    cout << "shit !" << endl;
    string s = "214748364721474836422147483641";
    vector<string> dic = {"ABC","ACB","ABC","ACB","ACB"};
    vector<vector<char>> char_vv = {
        {'a', 'a', 'a'},
        {'a', 'a', 'a'}
    };
    vector<int> nn = {5,2,2,4,0,6};
    vector<vector<int>> kk = {{1,2},{2,3},{2,4}};
   
    Solution ss;
    auto a = ss.countSubstrings("aba", "baba");
    cout << a << endl;
    // for (auto i: a) {
    //     cout << i << endl;
    // }

    



    cout << "shit!" << endl;

    return 0;
}