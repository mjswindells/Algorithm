#include <iostream>
#include <string>
#include <vector>
//프로그래머스 타겟넘버
//https://programmers.co.kr/learn/courses/30/lessons/43165
using namespace std;

//0~N까지의 원소 각각의 +-를 계산한다.
//재귀를 이용하여 O(2^N)이며 모든 경우의 수를 계산하는 완전탐색
int recursive(vector<int> v,int target,int sum,int idx){
    //return할 count를 0으로 설정한다.
    int count=0;
    //끝내는 조건은 idx가 N이 될 경우 retrun한다.
    if(idx==v.size()){
        //만약 모든 합이 target과 같을경우 1을 추가한 count값 return
        if(sum==target) return ++count;
        return 0;
    }
    //각각의 더하는 경우와 빼주는 경우를 생각하여 recursive
    //=================잘못생각한 부분=============================
    //recursive(v,target,sum+=v[idx],idx++) 이와같이 입력할 경우
    //함수의 오류가 생긴다 재귀로 넘길경우 값만을 넘기자
    count+=recursive(v,target,sum+v[idx],idx+1)+recursive(v,target,sum-v[idx],idx+1);
    return count;
}
int solution(vector<int> numbers, int target) {
    int answer = recursive(numbers,target,0,0);
    return answer;
}    

// int get_number(vector<int> v ,int sum,int idx, int count){
//     for(int i=idx;i<v.size();i++){
//         int temp=sum; temp-=v[i];
//         cout<<i<<' '<<temp<<endl;
//         if(temp==0) count++;
//         else if(temp>0) count+=get_number(v,temp,i+1,0);
//         else continue;
//     }
//     return count;
// }
// int solution(vector<int> numbers, int target)
// {
//     int sum = 0;
//     for (int i = 0; i < numbers.size(); i++)
//         sum += numbers[i];
//     if((sum-target)%2!=0) return 0;
//     sum = (sum - target) / 2;
//     int answer = get_number(numbers, sum, 0, 0);
//     return answer;
// }
int main(){
    vector<int> a ={1,1,1,1,1};
    cout<<solution(a,3); 
}