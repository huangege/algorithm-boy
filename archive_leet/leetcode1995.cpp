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
    int countQuadruplets(vector<int>& nums) {
        int r = 0;
        int n = nums.size();

        for (int i = 0; i < n - 3; i++) {
            for (int j = i + 1; j < n - 2; j++) {
                for (int k = j + 1; k < n - 1; k++) {
                    int ss = nums[i] + nums[j] + nums[k];
                    for (int q = k + 1; q < n; q++) {
                        if (ss == nums[q]) {
                            r++;
                        }
                    } 
                }

            }
        }
        return r;
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
   
    Solution ss;
    auto a = ss.countQuadruplets(nn);
    cout << a << endl;
    // for (auto i: a) {
    //     cout << i << endl;
    // }

    



    cout << "shit!" << endl;

    return 0;
}