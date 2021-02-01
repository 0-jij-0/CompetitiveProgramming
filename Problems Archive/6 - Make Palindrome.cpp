#include <iostream>
#include <string>
using namespace std;

int DP[1100][1100];
int CA[1100][1100];

int DPmakePal(string &s, int i, int j) {

	if (DP[i][j] != -1) return DP[i][j];

	if (s[i] == s[j]) { DP[i][j] = DPmakePal(s, i + 1, j - 1); CA[i][j] = 0; return DP[i][j]; }

	int x = 1 + DPmakePal(s, i + 1, j);
	int y = 1 + DPmakePal(s, i, j - 1);

	DP[i][j] = (x < y) ? x : y;
	CA[i][j] = (x < y) ? 1 : 2;
	return DP[i][j]; 
}

string printPal(string &s, int i, int j) {

	if (i == j) return string(1, s[i]);

	if (i > j) return "";

	switch (CA[i][j]) {
	case 0:
		return string(1, s[i]) + printPal(s, i + 1, j - 1) + string(1, s[i]);
		break;
	case 1:
		return string(1, s[i]) + printPal(s, i + 1, j) + string(1, s[i]);
		break;
	case 2:
		return string(1, s[j]) + printPal(s, i, j - 1) + string(1, s[j]);
		break;
	}

}

void makePal(string &s) {
	
	for (int i = 0; i < s.size() + 5; i++) {
		for (int j = 0; j < s.size() + 5; j++) {
			if (i > j || i == j) { DP[i][j] = 0; }
			else { DP[i][j] = -1; }
		}		
	}
	for (int i = 0; i < s.size() + 5; i++) {
		for (int j = 0; j < s.size() + 5; j++) {
			 CA[i][j] = -1;
		}
	}

	cout << DPmakePal(s, 0, s.size() - 1) << " "; cout << printPal(s, 0, s.size() - 1);
}

int main() {
	string s; cin >> s;
	while (!cin.fail()) {
		makePal(s); cout << endl;
		cin >> s;
	}
	cin.ignore(2);
	return 0;
}