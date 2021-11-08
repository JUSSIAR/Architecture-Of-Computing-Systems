from .transport import Auto
from .transport import Car
from .transport import Bus
from .transport import Truck
from .transport import Converter


def getContainer(file) -> list:
    return list(map(getItem, file.readlines()[1::]))


def getItem(string: str) -> Car or Bus or Truck or Auto:
    capacity, spending, auto_type, own_value = string.strip().split()

    auto_type = Converter.getName(int(auto_type) - 1)
    if auto_type == 'Car':
        return Car(int(capacity), float(spending), int(own_value))
    if auto_type == 'Bus':
        return Bus(int(capacity), float(spending), int(own_value))
    if auto_type == 'Truck':
        return Truck(int(capacity), float(spending), int(own_value))
    return Auto(0, 1, 3)
