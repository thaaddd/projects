# just an implementation of binary_search
# I didn't come up with this, obviously :)
# Python 2.7

import math

def binary_search(key,T):
    min_ = 0
    max_ = len(T)-1

    while min_ <= max_:

        guess = int(math.floor((min_ + max_) / 2))
       
        if T[guess] == key:
            return T[guess]

        if T[guess] < key:
            min_ = guess + 1
        else:
            max_ = guess - 1

    return -1

T = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97]
p = [_ for _ in xrange(0,99) if binary_search(_,T) != -1]

print p==T
