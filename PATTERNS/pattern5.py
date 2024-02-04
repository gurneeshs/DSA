# ***********************
# 1
# 2 3
# 3 4 5
# 4 5 6 7 
# **********************
i=1
cnt = 1
n=5
while(i<=n):
    j=1
    cnt = i
    while(j<=i):
        print(cnt, end=" ")
        cnt = cnt + 1
        j=j+1
    print()
    i=i+1
i=1
cnt = 1
n=5
while(i<=n):
    j=1
    while(j<=i):
        print(i+j-1, end=" ")
        j=j+1
    print()
    i=i+1
