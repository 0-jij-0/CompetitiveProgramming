#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> edges;
vector<bool> nodes;
int n, m;

void print_res() {
	vector<int> res;
	for (int i = 0; i < m; i++) {
		if (res.size() == n) { break; }
		int &u = edges[i].first, &v = edges[i].second;
		if (!(nodes[u] || nodes[v])) { 
			res.push_back(i + 1); nodes[u] = nodes[v] = true;
		}
	}
	if (res.size() == n) {
		cout << "Matching" << endl;
		for (int i = 0; i < n; i++) {
			cout << res[i];
			if (i + 1 != n) { cout << ' '; }
			else { cout << endl; }
		}
	}
	else {
		cout << "IndSet" << endl;
		int count = 0;
		for (int i = 0; i < 3 * n; i++) {
			if (nodes[i]) { continue; }
			cout << i + 1; count++;
			if (count != n) { cout << ' '; }
			else { cout << endl; break; }
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);	
	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n >> m;
		nodes.clear(); edges.clear();
		nodes.resize(3 * n, 0); edges.resize(m);
		for (int j = 0; j < m; j++) {
			int u, v; cin >> u >> v;
			edges[j] = { u - 1, v - 1 };
		}
		print_res();
	}
	cin.ignore(2); return 0;
}