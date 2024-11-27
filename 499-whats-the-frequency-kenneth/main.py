import sys
from collections import defaultdict

with sys.stdin as f:
    for line in f:
        counter = defaultdict(int)
        for ch in line:
            if ch.isalpha(): counter[ch] += 1
        max_count = max(counter.values())
        max_chars = sorted(k for k, v in counter.items() if v == max_count)
        print(f"{''.join(max_chars)} {max_count}")