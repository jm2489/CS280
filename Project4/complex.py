class Complex:
    def __init__(self, num=0, den=1):
        self.num = num
        self.den = den

    def __add__(self, other):
        if isinstance(other, (int, float)):
            return Complex(self.num + other, self.den)
        elif isinstance(other, Complex):
            return Complex(self.num + other.num, self.den + other.den)
        else:
            raise TypeError

    def __sub__(self, other):
        if isinstance(other, (int, float)):
            return Complex(self.num - other, self.den)
        elif isinstance(other, Complex):
            return Complex(self.num - other.num, self.den - other.den)
        else:
            raise TypeError

    def __mul__(self, other):
        if isinstance(other, (int, float)):
            return Complex(self.num * other, self.den * other)
        elif isinstance(other, Complex):
            return Complex(self.num * other.num - self.den * other.den,
                           self.num * other.den + self.den * other.num)
        else:
            raise TypeError

    def __truediv__(self, other):
        if isinstance(other, (int, float)):
            return Complex(self.num / other, self.den / other)
        elif isinstance(other, Complex):
            denom = other.num ** 2 + other.den ** 2
            return Complex((self.num * other.num + self.den * other.den) / denom,
                           (self.den * other.num - self.num * other.den) / denom)
        else:
            raise TypeError

    def __str__(self):
        return f"({self.num:.2f} + {self.den:.2f}j)"

if __name__ == "__main__":
    a = Complex(2.0, 3.0)
    b = Complex(1.0, -1.0)

    print(f"{a} + {b} = {a + b}")
    print(f"{a} - {b} = {a - b}")
    print(f"{a} * {b} = {a * b}")
    print(f"{a} / {b} = {a / b}")
