#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <string.h>
 
using namespace std;
typedef long long ll;
const int INF = 1 << 30;
int h, w;
 
struct edge {
	int u, v, w; edge() {}
	edge(int _u, int _v, int _w) :u(_u), v(_v), w(_w) {}
};
 
struct node { vector<edge> edges; };
 
struct graph {
	vector<node> nodes;
	int n;
 
	graph(int _n) :n(_n) { nodes.resize(n); }
 
	void add_edge(int u, int v, bool uD, bool vD) {
		edge e1(u, v, 0), e2(v, u, 0);
		if (uD) { e2.w = 1; }
		if (vD) { e1.w = 1; }
		nodes[u].edges.push_back(e1);
		nodes[v].edges.push_back(e2);
	}
 
	//Assumes all weights are either 0 or x for a fixed x >= 0
	//Returns the shortest distance from s to all nodes
	vector<int> bfs01(int s) {
		vector<bool> visited(n, 0); vector<int> dist(n, INF); deque<int> dq;
		dist[s] = 0; dq.push_back(s);
 
		while (!dq.empty()) {
			int cur = dq.front(); dq.pop_front();
			while (visited[cur] && !dq.empty()) { cur = dq.front(); dq.pop_front(); }
			if (visited[cur]) { break; } visited[cur] = 1;
 
			for (auto &e : nodes[cur].edges) {
				if (visited[e.v] || dist[e.v] < dist[cur] + e.w) { continue; }
				dist[e.v] = dist[cur] + e.w;
				if (e.w) { dq.push_back(e.v); }
				else { dq.push_front(e.v); }
			}
		}
 
		return move(dist);
	}
};
 
int dx[2] = { 1, 0 };
int dy[2] = { 0, 1 };
 
bool check(int i, int j) {
	if (i < 0 || j < 0 || i >= h || j >= w) { return false; }
	return true;
}
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
 
	int t; cin >> t;
	while (t--) {
		cin >> h >> w;
		vector<string> grid(h);
		for (auto &s : grid) { cin >> s; }
 
		int t1 = -1, t2 = -1;
 
		graph g(h*w + 1);
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				int cur = i * w + j;
				if (grid[i][j] == '$' && t1 == -1) { t1 = cur; }
				else if (grid[i][j] == '$') { t2 = cur; }
 
				for (int k = 0; k < 2; k++) {
					if (grid[i][j] == '*') { continue; }
					int ni = i + dx[k], nj = j + dy[k];
					if (!check(ni, nj) || grid[ni][nj] == '*') { continue; }
 
					bool uD = false, vD = false;
					if (grid[i][j] == '#') { uD = 1; }
					if (grid[ni][nj] == '#') { vD = 1; }
					g.add_edge(cur, ni*w + nj, uD, vD);
				}
			}
		}
 
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (grid[i][j] == '*') { continue; }
				int cur = i * w + j;
				if (i == 0 || i == h - 1 || j == 0 || j == w - 1) {
					bool uD = false, vD = false;
					if (grid[i][j] == '#') { uD = 1; }
					g.add_edge(cur, h*w, uD, 0);
				}
			}
		}
 
		vector<int> distS = g.bfs01(h*w);
		vector<int> distT1 = g.bfs01(t1);
		vector<int> distT2 = g.bfs01(t2);
 
		int res = h * w + 5;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (grid[i][j] == '*') { continue; }
				int cur = i * w + j;
				int newD = distS[cur] + distT1[cur] + distT2[cur];
				if (grid[i][j] == '#') { newD -= 2; }
				res = min(res, newD);
			}
		}
 
		cout << res << '\n';
	}
}