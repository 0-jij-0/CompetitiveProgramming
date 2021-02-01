#include <iostream>
#include <vector>
using namespace std;

vector<int> parent, respect, children;

int main() {
	int n; cin >> n; respect.resize(n);
	parent.resize(n); children.resize(n);
	for (int i = 0; i < n; i++) {
		int p, c; cin >> p >> c;
		parent[i] = p - 1; respect[i] = c; children[i] = c;
	}
	for (int i = 0; i < n; i++)
		if (parent[i] != -2) 
			children[parent[i]] *= respect[i];

	vector<int> res;
	for (int i = 0; i < n; i++) {
		if (!respect[i] || !children[i]) { continue; }
		res.push_back(i + 1);
		children[parent[i]] *= children[i];
	}
	if (res.empty()) { cout << -1 << endl; }
	for (int i = 0; i < (int)res.size(); i++) {
		cout << res[i];
		if (i + 1 != (int)res.size()) { cout << ' '; }
		else { cout << endl; }
	}
	cin.ignore(2); return 0;
}