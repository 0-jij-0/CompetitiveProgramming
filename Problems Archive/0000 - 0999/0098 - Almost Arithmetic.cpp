#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
vector<vector<int>> choices;
vector<int> tri;

void generate(int n) {
	if (n == 0) { choices.push_back(v); return; }
	for (unsigned int i = 0; i < tri.size(); i++) {
		int num = tri[i];
		v.push_back(num);
		generate(n - 1);
		v.pop_back();
	}
}

int check(int &a, int &b, int &c) {
	int d1 = b - a, d2 = c - b;
	if (d1 == d2) { return d1; }
	return -1;
}

int change_count(int k, int i) {
	int prev = v[2] + choices[i][2]; int count = 0;
	for (unsigned int i = 3; i < v.size(); i++) {
		int d = v[i] - prev;
		prev = v[i];
		if (d == k) { continue; }
		if (d == k + 1) { prev--; count++; continue; }
		if (d == k - 1) { prev++; count++; continue; }
		return -1;
	}
	return count;
}

int almost_arith() {
	if (v.size() <= 2) { return 0; }
	int a, b, c;
	int min = INT_MAX;
	for (unsigned int i = 0; i < choices.size(); i++) {
		a = v[0] + choices[i][0];
		b = v[1] + choices[i][1];
		c = v[2] + choices[i][2];
		int m = check(a, b, c);
		if (m == -1) { continue; }
		int count = change_count(m, i);
		if (count == -1) { continue; }
		if (choices[i][0] != 0) { count++; }
		if (choices[i][1] != 0) { count++; }
		if (choices[i][2] != 0) { count++; }
		if (count < min) { min = count; }
	}
	return (min == INT_MAX) ? -1 : min;
}

int main() {
	tri.push_back(-1); tri.push_back(0); tri.push_back(1);
	generate(3);
	int n; cin >> n; v.resize(n);
	for (int i = 0; i < n; i++) { cin >> v[i]; }
	cout << almost_arith() << endl;
	cin.ignore(2); return 0;
}