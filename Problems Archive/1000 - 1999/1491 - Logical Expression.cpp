#include <iostream>
#include <vector>
#include <string>
using namespace std;
typedef long long ll;

vector<string> v;

int main() {
	int n; cin >> n; v.resize(n);
	for (auto& x : v) { cin >> x; }

	ll res = 0; for (int i = n - 1; i >= 0; i--)
		if (v[i] == "OR") res += 1ll << (i + 1);

	cout << res + 1 << '\n';
	cin.ignore(2); return 0;
}