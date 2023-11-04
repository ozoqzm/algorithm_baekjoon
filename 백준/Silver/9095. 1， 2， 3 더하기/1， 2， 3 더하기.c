#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
    // 다시 보기
    // 피보나치 수열 점화식 사용!!

    int dp[11] = { 0 };
    //초깃값
    dp[1] = 1; //f(1) = 1
    dp[2] = 2;
    dp[3] = 4;

    // 숫자마다 방법의 수 구하기
    for (int i = 4; i < 11; i++)
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];

    int T, n;
    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        scanf("%d", &n);
        printf("%d\n", dp[n]);
    }

    return 0;
}
