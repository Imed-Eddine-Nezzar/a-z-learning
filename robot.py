#!/usr/bin/env python3

import itertools as it

class robot(object):
    def __init__(self, x = 0, y = 0):
        self._x = x
        self._y = y

    def go_up(self, steps)    : self._y += steps
    def go_down(self, steps)  : self._y -= steps
    def go_left(self, steps)  : self._x -= steps
    def go_right(self, steps) : self._x += steps

    def __str__(self):
        return "({}, {})".format(self._x, self._y)

    def __repr__(self):
        return self.__str__()

if __name__ == '__main__':
    dummy = robot()
    moves = [dummy.go_right, dummy.go_up, dummy.go_left, dummy.go_down]

    N = int(input())
    for i, move in zip(range(1, N + 1), it.cycle(moves)):
        move(i)

    print(dummy)
