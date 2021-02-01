#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<int> pref, suff, ver;

int find_min_road(int n) {
	int min1 = INT_MAX, min2 = INT_MAX;
	for (int i = 0; i < n; i++) {
		int a = pref[i] + suff[i] + ver[i];
		if (a < min1) { min2 = min1; min1 = a; continue; }
		if (a < min2) { min2 = a; }
	}
	return min1 + min2;
}

int main() {
	int n; cin >> n;
	int sum = 0; pref.push_back(0);
	for (int i = 0; i < n - 1; i++) {
		int a; cin >> a; sum += a; pref.push_back(sum);
	}
	vector<int> v;
	for (int i = 0; i < n - 1; i++) {
		int a; cin >> a; v.push_back(a);
	}
	suff.resize(n); suff[n - 1] = 0;
	for (int i = n - 2; i >= 0; i--) {
		suff[i] = suff[i + 1] + v[i];
	}
	for (int i = 0; i < n; i++) {
		int a; cin >> a; ver.push_back(a);
	}
	cout << find_min_road(n) << endl;
	cin.ignore(2); return 0;
}