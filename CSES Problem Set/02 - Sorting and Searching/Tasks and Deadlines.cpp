#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<pair<int, int>> v;

int main() {
	int n; cin >> n; v.resize(n);
	for (auto &x : v) { cin >> x.first >> x.second; }
	sort(v.begin(), v.end()); ll cur = 0, res = 0;
	for (auto &x : v) { cur += x.first; res += x.second - cur; }
	cout << res << endl; cin.ignore(2); return 0;
}