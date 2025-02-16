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
    bool doesAliceWin(string s) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        int num_v = 0;

        for (char i: s) {
            if (vowels.find(i) != vowels.end()) {
                num_v++;
            }
        }

        if (num_v > 0) {
            return true;
        }
        return false;
        
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