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
    static bool comp(vector<string> &v1, vector<string> &v2) {
        return v1[0] < v2[0];
    }

    static vector<string> merge_i_j(vector<string> &v1, vector<string> &v2) {
        vector<string> result;
        int l = 1, r = 1;
        bool flag = false;
        while(l < v1.size() && r < v2.size()) {
            if (v1[l] == v2[r]) {
                flag = true;
                break;
            } else if (v1[l] < v2[r]) {
                l++;
            } else {
                r++;
            }
        }

        if (!flag) {
            return result;
        }

        result.push_back(v2[0]);
        l = 1, r = 1;
        int v1_size = v1.size(), v2_size = v2.size();
        while(l < v1_size && r < v2_size) {
            if (v1[l] == v2[r]) {
                if (result.back() != v1[l]) {
                    result.push_back(v1[l]);
                }
                l++;
                r++;
            } else if (v1[l] < v2[r]) {
                if (result.back() != v1[l]) {
                    result.push_back(v1[l]);
                }
                l++;
            } else {
                if (result.back() != v2[r]) {
                    result.push_back(v2[r]);
                }
                r++;
            }
        }
        while(l < v1_size) {
            if (result.back() != v1[l]) {
                result.push_back(v1[l]);
            }
            l++;
        }
        while(r < v2_size) {
            if (result.back() != v2[r]) {
                result.push_back(v2[r]);
            }
            r++;
        }

        // v2.clear();
        // for (auto i: result) {
        //     v2.push_back(i);
        // }

        return result;
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<vector<string>> result;
        sort(accounts.begin(), accounts.end(), comp);
        for (int i = 0; i < accounts.size(); i++) {
            sort(accounts[i].begin() + 1, accounts[i].end());
        }

        for (int i = 0; i < accounts.size(); i++) {
            int flag = false;
            for (int j = i + 1; j < accounts.size() && accounts[j][0] == accounts[i][0]; j++) {
                auto merge_r = merge_i_j(accounts[i], accounts[j]);
                if (!merge_r.empty()) {
                    flag = true;
                    accounts[j] = merge_r;
                }
            }
            if (!flag) {
                vector<string> cur;
                cur.push_back(accounts[i][0]);
                for (int k = 1; k < accounts[i].size(); k++) {
                    if (cur.back() != accounts[i][k]) {
                        cur.push_back(accounts[i][k]);
                    }
                }
                result.push_back(cur);
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