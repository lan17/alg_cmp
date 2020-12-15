import re

RULE_REGEX = re.compile('([0-9]*)\-([0-9]*) ([a-z]): ([a-z]+)')


class Policy:
    def __init__(self, low, high, c):
        self.low = low
        self.high = high
        self.c = c


def is_valid(password: str, policy: Policy):
    cnt = 0
    for i in range(len(password)):
        c = password[i]
        if c == policy.c:
            cnt += 1
    if policy.low <= cnt <= policy.high:
        return True
    return False


def is_valid_day_2(password: str, policy: Policy):
    return (password[policy.low - 1] == policy.c or password[policy.high - 1] == policy.c) and not (
            password[policy.low - 1] == policy.c and password[policy.high - 1] == policy.c
    )


def main():
    with open('day2.in') as file:
        count = 0
        count_day_2 = 0
        for line in file.readlines():
            m = RULE_REGEX.match(line.strip())
            if m:
                policy = Policy(int(m.group(1)), int(m.group(2)), m.group(3))
                if is_valid(m.group(4), policy):
                    count += 1
                if is_valid_day_2(m.group(4), policy):
                    count_day_2 += 1
        print(count)
        print(count_day_2)


if __name__ == '__main__':
    main()
