#!/usr/bin/env python
# -*- coding: utf-8 -*-

def largetest_palindrome_product(n):
    for i in range(pow(pow(10, n) - 1, 2), pow(pow(10, n-1), 2) - 1, -1):
        if is_palindrome(i):
            for j in range(pow(10, n-1), pow(10, n)):
                if i % j == 0 and (i / j >= 100) and (i / j <= 999):
                    return i
        
def is_palindrome(n):
    c = 0
    t = n
    while t > 0:
        t /= 10
        c += 1
    for i in range(c / 2):
        if (n / pow(10, i) % 10) != (n / pow(10, c - 1 - i) % 10):
            return False
    return True
        
print largetest_palindrome_product(3)
