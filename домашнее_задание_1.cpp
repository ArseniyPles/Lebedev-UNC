#include <iostream>
#include <cmath>
using namespace std;

int main() {
	float x; cin >> x;
	float y; cin >> y;

	float r = (cos(3.14 * x) / sin(3.14 * x)) - (1 / cos(y));
	float s = log(pow(2, x));
	float c = max(r, s);
	cout << c;

	return 0;
}