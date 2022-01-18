#include <iostream>
#include <algorithm>
using namespace std;

//백준 14500번
//https://www.acmicpc.net/problem/14500
//ㅗ자 모양을 제외한 나머지 모양은 DFS로 충분히 구현가능하다 ㅗ모양만 예외처리를 하자.

int n,m,ans=0;
int board[500][500];
bool check[500][500];
const int dxdy[4][2]={
	{0,1},{0,-1},{1,0},{-1,0}
};

// ㅡ ㅁ ㄴ ㄹ 4가지 경우 처리가능
void DFS(int x,int y,int count,int sum){
	//기저사례 : 4개가 모였을 때
	if(count==4) {
		ans =max(ans,sum);
		return;
	}
	//자기 자신의 check를 꼭 true로 먼저 바꿔줘야한다 재귀를 도는 
	//과정에서 x,y의 check를 바꾸는 구간이 없으므로
	check[x][y]=true;
	for(int i=0;i<4;i++){
		int nx=x+dxdy[i][0];
		int ny=y+dxdy[i][1];
		//nx,ny가 범위에 들어오고 지나가지 않았을 경우
		if(nx>=0&&ny>=0&&nx<n&&ny<m&&!check[nx][ny]){
			DFS(nx,ny,count+1,sum+board[nx][ny]);
			check[nx][ny]=false;
		}
	}
	//*** 꼭 마지막에 x,y를 false로 바꿔서 board를 초기화 시켜주자!!
	check[x][y]=false;
	return;
}

int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++) cin>>board[i][j];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			DFS(i,j,1,board[i][j]);
			//ㅗ 모양 처리과정
			if(j+2<m){
                int tmp = board[i][j] + board[i][j+1] + board[i][j+2];
                if(i-1 >= 0){
                    ans = max(ans, tmp+board[i-1][j+1]);
                }
                if(i+1 < n){
                    ans = max(ans, tmp+board[i+1][j+1]);
                }
            }
            if(i+2<n){
                int tmp = board[i][j] + board[i+1][j] + board[i+2][j];
                if(j-1 >= 0){
                    ans = max(ans, tmp+board[i+1][j-1]);
                }
                if(j+1 < m){
                    ans = max(ans, tmp+board[i+1][j+1]);
                }
            }
		}
	}

	cout<<ans<<endl;
}