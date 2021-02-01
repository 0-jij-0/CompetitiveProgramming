#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int main() {
	int n; cin >> n; v.resize(n);
	for (auto &x : v) { cin >> x; }

	int res = 0, i = 0;
	while (i < n) {
		int cur = v[i];
		while (i < cur) { cur = max(cur, v[i]); i++; }
		res++;
	}
	cout << res << endl;
	cin.ignore(2); return 0;
}