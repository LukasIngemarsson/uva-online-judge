

def main():
    while True:
        try:
            line = input() + '.'
            cnt = 0
            last_was_alpha = False
            for ch in line:
                if ch.isalpha():
                    last_was_alpha = True
                else:
                    if last_was_alpha:
                        cnt += 1
                    last_was_alpha = False
            print(cnt)
        except:
            break


if __name__ == "__main__":
    main()
