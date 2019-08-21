''' Sum Digits without using a while statement '''

def split(n):
    ''' split positive n into all but its last digit and its last digit '''
    return n // 10, n % 10


def sum_digits(n):
    ''' return the sum of the digits of the positive integer n '''
    if n < 10:
        return n
    else:
        all_but_last, last = split(n)
        return sum_digits(all_but_last) + last
