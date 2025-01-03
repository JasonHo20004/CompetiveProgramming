class Animal:
   def make_sound(self):
        raise NotImplementedError("Subclass must implement abstract method")
   
class Dog(Animal):
    def make_sound(self):
        return "woof"
    
class Cat(Animal):
    def make_sound(self):
        return "meow"
    
def make_sound(animal: Animal):
    print(animal.make_sound())

dog = Dog()
cat = Cat()

make_sound(dog)
make_sound(cat)
 