#include <iostream>
#include <vector>
#include <set>
using namespace std;
typedef long long ll;

multiset<int> A, B;

int main() {
	int n; cin >> n; int i = 0;
	while (i < n) {
		int x; cin >> x;
		if (i == n - 1) { A.insert(x); break; }
		int y; cin >> y; if (x < y) { swap(x, y); }
		A.insert(x); i += 2;
		if (y > *A.begin()) { 
			B.insert(*A.begin()); 
			A.erase(A.begin());
			A.insert(y);
		}
		else { B.insert(y); }
	}
	ll sumA = 0, sumB = 0;
	for (auto &x : A) { sumA += x; }
	for (auto &x : B) { sumB += x; }
	cout << sumA << ' ' << sumB << endl;
	cin.ignore(2); return 0;
}