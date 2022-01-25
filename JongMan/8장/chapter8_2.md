#
# Quantization
1. 정렬
2. 한 구간에서의 분산 (평균의 반올림한 값으로 구한)
3. 구간의 분할(?)

![양자화비미분](https://user-images.githubusercontent.com/91093119/150964804-50529089-09e8-44aa-ab8a-71480e15f0e1.png)

```cpp
//lo부터 hi까지의 분산(O(1))
int minError(int lo, int hi){
    //구간의 합을 구한다.
    int sum = pSum[hi] - (lo == 0 ? 0 : pSum[lo-1]);
    int sqSum = pSqSum[hi] - (lo == 0 ? 0 : pSqSum[lo-1]);
    //구간합과 구간의 길이를 나눈 값으로 해당 구간의 양자값을 구한다.
    //반올림을 하는 과정 양자화되는 값은 int형이기 때문에 반올림으로 구한다
    int m = int(0.5 + (double)sum / (hi-lo+1));
    //구간의 오차를 구한다.
    //m의 값을 구했으니 그 구간에서의 최소값을 구하는 과정
    int ret = sqSum - 2 * m * sum + m * m * (hi - lo + 1);
    return ret;
}

// quantize의 값은 결국 minError의 값으로 결정이 되므로 
// 기저사례의 값을 0또는 INF값으로 설정한다.
// from번째 이후 숫자들을 parts개의 묶음으로 묶는다
//O(n^2s) 부분문제의 수 ns 각각의 계산 n
int quantize(int from, int parts){
    //모든 숫자를 양자화했을 때
    if(from == n) return 0;
    //숫자는 아직 남았는데 남는 조각 수가 없을 때는 포함을 시키면 안된다.
    if(parts == 0) return INF;
    int &ret = d[from][parts];
    if(ret != -1) return ret;
    ret = INF;

    //조각의 길이를 변화시켜가며 최소치를 찾는다.
    //
    for(int partSize=1;from+partSize<=n;++partSize)
        ret = min(ret, minError(from, from+partSize-1) + quantize(from+partSize, parts-1));

    return ret;
}
```
#
# 타일링 방법의 수 세기
- 1 2 3 5 8 ... 피보나치
- 피보나지 형태로 나오는 이유
- a　　　b　　　c
- ㅁㅣ　ㅁㅣㅣ　ㅁ=

```cpp
//n번째 타일을 구한다 했을 때 
//n-1번째와 n-2번째를 생각해보자
//a와b 는 사실상 같은 형태이다
int ans[101];
void FindAns(){
    ans[1]=1;
    ans[2]=2;
    for(int i=3;i<101;i++){
        ans[i]=(ans[i-2]+ans[i-1])%1000000007;
    }
}
```
#
# 삼각형 위의 최대경로 개수 세기
- 메모리제이션의 이유? 
- 내려가는 경로가 겹칠 수 밖에 없는데 추가적인 메모리를 낭비해야 하는가?

```cpp
int arr[100][100];
//arr를 정렬하는 과정
void FindMax(int n){
    for(int i=n-2;i>=0;i--){
        for(int j=0;j<i+1;j++){
            arr[i][j]+=max(arr[i+1][j],arr[i+1][j+1]);
        }
    }
}
int countMax(int i,int j,int n){
    //기저사례 : 맨 끝부분까지 갔을 경우 길을 찾았으니 return 1
    if(i==n-1) return 1;
    int ans=0;
    //2개의 경로중 큰 값이 있는 쪽으로 이동. 만약 같으면 둘 다 이동한다
    if(arr[i+1][j]>=arr[i+1][j+1]) ans+=countMax(i+1,j,n);
    if(arr[i+1][j]<=arr[i+1][j+1]) ans+=countMax(i+1,j+1,n);
    return ans;
}
```
#
# 장마가 찾아왔다
1. 75%를 어떻게 나타낼 것인가
2. 메모리제이션을 활요하자. ex)3일에 5만큼 올라간 경우는 3번이나 있다
```cpp
double cache[1000][2001];

double canclimb(int day,int climb){
    //기저사례 : m일만큼 올랐을때 높이 이상이면 1아니면 0 (확률이므로)
    if(day==m) return climb>=n?1:0;
    double& ret=cache[day][climb];

    if(ret!=-1.0) return ret;
    //75%확률로 비가 오므로
    return ret=0.25*canclimb(day+1,climb+1)+0.75*canclimb(day+1,climb+2);
}
```
- O(m^2) : m일까지는 다 오르고 나서 계산을 한다. 1일에(1,2) 2일에(2,3,4) 3일에 (3,4,5,6),~,k일에 (k,k+1,~,2k-1,2k)
- 즉 m인 경우 2~(m+1)까지의 합
```cpp
for(auto& r:cache){
    for (auto& c:r){
        c=-1.0;
    }
}
```
- cache의 범위가 double이므로 memset을 활용한 초기화에 오류가 생긴다.
- NAN(not a number) 오류 왜 생길까?
- int형과 double형의 표현방식이 달라서 생기는 문제이다 int형을 생각해보자
- memset(0)의 경우 0000->0 
- memset(-1)의 경우 1111->-1
#
# 비대칭 타일링
- 우선 대칭이 가능한 3가지형태만 생각하자
- a : ㅁㅣㅁ    (홀수일 경우)
- b : ㅁ=ㅁ     (짝수일 경우)    
- c : ㅁㅣㅣㅁ  (짝수일 경우)
- 이때 생각을 잘못했는데 c의 경우 ㅁㅁ로 생각을 해야한다.ㅁ==ㅁ이러한 경우도 대칭이 되기 떄문에.
```cpp
int tile[101];
int cache[101];

void symmetry(){
    tile[1]=1;tile[2]=2;
    cache[0]=cache[1]=cache[2]=0;

    for(int i=3;i<101;i++){
        tile[i]=(tile[i-2]+tile[i-1])%MOD;
        //짝수 : 굳이 2개로 나눈 이유는 하나로 합쳤을경우 범위의 오류로 인해 
        //원하는 답이 출력되지 않는다.
        if(i%2==0){
            //MOD를 더하고 나머지를 구하는 이유는 뺀 값이 음수가 나올 수 있기에 더해주고 나머지를 구한다.
            cache[i]=(tile[i]-tile[i/2-1]+MOD)%MOD;
            cache[i]=(cache[i]-tile[i/2]+MOD)%MOD;
        }
        //홀수
        if(i%2==1){
            cache[i]=(tile[i]-(tile[i/2])+MOD)%MOD;
        }
    }
}
```
- 함수를 void로 배열에다 원하는 값을 저장시켜 각각에 테스트케이스마다 O(1)이 나오게 설정한다.
- 책에 나온 풀이는 사각형의 너비가 작은 경우 효율적으로 작동하게 될것이다 만약 테스트케이스가 많고 너비가 큰(100)경우가 주어진 경우 array에서 바로 호출을 하는 풀이가 더 빠르게 나온다
#
# 폴리노미오
1. 정사각형의 수가 4일때 어떻게 19가 나온거지? (ㅡ과ㅣ를 다른 경우로 체크한다.대칭과 회전을 고려하지 않는다)
2. DFS로 풀 수 있을까? x (좌표로 생각해서는 시간안에 풀지도 못하고 예외처리할 부분이 많다)
![양자화비미분](https://user-images.githubusercontent.com/91093119/150958444-02424160-266d-41fe-9e85-c4697fa9375c.png)
- first + second -1 개의 경우를 가진다(2+3-1=4가지 경우)
```cpp

```