#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> p;
vector<bool> visited;
vector<vector<int>> c;
vector<vector<int>> sqrtp;

bool comp(vector<int> &v1, vector<int> &v2) {
	return (int) v1.size() < (int) v2.size();
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n; p.resize(n); 
	visited.resize(n, false);

	for (int i = 0; i < n; i++) {
		cin >> p[i]; p[i]--;
	}
	for (int i = 0; i < n; i++) {
		if (visited[i]) { continue; }
		vector<int> v; v.push_back(i);
		visited[i] = true;
		while (p[v.back()] != v.front()) {
			visited[p[v.back()]] = true;
			v.push_back(p[v.back()]);
		}
		c.emplace_back(v);
	}
	sort(c.begin(), c.end(), comp);
	bool b = true;
	for (int i = 0; i < (int)c.size(); i++) {
		if (c[i].size() == 1) { sqrtp.emplace_back(c[i]); continue; }
		if ((int) c[i].size() % 2) {
			int j = 0, k = ((int)c[i].size() + 1) >> 1;
			vector<int> v;
			while (k != (int)c[i].size()) {
				v.push_back(c[i][j]);
				v.push_back(c[i][k]);
				j++; k++;
			}
			v.push_back(c[i][j]);
			sqrtp.emplace_back(v);
		}
		else {
			int j = i; while (j < (int)c.size() && c[i].size() == c[j].size()) { j++; }
			j--; if ((j - i + 1) % 2) { b = false; break; }
			int k = i; i = j;
			while (k < j) {
				int idx = 0; vector<int> v;
				while (idx != (int)c[i].size()) {
					v.push_back(c[k][idx]);
					v.push_back(c[j][idx]);
					idx++;
				}
				sqrtp.emplace_back(v);
				k++; j--;
			}
		}
	}
	if (!b) { cout << -1 << endl; }
	else {
		for (auto &x : sqrtp) {
			p[x.back()] = x.front();
			for (int i = 0; i < (int)x.size() - 1; i++)
				p[x[i]] = x[i + 1];
		}
		for (auto &x : p) { cout << x + 1 << ' '; }
		cout << endl;
	}
	cin.ignore(2); return 0;
}