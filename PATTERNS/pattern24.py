''' 
*********************
      1
    1 2 1
  1 2 3 2 1
1 2 3 4 3 2 1
*********************
'''
i=1
n=5

while(i<=n):
    sp =i
    while(sp<n):
        print(" ", end=" ")
        sp = sp +1
    j=1
    while(j<=i):
        print(j, end=" ")
        j = j+1
    
    k=i-1
    while(k):
        print(k,end=" ")
        k = k-1
    print("")
    i=i+1
