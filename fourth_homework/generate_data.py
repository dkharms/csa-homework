#!/usr/bin/python

import random
import sys


def generate_data(n):
    shapes = [0, 1, 2]
    with open('input.txt', 'w+') as file:
        file.write(f'm {n}\n')
        for i in range(n):
            shape = random.choice(shapes)
            density = random.random() * 100

            if shape == 0 or shape == 2:
                side = random.randint(0, 100)
                file.write(f'{shape} {side} {density}\n')

            if shape == 1:
                a, b, c = [random.randint(0, 100) for _ in range(3)]
                file.write(f'{shape} {a} {b} {c} {density}\n')


def main():
    if (len(sys.argv) == 1):
        n = int(input())
    else:
        n = int(sys.argv[1])

    generate_data(n)


if __name__ == '__main__':
    main()
