import numpy as np
import matplotlib.pyplot as plt

# Define the vector components
x = np.linspace(-1, 1, 100)
y = np.sin(np.pi * x)
z = -np.sin(np.pi * y) + np.sqrt(2/3) * np.sin(np.pi * x)

# Create a figure and axis
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

# Plot the vector
ax.quiver(0, 0, 0, y, z, x, length=0.75, color='red', arrow_length_ratio=1.5)

# Set axis labels and limits
ax.set_xlabel('X')
ax.set_ylabel('Y')
ax.set_zlabel('Z')
ax.set_xlim(-1, 1)
ax.set_ylim(-1, 1)
ax.set_zlim(-1, 1)

# Set aspect ratio
ax.set_box_aspect((1, 1, 1))

# Show the plot
plt.show()