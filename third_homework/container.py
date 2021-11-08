import random
from shapes import shape


class Container(object):
    def __init__(self):
        self.container = []

    def push(self, shape: shape.Shape):
        self.container.append(shape)

    def sort(self):
        self.container = self._quicksort(self.container)

    def _quicksort(self, container):
        if len(container) <= 1:
            return container
        else:
            q = random.choice(container)
            smaller_shapes = []
            greater_shapes = []
            equal_shapes = []
            for container_shape in container:
                if container_shape.surface_area < q.surface_area:
                    smaller_shapes.append(container_shape)
                elif container_shape.surface_area > q.surface_area:
                    greater_shapes.append(container_shape)
                else:
                    equal_shapes.append(container_shape)
            return self._quicksort(smaller_shapes) + equal_shapes + self._quicksort(greater_shapes)

    def __iter__(self):
        for shape_container in self.container:
            yield shape_container
