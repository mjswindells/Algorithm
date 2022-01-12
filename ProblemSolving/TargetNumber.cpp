#include <iostream>
#include <string>
#include <vector>
//프로그래머스 타겟넘버
// https://programmers.co.kr/learn/courses/30/lessons/43165
using namespace std;

// 0~N까지의 원소 각각의 +-를 계산한다.
//재귀를 이용하여 O(2^N)이며 모든 경우의 수를 계산하는 완전탐색
int recursive(vector<int> v, int target, int sum, int idx)
{
    //끝내는 조건은 idx가 N이 될 경우 retrun한다.
    if (idx == v.size())
    {
        //만약 모든 합이 target과 같을경우 1 return 
        if (sum == target)
            return 1;
        return 0;
    }
    //각각의 더하는 경우와 빼주는 경우를 생각하여 recursive
    //=================잘못생각한 부분=============================
    // recursive(v,target,sum+=v[idx],idx++) 이와같이 입력할 경우
    //함수의 오류가 생긴다 재귀로 넘길경우 값만을 넘기자
    return recursive(v, target, sum + v[idx], idx + 1) + recursive(v, target, sum - v[idx], idx + 1);

}
int solution(vector<int> numbers, int target)
{
    int answer = recursive(numbers, target, 0, 0);
    return answer;
}

//배열의 크기가 클 경우 평균적으로 위 코드보다 효율적인 코드
// v={1,1,1,1,1} t=3 일 경우 v의 모든 원소의 합 sum=5
// sum-t=2 이고 2/2=1이다 즉 v에서 합이 1인 집합의 모임만 찾아주면 된다.
//여기서 합이 1인 집합을 찾는 다는 의미는 나머지는 부호가 +이고 1로 이루어진 집합만 -부호이다
// 2로 나누어주는 이유는 +인 집합에서 어느 한 원소(a)를 -로 바꾸면 실제 sum은 sum-2a가 되기때문
// int get_number(vector<int> v, int sum, int idx, int count)
// {
//     //(vector, 합하였을때 원하는 값, index, return할 숫자값)
//     for (int i = idx; i < v.size(); i++)
//     {
//         int temp = sum - v[i];
//         // temp가 0인 경우 답이므로 count를 늘리고 다음 인덱스로 넘어간다
//         //즉 마지막에 뺀 원소와 같은 값이 되도록 새로운 원소들의 합을 찾는 과정
//         if (temp == 0)
//             count++;
//         // temp가 0보다 클 경우 합해야할 원소가 남아 있으므로 다음 idx부터 다시 합해간다
//         else if (temp > 0)
//             count += get_number(v, temp, i + 1, 0);
//         // temp<0 즉 v[idx]를 합하였을 때 초과한 경우 다음 인덱스로 넘어간다
//         else
//             continue;
//     }
//     return count;
// }
// int solution(vector<int> numbers, int target)
// {
//     int sum = 0;
//     for (int i = 0; i < numbers.size(); i++)
//         sum += numbers[i];
//     //만약 sum-target이 홀수면 답이 없다.
//     if ((sum - target) % 2 != 0)
//         return 0;
//     sum = (sum - target) / 2;
//     int answer = get_number(numbers, sum, 0, 0);
//     return answer;
// }
int main()
{
    vector<int> a = {1, 1, 1, 1, 1};
    cout << solution(a, 3);
}