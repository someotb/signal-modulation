import numpy as np
from matplotlib import pyplot as plt
from numpy._core.numerictypes import int16

with open("../build/output.csv", "r") as f:
    hz = f.readline().strip().split(",")
    sin = {}
    sin_up = {}
    for label in hz:
        sin[label] = np.array(f.readline().strip().split(","), dtype=float)
        sin_up[label] = np.array(f.readline().strip().split(","), dtype=float)
    sin_int16_t = {}
    sin_int16_t_up = {}
    for label in hz:
        sin_int16_t[label] = np.array(f.readline().strip().split(","), dtype=int16)
        sin_int16_t_up[label] = np.array(f.readline().strip().split(","), dtype=int16)

plt.figure(figsize=(12, 8), label="sin(float)")
ax1 = plt.subplot2grid((3, 2), (0, 0))
ax1.plot(sin["1hz"], label="Sin(1hz)", marker="o", markersize=3)
ax1.plot(sin_up["1hz"], label="Sin Up(1hz)", marker="o", markersize=3)
ax1.legend()

ax2 = plt.subplot2grid((3, 2), (0, 1))
ax2.plot(sin["5hz"], label="Sin(5hz)", marker="o", markersize=3)
ax2.plot(sin_up["5hz"], label="Sin Up(5hz)", marker="o", markersize=3)
ax2.legend()

ax3 = plt.subplot2grid((3, 2), (1, 0))
ax3.plot(sin["10hz"], label="Sin(10hz)", marker="o", markersize=3)
ax3.plot(sin_up["10hz"], label="Sin Up(10hz)", marker="o", markersize=3)
ax3.legend()

ax4 = plt.subplot2grid((3, 2), (1, 1))
ax4.plot(sin["20hz"], label="Sin(20hz)", marker="o", markersize=3)
ax4.plot(sin_up["20hz"], label="Sin Up(20hz)", marker="o", markersize=3)
ax4.legend()

ax5 = plt.subplot2grid((3, 2), (2, 0), colspan=2)
ax5.plot(sin["49hz"], label="Sin(49hz)", marker="o", markersize=3)
ax5.plot(sin_up["49hz"], label="Sin Up(49hz)", marker="o", markersize=3)
ax5.legend()

plt.figure(figsize=(12, 8), label="sin(int16_t)")
ax1 = plt.subplot2grid((3, 2), (0, 0))
ax1.plot(sin_int16_t["1hz"], label="Sin(1hz)", marker="o", markersize=3)
ax1.plot(sin_int16_t_up["1hz"], label="Sin Up(1hz)", marker="o", markersize=3)
ax1.legend()

ax2 = plt.subplot2grid((3, 2), (0, 1))
ax2.plot(sin_int16_t["5hz"], label="Sin(5hz)", marker="o", markersize=3)
ax2.plot(sin_int16_t_up["5hz"], label="Sin Up(5hz)", marker="o", markersize=3)
ax2.legend()

ax3 = plt.subplot2grid((3, 2), (1, 0))
ax3.plot(sin_int16_t["10hz"], label="Sin(10hz)", marker="o", markersize=3)
ax3.plot(sin_int16_t_up["10hz"], label="Sin Up(10hz)", marker="o", markersize=3)
ax3.legend()

ax4 = plt.subplot2grid((3, 2), (1, 1))
ax4.plot(sin_int16_t["20hz"], label="Sin(20hz)", marker="o", markersize=3)
ax4.plot(sin_int16_t_up["20hz"], label="Sin Up(20hz)", marker="o", markersize=3)
ax4.legend()

ax5 = plt.subplot2grid((3, 2), (2, 0), colspan=2)
ax5.plot(sin_int16_t["49hz"], label="Sin(49hz)", marker="o", markersize=3)
ax5.plot(sin_int16_t_up["49hz"], label="Sin Up(49hz)", marker="o", markersize=3)
ax5.legend()

plt.show()
