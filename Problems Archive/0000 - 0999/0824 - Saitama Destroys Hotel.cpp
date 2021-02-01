#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int main() {
	int n, s; cin >> n >> s; v.resize(s + 1, 0);
	for (int i = 0; i < n; i++) {
		int f, t; cin >> f >> t;
		v[f] = max(v[f], t);
	}
	int res = 0;
	for (int i = s; i >= 0; i--)
		res = (res < v[i]) ? v[i] + 1 : res + 1;
	cout << res - 1 << endl;
	cin.ignore(2); return 0;
}