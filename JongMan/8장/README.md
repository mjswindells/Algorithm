동적계획법 (Dynamic Programming)
==============================
(Dynamic Programming = DP라 칭함)

분할정복과 공통점은 큰 문제를 작은문제로 나누어 푸는것이다.

차이점은 memorization으로 작은 부분문제들이 반복되는것을 방지한다.

# memorization
그냥 재귀를 사용했을 경우
```cpp
int Fi(int num)
{

   if(num==1||num==2)
      return 1;
   else
      return Fi(num-1)+Fi(num-2);

}
```
memorization을 사용했을 경우
```cpp
int arr[10001];

int fibo(int x) {
	if (x == 1) {
		arr[x] = x;
		return arr[x];
	}
	if (arr[x] != 0) {
		return arr[x];
	}
	arr[x] = fibo(x - 1) + fibo(x - 2);
	return arr[x];
}
```
이렇듯 DP를 사용하게되면 메모리를 추가적으로 사용하지만 반복적인 계산을 없애 알고리즘의 속도를 향상시킬 수 있다.

# method
## TopDown
- 문제 풀이가 위에서 아래로 진행되는 것

- 위의 fibo가 예시이다.
## BottomUp
- TopDown과 상반되게 문제풀이가 아래에서 위로 진행되는 것

- 같은 피보나치수열로 예시를 보자
```cpp
int arr[10001];

int fibo(int n)
{
  arr[0] = 0;
  arr[1] = 1;
  for (int i=2; i<=n; i++)
    arr[i] = arr[i - 1] + arr[i - 2];
  return arr[n];
}
```
이와같이 1에서부터 n까지 점진적으로 계산해나가는걸 볼 수 있다.