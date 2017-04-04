#!/usr/bin/env python
# -*- coding: utf-8 -*-

def smallest_miltiple(n):
    d = dict()
    s = 1
    for i in range(2, n + 1):
        t = max_common_factor(s, i) 
        s = s * (i / t)
    return s

def max_common_factor(m, n):
    if m > n:
        return max_common_factor(n, m)
    while m != 0:
        t = n - m
        if t > m:
            n = t
        else:
            n = m
            m = t
    return n

print smallest_miltiple(10)
print smallest_miltiple(20)
