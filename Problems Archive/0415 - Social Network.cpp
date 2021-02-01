#include <iostream>
#include <set>
#include <queue>
#include <stack>
using namespace std;

set<int> screen;
queue<int> order;

int main() {
	int n, k; cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		if (screen.count(a)) { continue; }
		if ((int)screen.size() == k) {
			int q = order.front(); order.pop();
			screen.erase(q);
		}
		order.push(a); screen.insert(a);
	}
	stack<int> res; 
	while (!order.empty()) { res.push(order.front()); order.pop(); }
	cout << res.size() << endl;
	while (!res.empty()) { cout << res.top() << ' '; res.pop(); }
	cout << endl; cin.ignore(2); return 0;
}