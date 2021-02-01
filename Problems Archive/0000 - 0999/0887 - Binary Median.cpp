#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<string> v; int n, m;

void addOne(string &res) {
	int i = (int)res.size() - 1;
	while (res[i] == '1') { res[i--] = '0'; }
	res[i] = '1';
}

string toBinary(ll k) {
	if (k == 0) { return string(m, '0'); }
	string res;
	while (k) { res.push_back((k % 2) + '0'); k >>= 1; }
	while (res.size() != m) { res.push_back('0'); }
	reverse(res.begin(), res.end()); return res;
}

void findRes(string &res, ll k){
	ll x = max(k - 100, 0ll);
	res = toBinary(x);
	int a = lower_bound(v.begin(), v.end(), res) - v.begin();
	ll rem = min(100ll, k) + a + (a != n && v[a] == res);
	while (rem) { addOne(res); rem -= !binary_search(v.begin(), v.end(), res); }
}

int main() {
	int t; cin >> t;
	while (t--) {
		cin >> n >> m; v.resize(n);
		for (auto &x : v) { cin >> x; }
		sort(v.begin(), v.end()); string res(m, '0'); 
		findRes(res, ((1ll << m) - n - 1) / 2);
		cout << res << endl;
	}
	cin.ignore(2); return 0;
}