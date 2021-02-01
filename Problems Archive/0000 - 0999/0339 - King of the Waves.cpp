#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

vector<vector<int>> canBeat;
vector<int> used, res;
queue<int> q;

int main() {
	int n; cin >> n;
	canBeat.resize(n); used.resize(n);
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < n; j++)
			if (s[j] == '1')
				canBeat[i].push_back(j);
	}

	res.push_back(0); used[0] = 1; q.push(0);
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (auto &x : canBeat[cur])
			if (!used[x]) {
				res.push_back(x);
				q.push(x); used[x] = 1;
			}
	}

	if (res.size() != n) { cout << "impossible" << endl; }
	else {
		for (int i = (int)res.size() - 1; i >= 0; i--) {
			cout << res[i];
			if (i != 0) { cout << ' '; }
			else { cout << endl; }
		}
	}
	cin.ignore(2); return 0;
}