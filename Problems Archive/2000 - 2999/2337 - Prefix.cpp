#include <iostream>
#include <string>
using namespace std;

string s, t;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> s >> t;
	while (t.size() > s.size()) t.pop_back();
	cout << (t == s ? "Yes" : "No") << '\n';
}