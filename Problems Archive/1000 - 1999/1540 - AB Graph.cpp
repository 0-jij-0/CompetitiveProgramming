#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
#include <string>
using namespace std;

vector<string> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t; while (t--) {
		int n, m; cin >> n >> m; v.resize(n);
		for (auto& x : v) { cin >> x; }

		if (m & 1) {
			cout << "YES" << '\n';
			for (int i = 0; i <= m; i++)
				cout << (i % 2 ? 2 : 1) << ' ';
			cout << '\n'; continue;
		}

		int I = -1, J = -1;
		for (int i = 0; i < n; i++)
			for(int j = i + 1; j < n; j++)
				if (v[i][j] == v[j][i]) { I = i; J = j; break; }

		if (I != -1) {
			cout << "YES" << '\n';
			for (int i = 0; i <= m; i++)
				cout << (i % 2 ? J + 1 : I + 1) << ' ';
			cout << '\n'; continue;
		}

		int K = -1;
		for (int i = 0; i < n; i++) {
			int x = count(v[i].begin(), v[i].end(), 'a');
			if (x == n - 1 || x == 0) { continue; }
			I = i; J = find(v[i].begin(), v[i].end(), 'a') - v[i].begin();
			K = find(v[i].begin(), v[i].end(), 'b') - v[i].begin(); break;
		}

		if (K == -1) { cout << "NO" << '\n'; continue; }
		cout << "YES" << '\n';
		
		if (m % 4 == 0) {
			for (int i = 0; i <= m / 2; i++)
				cout << (i % 2 ? J + 1 : I + 1) << ' ';
			for (int i = 0; i < m / 2; i++)
				cout << (i % 2 ? I + 1 : K + 1) << ' ';
			cout << '\n'; continue;
		}

		for (int i = 0; i <= m / 2; i++)
			cout << (i % 2 ? I + 1 : J + 1) << ' ';
		for (int i = 0; i < m / 2; i++)
			cout << (i % 2 ? I + 1 : K + 1) << ' ';
		cout << '\n'; continue;

	}

	cin.ignore(2); return 0;
}