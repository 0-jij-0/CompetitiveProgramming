#include <iostream>
#include <string>
using namespace std;

int numSeq(long long idx) {
	int i = 0;
	string frag = "";
	while (frag.size() < idx) {
		idx -= frag.size();
		i++;
		frag = frag + to_string(i);
	}
	return frag[idx - 1] - '0';
}

int main() {

	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		int idx; cin >> idx;
		cout << numSeq(idx) << endl;
	}

	cout << endl; cin.ignore(2); return 0;
}