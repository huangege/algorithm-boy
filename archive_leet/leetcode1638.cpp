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
    int countSubstrings(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> same(n, vector<int>(m, 0));
        vector<vector<int>> dp(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            same[i][0] = (s[i] == t[0]);
            dp[i][0] = (s[i] != t[0]);
        }
        for (int i = 0; i < m; i++) {
            same[0][i] = (s[0] == t[i]);
            dp[0][i] = (s[0] != t[i]);
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (s[i] == t[j]) {
                    same[i][j] = 1 + same[i-1][j-1];
                } else {
                    same[i][j] = 0;
                }
            }
        }

        int result = 0;
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (s[i] == t[j]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = same[i-1][j-1] + 1;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                result += dp[i][j];
            }
        }

        // print_mat(same);
        // cout << "======"<< endl;
        // print_mat(dp);

        return result;
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