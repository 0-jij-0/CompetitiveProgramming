#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<int> v;

int main() {
	int n; cin >> n; v.resize(n);
	for (auto& x : v) { cin >> x; }
	sort(v.begin(), v.end()); 
	ll res = 1;	for (auto& x : v) {
		if (x > res) break; res += x;
	}
	cout << res << '\n';
	cin.ignore(2); return 0;
}