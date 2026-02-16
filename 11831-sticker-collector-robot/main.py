import sys


def main():
    NORMAL = '.'
    STICKER = '*'
    PILLAR = '#'
    ORS = ['N', 'L', 'S', 'O']
    MOVES = [(-1, 0), (0, 1), (1, 0), (0, -1)]
    in_iter = iter(sys.stdin.read().split())
    while True:
        N, M, S = next(in_iter), next(in_iter), next(in_iter)
        N, M, S = int(N), int(M), int(S)
        if N == 0 and M == 0 and S == 0:
            break
        grid = [list(next(in_iter)) for _ in range(N)]
        r, c = next((r, c) for r in range(N) for c in range(M) if grid[r][c] in ORS)
        o = next(i for i, o in enumerate(ORS) if grid[r][c] == o)
        instructions = next(in_iter)
        ans = 0
        for instr in instructions:
            if instr == 'D':
                o = (o + 1) % len(ORS)
            elif instr == 'E':
                o = (o - 1) % len(ORS)
            else:
                rr, cc = MOVES[o]
                nr, nc = r + rr, c + cc
                oob = nr < 0 or nr >= N or nc < 0 or nc >= M
                if oob or grid[nr][nc] == PILLAR:
                    continue
                if grid[nr][nc] == STICKER:
                    ans += 1
                    grid[nr][nc] = NORMAL
                r, c = nr, nc
        print(ans)


if __name__ == "__main__":
    main()

