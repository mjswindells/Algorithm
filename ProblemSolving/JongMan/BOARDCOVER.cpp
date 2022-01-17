#include <iostream>

using namespace std;

//board의 크기를 20x20보다 2칸 더 늘려서 설정한다
//재귀도중 idx가 넘어갔을 경우 따로 처리를 하지 않기 위해
bool board[22][22];
//(x,y)기준으로 그 전 idx들은 false이므로 앞으로 올것만 생각. 4가지 경우가 있다.
const int nx[4][2]={{1,0},{1,1},{1,1},{0,1}};
const int ny[4][2]={{0,1},{0,1},{0,-1},{1,1}};

void init(){
    for(int i=0;i<22;i++){
        for(int j=0;j<22;j++) board[i][j]=false;
    }
}
int count(int height,int width){
    int x=-1,y=-1;
    for(int i=1;i<=height;i++){
        for(int j=1;j<=width;j++){
            if(board[i][j]){x=i;y=j;break;}
        }
        if(x!=-1) break;
    }
    //기저사례 : 모두 false(black)인 경우
    if(x==-1) return 1;
   
    int ans=0;
    int moveX[2],moveY[2];
    for(int i=0;i<4;i++){
        moveX[0]=x+nx[i][0];moveX[1]=x+nx[i][1];
        moveY[0]=y+ny[i][0];moveY[1]=y+ny[i][1];
        if(board[moveX[0]][moveY[0]]&&board[moveX[1]][moveY[1]]){
            board[x][y]=board[moveX[0]][moveY[0]]=board[moveX[1]][moveY[1]]=false;
            ans+=count(height,width);
            board[x][y]=board[moveX[0]][moveY[0]]=board[moveX[1]][moveY[1]]=true;
        }
    }
    return ans;
}
int main(){
    char color;
    int T,h,w;;cin>>T;
    while(T--){
        init();
        int white=0;
        cin>>h>>w;
        for(int i=1;i<=h;i++){
            for(int j=1;j<=w;j++){
                cin>>color;
                if(color=='.') {
                    board[i][j]=true;
                    white++;
                }
            }
        }
        if(white%3) cout<<0<<endl;
        else cout<<count(h,w)<<endl;
    }
}