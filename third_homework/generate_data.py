#!/usr/bin/python

import random
import sys


def generate_data(n):
    shapes = [0, 1, 2]
    sys.stdout.write('m\n')
    for i in range(n):
        shape = random.choice(shapes)
        density = random.random() * 100

        if shape == 0 or shape == 2:
            side = random.randint(0, 100)
            sys.stdout.write(f'{shape} {side} {density}\n')

        if shape == 1:
            a, b, c = [random.randint(0, 100) for _ in range(3)]
            sys.stdout.write(f'{shape} {a} {b} {c} {density}\n')


if __name__ == '__main__':
    generate_data(int(sys.argv[1]))
