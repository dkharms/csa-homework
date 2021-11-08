from shapes import shape


class Parallelepiped(shape.Shape):
    def __init__(self, width, length, height, density):
        super(Parallelepiped, self).__init__(density)
        self.width = width
        self.length = length
        self.height = height

    @property
    def surface_area(self):
        return 2 * (self.height * self.length + self.width * self.length + self.width * self.height)

    def __str__(self):
        return f'[PARALLELEPIPED] width = {self.width} | length = {self.length} | ' \
               f'height = {self.height} | density = {self.density} | surface_area = {self.surface_area}'
