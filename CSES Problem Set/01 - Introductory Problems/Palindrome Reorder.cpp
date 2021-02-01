#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string s, a, b;
vector<int> freq(26, 0);

int main() {
	cin >> s; int n = (int)s.size(); int ok = (n % 2) * 27;
	for (char &c : s) { freq[c - 'A']++; }
	for (int i = 0; i < 26; i++) {
		if (freq[i] % 2 && ok == 27) { ok = i; continue; }
		if (freq[i] % 2) { ok = -1; break; }
		a += string(freq[i] / 2, i + 'A');
		b += string(freq[i] / 2, i + 'A');
	}
	if (ok == -1) { cout << "NO SOLUTION" << endl; return 0; }
	if (n % 2) { a += string(freq[ok], ok + 'A'); }
	reverse(b.begin(), b.end()); cout << a + b << endl;
	cin.ignore(2); return 0;
}