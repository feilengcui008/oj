#!/usr/bin/env python
# -*- coding: utf-8 -*-


def is_prime(k):
    if k < 2:
        return False
    for i in range(2, int(pow(k, 0.5))+1):
        if k % i == 0:
            return False
    return True

def sum_of_prime(n):
    s = 0
    for i in range(2, n):
        if is_prime(i):
            s += i
    return s

print sum_of_prime(2000000)
