#**************** 
# A A A
# B B B 
# C C C
# ***************
char = 65
i=1
n=4
while(i<=n):
    j=1
    while(j<=n):
        print(chr(char), end=" ")
        j=j+1
    print()
    i=i+1
    char = char + 1
