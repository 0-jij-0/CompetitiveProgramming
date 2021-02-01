#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

int main() {
	int n; cin >> n; v.resize(n);
	for (auto &x : v) { cin >> x; }
	int max = 0;
	for (auto &x : v) {
		cout << x + max << ' ';
		if (x + max > max) { max = x + max; }
	}
	cout << endl; cin.ignore(2); return 0;
}