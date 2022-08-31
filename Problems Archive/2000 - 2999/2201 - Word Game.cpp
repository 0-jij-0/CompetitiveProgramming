#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

map<string, vector<int>> M;
vector<vector<string>> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n; M.clear(); v.clear();
		v.resize(3, vector<string>(n));
		for(int i = 0; i < 3; i++)
			for (int j = 0; j < n; j++) {
				cin >> v[i][j]; M[v[i][j]].push_back(i);
			}

		int score[3] = { 0, 0, 0 };
		for (auto& s : M)
			if (s.second.size() == 1) score[s.second.front()] += 3;
			else if (s.second.size() != 3) for (int& e : s.second) score[e]++;

		for (int& r : score) cout << r << ' '; cout << '\n';
	}
}