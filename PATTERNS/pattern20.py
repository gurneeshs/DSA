''' 
*********************
1 1 1 1
  2 2 2
    3 3
      4
*********************
'''
i=1
n=4

while(i<=n):
    sp =1
    while(sp<i):
        print(" ", end=" ")
        sp = sp +1
    j=i
    while(j<=n):
        print(i, end=" ")
        j = j+1
    print("")
    i=i+1