def sum(a, b):
    """
    Sum of two datatypes or structures. Specifically,
    - If `a` and `b` are primitive datatypes, returns the sum of those types
    - If `a` and `b` are lists or tuples, concatenates the structures
    - If `a` and `b` are np.ndarray, uses the overload of those objects
    - Undefined behaviour for structures that do not support +

    Parameters
    ----------
    a : structure, object or primitive datatype
        First argument
    b : structure, object or primitive datatype
        Second argument

    Returns
    ----------
    output : structure, object or primitive datatype
        Returns the sum operation of `a` and `b`. The type of which depends on the inputs.

    Examples
    ----------
    >>> sum(3, 4)
    7

    >>> sum([1,2], [3, 4])
    [1, 2, 3, 4]
    """
    return a + b

print(help(sum))
