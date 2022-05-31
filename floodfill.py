u = 8
v = 8

def Flood_fillingfn(S, a, b, Old_C, New_C):
    if (a < 0 or a >= u or b < 0 or
            b >= v or S[a][b] != Old_C or
            S[a][b] == New_C):
        return

    S[a][b] = New_C
    Flood_fillingfn(S, a + 1, b, Old_C, New_C)
    Flood_fillingfn(S, a - 1, b, Old_C, New_C)
    Flood_fillingfn(S, a, b + 1, Old_C, New_C)
    Flood_fillingfn(S, a, b - 1, Old_C, New_C)

def Flood_filling(S, a, b, New_C):
    Old_C = S[a][b]
    if (Old_C == New_C):
        return
    Flood_fillingfn(S, a, b, Old_C, New_C)
S = [[1, 1, 1, 0, 1, 1, 0, 1],
     [1, 0, 1, 1, 0, 1, 0, 0],
     [1, 3, 0, 1, 1, 0, 1, 1],
     [1, 2, 3, 2, 2, 0, 1, 0],
     [1, 1, 1, 2, 1, 0, 2, 0],
     [1, 0, 1, 2, 2, 3, 2, 0],
     [1, 1, 0, 1, 1, 2, 3, 1],
     [1, 2, 3, 1, 0, 2, 2, 1]]

a = 4
b = 4
New_C = 4
Flood_filling(S, a, b, New_C)

print("Updated screen after call to floodFill:")
for x in range(u):
    for y in range(v):
        print(S[x][y], end=' ')
    print()
