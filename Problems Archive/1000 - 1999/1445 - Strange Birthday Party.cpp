#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
typedef long long ll;

vector<int> K, C;

int main() {
	int t; cin >> t; while (t--) {
		int n, m; cin >> n >> m;
		K.resize(n); C.resize(m);
		for (auto& x : K) { cin >> x; x--; }
		for (auto& x : C) { cin >> x; }
		vector<int> v(n); iota(v.begin(), v.end(), 0);
		auto comp = [&](const int& i, const int& j) {return K[i] < K[j]; };
		sort(v.rbegin(), v.rend(), comp); ll res = 0; int cur = 0;
		for (int i = 0; i < n; i++) {
			if (cur <= K[v[i]]) { res += C[cur++]; continue; }
			res += C[K[v[i]]];
		}
		cout << res << '\n';
	}
	cin.ignore(2); return 0;
}