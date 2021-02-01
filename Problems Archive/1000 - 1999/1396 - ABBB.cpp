#include <iostream>
#include <string>
#include <stack>
using namespace std;

string s; stack<char> st;

int main() {
	int t; cin >> t; while (t--) {
		cin >> s;; int n = (int)s.size();
		int res = 0, b = 0;
		for (int i = n - 1; i >= 0; i--) {
			if (s[i] == 'B') { b++; continue; }
			b ? b-- : res++;
		}
		cout << res + (b & 1) << '\n';
	}
	cin.ignore(2); return 0;
}