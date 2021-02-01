#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n; cin >> n;
	if (n % 2 == 0) { cout << "NO" << endl; }
	else {
		cout << "YES" << endl;
		vector<int> one, two;
		int i = 1; bool b = true;
		while (i <= 2 * n) {
			if (b) {
				one.push_back(i); two.push_back(i + 1); b = !b;
			}
			else {
				one.push_back(i + 1); two.push_back(i); b = !b;
			}
			i += 2;
		}
		for (auto &x : one) { cout << x << ' '; }
		for (auto &x : two) { cout << x << ' '; }
		cout << endl;
	}
	cin.ignore(2); return 0;
}