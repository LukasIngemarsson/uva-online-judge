import sys


class Solver:
    _UNVISITED = -1
    _DIRS = ((1, 0), (-1, 0), (0, 1), (0, -1))

    def __init__(self, R: int, C: int) -> None:
        self.R, self.C = R, C
        self.grid = [[0] * C for _ in range(R)]
        self._dp = [[self._UNVISITED] * C for _ in range(R)]

    def is_unvisited(self, r: int, c: int) -> bool:
        return self._dp[r][c] == self._UNVISITED

    def dfs(self, r: int, c: int) -> int:
        if self.is_unvisited(r, c):
            max_depth = 0
            for dr, dc in self._DIRS:
                nr, nc = r + dr, c + dc
                if nr < 0 or nr >= self.R or nc < 0 or nc >= self.C:
                    continue
                if self.grid[nr][nc] >= self.grid[r][c]:
                    continue
                max_depth = max(max_depth, self.dfs(nr, nc))
            self._dp[r][c] = max_depth
        return self._dp[r][c] + 1


def main():
    in_iter = iter(sys.stdin.read().split())
    N = int(next(in_iter))
    for _ in range(N):
        name = next(in_iter)
        solver = Solver(int(next(in_iter)), int(next(in_iter)))
        for i in range(solver.R):
            for j in range(solver.C):
                solver.grid[i][j] = int(next(in_iter))

        ans = 0
        for i in range(solver.R):
            for j in range(solver.C):
                if solver.is_unvisited(i, j):
                    ans = max(ans, solver.dfs(i, j))
        print(f"{name}: {ans}")


if __name__ == "__main__":
    main()

