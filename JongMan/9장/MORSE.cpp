#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;
//MORSE
//https://algospot.com/judge/problem/read/MORSE
//이항계수를 사용한 풀이 이해가 더 필요하다.

const int M = 1000000000 + 100;
int n, m, k;
int skip;
int dp[201][201];
//이항계수 설정
void init() {
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i <= 200; ++i) {
		dp[i][0] = dp[i][i] = 1;

		for (int j = 1; j < i; ++j)
			dp[i][j] = min(M, dp[i - 1][j - 1] + dp[i - 1][j]);
	}
}

void generate3(int n,int m,string s){
    //기저사례 : skip<0
    if(skip<0) return;
    //기저사례 : n==m==0
    if(n==0&&m==0){
        if(skip==0) cout<<s<<endl;
        --skip;
        return;
    }
    if(dp[n+m][n]<=skip){
        skip-=dp[n+m][n];
        return;
    }
    if(n>0) generate3(n-1,m,s+"-");
    if(m>0) generate3(n,m-1,s+"o");

}

string dfs2(int x, int y, int skip) {
	// 이항계수 성질
	// (x+y)C(y) == (x+y)C(x) = (x+y-1)C(x-1) + (x+y-1)C(x)
	if (x == 0)return string(y, 'o');

	if (skip < dp[x + y - 1][x - 1])
		return '-' + dfs2(x - 1, y, skip);
	return 'o' + dfs2(x, y - 1, skip - dp[x + y - 1][x - 1]);
}
int main() {
	int testcase;
	cin >> testcase;

	init();

	while (testcase--) {
		cin >> n >> m >> k;

		cout << dfs2(n, m, k - 1) << '\n';
	}

	return 0;
}