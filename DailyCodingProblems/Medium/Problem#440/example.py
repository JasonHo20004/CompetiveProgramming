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
