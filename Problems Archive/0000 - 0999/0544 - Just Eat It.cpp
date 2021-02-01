#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
vector<int> v;

bool maxSumSub() {
	int L = 0, R = 0;
	int l = 0, r = 0;
	int n = (int)v.size();
	ll cur_sum = 0, max_sum = 0;
	while (r != n) {
		cur_sum += v[r]; r++;
		if (cur_sum > max_sum) {
			L = l; R = r;
			max_sum = cur_sum;
		}
		if (cur_sum <= 0) {
			return false;
		}
	}
	return L == 0 && R == n;
}

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n; v.resize(n);
		for (auto &x : v) { cin >> x; }
		cout << (maxSumSub() ? "YES" : "NO") << endl;
	}
	cin.ignore(2); return 0;
}