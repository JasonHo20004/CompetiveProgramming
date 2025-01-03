from functools import singledispatch

@singledispatch
def printValue(value):
    print("Unsupported type")

@printValue.register
def _(value : int):
    print(f"Interger: {value}")


@printValue.register
def _(value : float):
    print(f"float: {value}")

@printValue.register
def _(value: str):
    print(f"String: {value}")


printValue(12)
printValue(3.44)
printValue("ABC")
printValue([1, 2, 3]) #Unsupported type

from typing import TypeVar, List

T = TypeVar('T')
def print_list(items: list[T]) -> None:
    for item in items:
        print(item, end=" ")
    print()

print_list([1, 2, 3])
print_list([1.1, 2.2, 3.3])
print_list(["A", "B", "C"])