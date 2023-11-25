# 두 팀의 능력치 차이 계산해 반환
def start_link(team1, team2):
    team1_score = sum(score[i - 1][k - 1] for i in team1 for k in range(1, N + 1) if i != k and visited[k])
    team2_score = sum(score[i - 1][k - 1] for i in team2 for k in range(1, N + 1) if i != k and not visited[k])
    return abs(team1_score - team2_score)

# 팀 나누는 경우의 수 
def func(x, start):
    global s_min
    if x == half:
        team2 = [i for i in range(1, N + 1) if not visited[i]]
        s_min = min(s_min, start_link(team1, team2))
        return

    for i in range(start, N + 1):
        if not visited[i]:
            team1[x] = i
            visited[i] = 1
            func(x + 1, i + 1)
            visited[i] = 0

MAX = lambda a, b: b if a < b else a
MIN = lambda a, b: a if a < b else b

N = int(input()) # 팀 수
half = N // 2

# 능력치 입력
score = [list(map(int, input().split())) for _ in range(N)]

visited = [0] * (N + 1) # 방문 여부 배열
team1 = [0] * half
team2 = [0] * half
s_min = 9999999

func(0, 1)
print(s_min)
