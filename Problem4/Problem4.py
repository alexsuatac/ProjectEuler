# find the largest palindrome that is the product of two three-digit numbers

# function that checks if value is a palindrome
def isPalindrome(val):
    # convert to string, reverse and check for equality
    s = str(val)
    sr = s[::-1]
    return s == sr

palindromes = []

# count down from largest product
# the first palidrome will be the largest one
# O(n^2)
for multiplicand in range(999, 100, -1):
    for multiplier in range(999, 100, -1):
        num = multiplicand*multiplier
        if isPalindrome(num):
            palindromes.append(num)

# find largest value in list
print(max(palindromes))

