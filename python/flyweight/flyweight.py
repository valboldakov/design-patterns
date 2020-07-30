from random import randrange


class Flyweight:
    def __init__(self, id_: int, texture: int):
        self._id_: int = id_
        self._texture: int = texture

    def get_id(self) -> int:
        return self._id_

    def get_texture(self) -> int:
        return self._texture


class Car:
    def __init__(self, flyweight: Flyweight):
        self._flyweight = flyweight

    def draw(self):
        print(f"Drawing car with texture {self._flyweight.get_texture()} and id={self._flyweight.get_id()}")


class CarFactory:
    def __init__(self):
        self._flyweights = {}

    def create(self, texture_config: int) -> Car:
        if texture_config not in self._flyweights:
            self._flyweights[texture_config] = Flyweight(randrange(0, 1000), texture_config)
        return Car(self._flyweights[texture_config])


def main():
    factory = CarFactory()
    car1: Car = factory.create(3)
    car2: Car = factory.create(3)
    car3: Car = factory.create(1)
    car4: Car = factory.create(3)
    car1.draw()
    car2.draw()
    car3.draw()
    car4.draw()


if __name__ == '__main__':
    main()
