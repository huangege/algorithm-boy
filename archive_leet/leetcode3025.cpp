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
    static bool comp(vector<int> &l, vector<int> &r) {
        if (l[0] < r[0]) {
            return true;
        } else if (l[0] == r[0]) {
            if (l[1] > r[1]) {
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    }
  
    int numberOfPairs(vector<vector<int>>& points) {
        if (points.size() <= 1) {
            return 0;
        }
        sort(points.begin(), points.end(), comp);
        int result = 0;
        for (int i = 0; i < points.size() - 1; i++) {
            int top = INT_MIN;

            for (int j = i + 1; j < points.size(); j++) {
                if (points[j][1] <= points[i][1] && points[j][1] > top) {
                    result++;
                    top = points[j][1];
                }
            }
        }

        return result;
    }
};

int main() {
    cout << "shit !" << endl;
    vector<vector<int>> points = {
        {1, 1},
        {2, 2},
        {3, 3}
    };
    Solution s;
    int a = s.numberOfPairs(points);
    cout << a << endl;
    cout << "shit!" << endl;

    return 0;
}