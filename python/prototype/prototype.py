from abc import ABC


class Prototype(ABC):
    def clone(self) -> "Prototype":
        raise NotImplementedError()


class Shape(Prototype):
    def __init__(self, x: int, y: int):
        self._x = x
        self._y = y

    def clone(self) -> "Prototype":
        return Shape(self._x, self._y)

    def show(self):
        print(self._x, self._y)


def main():
    shape1 = Shape(2, 3)
    shape2: Shape = shape1.clone()
    shape1.show()
    shape2.show()


if __name__ == '__main__':
    main()
