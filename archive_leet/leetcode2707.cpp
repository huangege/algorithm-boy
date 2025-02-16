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


using namespace std;



class Solution {
public:
    void update_cover(vector<vector<int>> &cover, string &s, string &word) {
        for (int i = 0; i < s.size(); i++) {
            if (i + word.size() > s.size() || cover[i][i + word.size()]) {
                continue;
            }
            bool flag = true;
            for (int j = 0; j < word.size(); j++) {
                if (s[i + j] != word[j]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                cover[i][i + word.size()] = 1;
            }
        }
    }
    int minExtraChar(string s, vector<string>& dictionary) {
       vector<vector<int>> cover(s.size() + 1, vector<int>(s.size() + 1, 0)); 
       for (int i = 0; i < dictionary.size(); i++) {
            update_cover(cover, s, dictionary[i]);
       }

       vector<int> dp(s.size() + 1, 0);

       for (int i = s.size() - 1; i >= 0; i--) {
            for (int j = i + 1; j <= s.size(); j++) {
                int cur_cover = dp[i];
                int update_cover = dp[j];
                if (cover[i][j] == 1) {
                    update_cover += (j - i);
                }
                dp[i] = cur_cover > update_cover ? cur_cover : update_cover;
            }
       }
    //    for (auto i: dp) {
    //         cout << i << " " << endl;
    //    }
       
       return s.size() - dp[0];
    }
};

int main() {
    cout << "shit !" << endl;
    string s = "leetscode";
    vector<string> dic = {"leet","code","leetcode"};
   
    Solution ss;
    int a = ss.minExtraChar(s, dic);
    cout << a << endl;



    cout << "shit!" << endl;

    return 0;
}