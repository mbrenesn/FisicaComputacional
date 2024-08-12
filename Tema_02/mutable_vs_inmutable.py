#!/usr/bin/env python3

# Esto es una lista y es *mutable*
# Es decir, si se pasa como argumento de una
# función, la función puede modificar su contenido
a = [3, 1, 'foo', 12.0]
def func(l):
    l[0] = 5
    return l
print(func(a)) # [5, 1, 'foo', 12.0]

# Esto es un tuple y es *inmutable*
b = (3, 1, 'foo', 12.0)
print(func(b)) # Runtime error. b es inmutable
