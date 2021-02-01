#include <iostream>
using namespace std;

int min_time(int ants[], int size, int l) {
	double mid = (l + 0.0) / 2.0;
	double min = l;
	int min_idx = 0;
	for (int i = 0; i < size; i++) {
		double b = (ants[i] < mid) ? mid - ants[i] : ants[i] - mid;
		if (b < min) {
			min = b; min_idx = i;
		}
	}
	return (ants[min_idx] < mid) ? ants[min_idx] : l - ants[min_idx];
}

int max_time(int ants[], int size, int l) {
	int mid = l / 2;
	int max = 0;
	int max_idx = 0;
	for (int i = 0; i < size; i++) {
		int b = (ants[i] > mid) ? ants[i] : l - ants[i];
		if (b > max) {
			max = b; max_idx = i;
		}
	}
	return max;
}

int main() {
	int n; cin >> n;

	for (int i = 0; i < n; i++) {
		int l; cin >> l;
		int size; cin >> size;
		int *ants = new int[size];

		for (int j = 0; j < size; j++) { cin >> ants[j]; }

		cout << min_time(ants, size, l) << " " << max_time(ants, size, l) << endl;
	}

	cout << endl; cin.ignore(2); return 0;
}