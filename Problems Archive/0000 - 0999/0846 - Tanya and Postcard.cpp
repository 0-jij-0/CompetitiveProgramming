#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool isLower(char &c) { return c >= 'a' && c <= 'z'; }
bool isUpper(char &c) { return c >= 'A' && c <= 'Z'; }

vector<int> lowerS, lowerT, upperS, upperT;

int main() {
	lowerS.resize(26, 0); lowerT.resize(26, 0);
	upperS.resize(26, 0); upperT.resize(26, 0);
	string s, t; cin >> s >> t;
	for (char &c : s)
		if (isLower(c)) { lowerS[c - 'a']++; }
		else { upperS[c - 'A']++; }
	for (char &c : t)
		if (isLower(c)) { lowerT[c - 'a']++; }
		else { upperT[c - 'A']++; }

	int y = 0, w = 0;
	for (int i = 0; i < 26; i++) {
		int ans = min(lowerS[i], lowerT[i]);
		y += ans; lowerS[i] -= ans; lowerT[i] -= ans;
		ans = min(upperS[i], upperT[i]);
		y += ans; upperS[i] -= ans; upperT[i] -= ans;

		ans = min(lowerS[i], upperT[i]);
		w += ans; lowerS[i] -= ans; upperT[i] -= ans;
		ans = min(upperS[i], lowerT[i]);
		w += ans; upperS[i] -= ans; lowerT[i] -= ans;
	}
	cout << y << ' ' << w << endl;
	cin.ignore(2); return 0;
}