#**************** 
# A B C
# B C D 
# C D E
# ***************
char = 64
i=1
n=3
while(i<=n):
    j=1
    while(j<=n):
        print(chr(char+i+j-1), end=" ")
        j=j+1
    print()
    i=i+1
