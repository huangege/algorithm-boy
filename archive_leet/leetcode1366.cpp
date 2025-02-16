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



class Solution {
public:
    static bool comp(vector<int> &l, vector<int> &r) {
        for (int i = 0; i < l.size(); i++) {
            if (l[i] == r[i]) {
                continue;
            } else {
                return l[i] > r[i];
            }
        }
        return true;
    }
    string rankTeams(vector<string>& votes) {
        int n = 26;
        int m = votes.size();
        vector<vector<int>> nv(n, vector<int>(n + 1, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < votes[0].size(); j++) {
                int t = votes[i][j] - 'A';
                nv[t][j]++;
            }
        }

        for (char c: votes[0]) {

        }
        for (int i = 0; i < n; i++) {
            nv[i][n] += (26 - i);
        }

        sort(nv.begin(), nv.end(), comp);

        string result = "";
        for (int i = 0; i < votes[0].size(); i++) {
            int c_index = 26 - nv[i][n] % 100;
            char c = c_index + 'A';
            if (votes[0].find(c) != std::string::npos) {
                result += c;
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
    vector<int> nn = {5,2,2,4,0,6};
    vector<vector<int>> kk = {{1,2},{2,3},{2,4}};
   
    Solution ss;
    auto a = ss.rankTeams(dic);
    cout << a << endl;
    for (auto i: a) {
        cout << i << endl;
    }

    



    cout << "shit!" << endl;

    return 0;
}