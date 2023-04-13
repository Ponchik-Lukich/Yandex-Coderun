def solve_equations(a, b, c):
    for x in range(1, a):
        for y in range(1, x):
            z = a - x - y
            if z <= y:
                break
            if (x**2 + y**2 + z**2 == b) and (x**3 + y**3 + z**3 == c):
                return x, y, z


n = int(input())
x, y, z = map(int, input().split())
a_value = int(n*(n+1)/2 - x)
b_value = int(n*(n+1)*(2*n+1)/6 - y)
c_value = int(n*n*(n+1)*(n+1)/4 - z)

r1, r2, r3 = solve_equations(a_value, b_value, c_value)
print(r1, r2, r3)