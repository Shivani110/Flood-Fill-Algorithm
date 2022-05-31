#include<iostream>
using namespace std;
#define u 8
#define v 8

void Flood_fillingfn(int S[][v], int a, int b, int Old_C, int New_C)
{
	if (a < 0 || a >= u || b < 0 || b >= v)
		return;
	if (S[a][b] != Old_C)
		return;
	if (S[a][b] == New_C)
		return;
	S[a][b] = New_C;

	Flood_fillingfn(S, a+1, b, Old_C, New_C);
	Flood_fillingfn(S, a-1, b, Old_C, New_C);
	Flood_fillingfn(S, a, b+1, Old_C, New_C);
	Flood_fillingfn(S, a, b-1, Old_C, New_C);
}

void Flood_filling(int S[][v], int a, int b, int New_C)
{
	int Old_C = S[a][b];
	if(Old_C==New_C) return;
	Flood_fillingfn(S, a, b, Old_C, New_C);
}

int main()
{
	int S[u][v] = {{1, 1, 1, 0, 1, 1, 0, 1},
					{1, 0, 1, 1, 0, 1, 0, 0},
					{1, 3, 0, 1, 1, 0, 1, 1},
					{1, 2, 3, 2, 2, 0, 1, 0},
					{1, 1, 1, 2, 1, 0, 2, 0},
					{1, 0, 1, 2, 2, 3, 2, 0},
					{1, 1, 0, 1, 1, 2, 3, 1},
					{1, 2, 3, 1, 0, 2, 2, 1},
					};
	int a = 4, b = 4, New_C = 4;
	Flood_filling(S, a, b, New_C);

	cout << "Matrix is updated after adding New color : \n";
	for (int x = 0; x < u; x++)
	{
		for (int y = 0; y < v; y++)
		cout << S[x][y] << " ";
		cout << endl;
	}
}


