#**************** 
# A B C
# D E F
# G H I
# ***************
char = 65
i=1
n=6
while(i<=n):
    j=1
    while(j<=n):
        print(chr(char+j-1), end=" ")
        j=j+1
    print()
    i=i+1
