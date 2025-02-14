import sys
import math

with sys.stdin as f:
    for line in f:
        w_ints = sorted([sum([32**i * (ord(ch) - 97 + 1) for i, ch in enumerate(w[::-1])])\
                        for w in line.strip().split()])
        n, c = len(w_ints), w_ints[0]
        get_hash = lambda w, c: math.floor(c / w) % n
        while True:
            hash_vals = {}
            for w in w_ints:
                hash_ = get_hash(w, c)
                if hash_ in hash_vals:
                    c = min((math.floor(c / w) + 1) * w,
                            (math.floor(c / hash_vals[hash_]) + 1) * hash_vals[hash_])
                    break
                hash_vals[hash_] = w
            else:
                break
        print(line.strip())
        print(c)
        print()