#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
//QUANTIZE
//https://algospot.com/judge/problem/read/QUANTIZE
//quantize 함수의 이해가 더 필요하고 수학적으로 풀 수 있는 방법들에 대한 생각 또한 필요하다
//사용할 수 있는 숫자의 갯수가 n개여도 꼭 n개를 사용할 필요는 없다

const int INF = 987654321;
const int MAX = 101;
int d[MAX][11];
int A[MAX], pSum[MAX], pSqSum[MAX];
int n, s;

//배여을 정렬, psum과 psqsum을 구하는 과정
void precalc(){
    sort(A,A+n);
    pSum[0] = A[0];
    pSqSum[0] = A[0] * A[0];
    for(int i=1;i<n;i++){
        pSum[i] = pSum[i-1] + A[i];
        pSqSum[i] = pSqSum[i-1] + A[i] * A[i];
    }
}

//A[lo..hi] 구간을 하나의 숫자로 표현할 때 최소 오차 합을 계산한다.
//[a,b] 구간을 m으로 양자화했을경우를 생각해보자
//f(m) = ∑(v[i]−m)^2 = ∑v[i]^2−2m∑v[i] + (m^2)(b − a + 1)
//m에 대한 2차식이므로 미분을 통해 최소값을 구할 수 있다
// m = ∑v[i]/(b-a+1)
int minError(int lo, int hi){
    //구간의 합을 구한다.
    //psum과 psqsum의 0번째 값은 0으로 설정했기때문.
    int sum = pSum[hi] - (lo == 0 ? 0 : pSum[lo-1]);
    int sqSum = pSqSum[hi] - (lo == 0 ? 0 : pSqSum[lo-1]);
    //구간합과 구간의 길이를 나눈 값으로 해당 구간의 양자값을 구한다.
    //반올림을 하는 과정 양자화되는 값은 int형이기 때문에 반올림으로 구한다
    int m = int(0.5 + (double)sum / (hi-lo+1));
    //구간의 오차를 구한다.
    //m의 값을 구했으니 그 구간에서의 최소값을 구하는 과정
    int ret = sqSum - 2 * m * sum + m * m * (hi - lo + 1);
    return ret;
}

// quantize의 값은 결국 minError의 값으로 결정이 되므로 
// 기저사례의 값을 0또는 INF값으로 설정한다.
int quantize(int from, int parts){
    //모든 숫자를 양자화했을 때
    if(from == n) return 0;
    //숫자는 아직 남았는데 남는 조각 수가 없을 때는 포함을 시키면 안된다.
    if(parts == 0) return INF;
    int &ret = d[from][parts];
    if(ret != -1) return ret;
    ret = INF;

    //조각의 길이를 변화시켜가며 최소치를 찾는다.
    //
    for(int partSize=1;from+partSize<=n;++partSize)
        ret = min(ret, minError(from, from+partSize-1) + quantize(from+partSize, parts-1));

    return ret;
}

int main(){

    int T;
    cin >> T;
    while(T--){
        memset(d, -1, sizeof(d));

        cin >> n >> s;
        for(int i=0;i<n;i++)
            cin >> A[i];
        precalc();

        cout << quantize(0,s) << endl;
    }

    return 0;
}