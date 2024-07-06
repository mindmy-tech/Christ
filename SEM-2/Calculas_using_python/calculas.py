from sympy import *

def q1():
    x = Symbol('x')
    expr = (x**2 - 4)
    expr_limit = limit(expr, x , 2)
    print(expr_limit)

def q2():
    x = Symbol('x')
    expr = (x**3 - 4*x) / (2*x**2 + 3*x)
    print(expr)
    expr_limit = limit(expr, x , 0)
    print(expr_limit)

def q3():
    x = Symbol('x')
    expr = (x**3)/ (x + 1)**2
    expr_limit = limit(expr, x , 1)
    print(expr_limit)

def q4():
    x = Symbol('x')
    expr = (x - 2)/ x**2 - 3 * x + 2
    expr_limit = limit(expr, x , 2)
    print(expr_limit)
def q5():
    x = Symbol('x')
    expr = (x - 2)/ x**2 - 3 * x + 2
    expr_limit = limit(expr, x , 2)
    print(expr_limit)


def q5():
    x = Symbol('x')
    expr = (x **2 + 2* x + 1)
    def_eqn = Derivative(expr, x).doit()
    print(def_eqn)
    
def q6():
    x = Symbol('x')
    y = (4 * x**3 - 3*x**2 + 2 * x -1)
    ans = Derivative(y, x).doit()
    print(ans)
    
def q7():
    x = Symbol('x')
    y = (1/4 * x**4 + 1/3 * x**3 + 1/2* x**2)    
    ans = Derivative(y, x).doit()
    print(ans)

def q8():
    x = Symbol('x')
    y = (x + x**1/2 + x**1/3 + x**1/5)
    ans = Derivative(y, x).doit()
    print(ans)

def q9():
    x = Symbol('x')
    y = ((x ** 8)**1/3 - (x ** 7)**1/4 + (x ** 6)**1/5 )
    ans = Derivative(y, x).doit()
    print(ans)

def q10():
    x = Symbol('x')
    y = ()
    ans = Derivative(y, x).doit()
    print(ans)

def q11():
    x = Symbol('x')
    y = (1/(2*x**4)**1/3 - 5)
    ans = Derivative(y, x).doit()
    print(ans)

q9()