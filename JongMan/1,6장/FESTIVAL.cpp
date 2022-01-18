#include <iostream>
using namespace std;

// https://algospot.com/judge/problem/read/FESTIVAL

//나의풀이
int main(){
    int C,N,L;
    cin>>C;
    while(C--){
        cin>>N>>L;
        int array[N];
        for(int i=0;i<N;i++) cin>>array[i];
        double ave=987654321;
        //0~3 0~4 0~N
        //1~4 1~5 1~N 이런식으로 진행
        for(int i=0;i<N-L+1;i++){
            double sum=0;
            for(int j=i;j<N;j++){
                sum+=array[j];
                int count=j-i+1;
                if(count>=L){
                    if(ave>(sum/count)) ave=sum/count;
                }
            } 
        }
        //소수점 11자리
        cout<<fixed;
        cout.precision(11);
        cout<<ave<<endl;
    }
}

// #define min(a,b) (a<b?a:b)
// int main() {
// 	int t;
// 	scanf("%d", &t);
// 	for (; t--;) {
// 		int n, l;
// 		scanf("%d %d", &n, &l);
// 		int psum[1001] = { 0, };
// 		int cost;
//         //i번째 인덱스에는 0~(i-1)번째 인덱스까지의 합이 저장된다
// 		for (int i = 1; i <= n; i++) {
// 			scanf("%d", &cost);
// 			psum[i] = psum[i -1] + cost;
// 		}
// 		double ans = 1000.0;
// 		for (int i = l; i <= n; i++) {
// 			int s = 1, e = i;
// 			while (e <= n) {
//                 //3~6번째까지의 합을 알고싶으면 psum[6]-psum[3-1]
// 				double av = (double)(psum[e] - psum[s-1]) / i;
// 				s++, e++;
// 				ans = min(ans, av);
// 			}
// 		}
// 		printf("%0.9lf\n", ans);
// 	}
// }
