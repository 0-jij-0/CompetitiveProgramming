#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int main() {
	int n; cin >> n; v.resize(n);
	for (auto &x : v) { cin >> x; }
	sort(v.begin(), v.end());
	int a = v.back(); v.pop_back();
	int b = v.back(); v.pop_back();
	v.push_back(a); reverse(v.begin(), v.end());
	v.push_back(b);
	if (v[0] >= v[1] + v.back()) { cout << "NO" << endl; }
	else {
		cout << "YES" << endl;
		for (int i = 0; i < n; i++) {
			cout << v[i];
			if (i + 1 != n) { cout << ' '; }
			else { cout << endl; }
		}
	}
	cin.ignore(2); return 0;
}