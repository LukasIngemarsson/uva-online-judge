import sys


class AlmostUnionFind:
    def __init__(self, n):
        self.parent = list(range(n)) 
        self.rank = [0] * n
        self.loc = list(range(n))
        self.cnt = [1] * n
        self.sum = list(range(n))

    def find(self, a):
        return self._find(self.loc[a])

    def _find(self, a):
        if self.parent[a] != a:
            self.parent[a] = self._find(self.parent[a])
        return self.parent[a]

    def union(self, a, b):
        a_root = self.find(a)
        b_root = self.find(b)
        if a_root == b_root:
            return
        if self.rank[a_root] <= self.rank[b_root]:
            if self.rank[a_root] == self.rank[b_root]:
                self.rank[b_root] += 1
            self.parent[a_root] = b_root
            self.cnt[b_root] += self.cnt[a_root]
            self.sum[b_root] += self.sum[a_root]
        else:
            self.parent[b_root] = a_root
            self.cnt[a_root] += self.cnt[b_root]
            self.sum[a_root] += self.sum[b_root]

    def move(self, a, b):
        a_root = self.find(a)
        b_root = self.find(b)
        if a_root == b_root:
            return
        self.cnt[a_root] -= 1
        self.sum[a_root] -= a
        self.cnt[b_root] += 1
        self.sum[b_root] += a
        self.loc[a] = b_root

    def get(self, a):
        a_root = self.find(a)
        return self.cnt[a_root], self.sum[a_root]


def main():
    char_iter = iter(sys.stdin.read().split())
    print_buffer = []
    while True:
        try:
            N, M = int(next(char_iter)), int(next(char_iter))
        except StopIteration:
            break
        auf = AlmostUnionFind(N + 1)
        for _ in range(M):
            cmnd, p = int(next(char_iter)), int(next(char_iter))
            if cmnd == 1:
                q = int(next(char_iter))
                auf.union(p, q)
            elif cmnd == 2:
                q = int(next(char_iter))
                auf.move(p, q)
            else:
                cnt, sum_ = auf.get(p)
                print_buffer.append(str(cnt) + ' ' + str(sum_))
    for res in print_buffer:
        sys.stdout.write(res + '\n')


if __name__ == "__main__":
    main()

