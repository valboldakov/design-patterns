from abc import ABC


class IFurnitureFactory(ABC):
    def create_table(self):
        pass

    def create_chair(self):
        pass


class IChair(ABC):
    def sit_on(self):
        pass


class ArtChair(IChair):
    def sit_on(self):
        print("Sitting on art chair.")


class ITable(ABC):
    def eat_from(self):
        pass


class ArtTable(ITable):
    def eat_from(self):
        print("Eating from art table.")


class ArtFurnitureFactory(IFurnitureFactory):
    def create_table(self):
        return ArtTable()

    def create_chair(self):
        return ArtChair()


if __name__ == '__main__':
    factory = ArtFurnitureFactory()
    chair = factory.create_chair()
    table = factory.create_table()
    chair.sit_on()
    table.eat_from()
