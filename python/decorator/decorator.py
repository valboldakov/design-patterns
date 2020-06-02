from abc import ABC


class IBeverage(ABC):
    def get_cost(self):
        pass


class Coffee(IBeverage):
    def __init__(self):
        self._cost = 2.0

    def get_cost(self):
        return self._cost


class BeverageDecorator(IBeverage, ABC):
    def __init__(self, beverage):
        self._beverage = beverage


class Mocha(BeverageDecorator):
    def __init__(self, beverage):
        super(Mocha, self).__init__(beverage)

    def get_cost(self):
        return self._beverage.get_cost() + 0.2


if __name__ == '__main__':
    coffee = Coffee()
    coffee_with_mocha = Mocha(coffee)
    print(coffee_with_mocha.get_cost())
    coffee_with_mocha = Mocha(coffee_with_mocha)
    print(coffee_with_mocha.get_cost())
