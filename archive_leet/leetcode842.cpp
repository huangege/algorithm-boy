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
    vector<int> get_fib(int head_len, string &num) {
        vector<int> result;
        long head_num = stol(num.substr(0, head_len));
        if (head_num >= 2147483648l) {
            return result;
        }

        // iterate second number
        for (int i = 1; 2 * i + head_len <= num.size() && i + 2 * head_len <= num.size() && i <= 10; i++) {
            long sec_num = stol(num.substr(head_len, i));
            if (sec_num >= 2147483648l) {
                continue;
            }
            result.push_back(head_num);
            result.push_back(sec_num);

            int cur_k = head_len + i;
            long cur_sum = 0l;
            while (cur_k < num.size()) {
                long pre_num = result[result.size() - 1];
                long pre_pre_num = result[result.size() - 2];
                cur_sum = pre_num + pre_pre_num;
                string cur_sum_str = to_string(cur_sum);
                int cur_sum_len = cur_sum_str.size();
                if (cur_sum > 2147483648l || cur_k + cur_sum_len > num.size()) {
                    break;
                }
                if (cur_sum_str == num.substr(cur_k, cur_sum_len)) {
                    result.push_back(cur_sum);
                    cur_k += cur_sum_len;
                } else {
                    break;
                }
            }
            if (cur_k == num.size()) {
                return result;
            }
            result.clear();
        }


        return result;
    }
    vector<int> splitIntoFibonacci(string num) {
        if (num[0] == '0') {
            return get_fib(1, num);
        }
        for (int i = 1; i <= num.size() / 2 && i <= 10; i++) {
            vector<int> cur_r = get_fib(i, num);
            if (!cur_r.empty()) {
                return cur_r;
            }
        }
        return vector<int>();
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