#include <iostream>
#include <string>
using namespace std;

string s; int a, b;

int main() {
	int n; cin >> n >> s; int res = 0;
	for (int i = 0; i < n; i += 2) {
		if (s[i] == 'a') { a++; }
		else { b++; }
		if (s[i + 1] == 'a') { a++; }
		else { b++; }
		if (a == b) { continue; }
		s[i] = (s[i] == 'a') ? 'b' : 'a';
		a = b; res++;
	}
	cout << res << endl << s << endl;
	cin.ignore(2); return 0;
}