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
    int test_dist(vector<int>& position, int m, int dis) {
        int sum = 0;
        m--;
        for (int i = 1; i < position.size(); i++) {
            sum += (position[i] - position[i - 1]);
            if (sum >= dis) {
                sum = 0;
                m--;
            }
        }
        if (m > 0) {
            return 1; // too large
        }
        return -1; // too small
    }

    int maxDistance(vector<int>& position, int m) {

        sort(position.begin(), position.end());

        int l = 1, r = position.back();

        while (l < r) {
            int dis = (l + r) / 2;
            int test_re = test_dist(position, m, dis);
            // cout << test_re << " " << dis << " " << l << " " << r <<  endl;
            if (test_re > 0) {
                r = dis - 1;
            } else {
                l = dis + 1;
            } 
        }
        if (test_dist(position, m, l) > 0) {
            return l - 1;
        }

        return l;
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
    vector<int> nn = {1,2,3,4,7};
    vector<vector<int>> kk = {{1,2},{2,3},{2,4}};
    vector<vector<string>> m = {{"John","johnsmith@mail.com","john_newyork@mail.com"},{"John","johnsmith@mail.com","john00@mail.com"},{"Mary","mary@mail.com"},{"John","johnnybravo@mail.com"}};
   
    Solution ss;
    auto a = ss.maxDistance(nn, 3);

    



    cout << "shit!" << endl;

    return 0;
}