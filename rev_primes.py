""" Finds the first n values that are prime and prime when reversed.
    Example: 13 is prime, and so is 31. """

# returns true if the value passed to the function is a prime number
def isPrime(value):
    value = int(value)
    prime = True
    if value == 0 or value == 1:        # take care of the first two integers
        prime = False                   # by definition, a prime number is greater than one (0 andd 1 are not prime)
        return prime
    else:
        for i in range(2, (value - 1)):
            if value % i == 0:          # if the value is divisible by another value in this range value != prime
                prime = False
        return prime

def reverse(value):        # just testing Python's string functions
    value = str(value)
    return int(value[::-1])     # use string slicing; return the value as an integer

# find N emirps
def findNEmirps(value):
    value = int(value)      # value needs to be an integer
    nEmirps = 0             # counter for the N of primes
    potentialVal = 2        # by definition primes are >= 2
    printCount = 1
    while nEmirps < value:
        if isPrime(potentialVal) and isPrime(reverse(potentialVal)):
            nEmirps += 1
            if printCount !=0 and printCount<= 5:
                print(str(potentialVal), end= "\t")
                printCount += 1
                if printCount == 5:
                    printCount = 0
            elif printCount == 0:
                print(str(potentialVal))
                printCount += 1
        potentialVal += 1


def main():
    while True:
        value = input("Please enter a positive value: ")
        try:
            posVal = int(value)
            if posVal < 0:
                print("Value is not positive; please enter a positive value: ")         # for non-positive integer values
                continue
            break
        except ValueError:
            print("Value entered is not an integer!")       # for non-integer values
    findNEmirps(value)


if __name__ == "__main__":
    main()
