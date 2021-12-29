# find the smallest integer that is evenly divisible by each integer from 1 through 20

def evenlyDivisible1To20(num):
    for d in range(1,21):
        if num % d != 0:
            return False
    
    return True

# lowest possible value must be at least 20
val = 20
while(True):
    if evenlyDivisible1To20(val):
        print(val)
        exit()
    else:
        val = val+1

