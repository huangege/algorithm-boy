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
    static bool comp_hor(vector<int> &l, vector<int> &r) {
        return l[1] < r[1];
    }

    static bool comp_ver(vector<int> &l, vector<int> &r) {
        return l[0] < r[0];
    }

    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        // try vertital
        sort(rectangles.begin(), rectangles.end(), comp_ver);
        int k = 0;
        int right_end = rectangles[0][2];
        for (int i = 1; i < rectangles.size(); i++) {
            int x1 = rectangles[i][0];
            int x2 = rectangles[i][2];

            if (x1 >= right_end) {
                k++;
                if (k == 2) {
                    return true;
                }
            }
            if (x2 > right_end) {
                right_end = x2;
            }
        }


        // vertical
        sort(rectangles.begin(), rectangles.end(), comp_hor);
        k = 0;
        int up_end = rectangles[0][3];
        for (int i = 1; i < rectangles.size(); i++) {
            int y1 = rectangles[i][1];
            int y2 = rectangles[i][3];

            if (y1 >= up_end) {
                k++;
                if (k == 2) {
                    return true;
                }
            }
            if (y2 > up_end){
                up_end = y2;
            }
        }

        return false;
        
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
    vector<vector<int>> ma = {{0,0,1,4},{1,0,3,2},{3,0,5,2},{1,2,3,4},{3,2,5,4},{0,4,1,5},{1,4,5,5}};
    vector<vector<int>> mb = {
        {0, 0, 1, 4},
        {1, 0, 2, 3},
        {2, 0, 3, 3},
        {3, 0, 4, 3},
        {1, 3, 4, 4}
    };
   
    Solution ss;
    auto a = ss.checkValidCuts(5, ma);

    cout << a << endl;



    cout << "shit!" << endl;

    return 0;
}