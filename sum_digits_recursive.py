''' Sum Digits without using a while statement '''

def split(n):
    '''
    split positive n into all but its last digit and its last digit
    >>> split(1043)
    (104, 3)
    >>> split(134)
    (13, 4)
    '''
    return n // 10, n % 10


def sum_digits(n):
    '''
    return the sum of the digits of the positive integer n
    >>> sum_digits(1043)
    8
    >>> sum_digits(1414)
    10 
    '''
    if n < 10:
        return n
    else:
        all_but_last, last = split(n)
        return sum_digits(all_but_last) + last
