#include <iostream>
#include <string>
using namespace std;

string path;

string different() {
	string res = ""; res.resize(path.size());
	for (int i = 0; i < path.size(); i++) {
		res[i] = (path[i] == 'S') ? 'E' : 'S';
	}
	return res;
}

int main() {
	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		int n; cin >> n;
		cin >> path;
		cout << "Case #" << i + 1 << ": " << different() << endl;
	}
	cout << endl; cin.ignore(2); return 0;
}