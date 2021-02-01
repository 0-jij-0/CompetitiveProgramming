#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;

vector<ll> a, b;
ll sumA = 0, sumB = 0;
pair<int, int> s[2];
map<ll, pair<int, int>> mp;

int main() {
	int n; cin >> n; a.resize(n);
	for (auto &x : a) { cin >> x; sumA += x; }
	int m; cin >> m; b.resize(m);
	for (auto &x : b) { cin >> x; sumB += x; }

	ll minDif = abs(sumA - sumB), numSwaps = 0;

	for(int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			ll dif = abs(sumA - sumB + 2*(b[j] - a[i]));
			if (dif < minDif) { numSwaps = 1; minDif = dif; s[0] = { i, j }; }
		}

	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			mp[2 * (a[i] + a[j])] = { i, j };

	if (n < 2) { 
		cout << minDif << endl << numSwaps << endl;
		if (numSwaps == 1) { cout << s[0].first + 1 << ' ' << s[0].second + 1 << endl; }
		return 0;
	}

	for (int i = 0; i < m; i++)
		for (int j = i + 1; j < m; j++) {
			ll dif = sumA - sumB + 2*(b[i] + b[j]);
			auto it1 = mp.lower_bound(dif), it2 = it1;
			if (it1 != mp.begin()) { it2--; }
			if (it1 == mp.end()) { it1--; }
			ll dif1 = abs(dif - it1->first), dif2 = abs(dif - it2->first);
			if (dif1 < minDif) { numSwaps = 2; minDif = dif1; s[0] = it1->second; s[1] = { i, j }; }
			if (dif2 < minDif) { numSwaps = 2; minDif = dif2; s[0] = it2->second; s[1] = { i, j }; }
		}

	cout << minDif << endl << numSwaps << endl;
	if (numSwaps == 1) { cout << s[0].first + 1 << ' ' << s[0].second + 1 << endl; }
	if (numSwaps == 2) {
		cout << s[0].first + 1 << ' ' << s[1].first + 1 << endl;
		cout << s[0].second + 1 << ' ' << s[1].second + 1 << endl;
	}
	cin.ignore(2); return 0;
}