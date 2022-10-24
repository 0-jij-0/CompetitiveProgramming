#include <bits/stdc++.h>
using namespace std;

vector<int> B; int n, M;

vector<int> check(int x) {
	int y = B[0] + B[1] - x;
	if (y < 0 || (y & 1)) return {};

	multiset<int> S(B.begin(), B.end());
	vector<int> res(n); res[0] = y / 2;
	
	for (int i = 1; i < n; i++) {
		res[i] = *S.begin() - res[0];
		for (int j = 0; j < i; j++) {
			auto it = S.find(res[i] + res[j]);
			if (it == S.end()) return {};
			S.erase(it);
		}
	}

	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n; B.resize(n * (n - 1) / 2);
	for (auto& x : B) cin >> x;
	sort(B.begin(), B.end());

	M = n * (n - 1) / 2; vector<int> res;
	for (int i = 2; i < M; i++) 
		if(!(res = check(B[i])).empty()) break;

	for (auto& x : res) cout << x << ' '; cout << '\n';
}