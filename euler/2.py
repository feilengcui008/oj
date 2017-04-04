#!/usr/bin/env python
# -*- coding: utf-8 -*-

def sum_of_even_valued_terms(n):
    i, j, s = 0, 1, 0
    while j <= n:
        if j % 2 == 0:
            s += j
        t = j
        j = i + j
        i = t
    return s
    
print sum_of_even_valued_terms(4000000)
