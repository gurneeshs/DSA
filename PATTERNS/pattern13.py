#***************
# A
# B B
# C C C
#***************

char = 65
i=1
n=5
while(i<=n):
    j=1
    while(j<=i):
        print(chr(char+i-1), end=" ")
        j=j+1
    print()
    i=i+1
