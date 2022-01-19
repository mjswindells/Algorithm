#include <iostream>
#include <vector>

using namespace std;
//JUMPGAME
//https://algospot.com/judge/problem/read/JUMPGAME
//memorization을 이용하여 중복된 칸에는 가지 않도록 설정

int N;
int arr[100][100];
bool check[100][100];

bool FindAns(int x,int y){
    //기저사례 : 마지막칸에 도착했을 경우 true
    if(x==N-1&&y==N-1) return true;
    //범위에서 벗어나거나 이미 지나간 칸인 경우 false
    if(x>=N||y>=N) return false;
    if(check[x][y]) return false;

    //이번 칸은 확인을 했으므로 check를 true로 바꾼다
    check[x][y]=true;
    int x1=x+arr[x][y];
    int y1=y+arr[x][y];

    return FindAns(x,y1)||FindAns(x1,y);
}
int main(){
    int T;cin>>T;
    while(T--){
        cin>>N;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++) cin>>arr[i][j];
        }
        if(FindAns(0,0)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}