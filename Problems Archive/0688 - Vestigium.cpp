#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<set<int>> row, col;

int main() {
	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		int n; cin >> n; row.clear(); col.clear();
		row.resize(n); col.resize(n);
		int trace = 0, rl = 0, cl = 0;
		for(int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				int x; cin >> x; if (i == j) { trace += x; }
				row[i].insert(x); col[j].insert(x);
			}
		for (auto &x : row) { 
			rl += x.size() != n;
		}
		for (auto &x : col) { cl += x.size() != n; }
		cout << "Case #" << t << ": ";
		cout << trace << ' ' << rl << ' ' << cl << endl;
	}
	cin.ignore(2); return 0;
}