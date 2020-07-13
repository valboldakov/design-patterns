from abc import ABC


class CaffeineBeverage(ABC):
    def _boil_water(self):
        print("Boiling Water!")

    def _add_components(self):
        raise NotImplementedError()

    def prepare(self):
        self._boil_water()
        self._add_components()


class Tea(CaffeineBeverage):
    def _add_components(self):
        print("Adding Lemons!")


def main():
    tea = Tea()
    tea.prepare()


if __name__ == '__main__':
    main()
