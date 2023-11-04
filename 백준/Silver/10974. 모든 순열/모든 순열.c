#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
char res[17];
int N, chk[9];
void dpl(int depth)
{
	int i;
	if (depth == N) printf("%s", res);

	for (i = 1; i <= N; i++)
	{
		if (chk[i] == 1) continue;

		chk[i] = 1;
		res[2 * depth] = i + '0';
		dpl(depth + 1);
		chk[i] = 0;
	}
}
int main(void)
{
	int i;
	scanf("%d", &N);
	for (i = 0; i < N; i++) res[2 * i + 1] = ' ';
	res[2 * N - 1] = '\n';
	dpl(0);
}