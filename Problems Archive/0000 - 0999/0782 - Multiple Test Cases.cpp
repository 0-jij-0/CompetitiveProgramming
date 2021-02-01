#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<int> v, c, freq;

bool check(ll m) {
	int k = (int)freq.size() - 1;
	ll myCap = m*c[1], reqCap = 0; int i = 1;
	while (i <= k) {
		myCap = min(myCap, m*c[i]); reqCap = freq[i];
		if (myCap < reqCap) { return false; }
		myCap -= reqCap; i++;
	}
	return true;
}

int findMinNum() {
	int l = 0, r = 200005;
	while (l != r) {
		int mid = (l + r) >> 1;
		bool b = check(mid);
		b ? r = mid : l = mid + 1;
	}
	return l;
}

void findMinTest() {
	int num = findMinNum(), k = (int)c.size() - 1;
	vector<vector<int>> res(num);

	int idx = 0;
	for (int i = 1; i <= k; i++)
		for (int j = 0; j < freq[i]; j++)
			res[(idx++) % num].push_back(i);

	cout << num << '\n';
	for (auto &x : res) {
		cout << x.size() << ' ';
		for (auto &y : x) { cout << y << ' '; }
		cout << '\n';
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, k; cin >> n >> k;
	v.resize(n); freq.resize(k + 1, 0); c.resize(k + 1, 0);
	for (auto &x : v) { cin >> x; freq[x]++; }
	for (int i = 1; i <= k; i++) { cin >> c[i]; }

	findMinTest(); cin.ignore(2); return 0;
}