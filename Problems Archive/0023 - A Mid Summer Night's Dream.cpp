#include <iostream>
#include <vector>
using namespace std;

void countSort(vector<int> &v) {
	vector<int> output;
	vector<int> count;
	unsigned int i;
	count.resize(65537, 0);
 
	for (i = 0; i < v.size(); i++) { count[v[i]]++; }

	int j = 0; i = 0;
	while (i < v.size()) {
		while (count[j] != 0) {
			output.push_back(j);
			count[j]--;	i++;
		}
		j++;
	}

	for (i = 0; i < v.size(); i++) { v[i] = output[i]; }
}

void MSND(vector<int> &v) {
	countSort(v);
	if (v.size() % 2 == 1) {
		int med = v[v.size() / 2];
		int count = 1;
		int i = (v.size()/2) - 1;
		while (i > -1 && v[i] == med) { count++; i--; }
		i = (v.size() / 2) + 1;
		while (i < v.size() && v[i] == med) { count++; i++; }

		cout << med << " " << count << " " << 1 << endl;
		return;
	}
	int med1 = v[(v.size() / 2) - 1];
	int med2 = v[(v.size() / 2)];
	int count = 1;
	int i = (v.size() / 2) - 1;
	while (i > -1 && v[i] == med1) { count++; i--; }
	i = (v.size() / 2) + 1;
	while (i < v.size() && v[i] == med2) { count++; i++; }
	int med_count = med2 - med1 + 1;

	cout << med1 << " " << count << " " << med_count << endl;
}

int main() {
	int n;
	while (true) {
		cin >> n;
		if (cin.fail()) { break; }
		vector<int> v;
		for (int i = 0; i < n; i++) {
			int num; cin >> num;
			v.push_back(num);
		}
		MSND(v);
	}

	cout << endl; cin.ignore(2); return 0;
}