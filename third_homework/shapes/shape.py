import abc


class Shape(abc.ABC):

    def __init__(self, density):
        self.density = density

    @abc.abstractmethod
    def surface_area(self):
        pass
