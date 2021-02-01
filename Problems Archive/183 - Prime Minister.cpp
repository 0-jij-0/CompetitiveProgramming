#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

int main() {
	int n, a; cin >> n >> a; 
	int sum = a, presum = a;
	for (int i = 1; i < n; i++) { 
		int x; cin >> x; sum += x;
		if (x > a / 2) { continue; }
		v.push_back(i); presum += x;
	}
	if (a > sum / 2) {
		cout << 1 << endl << 1 << endl;
	}
	else if (presum > sum / 2) {
		cout << v.size() + 1 << endl;
		cout << 1 << ' ';
		for (unsigned int i = 0; i < v.size(); i++) {
			cout << v[i] + 1;
			if (i + 1 != v.size()) { cout << ' '; }
			else { cout << endl; }
		}
	}
	else { cout << 0 << endl; }
	cin.ignore(2); return 0;
}