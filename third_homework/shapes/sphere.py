import math
from shapes import shape


class Sphere(shape.Shape):

    def __init__(self, radius, density):
        super(Sphere, self).__init__(density)
        self.radius = radius

    @property
    def surface_area(self):
        return 4 * math.pi * self.radius ** 2

    def __str__(self):
        return f'[SPHERE] radius = {self.radius} | density = {self.density} | surface_area = {self.surface_area}'


__all__ = ['Sphere']
