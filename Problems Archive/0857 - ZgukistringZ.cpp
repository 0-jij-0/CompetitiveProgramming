#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<int> A, B, C;

int main() {
	string a, b, c; cin >> a >> b >> c;
	vector<int> A(26, 0), B(26, 0), C(26, 0);
	for (char &c : a) { A[c - 'a']++; }
	for (char &c : b) { B[c - 'a']++; }
	for (char &c : c) { C[c - 'a']++; }

	int ans = -1, bC = 0, cC = 0;
	for (int i = 0; i <= (int) a.size(); i++) {
		bool can = true; int res = 1000000000;
		for (int j = 0; j < 26; j++)
			if (B[j] * i > A[j]) { can = false; break; }
		if (!can) { break; }

		for (int j = 0; j < 26; j++) {
			if (C[j] > 0) { res = min(res, (A[j] - B[j] * i) / C[j]); }
		}
		if (ans < i + res) { ans = i + res; bC = i; cC = res; }
	}

	for(int i = 0; i < bC; i++) { cout << b; }
	for(int i = 0; i < cC; i++) { cout << c; }
	for (int i = 0; i < 26; i++) {
		A[i] -= (B[i] * bC + C[i] * cC);
		cout << string(A[i], i + 'a');
	}
	cout << endl; cin.ignore(2); return 0;
}