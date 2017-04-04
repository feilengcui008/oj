#!/usr/bin/env python
# -*- coding: utf-8 -*-

def nth_prime(n):
    s = 2
    while n > 0:
        if is_prime(s):
            n -= 1
        if s % 2 == 0:
            s += 1
        else:
            s += 2
    if s % 2 == 0:
        return s - 1
    return s - 2

def is_prime(n):
    t = 2
    while t < (n / 2 + 1):
        if n % t == 0:
            break
        t += 1
    return t > (n / 2)

print nth_prime(6)
print nth_prime(10001)
