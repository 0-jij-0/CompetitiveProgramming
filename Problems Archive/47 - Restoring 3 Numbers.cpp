#include <iostream>
#include <vector>
using namespace std;

vector<int> numbers;

int max_idx() {
	int max = numbers[0];
	int idx = 0;
	for (int i = 0; i < 4; i++) {
		if (numbers[i] > max) {
			max = numbers[i]; idx = i;
		}
	}
	return idx;
}

void recover() {
	int idx = max_idx();
	int a[3]; int j = 0;
	for (int i = 0; i < 4; i++) {
		if (i == idx) { continue; }
		a[j] = numbers[idx] - numbers[i];
		j++;
	}
	cout << a[0] << " " << a[1] << " " << a[2] << endl;
}

int main() {
	numbers.resize(4);
	cin >> numbers[0] >> numbers[1] >> numbers[2] >> numbers[3];
	recover();
	cout << endl; cin.ignore(2); return 0;
}
