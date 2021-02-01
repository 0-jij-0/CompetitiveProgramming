#include <iostream>
#include <map>
using namespace std;

map<int, int> m;

int main() {
	int n, k; cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int a; cin >> a; pair<int, int> p(a, i);
		m.insert(p); if (m.size() == k) { break; }
	}
	if (m.size() != k) { cout << "NO" << endl; }
	else {
		cout << "YES" << endl; auto it = m.begin();
		for (int i = 0; i < k; i++) { 
			cout << it->second + 1;
			if (i + 1 == k) { cout << endl; }
			else { cout << ' '; } it++;
		}
	}
	cin.ignore(2); return 0;
}