import sys
from collections import deque

with sys.stdin as f:
    lines = deque([int(l.strip()) for l in f.readlines()])
 
dataset_cnt = 1
while True:
    file_size = lines.popleft()
    if file_size == 0:
        break
    print(f"Output for data set {dataset_cnt}, {file_size} bytes:")
    acc_bytes, window_sum, second_cnt = 0, 0, 0
    while acc_bytes < file_size:
        b = lines.popleft()
        acc_bytes += b
        window_sum += b
        second_cnt += 1
        if second_cnt % 5 == 0:
            print(f"   Time remaining: ", end="")
            print("stalled" if window_sum == 0 else f"{((file_size - acc_bytes) * 5 + window_sum - 1) // window_sum} seconds")
            window_sum = 0
    
    print(f"Total time: {second_cnt} seconds\n")
    dataset_cnt += 1