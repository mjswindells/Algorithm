#include <iostream>
using namespace std;
//백준 9734 순환소수
//https://www.acmicpc.net/problem/9734

//a와b의 최대공약수 return
int gcd(int a,int b){
    //유클리드 호제법 사용
    if(b==0) return a;
    else return gcd(b,a%b);
}
int findMot(int zero,int nine){
    int ans=0;
    while(nine--){ans+=9;ans*=10;}ans/=10;
    while(zero--) ans*=10;
    return ans;
}
int main(){
    string str;
    while(cin>>str){
        int zero,nine,son,mot;
        string all="";
        string mi="";
        bool ismi=true;
        for(int i=0;i<str.length();i++){
            if(str[i]=='.') {
                zero=i;
            }
            else if(str[i]=='('){
                zero=i-zero-1;
                nine=i;
                ismi=false;
            }
            else if(str[i]==')'){
                nine=i-nine-1;
            }
            else if(isdigit(str[i])){
                all+=str[i];
                if(ismi) mi+=str[i];
            }
            else continue;
        }
        son=stoi(all)-stoi(mi);
        mot=findMot(zero,nine);
        int split;
        if(son>mot) split=gcd(son,mot);
        else split =gcd(mot,son);
        son/=split;mot/=split;
        cout<<str<<" = "<<son<<" / "<<mot<<endl;
        continue;
    }
    return 0;
}