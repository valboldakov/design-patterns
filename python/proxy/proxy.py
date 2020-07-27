from abc import ABC


class IPhone(ABC):
    def call(self):
        raise NotImplementedError()


class Phone(IPhone):
    def call(self):
        print("Calling!")


class ProxyPhone(IPhone):
    def __init__(self):
        self._phone = None

    def call(self):
        if self._phone is None:
            print("Creating phone!")
            self._phone = Phone()
        self._phone.call()


def main():
    phone = ProxyPhone()
    phone.call()
    phone.call()


if __name__ == '__main__':
    main()
