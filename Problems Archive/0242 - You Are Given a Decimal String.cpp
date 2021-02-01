#include <iostream>
#include <string>
using namespace std;

int min_sum[10][10][10];

void fill_min_sum() {
	for (int i = 0; i < 10; i++)
		for (int j = i; j < 10; j++)
			for (int k = 0; k < 10; k++)
				for (int u = 0; u < 10; u++)
					for (int v = 0; v < 10; v++) {
						if (!u && !v) { continue; }
						if ((u * i + v * j) % 10 == k) {
							if (min_sum[i][j][k] == -1)
								min_sum[i][j][k] = min_sum[j][i][k] = u + v;
							else if (u + v < min_sum[i][j][k])
									min_sum[i][j][k] = min_sum[j][i][k] = u + v;
						}
					}				
}

void reset_min_sum() {
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 11; j++)
			for (int k = 0; k < 11; k++)
				min_sum[i][j][k] = -1;
}

string s;
int res[10][10];

int find_res(int i, int j) {
	int res = 0; 
	for (int k = 1; k < (int)s.size(); k++) {
		int dif = s[k] - s[k - 1]; if (dif < 0) { dif += 10; }
		if (min_sum[i][j][dif] == -1) { return -1; }
		res += min_sum[i][j][dif] - 1;
	}
	return res;
}

void fill_res() {
	for (int i = 0; i < 10; i++) {
		for (int j = i; j < 10; j++) {
			res[i][j] = res[j][i] = find_res(i, j);
		}
	}
}


int main() {
	reset_min_sum(); fill_min_sum();
	cin >> s; fill_res();
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cout << res[i][j];
			if (j != 10) { cout << ' '; }
		}
		cout << endl;
	}
	cin.ignore(2); return 0;
}