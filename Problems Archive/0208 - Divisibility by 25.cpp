#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string s;
vector<vector<int>>dig_idx;

int make(string str, int x, int y) {
	int num = 0;
	int idx1 = dig_idx[y][dig_idx[y].size() - 1];
	int idx2 = dig_idx[x][dig_idx[x].size() - 1];
	if (x == y) { idx2 = dig_idx[y][dig_idx[y].size() - 2]; }
	if (idx1 > idx2) {
		while (idx1 != str.size() - 1) { swap(str[idx1], str[idx1 + 1]); idx1++; num++; }
		while (idx2 != str.size() - 2) { swap(str[idx2], str[idx2 + 1]); idx2++; num++; }
	}
	else {
		if(idx2 == str.size() - 1 && idx1 == str.size() - 2){
			swap(str[idx2], str[idx1]); num++;
		}
		else if (idx2 == str.size() - 1) {
			while (idx1 != str.size() - 1) { swap(str[idx1], str[idx1 + 1]); idx1++; num++; }
		}
		else {
			while (idx2 != str.size() - 2) { swap(str[idx2], str[idx2 + 1]); idx2++; num++; }
			while (idx1 != str.size() - 1) { swap(str[idx1], str[idx1 + 1]); idx1++; num++; }
			swap(str[idx2], str[idx2 - 1]); num++;
		}
	}
	if (str[0] == '0') {
		unsigned int i = 0;
		for (; i < s.size() - 2; i++) { if (str[i] != '0') { break; } }
		if (i == s.size() - 2) { return -1; }
		num += i;
	}
	return num;
}

int moves_num() {
	dig_idx.resize(10);
	for (unsigned int i = 0; i < s.size(); i++) {
		dig_idx[s[i] - '0'].push_back(i);
	}
	int res = 1000;
	int a = dig_idx[0].size();
	if (a > 1) {
		int x = make(s, 0, 0);
		res = (x != -1) ? min(res, x) : res;
	}
	int b = dig_idx[2].size();
	int c = dig_idx[5].size();
	int d = dig_idx[7].size();
	if (b * c != 0) {
		int x = make(s, 2, 5);
		res = (x != -1) ? min(res, x) : res;
	}
	if (a * c != 0) {
		int x = make(s, 5, 0);
		res = (x != -1) ? min(res, x) : res;
	}
	if (c * d != 0) {
		int x = make(s, 7, 5);
		res = (x != -1) ? min(res, x) : res;
	}
	if (res == 1000) { return -1; }
	return res;
}

int main() {
	cin >> s;
	cout << moves_num() << endl;
	cin.ignore(2); return 0;
}

