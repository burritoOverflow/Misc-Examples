import collections
# yes these all work the same.
# adopted this from somewhere; use as a quick lambda reference (and a comparison with alternatives)

def triple(a):
  return 3 * a

thrice = lambda x: 3 * x

these = [triple(i) for i in range(5)]
are = [(lambda x: 3*x)(i) for i in range(5)]
all = [thrice(i) for i in range(5)]
the = map(thrice, range(5))
same = map(triple, range(5))


some_list = list(range(25))

only_evens = filter(lambda x: x % 2 == 0, some_list)
only_evens_list = [x for x in some_list if x % 2 == 0]

compare = lambda x, y: collections.Counter(only_evens) == collections.Counter(only_evens_list)

if compare:
    print("True.")
