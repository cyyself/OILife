def f(x):
	return int(str(x)[::-1])
T = int(input())
for i in range(T):
	S = input().split()
	print(int(f(int(f(S[0]))+int(f(S[1])))))
