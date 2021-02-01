#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int main() {
	int n; cin >> n; v.resize(n);
	for (auto &x : v) { cin >> x; }
	cout << *max_element(v.begin(), v.end()) << endl;
	cin.ignore(2); return 0;
}