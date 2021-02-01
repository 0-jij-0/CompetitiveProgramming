#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<int> b;

void fill(int n, int x) {
	map<int, int> pairs;
	int m = (int)pow(2.0, n + 0.0);
	if (x >= m) { 
		for (int i = 1; i < m; i++) { b.push_back(i); }
		return;
	}
	for (int i = 1; i < m; i++) {
		if (i == x) { continue; }
		int j = i ^ x;
		int min = (i < j) ? i : j;
		if (pairs.find(min) != pairs.end()) { continue; }
		int max = (i < j) ? j : i;
		pair<int, int> p(min, max);
		pairs.insert(p);
		b.push_back(min);
	}
}

int main() {
	int n, x; cin >> n >> x;
	fill(n, x);
	cout << b.size() << endl;
	if (!b.empty()) { cout << b[0]; } 
	if (b.size() > 1) { cout << " "; }
	for (unsigned int i = 1; i < b.size(); i++) {
		int a = b[i] ^ b[i - 1];
		cout << a;
		if (i + 1 != b.size()) { cout << " "; }
		else { cout << endl; }
	}
	cin.ignore(2); return 0;
}