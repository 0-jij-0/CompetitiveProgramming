#include <iostream>
#include <vector>
using namespace std;

vector<int> v; int e = 0, o = 0;

int main() {
	int n; cin >> n; v.resize(n);
	for (auto &x : v) { cin >> x; (x % 2 ? o : e)++; }
	int a = 0; for (auto &x : v) {
		if (x % 2 == 0) { cout << x / 2 << endl; continue; }
		cout << (a++ < o / 2 ? (x - 1) / 2 : (x + 1) / 2) << endl;
	}
	cin.ignore(2); return 0;
}