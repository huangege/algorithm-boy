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

    vector<int> compute_num_target(vector<vector<int>>& edges, int k) {
        int n = edges.size() + 1;
        vector<int> num_target(n, 1);
        vector<vector<int>> adj_matrix(n, vector<int>());

        for (auto i: edges) {
            adj_matrix[i[0]].push_back(i[1]);
            adj_matrix[i[1]].push_back(i[0]);
        }

        for (int i = 0; i < n; i++) {
            vector<bool> visited(n, false);
            queue<int> q;
            visited[i] = true;
            q.push(i);
            int j = 0; 
            while (j < k && !q.empty()) {
                int cur_q_size = q.size();
                for (int t = 0; t < cur_q_size; t++) {
                    int top = q.front();
                    q.pop();
                    for (auto r: adj_matrix[top]) {
                        if (!visited[r]) {
                            num_target[i]++;
                            visited[r] = true;
                            q.push(r);
                        }
                    }
                }
                j++;
            }
        }

        return num_target;
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        vector<int> num_target1 = compute_num_target(edges1, k);
        vector<int> num_target2 = compute_num_target(edges2, k - 1);

        int max_num_target2 = 0;
        for (auto i: num_target2) {
            max_num_target2 = max_num_target2 > i ? max_num_target2 : i;
        }

        if (k > 0) {
            for (auto &i: num_target1) {
                i += max_num_target2;
            }
        }

        return num_target1;
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
    vector<vector<int>> edges1 = {
        {0,1},
        {0,2},
        {2, 3},
        {2, 4}
    }; 
    // [[0,1],[0,2],[0,3],[2,7],[1,4],[4,5],[4,6]]
    vector<vector<int>> edges2 = {
        {0,1},
        {0,2},
        {0, 3},
        {2, 7},
        {1, 4},
        {4, 5},
        {4, 6}
    }; 
    int k = 2;
    auto a = s.maxTargetNodes(edges1, edges2, k);

    for (auto i: a) {
        cout << i << endl;
    }


    cout << "shit!" << endl;

    return 0;
}