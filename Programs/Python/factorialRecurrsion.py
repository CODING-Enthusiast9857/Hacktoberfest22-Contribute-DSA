def factorial(n):
    if n == 1:
        return n
    else:
        summ = n * factorial(n-1)
        return summ
number = int(input("Enter number: "))
print(factorial(number))



