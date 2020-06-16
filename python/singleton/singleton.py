class Pool:
    _instance = None

    def __init__(self):
        self.i = 0

    @staticmethod
    def get_instance():
        if Pool._instance is None:
            Pool._instance = Pool()
        return Pool._instance

    def inc(self):
        self.i += 1

    def __str__(self):
        return f"Current value: {str(self.i)}"


if __name__ == '__main__':
    Pool.get_instance().inc()
    print(Pool.get_instance())
    Pool.get_instance().inc()
    Pool.get_instance().inc()
    print(Pool.get_instance())
