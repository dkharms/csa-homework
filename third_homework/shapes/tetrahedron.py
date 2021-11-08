import math

from shapes import shape


class Tetrahedron(shape.Shape):
    def __init__(self, side, density):
        super(Tetrahedron, self).__init__(density)
        self.side = side

    @property
    def surface_area(self):
        return self.side ** 2 * math.sqrt(3)

    def __str__(self):
        return f'[TETRAHEDRON] side = {self.side} | density = {self.density} | surface_area = {self.surface_area}'


__all__ = ['Tetrahedron']
