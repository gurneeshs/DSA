#**************** 
# A B C
# A B C 
# A B C
# ***************
char = 65
i=1
n=4
while(i<=n):
    j=1
    char = 65
    while(j<=n):
        print(chr(char), end=" ")
        j=j+1
        char = char + 1
    print()
    i=i+1
