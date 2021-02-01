#include <iostream>
#include <vector>
using namespace std;

vector<int> food;
int weekly[3] = { 3, 2, 2 };
int week[7] = { 0, 1, 2, 0, 2, 1, 0 };

long long minimum(int a[3]) {
	int min = a[0];
	for (int i = 0; i < 3; i++) {
		if (a[i] < min) { min = a[i]; }
	}
	return min;
}

long long day_count() {
	long long count = 0; int ratio[3];
	for (int i = 0; i < 3; i++) { ratio[i] = food[i] / weekly[i]; }

	long long min = minimum(ratio);
	count += min * 7;

	for (int i = 0; i < 3; i++) { food[i] -= min * weekly[i]; }

	int rem[3]; long long old_count = count; long long max_count = count;

	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 3; j++) { rem[j] = food[j]; }

		int j = i;
		while (true) {
			j = j % 7;
			int daily = week[j];
			if (rem[daily] <= 0) { break; }
			rem[daily]--; count++; j++;
		}
		if (count > max_count) { max_count = count; }
		count = old_count;
	}
	return max_count;
}

int main() {
	food.resize(3);
	cin >> food[0] >> food[1] >> food[2];
	cout << day_count() << endl;
	return 0;
}