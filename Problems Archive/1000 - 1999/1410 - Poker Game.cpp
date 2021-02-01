#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int getInt(char& c) {
	if (c >= '0' && c <= '9') { return c - '0'; }
	if (c == 'X') { return 10; }
	if (c == 'J') { return 11; }
	if (c == 'Q') { return 12; }
	if (c == 'K') { return 13; }
	if (c == 'A') { return 14; }
}

char getChar(int idx) {
	if (idx <= 9) { return '0' + idx; }
	if (idx == 10) { return 'X'; }
	if (idx == 11) { return 'J'; }
	if (idx == 12) { return 'Q'; }
	if (idx == 13) { return 'K'; }
	return 'A';
}

static int comp(char& n1, char& n2) {
	return getInt(n1) < getInt(n2);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, k; cin >> n >> k;
	string community; cin >> community;
	string choices; cin >> choices;

	bool OK = true;
	vector<int> initialState(15, 0);
	vector<int> curFreq(15, 0);
	for (int i = 0; i < n; i++) {
		int idx = getInt(community[i]);
		bool raise = choices[i] == 'y';

		if (initialState[idx] == 0) {
			if (raise) { initialState[idx] = 1; }
			else { initialState[idx] = -1; }
		}

		if (curFreq[idx] && !raise) { OK = false; break; }
		curFreq[idx]++;
	}

	string initialHand;
	for (int i = 2; i < 15; i++) {
		if (initialState[i] == 1) {
			initialHand.push_back(getChar(i));
			curFreq[i]++;
			if (curFreq[i] > 4) { OK = false; break; }
		}
	}
	if (initialHand.size() > k) { OK = false; }

	if (!OK) { cout << "impossible\n"; }
	else {
		vector<vector<char>> priority(4, vector<char>());
		for (int i = 2; i < 15; i++) {
			if (curFreq[i] == 4 || initialState[i] == -1) { continue; }
			priority[3 - curFreq[i]].push_back(getChar(i));
		}

		for (int j = 0; j < 4; j++) {
			for (auto& c : priority[j]) {
				for (int kk = 0; kk <= j; kk++) {
					if (initialHand.size() >= k) { break; }
					initialHand.push_back(c);
				}
			}
		}

		if (initialHand.size() < k) { cout << "impossible" << '\n'; return 0; }
		sort(initialHand.begin(), initialHand.end(), comp);

		int jj = -1, cnt = 0;
		for (int j = 0; j < k - 4; j += 4) {
			if (initialHand[j + 1] != initialHand[j]) { jj = j; cnt = 3; break; }
			else if (initialHand[j + 2] != initialHand[j + 1]) { jj = j + 1; cnt = 2; break; }
			else if (initialHand[j + 3] != initialHand[j + 2]) { jj = j + 2; cnt = 1; break; }
		}

		if (jj != -1) {
			for (int j = k - 1; j >= 0 && j > jj; j--) {
				if (curFreq[getInt(initialHand[j])] == 4) { continue; }
				int removable = 4 - curFreq[getInt(initialHand[j])];
				if (cnt == removable) {
					for (int k = j; k > j - removable; k--) { initialHand[k] = initialHand[jj]; }
					break;
				}
			}
		}

		sort(initialHand.begin(), initialHand.end(), comp);
		cout << initialHand << '\n';
	}
}