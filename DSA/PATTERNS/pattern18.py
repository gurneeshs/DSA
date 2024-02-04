''' 
*********************
          *
        * *
      * * *
    * * * *
  * * * * *
* * * * * *  
*********************
'''
i=1
n=3

while(i<=n):
    sp =n
    while(sp>i):
        print(" ", end=" ")
        sp = sp -1
    j=1
    while(j<=i):
        print("*", end=" ")
        j = j+1
    print("")
    i=i+1