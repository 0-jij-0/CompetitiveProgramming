#include <iostream>
#include <set>
using namespace std;

int main() {
	int n; cin >> n; set<int> s;
	while (n--) { int x; cin >> x; s.insert(x); }
	cout << s.size() << endl;
	cin.ignore(2); return 0;
}