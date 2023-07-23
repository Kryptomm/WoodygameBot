import random

p = 0.5

def generateSample():
    i = 0
    while random.random() > p:
        i += 1  
        
    return 0.5 * 0.5**i


samples = 100
summe = 0
for i in range(0, samples):
    summe += generateSample()
summe = summe / samples

erg = 1 / (summe)

print(erg)