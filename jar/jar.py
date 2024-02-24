class Jar:
    def __init__(self, capacity=12):

        if capacity < 1:
            raise ValueError("Wrong capacity value")
        self._capacity = capacity
        self._n = 0

    def __str__(self):

        return "🍪" * self._n

    def deposit(self, n):

        if self._n + n > self.capacity:
            raise ValueError("Exceeded Cookie Capacity")
        self._n += n

    def withdraw(self, n):

        if self._n - n < n:
            raise ValueError("You are going to withdraw more cookie than the deposit")
        self._n -= n

    @property
    def capacity(self):
        return self._capacity

    @property
    def size(self):
        return self._n


my_jar = Jar()
my_jar.deposit(10)
print(my_jar)
my_jar.withdraw(5)
print(my_jar)
