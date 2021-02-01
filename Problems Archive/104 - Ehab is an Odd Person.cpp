#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int main() {
	int n; cin >> n;
	bool even = false, odd = false;
	for (int i = 0; i < n; i++) {
		int a; cin >> a; v.push_back(a);
		if (a % 2 == 0) { even = true; continue; }
		odd = true;
	}
	if (even && odd) { sort(v.begin(), v.end()); }
	for (int i = 0; i < n; i++) {
		cout << v[i];
		if (i + 1 != n) { cout << " "; }
		else { cout << endl; }
	}
	cin.ignore(2); return 0;
}