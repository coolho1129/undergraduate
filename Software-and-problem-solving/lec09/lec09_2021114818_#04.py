def find_pair(s):
    stack=[]
    for i in range(len(s)):
        if s[i]==')' and stack[-1]=='(':
            stack.pop()
            continue

        if s[i] == '}' and stack[-1] == '{':
            stack.pop()
            continue

        if s[i] == ']' and stack[-1] == '[':
            stack.pop()
            continue

        stack.append(s[i])
    return stack

N=int(input())
S=[]

for i in range(N):
    S.append(input())

for i in range(N):
    if find_pair(S[i])==[]:
        print('YES')
    else:
        print('NO')











