#include <iostream>
#include <list>
#include <vector>
using namespace std;

vector<int> v;

void maxSubArr(unsigned int k) {
	list<int> max;
	max.push_back(v[0]);
	for (unsigned int i = 1; i < k; i++) {
		int &n = v[i];
		while (!max.empty() && n > max.back()) { max.pop_back(); }
		max.push_back(n);
	}
	cout << max.front(); if (k != v.size()) { cout << " "; }
	for (unsigned int i = k; i < v.size(); i++) {
		if (v[i - k] == max.front()) { max.pop_front(); }
		int &n = v[i];
		while (!max.empty() && n > max.back()) { max.pop_back(); }
		max.push_back(n);
		cout << max.front(); if (i + 1 != v.size()) { cout << " "; }
	}
}

int main() {
	int n; cin >> n;
	while (n != 0) {
		v.clear(); int k; cin >> k;
		for (int i = 0; i < n; i++) {
			int a; cin >> a; v.push_back(a);
		}
		maxSubArr(k); cout << endl;	cin >> n;
	}
	cout << endl; cin.ignore(2); return 0;
}

