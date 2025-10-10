from collections import deque

def main():
    while True:
        n = int(input())
        if n == 0:
            break

        l = int(input())
        adj = [[] for _ in range(n)]
        for _ in range(l):
            a, b = map(int, input().split())
            adj[a].append(b)
            adj[b].append(a)

        def is_bicolorable():
            color = [-1 for _ in range(n)]
            q = deque()
            color[0] = 0
            q.append(0)

            while q:
                u = q.popleft()
                for v in adj[u]:
                    if color[v] == -1:
                        color[v] = 1 - color[u]
                        q.append(v)
                    elif color[u] == color[v]:
                        return False
            return True

        print(f"{'' if is_bicolorable() else 'NOT '}BICOLORABLE.")


if __name__ == "__main__":
    main()

