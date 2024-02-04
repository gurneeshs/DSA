''' 
*********************
* * * *
  * * *
    * *
      *
*********************
'''
i=1
n=5

while(i<=n):
    sp =1
    while(sp<i):
        print(" ", end=" ")
        sp = sp +1
    j=i
    while(j<=n):
        print("*", end=" ")
        j = j+1
    print("")
    i=i+1