def last_word(input):
    ret = ""
    for c in input:
        if len(ret) == 0:
            ret += c
            continue
        left = c + ret
        right = ret + c
        ret = max(left, right)
    return ret.strip()


def solve(fname):
    with open(fname, 'r') as f:
        lines = f.readlines()
        N = int(lines[0])
        sol = ""
        for i in xrange(1, N + 1):
            sol += "Case #%d: %s\n" % (i, last_word(lines[i]))
        print sol


if __name__ == "__main__":
    import sys

    solve(sys.argv[1])
