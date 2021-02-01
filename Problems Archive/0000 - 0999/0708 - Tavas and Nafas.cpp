#include <iostream>
#include <string>
using namespace std;

string digits[10] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
string tenth[10] = { "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
string rest[10] = { "", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };

int main() {
	int s; cin >> s;
	if (s < 10) { cout << digits[s] << endl; return 0; }
	if (s < 20) { cout << tenth[s - 10] << endl; return 0; }
	if (s % 10) { cout << rest[s / 10] + "-" + digits[s % 10] << endl; return 0; }
	cout << rest[s / 10] << endl; cin.ignore(2); return 0;
}