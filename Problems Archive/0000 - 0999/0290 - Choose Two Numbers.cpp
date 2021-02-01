#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> a, b;

int main() {
	int n; cin >> n; a.resize(n);
	for (auto &x : a) { cin >> x; }
	int m; cin >> m; b.resize(m);
	for (auto &x : b) { cin >> x; }
	cout << *max_element(a.begin(), a.end()) << ' ' << *max_element(b.begin(), b.end()) << endl;
	cin.ignore(2); return 0;
}