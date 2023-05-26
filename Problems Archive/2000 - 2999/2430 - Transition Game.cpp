#include <bits/stdc++.h>
using namespace std;

//Graphs where each vertex has out degree exactly one
//Each component in a functional graph is a cycle with paths that lead to that cycle
//Note that some paths can join into one path before reaching the cycle
//A component is thus defined by its "cycle root" which is toKth(u, len[u]) for any u
struct FunctionalGraph {
    int n, lg;
    vector<vector<int>> anc;
    vector<bool> vis, inCycle;

    vector<int> len;    //len[u] is the distance from u to the cycle root of the reachable cycle
                        //This distance is useful since that cycle root is the same for all nodes in the component 
                        //len[cycleRoot] is the length of the cycle in the corresponding component

    FunctionalGraph(int _n, vector<int> a, int _lg = 31) : n(_n), lg(_lg),
        anc(_lg, vector<int>(_n)), vis(_n), inCycle(_n), len(_n) {

        anc[0] = move(a);
        for (int i = 1; i < lg; i++)
            for (int u = 0; u < n; u++)
                anc[i][u] = anc[i - 1][anc[i - 1][u]];

        for (int i = 0; i < n; i++) if (!vis[i]) {
            dfs(i); int cycleRoot = kthAncestor(i, len[i]);
            if (!inCycle[cycleRoot]) { markCycle(cycleRoot); }
        }
    }

    void dfs(int s) {
        if (vis[s]) { return; }
        vis[s] = 1; dfs(anc[0][s]);
        len[s] = len[anc[0][s]] + 1;
    }

    void markCycle(int u) {
        if (inCycle[u]) { return; }
        inCycle[u] = true; markCycle(anc[0][u]);
    }

    //Finds the kth ancestor of Node x
    //toKth(x, len[x]) is the considered cycleRoot
    int kthAncestor(int x, int k) {
        if (k <= 0) { return x; }
        for (int i = 0; k; k >>= 1, i++)
            if (k & 1) { x = anc[i][x]; }
        return x;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n; cin >> n; vector<int> A(n);
    for (auto& x : A) { cin >> x;  --x; }

    FunctionalGraph G(n, A, 20);
    int takahashi = 0;
    for (int i = 0; i < n; i++)
        takahashi += G.inCycle[i];

    cout << takahashi << '\n';
}