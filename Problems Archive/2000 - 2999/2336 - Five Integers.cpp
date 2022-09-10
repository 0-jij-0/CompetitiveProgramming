#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	vector<int> v(5);
	for (auto& x : v) cin >> x;
	cout << (set<int>(v.begin(), v.end()).size()) << '\n';
}