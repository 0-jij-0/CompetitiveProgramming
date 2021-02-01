#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> a, b;

int main() {
	int n, x; cin >> n;
	for (int i = 0; i < n; i++) { cin >> x; a.push_back(x); }
	for (int i = 0; i < n; i++) { cin >> x; b.push_back(x);	}
	sort(a.begin(), a.end()); sort(b.begin(), b.end());
	int m = ((n + 1)/ 2) - 1; bool wa = true, wb = true;
	int i = m, j = 0;
	while (i < n) {
		if (a[i] < b[j]) { wa = false; break; }
		i++; j++;
	}
	i = 0; j = m;
	while (j < n) {
		if (b[j] < a[i]) { wb = false; break; }
		i++; j++;
	}
	if (wa && wb) { cout << "Both" << endl; }
	else if (wa) { cout << "First" << endl; }
	else if (wb) { cout << "Second" << endl; }
	else { cout << "None" << endl; }
	cin.ignore(2); return 0;
}