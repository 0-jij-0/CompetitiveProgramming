#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string s; cin >> s; int n = (int)s.size();
	cout << s[n >> 1] << '\n';
}