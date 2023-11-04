#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);
    int* a = (int*)malloc(N * sizeof(int));
    // 숫자 사용 여부를 체크할 배열
    int* visit = (int*)malloc((N + 1) * sizeof(int));

    // visit에 해당 숫자를 몇 번째에 사용했는지 표시
    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
        visit[a[i]] = i;
    }
    int inde = -1;
    visit[0] = -2;

    // 뒤의 수 보다 앞의 수가 클 경우
    for (int i = N - 1; i > 0; i--) {
        if (a[i - 1] > a[i]) {
            inde = i - 1;
            break;
        }
    }

    // 이전 순열이 없음
    if (inde == -1) {
        printf("-1");
    }
    else {
        // 해당 위치 뒤의 사용 여부 모두 제거
        for (int j = 1; j < N + 1; j++) {
            if (visit[j] >= inde) {
                visit[j] = -1;
            }
        }
        // 해당 위치의 숫자보다 작은 가장 가까운 값을 선택
        for (int i = a[inde] - 1; i > 0; i--) {
            if (visit[i] == -1) {
                a[inde] = i;
                visit[i] = inde;
                break;
            }
        }

        // 위치의 뒤는 남은 숫자 중 큰 순서대로 선택
        for (int i = inde + 1; i < N; i++) {
            for (int j = N; j > 0; j--) {
                if (visit[j] == -1) {
                    a[i] = j;
                    visit[j] = i;
                    break;
                }
            }
        }

        // 출력
        for (int i = 0; i < N; i++) {
            printf("%d ", a[i]);
        }
    }

    free(a);
    free(visit);

    return 0;
}
