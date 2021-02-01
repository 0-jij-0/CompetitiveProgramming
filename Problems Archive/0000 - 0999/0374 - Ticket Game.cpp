#include <iostream>
#include <string>
using namespace std;

string s;

int main() {
	int n; cin >> n >> s;
	int s1 = 0, s2 = 0, q1 = 0, q2 = 0;
	for (int i = 0; i < n / 2; i++) {
		if (s[i] == '?') { q1++; }
		else { s1 += s[i] - '0'; }
	}
	for (int i = n/2; i < n; i++) {
		if (s[i] == '?') { q2++; }
		else { s2 += s[i] - '0'; }
	}
	bool b; int dif = abs(s1 - s2);
	if ((q1 + q2) % 2) { b = true; }
	else if (q1 < q2 && s1 < s2) { b = true; }
	else if (q2 < q1 && s2 < s1) { b = true; }
	else {
		int x = 9 * (abs(q1 - q2) / 2);
		b = dif != x;
	}
	cout << (b ? "Monocarp" : "Bicarp") << endl;
	cin.ignore(2); return 0;
}