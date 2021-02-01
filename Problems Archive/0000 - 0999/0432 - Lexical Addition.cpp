#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
vector<ll> res;
ll n, a, b;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	cin >> n >> a >> b;	ll len = 1ll;
	for (; len <= 100000; len++) {
		ll x = n / len;
		if (x > b || (x == b && n % len)) { continue; }
		break;
	}
	if (a == b && n % a) { cout << "NO"; }
	else if(a == b) {
		cout << "YES" << endl;
		res.resize(n / a, a);
		for (auto &x : res) { cout << x << ' '; }
	}
	if (len == 100001 || n/len < a) { cout << "NO"; }
	else {
		cout << "YES" << endl;
		ll x = n / len, rem = n % len;
		res.resize(len, x);
		int j = (int)res.size() - 1;
		while (rem != 0) { res[j]++; rem--; j--; }
		int i = 0; j = (int)res.size() - 1;
		while (i < j) {
			if (res[i] == a) { i++; continue; }
			if (res[j] == b) { j--; continue; }
			res[i]--; res[j]++;
		}
		for (auto &x : res) { cout << x << ' '; }
	}
	cout << endl; cin.ignore(2); return 0;
}