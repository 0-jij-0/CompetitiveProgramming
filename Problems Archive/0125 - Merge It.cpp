#include <iostream>
using namespace std;

int mod[3];

int main() {
	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		mod[0] = 0; mod[1] = 0; mod[2] = 0;
		int n; cin >> n;
		for (int j = 0; j < n; j++) {
			int a; cin >> a; mod[a % 3]++;
		}
		int count = mod[0];
		int max = (mod[1] < mod[2]) ? mod[2] : mod[1];
		int min = (mod[1] < mod[2]) ? mod[1] : mod[2];
		count += min; max -= min; count += max / 3;
		cout << count << endl;
	}
	cin.ignore(2); return 0;
}