#!/usr/bin/env python
# -*- coding: utf-8 -*-

def largetest_prime_factor(n):
    max_prime = -1
    while n > max_prime:
        t = n
        for i in xrange(2, n / 2 + 1):
            if n % i == 0:
                t = i
                break
        n = n / t
        if is_prime(t) and t > max_prime:
            max_prime = t
    return max_prime

def is_prime(n):
    t = 2
    while t < (n / 2 + 1):
        if n % t == 0:
            break
        t += 1
    return t > (n / 2)

print is_prime(3)
print is_prime(4)
print largetest_prime_factor(13195)
print largetest_prime_factor(600851475143)

    
    
