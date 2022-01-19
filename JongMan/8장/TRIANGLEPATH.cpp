#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;
// TRIANGLEPATH
// https://algospot.com/judge/problem/read/TRIANGLEPATH


// TopDown을  사용할 경우
// 이 부분 알고리즘이 DP의 핵심이라 생각하므로 친숙해지도록 하자
// const int MAX = 101;
// int arr[MAX][MAX];
// // d는 memorization에 필요한 배열 테스트케이스 시작전에 초기화를 항상 시켜두자
// int d[MAX][MAX];
// int n;
// int dp(int x, int y){
//      //기저사례 : 깊이가 마지막 행까지 갔을 경우
//     if (y == n)
//         return arr[y][x];
//      //(y,x)에 이미 구한 max값이 있으면 return
//     if (d[y][x] != -1)
//         return d[y][x];
//         // d 캐쉬부분에 대입을 하며 이동
//         // 왼쪽 맨 밑으로 갔을 경우를 생각해보면 이해가 편하다
//         // 캐쉬면이나 중복이 일어나지 않게 구현가능
//     return d[y][x] = arr[y][x] + max(dp(x, y+1), dp(x+1, y+1));
// }
// int main(){
//     int T;
//     cin >> T;
//     while (T--){
//          //항상 시작 전에 초기화시켜둬야한다.
//         memset(d, -1, sizeof(d));
//         cin >> n;
//         for (int i=1;i<=n;i++)
//             for (int j=1;j<=i;j++)
//                 cin >> arr[i][j];
//         cout << dp(1, 1) << endl;
//     }
// }


// BottomUp 방식으로 제일 밑에서 시작하는게 편하다
//위에 시작했을 경우 배열을 하나더 추가로 만들어야하는 손실이 발생한다
//밑에서부터 (i,j)는 (max(i+1,j),(i+1,j+1))+(i,j) 로 쉽게 구하며 위로 이동한다
//결국 마지막 남은 (0,0)의 값이 최종 max값이다


int arr[100][100];
int FindMax(int n){
    for(int i=n-2;i>=0;i--){
        for(int j=0;j<i+1;j++){
            arr[i][j]+=max(arr[i+1][j],arr[i+1][j+1]);
        }
    }
    return arr[0][0];
}
int main(){
    int T,n; cin>>T;
    while(T--){
        cin>>n;
        for(int i=0;i<n;i++){
            for(int j=0;j<i+1;j++){
                cin>>arr[i][j];
            }
        }
        cout<<FindMax(n)<<endl;

    }
}