''' 
*********************
      1
    2 2
  3 3 3
4 4 4 4
*********************
'''
i=1
n=4

while(i<=n):
    sp =i
    while(sp<n):
        print(" ", end=" ")
        sp = sp +1
    j=n-i
    while(j<n):
        print(i, end=" ")
        j = j+1
    print("")
    i=i+1