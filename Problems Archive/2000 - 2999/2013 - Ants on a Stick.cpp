#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

vector<int> P, D, dist;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		int n, L; cin >> n >> L;
		P.resize(n); D.resize(n); dist.resize(n);
		for (int i = 0; i < n; i++) {
			cin >> P[i] >> D[i];
			dist[i] = D[i] ? L - P[i] : P[i];
		}
		vector<int> idx(n);
		iota(idx.begin(), idx.end(), 0);
		auto comp1 = [&](const int& i, const int& j) {
			return P[i] < P[j];
		}; sort(idx.begin(), idx.end(), comp1);

		vector<int> v(n);
		iota(v.begin(), v.end(), 0);
		auto comp2 = [&](const int& i, const int& j) {
			return dist[i] != dist[j] ? dist[i] < dist[j] : D[i] < D[j];
		}; sort(v.begin(), v.end(), comp2);

		vector<int> res;
		int i = 0, j = n - 1; for (auto& x : v)
			res.push_back(D[x] ? idx[j--] : idx[i++]);

		i = 0, j = 0; while (i != n) {
			while (j != n && dist[v[i]] == dist[v[j]]) j++;
			sort(res.begin() + i, res.begin() + j); i = j;
		}

		cout << "Case #" << t << ": ";
		for (auto& x : res) cout << x + 1 << ' '; cout << '\n';
	}
}