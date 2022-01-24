#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
//프로그래머스 입국심사
//https://programmers.co.kr/learn/courses/30/lessons/43238

long long solution(int n, vector<int> times) {
    long long answer = 0;
    // 가장 오래 걸리는 심사관의 시간을 알기 위한 정렬
    sort(times.begin(), times.end());

    // 시간으로 기준을 두었을 때 최소 => n이 1이고, 심사 시간이 1분만 걸리는 심사관 밖에 없을 때
    long long start = 1;
    // 시간으로 기준 두었을 때 최대 => 심사 시간이 가장 오래 걸리는 사람에게 n명 모두 갔을 때
    long long end = (long long) times[times.size()-1] * n;
    // 탐색 범위(시간) 기준
    long long mid;

    while(start <= end) {
        // 중앙값
        mid = (start + end) / 2;
        // mid 시간동안 심사 처리할 수 있는 모든 사람 수
        long long cnt = 0;

        for(int i = 0; i < times.size(); i++) {
            // 각 시간별 mid 시간 동안 처리할 수 있는 사람들 수를 더해준다.
            cnt += mid / times[i];
        }

        // mid 시간동안 처리할 수 있는 모든 사람 수가 n명 보다 작기 때문에 해당 문제 조건 만족 X
        if(cnt < n) {
            // 최소값을 mid + 1 로 좁혀준다.
            start = mid + 1;
        }
        // mid 시간 동안 처리할 수 있는 사람들이 n명 이상으로 해당 문제의 조건을 만족한다면
        else {
            // mid(기준 시간) 값이 end(최대 시간) 값 보다 이하면
            // mid 는 최소값이 될 수도 있기 때문에 answer에 넣어주고
            if(mid <= end) {
                answer = mid;
            }
            // 최소 값을 찾기 위해 범위를 더 좁혀준다
            end = mid - 1;
        }
    }

    return answer;
}

int main(){
    int n=6;
    vector<int> times={7,10};
    cout<<solution(n,times)<<endl;
}
