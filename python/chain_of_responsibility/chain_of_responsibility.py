from abc import ABC


class SumHandler(ABC):
    def __init__(self, next_handler=None):
        self._next_handler: SumHandler = next_handler

    def sum(self, a: int, b: int) -> int:
        raise NotImplementedError()


class PositiveSumHandler(SumHandler):
    def sum(self, a: int, b: int) -> int:
        if a > 0 and b > 0:
            return a + b
        if self._next_handler is not None:
            return self._next_handler.sum(a, b)
        else:
            return 0


class StrangeSumHanfler(SumHandler):

    def sum(self, a: int, b: int) -> int:
        return 42


def main():
    handler3 = StrangeSumHanfler()
    handler2 = PositiveSumHandler(handler3)
    handler1 = PositiveSumHandler(handler2)
    print(handler1.sum(-1, 3))
    print(handler1.sum(3, 3))


if __name__ == '__main__':
    main()
