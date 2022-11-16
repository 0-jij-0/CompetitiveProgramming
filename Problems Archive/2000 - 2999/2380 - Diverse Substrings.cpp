#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;

string s; int n;

ll countDiverse(int m) {
	vector<int> freq(10, 0);
	auto isDiverse = [&]() {
		int ma = *max_element(freq.begin(), freq.end());
		int cnt = 10 - count(freq.begin(), freq.end(), 0);
		return cnt >= ma;
	};

	for (int i = 0; i < m; i++) freq[s[i] - '0']++;

	ll res = isDiverse(); 
	for (int i = m; i < n; i++) {
		freq[s[i - m] - '0']--; freq[s[i] - '0']++;
		res += isDiverse();
	}

	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		cin >> n >> s; ll res = 0;

		for (int L = 1; L <= min(100, n); L++)
			res += countDiverse(L);

		cout << res << '\n';
	}
}