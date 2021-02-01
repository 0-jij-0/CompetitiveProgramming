#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<int> v; stack<int> s;

int main() {
	int n; cin >> n; v.resize(n);
	for (auto &x : v) { cin >> x; }
	ll res = 0; for (int i = 0; i <= n; i++) {
		while (!s.empty() && (i == n || v[i] <= v[s.top()])) {
			ll h = v[s.top()]; s.pop();
			ll w = s.empty() ? i : i - s.top() - 1;
			res = max(res, h * w);
		} s.push(i);
	}
	cout << res << endl;
	cin.ignore(2); return 0;
}