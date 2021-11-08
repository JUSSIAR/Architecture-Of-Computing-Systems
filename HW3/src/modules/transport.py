class Converter:
    @staticmethod
    def getName(type_id: int) -> str:
        return ('Car', 'Bus', 'Truck', 'Invalid')[type_id]

    @staticmethod
    def getTypeId(name: str) -> int:
        return {'Car': 0, 'Bus': 1, 'Truck': 2}[name]


class Auto:
    def __init__(self, capacity, spending, auto_id):
        self._capacity = capacity
        self._spending = spending
        self._auto_id = auto_id

    def distance(self) -> float:
        return 100.0 * self._capacity / self._spending

    def __str__(self) -> str:
        return Converter.getName(self._auto_id) + ' max distance = ' + str(self.distance())

    def __lt__(self, other) -> bool:
        return self.distance() < other.distance()


class Car(Auto):
    def __init__(self, capacity, spending, speed):
        super().__init__(capacity, spending, Converter.getTypeId('Car'))
        self._speed = speed


class Bus(Auto):
    def __init__(self, capacity, spending, passangers):
        super().__init__(capacity, spending, Converter.getTypeId('Bus'))
        self._passangers = passangers


class Truck(Auto):
    def __init__(self, capacity, spending, weight):
        super().__init__(capacity, spending, Converter.getTypeId('Truck'))
        self._weight = weight
