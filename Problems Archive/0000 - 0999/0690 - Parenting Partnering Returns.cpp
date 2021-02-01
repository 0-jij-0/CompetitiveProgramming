#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct task { 
	int s, e; task() {}
	bool operator < (const task &rhs) const { return s < rhs.s; }
};
vector<pair<task, int>> tasks;

int main() {
	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		int n; cin >> n; tasks.resize(n);
		for (int i = 0; i < n; i++) {
			cin >> tasks[i].first.s >> tasks[i].first.e;
			tasks[i].second = i;
		}
		sort(tasks.begin(), tasks.end());
		int C = 0, J = 0; vector<char> res(n); bool b = true;
		for (int i = 0; i < n; i++) {
			if (tasks[i].first.s >= C) { res[tasks[i].second] = 'C'; C = tasks[i].first.e; continue; }
			if (tasks[i].first.s >= J) { res[tasks[i].second] = 'J'; J = tasks[i].first.e; continue; }
			b = false; break;
		}
		cout << "Case #" << t << ": ";
		if (!b) { cout << "IMPOSSIBLE" << endl; continue; }
		for (char &c : res) { cout << c; }cout << endl;
	}
	cin.ignore(2); return 0;
}