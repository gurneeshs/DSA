''''
*********************
1 2 3 4 5 5 4 3 2 1
1 2 3 4 * * 4 3 2 1
1 2 3 * * * * 3 2 1
1 2 * * * * * * 2 1
1 * * * * * * * * 1
*********************
'''

i=1

n=5

while(i<=n):
    j=1
    while(j<=n-i+1):
        print(j, end=" ")
        j = j+1
    st=1
    
    while(st<=2*(i-1)):
        print("*",end=" ")
        st =st+1
        
    k=n-i+1
    while(k):
        print(k,end=" ")
        k=k-1

    print("")
    i=i+1
