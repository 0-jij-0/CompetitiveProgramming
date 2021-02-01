#include <iostream>
#include <queue>
using namespace std;

priority_queue<int> pq;

int main() {
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int a; cin >> a; pq.push(a);
	}
	int res = 0;
	while (m > 0) { res++; m -= pq.top(); pq.pop(); }
	cout << res << endl;
	cin.ignore(2); return 0;
}