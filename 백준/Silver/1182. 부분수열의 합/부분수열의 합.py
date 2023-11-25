# n=배열길이, s=더했을 때 합
n, s = map(int, input().split()) #n, s 입력받기
arr = list(map(int, input().split()[:n])) # 배열 원소 입력 받기

cnt = 0

def func(cur, tot): 
    global cnt
    if cur == n: #현재인덱스가 배열 길이와 같아졌을 때
        if tot == s: # 누적합이 s와 같아지면
            cnt += 1
        return
    func(cur + 1, tot) # 원소 더하지 x
    func(cur + 1, tot + arr[cur]) # 원소 더함

func(0, 0) # 깊이우선탐색 시작

if s == 0:
    cnt -= 1
print(cnt)
