print reduce(lambda y,x: y + (1 if str(x) == str(x)[::-1] else 0), range(0,999999+1), 0 )
