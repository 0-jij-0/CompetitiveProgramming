#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<vector<int>> alpha_idx;
vector<char> blocks;
vector<int> quest_left;
vector<int> quest_right;

int binary_search(int &i, int from, int to, int x) {
	if (alpha_idx[i][from] > x) { return from - 1; }
	if (from == to) { return from; }
	int mid = (from + to) / 2;
	if (alpha_idx[i][mid] == x) { return mid; }
	if (alpha_idx[i][mid] < x) {
		if (alpha_idx[i][mid + 1] > x) { return mid; }
		if (alpha_idx[i][mid + 1] == x) { return mid + 1; }
		return binary_search(i, mid + 1, to, x);
	}
	if (mid == 0) { return 0; }
	return binary_search(i, from, mid - 1, x);
}

void input(int &n, int &q) {
	blocks.clear(); alpha_idx.clear(); quest_left.clear(); quest_right.clear();
	blocks.resize(n); alpha_idx.resize(26); quest_left.resize(q); quest_right.resize(q);
	string line = ""; getline(cin, line); getline(cin, line);
	for (int i = 0; i < n; i++) {
		char a = line[i];
		int idx = a - 'A';
		alpha_idx[idx].push_back(i + 1);
		blocks.push_back(a);
	}
	for (int i = 0; i < q; i++) {
		int l, r; cin >> l >> r;
		quest_left[i] = l; quest_right[i] = r;
	}
}

int count_yes(int &n, int &q) {
	int total_count = 0;
	for (int i = 0; i < q; i++) {
		int &left = quest_left[i];
		int &right = quest_right[i];
		if (left == right) { total_count++; continue; }
		int parity = right - left + 1;
		bool yes = true; bool odd = false;
		for (int j = 0; j < 26; j++) {
			if (alpha_idx[j].empty()) { continue; }
			int l = binary_search(j, 0, alpha_idx[j].size() - 1, left);
			int r = binary_search(j, 0, alpha_idx[j].size() - 1, right);
			int count = r - l;
			if (l != - 1 && alpha_idx[j][l] == left) { count++; }
			if (parity % 2 == 1) {
				if (count % 2 == 1 && odd == false) { odd = true; continue; }
				if (count % 2 == 1) { yes = false; break; }
			}
			else if (count % 2 == 1) { yes = false; break; }
		}
		if (parity % 2 == 1 && yes == true && odd == true) { total_count++; continue; }
		if (parity % 2 == 0 && yes == true) { total_count++; continue; }
	}
	return total_count;
}

int main() {
	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		int n, q; cin >> n >> q;
		input(n, q);
		cout << "Case #" << i + 1 << ": " << count_yes(n, q) << endl;
	}
	cin.ignore(2); return 0;
}