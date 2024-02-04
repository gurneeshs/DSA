#**************** 
# D
# C D  
# B C D
# A B C D
# ***************
char = 65
i=1
n=4
while(i<=n):
    j=1
    while(j<=i):
        print(chr(char+n-i+j-1), end=" ")
        j=j+1
    print()
    i=i+1
