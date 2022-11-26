#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	string s, t; cin >> s >> t;
	int n = (int)s.size();
	cout << (s.find(t) != -1 ? "Yes" : "No") << '\n';
}