import random

g = open('Test1.txt', 'w')
g.write('1\n1000\n')

for i in range(0, 1000):
    x = random.randint(1, 1000)
    g.write(str(x) + '\n')
    # g.write(str(1) + '\n')

g.close()