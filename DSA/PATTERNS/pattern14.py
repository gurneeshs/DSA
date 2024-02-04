#***************
# A
# B C
# D E F
#***************

char = 65
i=1
n=5
while(i<=n):
    j=1
    while(j<=i):
        print(chr(char), end=" ")
        char = char + 1
        j=j+1
    print()
    i=i+1
