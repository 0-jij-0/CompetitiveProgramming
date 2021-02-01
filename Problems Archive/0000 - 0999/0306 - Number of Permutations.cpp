#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const long long mod = 998244353;
long long fact[300001];
vector<pair<int, int>> p;

bool compare1(const pair<int, int> &p1, const pair<int, int> &p2) {
	if (p1.first == p2.first) { return p1.second < p2.second; }
	return p1.first < p2.first;
}

bool compare2(const pair<int, int> &p1, const pair<int, int> &p2) {
	return p1.second < p2.second;
}

void fill_fact() {
	fact[0] = 1;
	for (int i = 1; i < 300001; i++) {
		fact[i] = i * fact[i - 1]; fact[i] %= mod;
	}
}

int main() {
	int n; cin >> n; p.resize(n); fill_fact();
	for (auto &x : p) { cin >> x.first >> x.second; }
	long long res = 0, a = 1;
	sort(p.begin(), p.end(), compare1);
	int x = 1, last = p.front().first;
	for (int i = 1; i < n; i++) {
		if (p[i].first == last) { x++; continue; }
		a *= fact[x]; x = 1; last = p[i].first; a %= mod;
	}
	a *= fact[x]; res += a; x = 1; res %= mod; a = 1;
	int last1 = p.front().first, last2 = p.front().second;
	for (int i = 1; i < n; i++) {
		if (p[i].second < p[i - 1].second) { a = 0; break; }
		if (p[i].first == last1 && p[i].second == last2) { x++; continue; }
		a *= fact[x] - mod; x = 1; last1 = p[i].first; last2 = p[i].second; a %= mod;
	}
	a *= fact[x]; res -= a - mod; x = 1; res %= mod; a = 1;
	sort(p.begin(), p.end(), compare2); last = p.front().second;
	for (int i = 1; i < n; i++) {
		if (p[i].second == last) { x++; continue; }
		a *= fact[x]; x = 1; last = p[i].second; a %= mod;
	}
	a *= fact[x]; res += a; x = 1; res %= mod;
	res = fact[n] - res + mod; res %= mod;
	cout << res << endl;
	cin.ignore(2); return 0;
}