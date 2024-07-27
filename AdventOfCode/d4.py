with open("input.txt") as f:
    d = f.read().split("\n")
    s = 0
    s2 = 0
    for pair in d:
        a, b = pair.split(",")
        a = [int(i) for i in a.split("-")]
        b = [int(i) for i in b.split("-")]
        a = set(range(a[0], a[1] + 1))
        b = set(range(b[0], b[1] + 1))
        s += a.issubset(b) or a.issuperset(b)
        s2 += bool(a & b)
    print(s)
    print(s2)