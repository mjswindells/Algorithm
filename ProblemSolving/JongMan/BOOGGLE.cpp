#include <iostream>
using namespace std;

//https://algospot.com/judge/problem/read/BOGGLE
//보글게임

//상하좌우 대각선으로 이동해보기 위한 배열
const int nx[8]={1,1,0,-1,-1,-1,0,1};
const int ny[8]={0,1,1,1,0,-1,-1,-1};
//word : 입력받을 단어
string  word[10];
//word의 단어를 만들 수 있으면 "YES"
string check[10];
//문자를 입력받을 board 입력받는건 5x5인데 7x7로 만든 이유는
//겉에 테두리를 '0'으로 설정해 단어에 방해되지 않게 하기 위하여
char board[7][7];
//FindAns(word중 하나의 string,그 word의 인덱스,
//word의 idx확인용,board의 x,board의 y)
void FindAns(string &word,int order,int idx,int x,int y){
    //재귀중 또는 처음문자를 다른 idx에서 발견했을때 불필요한 
    //reursive를 없애기 위해
    if(check[order]=="YES") return;
    //word끝까지 돌았을경우 단어를 만든것이므로 check를 "YES"로 바꾼다
    if(idx+1==word.length()){check[order]="YES";return;}
    for(int k=0;k<8;k++){
        if(board[x+nx[k]][y+ny[k]]==word[idx+1]){
            FindAns(word,order,idx+1,x+nx[k],y+ny[k]);
        }
    }
}
//check, word, board를 초기화
void init(){
    for(int i=0;i<10;i++) {
        check[i]="NO";
        word[i]="";
    }
    for(int i=0;i<7;i++){
        for(int j=0;j<7;j++) board[i][j]='0';
    }
}
int main(){
    int T,N;
    cin>>T;
    init();
    while(T--){
        for(int i=1;i<6;i++){
            for(int j=1;j<6;j++){
                cin>>board[i][j];
            }
        }
        cin>>N;
        for(int i=0;i<N;i++) cin>>word[i];

        for (int k = 0; k < N; k++) {
            for (int i = 1; i < 6; i++) {
                for (int j = 1; j < 6; j++) {
                    //불필요한 반복 없애기 위해
                    if(check[k]=="YES") break;
                    if(word[k][0]==board[i][j])
                        FindAns(word[k],k,0,i,j);
                }if(check[k]=="YES") break;
            }
        }
        for(int i=0;i<N;i++) cout<<word[i]<<" "<<check[i]<<endl;
        init();
    }
}