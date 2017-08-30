from random import randint
from random import shuffle
#3:2 below
zeroes = [0]*400000
ones = [1]*600000
#4:2 below
# zeroes = [0]*333332
# ones = [1]*666664
total = ones+zeroes
shuffle(total)
print(total)