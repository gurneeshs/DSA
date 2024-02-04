# ***********************
# 1
# 2 3
# 4 5 6
# 7 8 9 10 
# **********************
i=1
cnt = 1
n=4
while(i<=n):
    j=1
    while(j<=i):
        print(cnt, end=" ")
        cnt = cnt + 1
        j=j+1
    print()
    i=i+1
