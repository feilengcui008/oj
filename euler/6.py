#!/usr/bin/env python
# -*- coding: utf-8 -*-

def sum_square_difference(n):
    return pow(sum([x for x in range(1, n + 1)]), 2) - sum([x*x for x in range(1, n + 1)])

print sum_square_difference(10)
print sum_square_difference(100)

