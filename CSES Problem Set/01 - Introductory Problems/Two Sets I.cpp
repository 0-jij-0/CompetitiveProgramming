#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll n; cin >> n; ll sum = n * (n + 1) / 2;
	if (sum % 2) { cout << "NO" << endl; return 0; }
	vector<int> first, second; ll fs = 0; int i = 1;
	while (sum - fs > fs) { fs += i; first.push_back(i++); }
	int moveIt = ((fs << 1) - sum) >> 1;
	if (moveIt) {
		first.erase(first.begin() + moveIt - 1);
		second.push_back(moveIt);
	}
	while (i <= n) { second.push_back(i++); } 
	cout << "YES" << '\n' << first.size() << '\n';
	for (auto &x : first) { cout << x << ' '; }
	cout << '\n' << second.size() << '\n';
	for (auto &x : second) { cout << x << ' '; }
	cout << '\n';
}