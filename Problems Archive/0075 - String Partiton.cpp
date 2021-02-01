#include <iostream>
#include <string>
using namespace std;

string s;
string comp = "2147483647";
long long DP[201][201];

bool check_int(int i, int j) {
	if (j - i + 1 > 10) { return false; }
	if (j - i + 1 < 10) { return true; }
	string str = s.substr(i, j - i + 1);
	return str < comp;
}

long long partition(int i, int j) {
	if (DP[i][j] != -1) { return DP[i][j]; }
	if (check_int(i, j)) { DP[i][j] = (long long)stoi(s.substr(i, j - i + 1)); return DP[i][j]; }
	long long max = 0;
	for (int k = i; k < j; k++) {
		if (k - i == 10) { break; }
		long long a = partition(i, k) + partition(k + 1, j);
		max = (max < a) ? a : max;
	}
	DP[i][j] = max;
	return max;
}

long long partition_sum() {
	for (int i = 0; i < s.size() + 1; i++) {
		for (int j = 0; j < s.size() + 1; j++) { DP[i][j] = -1; }
	}
	return partition(0, s.size() - 1);
}

int main() {
	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> s;
		cout << partition_sum() << endl;
	}
	cin.ignore(2); return 0;
}