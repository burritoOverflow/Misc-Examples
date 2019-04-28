import math, statistics
from functools import reduce

def area(r):
    return math.pi * (r**2)

radii = [2, 5, 12.4, 65.3, 1.98, 2.334]

areas = []
for r in radii:
    areas.append(area(r))

# Let's do this with a map function
# first arg is the function, second is the list. Will apply the function to every element in the list.

# pass it to a list constructor
areas2 = list(map(area, radii))

# let's test that these produced the same results
for a1, a2 in zip(areas, areas2):
    assert a1 == a2


#lets try something else
# these are temperatures in C; we need to convert these to degrees F
# F = (9/5) * C + 32
c_temps = [("Berlin", 29), ("Cairo", 36), ("Buenos Aires", 19), ("Los Angeles", 26), ("Tokyo", 27), ("New York", 28),
        ("London", 22), ("Beijing", 32)]

c_to_f = lambda data: (data[0], (9/5)*data[1] + 32)

# create list using the map function and the temp list
f_temps = list(map(c_to_f, c_temps))

data_sample = [1.2, 3.4, 5.6, 1.8, 5.9, 4.3]
avg = statistics.mean(data_sample)

# now lets find the values greater than average
# again, using the list constructor
list(filter(lambda x: x > avg, data_sample))

# here's the values below average
list(filter(lambda x: x < avg, data_sample))

# Using the filter function to remove missing data
# empty values are treated as false
States = ["", "", "California", "Nevada", "Colorado", "New York", "New Mexico", "New Jersey", "Maryland", "", "Rhode Island", "", "Florida"]
list(filter(None, States))

# multiply all numbers in a list
nums = [12, 43, 32, 5, 67, 12, 90, 112, 34, 56, 18, 30]
multiplier = lambda x, y: x * y
reduce_product = reduce(multiplier, nums)

product = 1
for elem in nums:
    product = product * elem

# these two examples produce the same output
assert product == reduce_product
