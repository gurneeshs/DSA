#**************** 
# A 
# B C  
# C D E
# D E F G
# ***************
char = 64
i=1
n=5
while(i<=n):
    j=1
    while(j<=i):
        print(chr(char+i+j-1), end=" ")
        j=j+1
    print()
    i=i+1
