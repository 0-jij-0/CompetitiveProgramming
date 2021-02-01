#include <iostream>
#include <string>
#include <map>
using namespace std;

bool exchange(multimap<int, int> v) {
	if (v.size() % 2 == 1) { return false; }

	while (v.size() != 0) {
		int first = v.begin()->first;
		int second = v.begin()->second;

		map<int, int>::iterator it = v.find(second);
		while (it->first == second && it->second != first) { it++; }
		if (it == v.end()) { return false; }
		v.erase(it); v.erase(v.begin());
	}
	return true;
}

int main() {
	int n; cin >> n;
	while (n != 0) {
		multimap<int, int> v;
		for (int i = 0; i < n; i++) {
			int from, to;
			cin >> from >> to;
			pair<int, int> p(from, to);
			v.insert(p);
		}
		string res = (exchange(v)) ? "YES" : "NO";
		cout << res << endl;
		cin >> n;
	}
	return 0;
}