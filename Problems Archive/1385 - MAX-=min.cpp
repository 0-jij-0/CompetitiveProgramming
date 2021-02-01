#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main() {
	int n; cin >> n; v.resize(n); int g = 0;
	for (auto &x : v) { cin >> x; g = gcd(g, x); }
	cout << g << '\n'; cin.ignore(2); return 0;
}