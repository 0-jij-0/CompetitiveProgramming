#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> a, b;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n; a.resize(n); b.resize(n);
		for (auto& x : a) { cin >> x; while (!(x & 1)) x >>= 1; }
		for (auto& x : b) { cin >> x; while (!(x & 1)) x >>= 1; }
		sort(a.begin(), a.end()); sort(b.begin(), b.end());

		while (!a.empty() && a[0] <= b[0]) {
			vector<int> A; int N = (int)a.size();
			vector<int> B; int M = (int)b.size();

			int i = 0, j = 0;
			while (i != N || j != M) {
				if (i == N) { B.push_back(b[j++]); continue; }
				if (j == M) { A.push_back(a[i++]); continue; }

				if (a[i] < b[j]) { A.push_back(a[i++]); continue; }
				if (b[j] < a[i]) { B.push_back(b[j++]); continue; }
				i++; j++;
			}

			for (auto& x : B) x >>= 1;
			a = move(A); b = move(B);
		}

		cout << (a.empty() ? "YES" : "NO") << '\n';
	}
}