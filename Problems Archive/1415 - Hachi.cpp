#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> freq, mult8;
vector<vector<int>> f;

int main() {
	f.resize(125); for (int i = 0; i < 125; i++) {
		string s = to_string(8 * i); f[i].resize(10, 0); 
		for (char& c : s) f[i][c - '0']++;
	}

	string s; cin >> s; int n = (int)s.size();
	vector<int> freq(10, 0);
	for (char& c : s) freq[c - '0']++;

	if (n < 3) {
		bool okk = false;
		for (int i = 0; i < 13; i++) {
			bool ok = true;
			for(int j = 0; j < 10 && ok; j++)
				if (freq[j] != f[i][j]) { ok = false; }
			if (ok) { cout << "Yes" << '\n'; okk = true; break; }
		}
		if (!okk) { cout << "No" << '\n'; }
	}
	else {
		bool okk = false;
		for (int i = 13; i < 125; i++) {
			bool ok = true;
			for (int j = 0; j < 10 && ok; j++)
				if (freq[j] < f[i][j]) { ok = false; }
			if (ok) { cout << "Yes" << '\n'; okk = true; break; }
		}
		if (!okk) { cout << "No" << '\n'; }
	}
	cin.ignore(2); return 0;
}