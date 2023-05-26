#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	string s; cin >> s;
	cout << find_if(s.begin(), s.end(), [&](char c) { return c >= 'A' && c <= 'Z'; }) - s.begin() + 1 << '\n';
}