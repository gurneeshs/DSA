import math
number = int(input("Enter Number"))
num = abs(number)
binary = 0

i=0
one_complement = 0
while(num!=0):
    bit = num & 1
    binary = (bit * (int(math.pow(10,i))))+binary
    num = num >> 1
    i = i+1
i=0
# if(number<0):
#     while(binary>=1):
#         temp = binary%10
#         temp = int(not(temp))
#         one_complement = (one_complement * (int(math.pow(10,1))))+ temp
#         binary = int(binary/10)
#         print(temp, one_complement, binary)

#     one_complement = str(one_complement)
#     one_complement = one_complement[::-1]
#     # one_complement = int(one_complement)

#     binary = one_complement

print(binary)