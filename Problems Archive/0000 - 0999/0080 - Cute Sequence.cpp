#include <iostream>
#include <vector>
#include <climits>
using namespace std;

unsigned long long a, b, m;

void find() {
	vector<unsigned long long> min;
	min.push_back(a); min.push_back(a + 1);
	while (min.back() < b) { min.push_back(2 * min.back()); }

	vector<unsigned long long> max;
	max.push_back(a); max.push_back(a + m);
	while (max.back() < b) { max.push_back(2 * max.back()); }

	unsigned int idx = 100;
	for (unsigned int i = 0; i < max.size(); i++) {
		if (min[i] <= b && max[i] >= b) { idx = i; break; }
	}
	if (idx >= 50) { cout << -1 << endl; return; }
	cout << idx + 1 << " ";
	vector<unsigned long long> seq;
	seq.resize(idx + 1);
	seq[idx] = b;
	bool flo = true;
	for (int i = 1; i < idx; i++) {
		if (seq[idx - i + 1] % 2 == 0) { seq[idx - i] = seq[idx - i + 1] / 2; continue; }
		if (flo) { seq[idx - i] = seq[idx - i + 1] / 2; flo = false; }
		else { seq[idx - i] = (seq[idx - i + 1] + 1) / 2; flo = true; }
	}
	seq[0] = a;
	for (unsigned int i = 0; i < seq.size(); i++) {
		cout << seq[i]; 
		if (i + 1 != seq.size()) { cout << " "; }
		else { cout << endl; }
	}
}

int main() {
	int q; cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> a >> b >> m;
		find();
	}
	return 0;
}