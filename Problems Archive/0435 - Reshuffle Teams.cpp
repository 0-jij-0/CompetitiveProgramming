#include <iostream>
#include <string>
#include <set>
#include <climits>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main() {
	int T; cin >> T;
	while (T--) {
		string s; cin >> s;	map<char, int> teams; set<char> temp;
		for (char &c : s) { teams[c]++; temp.insert(c); }

		vector<char> states;
		for (auto &el : temp) { states.push_back(el); }

		int minDif = (int)s.size();
		do {
			int j = 0, dif = 0, mod = (int) s.size();
			for (char &c : states) {
				int num = teams[c];
				while (num--)
					if (s[j] != c) { dif++; j++; }
					else { j++; }
			}
			vector<int> pos(1, 0);
			for (char &c : states) {
				pos.push_back(teams[c]);
				pos[pos.size() - 1] += pos[pos.size() - 2];
			}
			pos.pop_back();	minDif = min(minDif, dif);

			for (int m = 1; m < mod; m++) {
				for (int k = 0; k < pos.size(); k++) {
					if (s[pos[k]] != states[k]) { dif--; }
					if (s[pos[(k + 1) % pos.size()]] != states[k]) { dif++; }
				}
				for (int k = 0; k < pos.size(); k++) { pos[k]++; pos[k] %= mod;	}
				minDif = min(minDif, dif);
			}
		} while (next_permutation(states.begin(), states.end()));
		cout << minDif << endl;
	}
	cin.ignore(2); return 0;
}