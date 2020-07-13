from abc import ABC


class IChair(ABC):
    def sit_on(self):
        pass


class ITable(ABC):
    def eat_from(self):
        pass


class NormalChair(IChair):
    def sit_on(self):
        print("Sitting on the chair!")


class NormalTable(ITable):

    def eat_from(self):
        print("Eating from the table!")


class KitchenFacade:
    def __init__(self, table: ITable, chair: IChair):
        self._table = table
        self._chair = chair

    def eat(self):
        self._chair.sit_on()
        self._table.eat_from()


def main():
    facade = KitchenFacade(NormalTable(), NormalChair())
    facade.eat()


if __name__ == '__main__':
    main()
