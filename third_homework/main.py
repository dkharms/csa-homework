import sys
import random
import argparse

from shapes import *
from container import Container


def setup_arg_parser():
    options = {'input': ('-i', '--input'), 'output': ('-o', '--output')}

    parser = argparse.ArgumentParser(description='Storing shapes in container')
    parser.add_argument(*options['input'], dest='input', required=True, help='Input file which contains shapes data')
    parser.add_argument(*options['output'], dest='output', required=True, help='Output file which contains shapes data')

    return parser


def create_shape_random():
    cls_shapes = [Sphere, Parallelepiped, Tetrahedron]
    shape_args = {'Sphere': [random.random() for _ in range(2)],
                  'Parallelepiped': [random.random() for _ in range(4)],
                  'Tetrahedron': [random.random() for _ in range(2)]}
    cls_shape = random.choice(cls_shapes)

    return cls_shape(*shape_args[cls_shape.__name__])


def create_shape_from_file(line: str = None) -> Shape:
    cls_shapes = [Sphere, Parallelepiped, Tetrahedron]
    shape_type, *shape_args = line.split()

    return cls_shapes[int(shape_type)](*map(float, shape_args))


def fill_container_random(shape_container: Container, number: int) -> Container:
    for i in range(number):
        shape_container.push(create_shape_random())

    return shape_container


def create_container(file_name: str) -> Container:
    shape_container = Container()
    with open(file_name, 'r') as file:
        creation_type, *number = next(file).split()

    if creation_type[0] == 'm':
        return fill_container_from_file(file_name, shape_container)

    return fill_container_random(shape_container, int(*number))


def fill_container_from_file(file_name: str, shape_container: Container) -> Container:
    with open(file_name, 'r') as file:
        _ = next(file)
        for line in file:
            shape_container.push(create_shape_from_file(line))

    return shape_container


def write_container_data_to_file(file_name: str, shape_container: Container) -> None:
    with open(file_name, 'w') as file:
        for shape in shape_container:
            file.write(f'{shape}\n')


if __name__ == '__main__':
    parser = setup_arg_parser()
    args = parser.parse_args(sys.argv[1:])

    shape_container = create_container(args.input)
    shape_container.sort()

    write_container_data_to_file(args.output, shape_container)
