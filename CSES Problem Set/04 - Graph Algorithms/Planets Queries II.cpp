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

    FunctionalGraph(int _n, vector<int> a, int _lg = 30) : n(_n), lg(_lg),
        anc(_lg, vector<int>(_n)), vis(_n), inCycle(_n), len(_n) {

        anc[0] = move(a);
        for (int i = 1; i < lg; i++)
            for (int u = 0; u < n; u++)
                anc[i][u] = anc[i - 1][anc[i - 1][u]];

        for (int i = 0; i < n; i++) if (!vis[i]) {
            dfs(i); int cycleRoot = toKth(i, len[i]);
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
    int toKth(int x, int k) {
        if (k <= 0) { return x; }
        int i = 0; while (k) {
            if (k & 1) { x = anc[i][x]; }
            k >>= 1; i++;
        }
        return x;
    }

    //Finds the first node inCycle by following the path that starts at u
    //Note that len[cycleStart] != length of the cycle
    int findFirstCycleNode(int u) {
        if (inCycle[u]) { return u; }
        int i = lg + 1; while (--i >= 0)
            if (!inCycle[anc[i][u]]) u = anc[i][u];
        return anc[0][u];
    }

    int dist(int u, int v) {
        if (u == v) { return 0; }
        int cU = toKth(u, len[u]), cV = toKth(v, len[v]);
        if (cU != cV || (inCycle[u] && !inCycle[v])) { return -1; }
        if (inCycle[u] && inCycle[v]) { return len[u] - len[v] + len[cU] * (len[u] < len[v]); }
        if (toKth(u, len[u] - len[v]) == v) { return len[u] - len[v]; }
        if (toKth(cU, len[cU] - len[v]) == v) { return len[u] + len[cU] - len[v]; }
        return -1;
    }
};

vector<int> v;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n, q; cin >> n >> q; v.resize(n);
    for (auto& x : v) { cin >> x; x--; }

    FunctionalGraph g(n, v, 19); while (q--) {
        int u, v; cin >> u >> v;
        cout << g.dist(--u, --v) << '\n';
    }
}