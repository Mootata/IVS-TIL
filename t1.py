# def solution(N, M, board):
#     answer = 0

#     for i in range(N):
#         temp = 0
#         for j in range(M):
#             if board[j][i] == 0:
#                 temp += 1
#             else:
#                 break
#         answer = max(answer, temp)
#     return answer


# # print(solution(3, 3, [[1, 0, 1], [1, 0, 1], [1, 0, 1]]))
# print(solution(3, 3, [[1, 1, 1], [0, 0, 1], [1, 0, 0]]))

N = 3
M = 4
new = [[0 for _ in range(M)] for _ in range(N)]
A = [[1, 0, 0],[1, 1, 1], [0, 0, 1], [1, 0, 0]]
for i in A:
     print(i)
for y in range(M):
        for x in range(N):
            if A[y][x]==1:
                new[x][y]=1
for i in new:
     print(i)
mmax=0
for y in range(N):
        cnt = 0
        for x in range(M):
            if new[y][x]==0:
                cnt += 1
            else:
                break
        if cnt>mmax:
            mmax = cnt
print(mmax)