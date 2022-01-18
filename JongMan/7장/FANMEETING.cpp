#include <iostream>
#include <algorithm>

using namespace std;

//FENMEETING
//https://algospot.com/judge/problem/read/FANMEETING
//알고리즘을 생각하던 도중 비트연산을 이용하면 빠를거 같다는 생각이 들었다.
//하지만 자릿수가 20만이하라 구현을 할 수 없었다.
//결국 카라츠바알고리즘을 사용하여 구현을 해야하는데 이부분은 공부가 더 필요하다.

int main(){

}

//밑에는 자바풀이이다. 알고만 있자 일단
// import java.io.*;
// import java.util.*;

// class Main{

//    public static void main(String[] args) throws IOException {
//       BufferedReader br =new BufferedReader(new InputStreamReader(System.in));
//       int n= Integer.parseInt(br.readLine());
//       String a,b;
//       while(n-->0){
//          a=br.readLine();
//          b=br.readLine();
//          System.out.println(hugs(b,a));
//       }
//    }

//    public static int hugs(String members, String fans) {
//       String strA = members.replace('F', '0').replace('M', '1');
//       String strB = fans.replace('F', '0').replace('M', '1');
//       if (strA.length() > strB.length()) {
//          String temp = "";
//          temp = strA;
//          strA = strB;
//          strB = temp;
//       }
//       int A = Integer.parseInt(strA, 2);
//       int B = Integer.parseInt(strB, 2);
//       int result = 0;
//       for (int i = 0; i < strB.length() - strA.length() + 1; i++) {
//          if ((A & B) == 0) {
//             result += 1;
//          }
//          B = (B >> 1);
//       }
//       return result;
//    }
// }
