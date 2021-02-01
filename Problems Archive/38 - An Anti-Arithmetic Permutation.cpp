#include <iostream>
#include <vector>
#include <list>
using namespace std;

list<int> l;

void build(int n) {
	l.push_back(0);
	l.push_back(2);
	l.push_back(1);

	vector<bool> in;
	in.resize(n, 0);
	in[0] = in[1] = in[2] = 1;
	
	int count = n - 3;
	list<int>::iterator it;
	for (int i = 2; true; i++) {
		it = find(l.begin(), l.end(), i);
		int a2 = *it; it++;
		int a3 = *it; it--; it--;
		int a1 = *it;
		int b = (a1 < a2) ? a1 + 2 * (a2 - a1) : a2 + 2 * (a1 - a2);
		int c = (a2 < a3) ? a2 + 2 * (a3 - a2) : a3 + 2 * (a2 - a3);
		it++;
		if (b < n && in[b] == 0) { l.insert(it, b); count--; in[b] = 1; }
		if (count == 0) { break; } it++;
		if (c < n && in[c] == 0) { l.insert(it, c); count--; in[c] = 1; }
		if (count == 0) { break; }
	}
	cout << n << ": ";
	it = l.begin();
	while (it != l.end()) {
		cout << *it; it++;
		if (it != l.end()) { cout << " "; }
	}
	cout << endl;	
}

int main() {
	int n; cin >> n;
	while (n != 0) {
		l.clear();
		build(n);
		cin >> n;
	}
	cout << endl; cin.ignore(2); return 0;
}