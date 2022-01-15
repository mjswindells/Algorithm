#include <iostream>

using namespace std;

//https://algospot.com/judge/problem/read/PICNIC
//PICNIC

//board 친구인지 판별하는 배열
bool board[10][10];
//짝이 지어졌으면 true
bool check[10];
//board와check를 초기화
void init() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            board[i][j] = false;
            check[i] = false;
        }
    }
}
//board와 check가 전역변수로 설정이 돼있어 인자로 친구수인n만 들어간다
int Findfriend(int n){
    int first=-1;
    //first는 인덱스. 짝이지어지지않은 가장작은 idx로 설정
    for(int i=0;i<n;i++) if(!check[i]) {first=i;break;}
    //기저사례 모든학생이 짝을 찾았으므로 1추가
    if(first==-1) return 1; 
    int ans=0;
    //first의 다음 idx부터 짝이되는 친구를 찾는다
    for(int i=first+1;i<n;i++){
        if(!check[i]&&board[first][i]){
            check[first]=check[i]=true;
            ans+=Findfriend(n);
            check[first]=check[i]=false;
        }
    }
    return ans;
}
int main(){
    int T,n,m,x,y,count; cin>>T;
    while(T--){
        count=0;
        init();
        cin>>n>>m;
        for(int i=0;i<m;i++){
            cin>>x>>y;
            if(x<y) board[x][y]=true;
            else board[y][x]=true;
        }
        count=Findfriend(n);
        cout<<count<<endl;
    }
}