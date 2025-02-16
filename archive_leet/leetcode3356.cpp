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
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> cnt(n + 1, 0);
        int sum = 0;
        int j = 0;

        for (int i = 0; i < n; i++) {
            sum += cnt[i];
            while(sum < nums[i] && j < queries.size()) {
                int l = queries[j][0];
                int r = queries[j][1];
                int val = queries[j][2];

                if (r >= i) {
                    if (l <= i) {
                        sum += val;
                    } else {
                        cnt[l] += val;
                    }
                    cnt[r + 1] -= val;

                } 
                j++;
            }
            if (sum < nums[i]) {
                return -1;
            }
        }


        return j;
    }
};

int main() {
    cout << "shit !" << endl;
    string s = "214748364721474836422147483641";
    vector<string> dic = {"leet","code","leetcode"};
    vector<vector<char>> char_vv = {
        {'a', 'a', 'a'},
        {'a', 'a', 'a'}
    };
    vector<int> nn = {5,2,2,4,0,6};
   
    Solution ss;
    auto a = ss.splitIntoFibonacci(s);

    



    cout << "shit!" << endl;

    return 0;
}