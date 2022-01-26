#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;
//두니발박사의 탈옥
//https://algospot.com/judge/problem/read/NUMB3RS
//마르코프연쇄를 이용해 풀었다. 행렬의 크기:n 거듭제곱의 수 :m
//O(n^3m)

#define matrix vector<vector<double>> 

// board를 확률로 나타내기 위한 check 
int check[50];
//마을의수, 지난일수, 교도소번호
int n,d,p;

//n을 행렬의 크기라 했을때 O(n^3)
//슈트라센알고리즘을 이용하면 시간을 더 줄일 수 있다.

matrix operator*(const matrix &a, const matrix &b) {
    matrix res(n, vector<double>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                res[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return res;
}

//7장 행렬의 거듭제곱을 구하는 분할정복 알고리즘
//M을 거듭제곱횟수라 했을 경우 O(logM)
matrix power(matrix a, double r) {
    matrix res(n, vector<double>(n));
    // res를 단위행렬로 설정
    for (int i = 0; i < n; i++)
        res[i][i] = 1;
    while (r > 0) {
        if ((int)r % 2 == 1) {
            res = res * a;
        }
        r /= 2;
        a = a * a;
    }
    return res;
}

int main(){
    int T,k;cin>>T;
    while(T--){
        memset(check,0,sizeof(check));
        cin>>n>>d>>p;
        matrix board(n, vector<double>(n));

        //check와 board 입력
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>k;
                if(k==1) check[i]++;
                board[i][j]=k;
            }
        }
        //board의 1을 확률로 변환 ex) 0110 -> 0 0.5 0.5 0
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==1){
                    board[i][j]=board[i][j]/check[i];
                }
            }
        }
        //O(n^3logM)
        matrix answ=power(board,d);

        cout<<endl<<endl<<"board:"<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++) cout<<board[i][j]<<" ";
            cout<<endl;
        }
        cout<<endl<<"ans:"<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++) cout<<answ[i][j]<<" ";
            cout<<endl;
        }
        
        cout<<endl<<endl;
        int t,temp;cin>>t;
        while(t--) {
            cin>>temp;
            cout<<answ[p][temp]<<" ";
        }
        
    }
}




// double cache[51][101];
// int connected[51][51];
// int deg[51];
// int n,d,p,q;

// //감옥에서부터 시작하지 않고 
// //다른 마을에서부터 시작하여 감옥으로 도착하는 경우를 확인.
// double search(int here, int days){
//     if(days == 0) return (here == p ? 1.0 : 0.0);
    
//     double &ret = cache[here][days];
//     if(ret > -0.5) return ret;
//     ret = 0.0;
//     //현재위치와 인접한 경로를 모두 방문하여 d일째에 감옥에 위치할 확률을 구한다.
//     for(int there=0;there<n;++there)
//         if(connected[here][there])
//             ret += search(there, days-1) / deg[there];
//     return ret;
// }

// int main(){

//     int _;
//     cin >> _;
//     while(_--){
//         memset(cache, -1, sizeof(cache));
//         memset(deg, 0, sizeof(deg));

//         cin >> n >> d >> p;
//         for(int i=0;i<n;i++){
//             for(int j=0;j<n;j++){
//                 cin >> connected[i][j];
//                 //i번째 마을과 연결된 마을의 개수를 더해준다.
//                 deg[i] += connected[i][j];
//             }
//         }

//         cin >> q;
//         while(q--){
//             int h;
//             cin >> h;
//             cout.precision(8);
//             cout << search(h, d) << " ";
//         }
//         cout << endl;
//     }
// }