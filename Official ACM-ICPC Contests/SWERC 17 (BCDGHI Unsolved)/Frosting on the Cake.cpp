#include <iostream>
#include <string>
#include <map>
#include <set>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
 
using namespace std;
typedef long long ll;
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
 
	int n; cin >> n;
	vector<int> A(n), B(n);
	for (auto &x : A) { cin >> x; }
	for (auto &x : B) { cin >> x; }
 
	ll c1 = 0, c2 = 0, c3 = 0;
	vector<ll> Bs(3, 0);
	for (int i = 0; i < n; i++) {
		Bs[i % 3] += B[i];
	}
 
	for (int i = 0; i < n; i++) {
		if (i % 3 == 0) {
			c1 += Bs[0] * A[i];
			c2 += Bs[1] * A[i];
			c3 += Bs[2] * A[i];
		}
		else if (i % 3 == 1) {
			c1 += Bs[2] * A[i];
			c2 += Bs[0] * A[i];
			c3 += Bs[1] * A[i];
		}
		else {
			c1 += Bs[1] * A[i];
			c2 += Bs[2] * A[i];
			c3 += Bs[0] * A[i];
		}
	}
 
	cout << c2 << ' ' << c3 << ' ' << c1 << '\n';
}