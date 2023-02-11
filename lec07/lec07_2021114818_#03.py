str_1=input()
str_2=input()
find=False
temp_for_break=False
for i in range(len(str_1)):
    if str_1[i]==str_2[0]:
        for j in range(len(str_2)):
            if str_1[i+j] == str_2[j]:
                find=True
                temp_for_break = True
        if temp_for_break:
            print("index:",i)
            temp_for_break = False
if find==False:
    print(-1)