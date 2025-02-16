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
    int maximumTop(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 1) {
            if (k % 2 == 1) {
                return -1;
            }
        }
        int n_max = 0;
        for (int i = 0; i < k - 1 && i < n; i++) {
            n_max = n_max > nums[i] ? n_max : nums[i];
        }

        if (k + 1 <= n) {
            n_max = n_max > nums[k] ? n_max : nums[k];
        }

        return n_max;
    }
};



int main() {
    cout << "shit !" << endl;
    string s = "leetscode";
    vector<string> dic = {"leet","code","leetcode"};
    vector<vector<char>> char_vv = {
        {'a', 'a', 'a'},
        {'a', 'a', 'a'}
    };
    vector<int> nn = {5,2,2,4,0,6};
   
    Solution ss;
    int a = ss.maximumTop(nn, 4);
    cout << a << endl;



    cout << "shit!" << endl;

    return 0;
}