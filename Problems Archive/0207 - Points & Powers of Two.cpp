#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> v;

void find_subs() {
	long long one = v[0];
	pair<long long, long long> two = { -1, -1 };
	for (unsigned int i = 0; i < v.size(); i++) {
		long long x = 1;
		while (x <= 2000000000) {
			auto it = binary_search(v.begin(), v.end(), v[i] + x);
			if (it) { two = { v[i], v[i] + x }; }
			else { x *= 2; continue; }
			it = binary_search(v.begin(), v.end(), v[i] + 2 * x);
			if (it) { 
				cout << 3 << endl;
				cout << v[i] << ' ' << v[i] + x << ' ' << v[i] + 2 * x << endl;
				return;
			}
			x *= 2;
		}
	}
	if(two.first != -1){
		cout << 2 << endl;
		cout << two.first << ' ' << two.second << endl;
		return;
	}
	cout << 1 << endl << one << endl;
}

int main() {
	int n; cin >> n; v.resize(n);
	for (int i = 0; i < n; i++) { cin >> v[i]; }
	sort(v.begin(), v.end());
	find_subs();
	cin.ignore(2); return 0;
}