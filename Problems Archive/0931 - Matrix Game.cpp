#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

vector<vector<int>> v;
set<int> row, col;

int main() {
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m; v.clear(); 
		v.resize(n, vector<int>(m)); row.clear(); col.clear();
		for (int i = 0; i < n; i++) { row.insert(i); }
		for (int i = 0; i < m; i++) { col.insert(i); }
		for(int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				cin >> v[i][j]; if (v[i][j]) {
					row.erase(i); col.erase(j);
				}
			}
		int res = min(row.size(), col.size());
		cout << (res % 2 ? "Ashish" : "Vivek") << endl;
	}
	cin.ignore(2); return 0;
}