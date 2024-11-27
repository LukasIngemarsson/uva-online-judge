import sys
import string
from collections import deque

alphabet = string.ascii_lowercase
word_to_pos = {let: i + 1 for i, let in enumerate(alphabet)}
Q = deque([let for let in alphabet])
count = len(alphabet) + 1
while Q:
    w = Q.popleft()
    if len(w) >= 5: continue
    for i in range(word_to_pos[w[-1]], len(alphabet)):
        Q.append(w + alphabet[i])
        word_to_pos[Q[-1]] = count
        count += 1

with sys.stdin as f:
    for line in f:
        w = line.strip()
        print(word_to_pos[w] if w in word_to_pos else 0)