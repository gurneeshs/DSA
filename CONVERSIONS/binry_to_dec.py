import math
num = int(input("Enter Number"))
dec = 0

i=0
one_complement = 0
while(num!=0):
    bit = num % 10
    dec = dec + (bit*(2**i))
    num = int(num / 10)
    i = i+1

print(dec)