''' 
*********************
      1
    2 3
  4 5 6
7 8 9 10
*********************
'''
i=1
n=4
cnt = 1

while(i<=n):
    sp =i
    while(sp<n):
        print(" ", end=" ")
        sp = sp +1
    j=n-i
    while(j<n):
        print(cnt, end=" ")
        j = j+1
        cnt = cnt +1
    print("")
    i=i+1