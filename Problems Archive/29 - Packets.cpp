#include <iostream>
using namespace std;

int parcels(int packets[7]) {

	int count = 0;
	if (packets[6] != 0) { count += packets[6]; packets[6] = 0; }

	if (packets[5] != 0) {
		int five_one = packets[5] * 11;
		count += packets[5];
		packets[1] = (packets[1] > five_one) ? packets[1] - five_one : 0;
		packets[5] = 0;
	}

	if (packets[4] != 0) {
		int four_two = packets[4] * 5;
		int two_four = packets[2] / packets[4];
		if (two_four >= 5) {
			count += packets[4];
			packets[2] -= four_two;
			packets[4] = 0;
		}
		else {
			int frac = packets[2] / 5;
			count += frac;
			packets[2] -= frac * 5;
			packets[4] -= frac;

			int rem_space = 6 * 6 - 4 * 4 - packets[2] * 2 * 2;
			packets[1] = (packets[1] > rem_space) ? packets[1] - rem_space : 0;
			count++;
			packets[2] = 0;
			packets[4]--;
		}
		if (packets[4] != 0) {
			int four_one = packets[4] * 20;
			count += packets[4];
			packets[1] = (packets[1] > four_one) ? packets[1] - four_one : 0;
			packets[4] = 0;
		}
	}

	if (packets[3] != 0) {
		int three_three = packets[3] / 4;
		count += three_three;
		packets[3] -= three_three * 4;

		if (packets[3] != 0) {
			int rem_space = 6 * 6 - packets[3] * 3 * 3;
			int num_two = rem_space / 4;
			if (num_two != 1) { num_two--; }
			if (packets[2] >= num_two) {
				packets[2] -= num_two;
				rem_space -= num_two * 2 * 2;
				packets[1] = (packets[1] > rem_space) ? packets[1] - rem_space : 0;
				packets[4] = 0;
				count++;
			}
			else {
				packets[2] = 0;
				rem_space -= packets[2] * 2 * 2;
				packets[1] = (packets[1] > rem_space) ? packets[1] - rem_space : 0;
				packets[4] = 0;
				count++;
			}
		}
	}

	if (packets[2] != 0) {
		int two_two = packets[2] / 9;
		count += two_two;
		packets[2] -= two_two * 9;

		if (packets[2] != 0) {
			int rem_space = 6 * 6 - packets[2] * 2 * 2;
			packets[1] = (packets[1] > rem_space) ? packets[1] - rem_space : 0;
			packets[2] = 0;
			count++;
		}
	}

	if (packets[1] != 0) {
		int one_one = packets[1] / 36;
		count += one_one;
		packets[1] -= one_one * 36;

		if (packets[1] != 0) {
			packets[1] = 0;
			count++;
		}
	}
	return count;	
}

int main() {
	int count[7]; count[0] = 0;

	while (true) {
		cin >> count[1] >> count[2] >> count[3] >> count[4] >> count[5] >> count[6];
		int p = parcels(count);
		if (p == 0) { break; }
		cout << p << endl;
	}
	cout << endl; cin.ignore(2); return 0;
}