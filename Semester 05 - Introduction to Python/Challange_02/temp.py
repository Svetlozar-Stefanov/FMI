class Temp:
    counter = 0

    def __init__(self) -> None:
        self.kura_mi = 4

    def kur(self):
        print(self.kura_mi)

print(Temp.__dict__)
t = Temp()
print(t.__dict__)