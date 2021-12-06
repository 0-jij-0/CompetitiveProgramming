#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
#include <map>
#include <array>
using namespace std;
typedef long long ll;

struct DSU {
    vector<int> rank, parent;

    DSU(int n) : rank(n, 1), parent(n) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(const int u) { return parent[u] == u ? u : (parent[u] = find(parent[u])); }
    int size(int u) { return rank[find(u)]; }

    bool merge(int u, int v) {
        u = find(u); v = find(v);
        if (u == v) { return false; }
        if (rank[u] < rank[v]) { swap(u, v); }
        rank[u] += rank[v]; parent[v] = u;
        return true;
    }
};

struct edge {
    int u, v, id; edge() {}
    edge(int _u, int _v, int _w) : u(_u), v(_v), id(_w) {}
};

struct Tree {
    vector<vector<int>> anc;
    vector<vector<edge>> nodes;
    vector<int> depth;

    int n, lg2;

    Tree(int _n) : n(_n) {
        lg2 = (int)(ceil(log2(n + 0.0)));
        nodes.resize(n);
        depth.resize(n, 0);
        anc.resize(n + 1, vector<int>(lg2 + 1, -1));
    }

    void add_edge(int u, int v, int id) {
        nodes[u].emplace_back(u, v, id);
        nodes[v].emplace_back(v, u, id);
    }

    void fullPrprocess() {
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++) {
            if (visited[i]) { continue; }
            preprocess(visited, i);
        }
    }

    void preprocess(vector<bool>& visited, int r) {
        queue<int> q; q.push(r);
        visited[r] = true; anc[r][0] = r;

        vector<int> curComp;
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            curComp.push_back(cur);
            for (auto& e : nodes[cur]) {
                if (visited[e.v]) { continue; }
                anc[e.v][0] = cur;
                depth[e.v] = depth[cur] + 1;
                q.push(e.v); visited[e.v] = true;
            }
        }

        for (int i = 1; i <= lg2; i++) for (auto& u : curComp)
            anc[u][i] = anc[anc[u][i - 1]][i - 1];
    }

    int LCA(int u, int v) {
        if (depth[u] < depth[v]) { swap(u, v); }
        for (int i = lg2; i >= 0; i--)
            if (depth[u] - (1 << i) >= depth[v])
                u = anc[u][i];

        if (u == v) { return u; }
        for (int i = lg2; i >= 0; i--)
            if (anc[u][i] != anc[v][i]) {
                u = anc[u][i]; v = anc[v][i];
            }

        return anc[u][0];
    }

    int dist(int u, int v) {
        return depth[u] + depth[v] - 2 * depth[LCA(u, v)];
    }

    int findKthParent(int u, int k) {
        int pI = 0; while (k) {
            if (k & 1) { u = anc[u][pI]; }
            pI++; k >>= 1;
        }
        return u;
    }

    int findKthOnPath(int u, int v, int k) {
        int lca = LCA(u, v), d = dist(u, v);
        return dist(u, lca) >= k ? findKthParent(u, k) : findKthParent(v, d - k);
    }
};

int main() {
    freopen("sites.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t; cin >> t; while (t--) {
        int n, q; cin >> n >> q;
        map<pair<int, int>, int> m;

        Tree t(n); DSU dsu(n);
        vector<pair<string, int>> ans(q);
        vector<array<int, 3>> toDo;

        int eID = 1; for (int qID = 0; qID < q; qID++) {
            int type, u, v; cin >> type >> u >> v;
            u--; v--; if (type == 1) {
                if (dsu.find(u) == dsu.find(v)) { ans[qID] = { "", -1 }; }
                else {
                    t.add_edge(u, v, eID); dsu.merge(u, v);
                    m[{u, v}] = m[{v, u}] = eID;
                    ans[qID] = { "", eID++ };
                }
            }
            else {
                if (dsu.find(u) != dsu.find(v)) { ans[qID] = { "", -1 }; }
                else { toDo.push_back({ u, v, qID }); }
            }
        }

        t.fullPrprocess();
        for (auto& curQ : toDo) {
            int u = curQ[0], v = curQ[1], qIdx = curQ[2];

            int curD = t.dist(u, v);
            if (curD % 2 == 0) {
                int treeAns = t.findKthOnPath(u, v, curD / 2);
                ans[qIdx] = { "c", treeAns + 1 };
            }
            else {
                int nU = t.findKthOnPath(u, v, curD / 2);
                int nV = t.findKthOnPath(v, u, curD / 2);
                ans[qIdx] = { "r", m[{nU, nV}] };
            }
        }

        for (auto& p : ans) {
            if (p.first != "") { cout << p.first << " "; }
            cout << p.second << '\n';
        }
    }
}
