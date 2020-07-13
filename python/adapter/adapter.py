from abc import ABC


class Duck(ABC):
    def fly(self):
        print("Flying!")

    def quack(self):
        print("Quacking!")


class ITurkey(ABC):
    def fly(self):
        pass

    def gobble(self):
        pass


class Turkey(Duck):
    def fly(self):
        super().fly()

    def quack(self):
        print("Gobbling!")


class TurkeyAdapter(ITurkey):
    def __init__(self, duck: Duck):
        self._duck = duck

    def fly(self):
        self._duck.fly()

    def gobble(self):
        self._duck.quack()


def main():
    turkey = Turkey()
    adapter = TurkeyAdapter(turkey)
    adapter.fly()
    adapter.gobble()


if __name__ == '__main__':
    main()
