from abc import ABC


class Expression(ABC):
    def interpret(self, s: str) -> bool:
        raise NotImplementedError()


class Digit(Expression):
    def interpret(self, s: str) -> bool:
        return s in [str(i) for i in range(10)]


class Number(Expression):
    def interpret(self, s: str) -> bool:
        if not s:
            return False
        return Digit().interpret(s) or Digit().interpret(s[0]) and Number().interpret(s[1:])


def main():
    num: Number = Number()
    print(num.interpret("10"))
    print(num.interpret(""))
    print(num.interpret("f10"))
    print(num.interpret("10f"))


if __name__ == '__main__':
    main()
