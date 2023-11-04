#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	// 자릿수 구하기
	int N;
	scanf("%d", &N);

	long long cnt = 0; //자릿수 계산 변수

	int key[100];

	for (int i = 1; i <= N; i *= 10) {
		cnt += N - i + 1;
	}
	printf("%lld", cnt);
}
