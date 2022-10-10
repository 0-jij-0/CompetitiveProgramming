#include <bits/stdc++.h>
using namespace std;

int main() {
	string s; cin >> s; sort(s.begin(), s.end()); vector<string> res(1, s);
	while (next_permutation(s.begin(), s.end())) { res.push_back(s); }
	cout << res.size() << '\n'; for (auto &x : res)  
		cout << x << ' '; cout << '\n';
}