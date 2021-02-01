#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n; cin >> n; n--;
	vector<int> p1 = { 0, 1 }, p0 = { 1 };
	while (n) {
		vector<int> temp = p1; temp.insert(temp.begin(), 0);
		for (int i = 0; i < (int)p0.size(); i++) { temp[i] ^= p0[i]; }
		swap(p1, p0); swap(p1, temp); n--;
	}
	cout << (int)p1.size() - 1 << '\n';
	for (auto &x : p1) cout << x << ' '; cout << '\n';
	cout << (int)p0.size() - 1 << '\n';
	for (auto &x : p0) cout << x << ' '; cout << '\n';
	cin.ignore(2); return 0;
}