#include <iostream>
#include <queue>
#include <set>
using namespace std;

multiset<int> head; queue<int> tail;

int main() {
	int q; cin >> q; while (q--) {
		int t; cin >> t;
		if (t == 1) { 
			int x; cin >> x; 
			tail.push(x); continue;
		}
		if (t == 2 && !head.empty()) { 
			cout << *head.begin() << '\n'; 
			head.erase(head.begin()); continue;
		}
		if (t == 2) {
			cout << tail.front() << '\n';
			tail.pop(); continue;
		}
		while (!tail.empty()) { head.insert(tail.front()); tail.pop(); }
	}
	cin.ignore(2); return 0;
}