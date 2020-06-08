from abc import ABC
from enum import Enum


class Pizza(ABC):
    def bake(self):
        pass


class PizzaType(Enum):
    CHEESE = 1


class CheesePizza(Pizza):
    def bake(self):
        print("Baking cheese pizza")


class PizzaStore(ABC):
    def order_pizza(self, pizza_type: PizzaType) -> Pizza:
        pizza = self._create_pizza(pizza_type)
        pizza.bake()
        return pizza

    def _create_pizza(self, pizza_type: PizzaType) -> Pizza:
        pass


class NYPizzaStore(PizzaStore):
    def _create_pizza(self, pizza_type: PizzaType) -> Pizza:
        if pizza_type == PizzaType.CHEESE:
            return CheesePizza()


if __name__ == '__main__':
    store = NYPizzaStore()
    store.order_pizza(PizzaType.CHEESE)
