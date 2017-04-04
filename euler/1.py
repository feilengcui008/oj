#!/usr/bin/env python
# -*- coding: utf-8 -*-

def sum_of_multiples_of_m_or_n_below_k(m, n, k):
    s = 0
    for i in range(k):
        if i % m == 0 or i % n == 0:
            s += i
    return s
    
print sum_of_multiples_of_m_or_n_below_k(3, 5, 1000)
