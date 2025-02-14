nr_of_lines = int(input())

for _ in range(nr_of_lines):
    line = input()
    hours, mins = [int(ch) for ch in line.split(':')]
    
    if mins > 0:
        mins = 60 - mins
        
        if hours < 11:
            hours = 12 - hours - 1
        elif hours == 11:
            hours = 12
        else:
            hours -= 1
    else:
        if hours < 12:
            hours = 12 - hours
    
    print("{:02d}:{:02d}".format(hours, mins))