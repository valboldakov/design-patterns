class Visitor:
    def process_elemen(self, element: "Element"):
        print("Processing element!")


class Element:
    def accept_visitor(self, visitor: Visitor):
        visitor.process_elemen(self)


def main():
    element = Element()
    visitor = Visitor()
    element.accept_visitor(visitor)


if __name__ == '__main__':
    main()
