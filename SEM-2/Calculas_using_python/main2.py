import sympy as sp
import matplotlib.pyplot as plt
import numpy as np

# Define a symbol for the variable
x = sp.symbols('x')

# Define the quadratic function: f(x) = x^2
f_x = x**2

f_prime_x = sp.diff(f_x, x)

F_x = sp.integrate(f_x, x)

# Display the results
print("Original function: f(x) =", f_x)
print("Derivative: f'(x) =", f_prime_x)
print("Integral: F(x) =", F_x)

# Convert the symbolic expressions to Python functions
f_x_func = sp.lambdify(x, f_x, 'numpy')
f_prime_x_func = sp.lambdify(x, f_prime_x, 'numpy')
F_x_func = sp.lambdify(x, F_x, 'numpy')

# Generate data for the plots
x_vals = np.linspace(-5, 5, 100)
print(x_vals)
y_vals = f_x_func(x_vals)
y_prime_vals = f_prime_x_func(x_vals)
Y_vals = F_x_func(x_vals)

# Plotting
plt.figure(figsize=(12, 4))

# Plot the original function
plt.subplot(1, 3, 1)
plt.plot(x_vals, y_vals, label='f(x) = x^2')
plt.xlabel('x')
plt.ylabel('f(x)')
plt.title('Quadratic Function')
plt.legend()

# Plot the derivative
plt.subplot(1, 3, 2)
plt.plot(x_vals, y_prime_vals, label="f'(x)")
plt.xlabel('x')
plt.ylabel("f'(x)")
plt.title('Derivative')
plt.legend()

# Plot the integral
plt.subplot(1, 3, 3)
plt.plot(x_vals, Y_vals, label="F(x)")
plt.xlabel('x')
plt.ylabel('F(x)')
plt.title('Integral')
plt.legend()

plt.tight_layout()
plt.show()
