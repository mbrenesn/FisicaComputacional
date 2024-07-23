#!/usr/bin/env python3

# Los diccionarios son mutables
d = {'name': 'Marlon', 'age': 21}

print(d['name']) # Marlon
print(d['age']) # 21

def func(dd):
    dd['age'] = 20
    return dd

print(func(d))
