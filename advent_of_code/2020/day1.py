with open('day1.in') as file:
    numbers = []
    for line in file.readlines():
        try:
            numbers.append(int(line.strip()))
        except ValueError:
            pass
    print(f'read {len(numbers)} numbers')

    for i in range(len(numbers)):
        for j in range(i + 1, len(numbers)):
            if numbers[i] + numbers[j] == 2020:
                print(i, j, numbers[i], numbers[j], numbers[i] * numbers[j])

    for i in range(len(numbers)):
        for j in range(i + 1, len(numbers)):
            for k in range(j + 1, len(numbers)):
                if numbers[i] + numbers[j] + numbers[k] == 2020:
                    print(i, j, numbers[i], numbers[j], numbers[i] * numbers[j] * numbers[k])
