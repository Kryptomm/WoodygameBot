def test():
    yield (0,0)
    yield (0,1)
    yield (1,0)
    
for (x,y) in test():
    print(x,y)