#include <iostream>
#include <vector>
using namespace std;

vector<int> freq;

int main() {
	int n; cin >> n; freq.resize(200001, 0);
	for (int i = 0; i < n; i++) {
		int a; cin >> a; freq[a]++;
	}
	vector<int> a, b; bool ok = true;
	for (int i = 0; i < 200001; i++) {
		if (!freq[i]) { continue; }
		if (freq[i] > 2) { ok = false; break; }
		if (freq[i] == 1) { a.push_back(i); continue; }
		else { a.push_back(i); b.push_back(i); continue; }
	}
	if (!ok) { cout << "NO" << endl; }
	else { 
		cout << "YES" << endl;
		cout << a.size() << endl;
		for (int i = 0; i < (int)a.size(); i++) {
			cout << a[i];
			if (i + 1 != (int)a.size()) { cout << ' '; }
			else { cout << endl; }
		}
		cout << b.size() << endl;
		for (int i = (int)b.size() - 1; i >= 0; i--) {
			cout << b[i];
			if (i != 0) { cout << ' '; }
			else { cout << endl; }
		}
	}
	cin.ignore(2); return 0;
}