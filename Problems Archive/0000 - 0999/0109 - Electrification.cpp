#include <iostream>
#include <vector>
using namespace std;

vector<int> points;

int find_x(int n, int k) {
	int min_a = 0, min_b = 0, min = points.back() - points[0] + 1;
	int a, b;
	for (int i = 0; true; i++) {
		a = i; b = i + k; 
		if (b >= n) { break; }
		int d = points[b] - points[a];
		if (d < min) { min = d; min_a = a; min_b = b; }
	}
	int x = (points[min_a] + points[min_b]) / 2;
	return x;
}

int main() {
	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		int n, k; cin >> n >> k;
		points.clear();
		for (int j = 0; j < n; j++) { int a; cin >> a; points.push_back(a); }
		cout << find_x(n, k) << endl;
	}
	cin.ignore(2); return 0;
}