#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<int> v; set<int> s;

int main() {
	int n; cin >> n; v.resize(n);
	for (int i = 0; i <= n; i++) s.insert(i);
	for (auto &x : v) { cin >> x; }

	for (int i = 0; i < n; i++) {
		s.erase(v[i]); cout << *s.begin() << '\n';
	}
	cin.ignore(2); return 0;
}