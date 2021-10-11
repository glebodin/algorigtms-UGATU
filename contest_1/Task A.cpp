//1) Вася нашел 3 яблоко
//2) 54349113

#include <iostream>

using namespace std;

bool a[8] = {0, 0, 0, 0, 0, 1, 1, 1};

bool equalToOne(int x) {
	if (x >= 8) {
		return true;
	}
	return a[x];
}

int findOne() {
	if (equalToOne(0)) {
		return 0;
	}
	int len = 1;
	while (equalToOne(len) == false) {
		len *= 2;
	}
	return len;
}

int binarySearch(int l, int r) {
	while (l < r - 1) {
		int mid = (l + r) / 2;
		if (equalToOne(mid)) {
			r = mid;
		}
		else {
			l = mid;
		}
	}
	return r;
}

int binaryLifting() {
	int len = (1 << 20), pos = 0;//len = (1 << ceil(log2(n)))
	while (len >= 1) {
		if (!equalToOne(pos + len)) {
			pos += len;
		}
		len >>= 1;
	}
	return pos;
}

int main() {
	int l = -1, r = findOne();
	int ans = binarySearch(l, r);
	cout << (1 << 3) << " " << (8 >> 2) << "\n";
	cout << ans << " " << binaryLifting() + 1;
	return 0;
}
