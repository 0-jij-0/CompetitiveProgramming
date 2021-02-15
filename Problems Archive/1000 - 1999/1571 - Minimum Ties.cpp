#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> v;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n; v.clear();
		v.resize(n, vector<int>(n, 0));
		for (int d = 1; d <= (n >> 1); d++) {
			for (int i = 0; i < gcd(n, d); i++) {
				vector<int> r(1, i);
				while ((r.back() + d) % n != r.front())
					r.push_back((r.back() + d) % n);
				r.push_back(i);

				if (r.size() == 3) { v[r.front()][r.back()] = 0; continue; }
				for (int i = 1; i < (int)r.size(); i++)
					if (r[i] > r[i - 1]) v[r[i - 1]][r[i]] = 1;
					else v[r[i]][r[i - 1]] = -1;
			}
		}
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++)
				cout << v[i][j] << ' '; cout << '\n';
	}
	cin.ignore(2); return 0;
}