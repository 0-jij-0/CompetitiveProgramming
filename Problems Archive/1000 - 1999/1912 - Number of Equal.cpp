#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

ll numberOfEqual(vector<int>& a, vector<int>& b) {
	int iA = 0, jA = 0, n = (int)a.size();
	int iB = 0, jB = 0, m = (int)b.size();

	ll res = 0; while (iA != n && iB != m) {
		while (jA != n && a[jA] == a[iA]) { jA++; }
		while (jB != m && b[jB] == b[iB]) { jB++; }
		ll lenA = jA - iA, lenB = jB - iB;
		if (a[iA] != b[iB]) { a[iA] < b[iB] ? iA = jA : iB = jB; }
		else { res += lenA * lenB; iA = jA; iB = jB; }
	}

	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m; cin >> n >> m;
	vector<int> a(n), b(m);
	for (auto& x : a) cin >> x;
	for (auto& x : b) cin >> x;

	cout << numberOfEqual(a, b) << '\n';
	cin.ignore(2); return 0;
}