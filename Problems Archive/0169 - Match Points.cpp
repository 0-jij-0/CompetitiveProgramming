#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

multiset<int> s;

int main() {
	int n, z; cin >> n >> z;
	for (int i = 0; i < n; i++) { 
		int a; cin >> a; s.insert(a);
	}
	int num = 0;
	auto it = s.begin(); int i = 0;
	while (i != (s.size() - 1)/ 2) { it++; i++; }
	while(true) {
		int a = *it;
		auto it1 = s.lower_bound(a + z);
		if (it1 == s.end()) { 
			if (it == s.begin()) { break; }
			it--; continue;
		}
		num++; s.erase(it1); it = s.erase(it);
		if (it == s.begin()) { break; }
		it--;
	}
	cout << num << endl;
	cin.ignore(2); return 0;
}