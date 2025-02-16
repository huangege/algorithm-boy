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

void print_vec(vector<int> &ve) {
    for (auto j:ve) {
        cout << j << " ";
    }
    cout << endl;
}



class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            dp[i][i] = nums[i];
        }

        int result = nums[0];
        for (int k = 1; k < n; k++) {
            for (int i = 0; i < n; i++) {
                int j = (i + k) % n;
                if (((i + 1 + n) % n == j) || ((i - 1 + n) % n == j)) {
                    dp[i][j] = dp[(i + 1 + n) % n][j];
                } else {
                    for (int l = i; (l + n + 1) % n != j; l = (l + 1 + n) % n) {
                        int cur_sum = nums[j] + dp[i][l];
                        dp[i][j] = max(dp[i][j], cur_sum);
                    }
                }
                result = max(dp[i][j], result);
            }
        }

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
    vector<int> nn = {28,8,49,85,37,90,20,8};
    vector<vector<int>> kk = {{1,2},{2,3},{2,4}};
    vector<vector<string>> m = {{"John","johnsmith@mail.com","john_newyork@mail.com"},{"John","johnsmith@mail.com","john00@mail.com"},{"Mary","mary@mail.com"},{"John","johnnybravo@mail.com"}};
   
    Solution ss;
    auto a = ss.accountsMerge(m);
    for (auto i: a) {
        for (auto j: i) {
            cout << j << ", ";
        }
        cout << endl;
    }

    



    cout << "shit!" << endl;

    return 0;
}