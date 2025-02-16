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
    bool get_bit(int v, int index) {
        return v & (1 << index);
    }
    int max_dis(vector<vector<int>> &dist, int n, int state) {
        int m_dis = -1;
        int num_node = 0;
        int num_edge = 0;
        for (int i = 0; i < n; i++) {
            if (!get_bit(state, i)) {
                continue;
            }
            num_node++;
            for (int j = i + 1; j < n; j++) {
                if (!get_bit(state, j)) {
                    continue;
                }
                if (dist[i][j] == 1) {
                    num_edge++;
                }
                if (dist[i][j] < n) {
                    m_dis = max(m_dis, dist[i][j]);
                }
            }
        }

        if (num_node == num_edge + 1) {
            return m_dis;
        } else {
            return -1;
        }
    }

    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        int m = pow(2, n);
        vector<int> max_map(m, -1);
        vector<int> result(n - 1, 0);

        vector<vector<int>> dist(n, vector<int>(n, 2 * n));
        for (int i = 0; i < n - 1; i++) {
            dist[i][i] = 0;
            int l = edges[i][0] - 1;
            int r = edges[i][1] - 1;

            dist[l][r] = 1;
            dist[r][l] = 1;
        }
        dist[n-1][n-1] = 0;

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        for (int i = 0; i < m; i++) {
            int m_dis = max_dis(dist, n, i);
            if (m_dis > 0) {
                result[m_dis - 1]++;
            }

        }

        return result;
        
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
    vector<vector<int>> kk = {{1,2},{2,3},{2,4}};
   
    Solution ss;
    auto a = ss.countSubgraphsForEachDiameter(4, kk);
    for (auto i: a) {
        cout << i << endl;
    }

    



    cout << "shit!" << endl;

    return 0;
}