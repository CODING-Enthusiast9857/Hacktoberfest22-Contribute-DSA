n_steps = int(input ("How many steps wants to print? "))  
  
n1 = 0  
n2 = 1  
count = 0  
  
if n_steps <= 0:  
    print ("Please enter a positive integer, the given number is not valid")  
elif n_steps == 1:  
    print ("The Fibonacci sequence of the numbers up to", n_steps, ": ")  
    print(n1)  
else:  
    print ("The fibonacci sequence of the numbers is:")  
    while count < n_steps:  
        print(n1)  
        nth = n1 + n2  
        n1 = n2  
        n2 = nth  
        count += 1
