#!/usr/bin/env python
# -*- coding: utf-8 -*-


def solve():
    for i in range(334, 1000):
        for j in range(1, 334):
            for k in range(1, 1000):
                if i+j+k == 1000 and i*i == j*j + k*k:
                    print i, j, k, i*j*k
                    return

solve()
