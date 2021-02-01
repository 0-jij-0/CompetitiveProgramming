#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> vv;
vector<int> v;

int main() {
	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		int n, x; cin >> n >> x;
		v.clear(); vv.clear();
		v.resize(n); vv.resize(n);
		for (int j = 0; j < n; j++) {
			int d, h; cin >> d >> h;
			vv[j] = { d, h }; v[j] = d - h;
		}
		int max_d = max_element(vv.begin(), vv.end())->first;
		int max_dif = *max_element(v.begin(), v.end());
		if (max_d >= x) { cout << 1 << endl; }
		else if (max_dif <= 0) { cout << -1 << endl; }
		else {
			int m1 = (x + max_dif - 1) / max_dif;
			int m2 = ((x - max_d + max_dif - 1) / max_dif) + 1;
			cout << min(m1, m2) << endl;
		}
	}
	cin.ignore(2); return 0;
}