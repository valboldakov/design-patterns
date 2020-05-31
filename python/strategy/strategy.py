from abc import ABC


class IFlyBehaviour(ABC):
    def fly(self):
        pass


class LowFlyBehaviour(IFlyBehaviour):
    def fly(self):
        print("Flying low!")


class HighFlyBehaviour(IFlyBehaviour):
    def fly(self):
        print("Flying high!")


class Duck(ABC):
    def __init__(self, fly_behaviour: IFlyBehaviour):
        self._fly_behaviour = fly_behaviour

    def fly(self):
        self._fly_behaviour.fly()


class LittleDuck(Duck):
    def __init__(self):
        super(LittleDuck, self).__init__(LowFlyBehaviour())


class BigDuck(Duck):
    def __init__(self):
        super(BigDuck, self).__init__(HighFlyBehaviour())


if __name__ == '__main__':
    little_duck = LittleDuck()
    little_duck.fly()
    big_duck = BigDuck()
    big_duck.fly()
