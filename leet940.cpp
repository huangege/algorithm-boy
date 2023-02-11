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

class Hungarian {
    long n;
    vector<int> lx;
    vector<int> ly;
    vector<vector<int>> g;
    vector<bool> freex;
    vector<int> matx;
    vector<int> maty;
    vector<int> prey;
    vector<int> slack;
    vector<bool> S, T;
    queue<int> q;
    
public:
    Hungarian(vector<vector<int>>& graph) {
        n = max(graph.size(), graph[0].size());
        lx = vector<int>(n, 0);
        ly = vector<int>(n, 0);
        freex = vector<bool>(n, true);
      
        matx = vector<int>(n, -1);
        maty = vector<int>(n, -1);
        prey = vector<int>(n, -1);

        // initialize g and lx
        g = vector<vector<int>>(n, vector<int>(n, 0));
        for (int i = 0; i < graph.size(); i++) {
            for(int j = 0; j < graph[0].size(); j++) {
                g[i][j] = max(0, graph[i][j]);
                if (lx[i] < g[i][j]) {
                    lx[i] = g[i][j];
                }
            }
        }
        // initialize matching
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (maty[j] == -1 && lx[i] + ly[j] == g[i][j]) {
                    matx[i] = j;
                    maty[j] = i;
                    freex[i] = false;
                    break;
                }
            }
        }
        
    }
    
    // return true if y is free else false
    bool pick(int y) {
        if (maty[y] != -1) {
            // y is matched
            S[maty[y]] = true;
            q.push(maty[y]);
            T[y] = true;
            return false;
        }
        // augmenting path
        int x;
        while (y != -1) {
            // augmenting path
            x = prey[y];
            maty[y] = x;
            int nexty = matx[x];
            matx[x] = y;
            y = nexty;
        }
        freex[x] = true;
        return true;
    }
    
    void bfs(int index) {
        while(!q.empty()) q.pop();
        q.push(index);
        S[index] = true;
        while(true) {
            // update matching
            while(!q.empty()) {
                int u = q.front();
                q.pop();
                for (int y = 0; y < n; y++) {
                    if (!T[y]) {
                        int delta = lx[u] + ly[y] - g[u][y];
                        if (delta == 0) {
                            // y in NS - T
                            prey[y] = u;
                            if (pick(y)) return;
                            
                            
                        } else if (delta < slack[y]) {
                            // y not in NS nor T
                            prey[y] = u;
                            slack[y] = delta;
                        }
                    }
                }
            }
            // update label
            int alpha = INT_MAX;
            for (int y = 0; y < n; y++) {
                if (!T[y]) alpha = min(alpha, slack[y]);
            }
            for (int i = 0; i < n; i++) {
                if (S[i]) {
                    lx[i] -= alpha;
                }
                if (T[i]) {
                    ly[i] += alpha;
                } else {
                    slack[i] -= alpha;
                }
            }
            for (int y = 0; y < n; y++) {
                if (!T[y] && slack[y] == 0 && pick(y)) return;
            }
        }
    }

    int solve() {
        for (int i = 0; i < n; i++) {
            if (freex[i]) {
                slack = vector<int>(n, INT_MAX);
                S = vector<bool>(n, false);
                T = vector<bool>(n, false);
                prey = vector<int>(n, -1);
                bfs(i);
            }
        }
            
        // compute result;
        int result = 0;
        for (int i = 0; i < n; i++) {
            if (g[i][matx[i]] > 0) result += g[i][matx[i]];
        }
        
        return result;
    }
    
};

int main() {
    cout << "shit !" << endl;

    return 0;
}