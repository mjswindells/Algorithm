#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
//POLY
//https://algospot.com/judge/problem/read/POLY
// Main에서 poly가 호출되는 수 O(n)
// n과 first의 조합가능수 O(n^2) : cache의 nXn부분만 채우면 된다

const int MOD = 10 * 1000 * 1000;

int cache[101][101];

// n 개의 정사각형으로 이루어졌고, 맨 위 가로줄에 first개의
// 정사각형을 포함하는 폴리오미노의 수를 반환한다.
int poly(int n, int first) {
// 기저 사례 : n == first
	if(n == first) return 1;
// 메모이제이션
	int& ret = cache[n][first];
	if (ret != -1) return ret;
	ret = 0;
	for (int second = 1; second <= n - first; ++second) {
		int add = second + first - 1;
		add *= poly(n - first, second);
		add %= MOD;
		ret += add;
		ret %= MOD;
	}
	return ret;
}
int main() {
	int T,n; cin >> T;

	while (T--) {
		memset(cache, -1, sizeof(cache));
		cin >> n;
		int ans = 0;

		for (int i = 1; i <= n; ++i) {
			ans += poly(n, i);
			ans %= MOD;
		}

		cout << ans << "\n";
	}
	return 0;
}