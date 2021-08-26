#include <iostream>
using namespace std;

const int rows = 5;
const int cols = 6;

int grid[rows][cols];
bool visited[rows][cols];

int dr[] = { -1,  +1,   0,   0 };
int dc[] = {  0,   0,  -1,  +1 };

void dfs(int r, int c) {
	visited[r][c] = true;
	// for new node in neighbours of (r,c)
	for (int i = 0; i < 4; i++) {
		int R = r + dr[i];
		int C = c + dc[i];
		// Check for the grid boundaries:
		if (R < 0 || C < 0 || R >= rows || C >= cols)
			continue;
		
		if (!visited[R][C])
			dfs(R, C);
	}
	return;
}


int main() {
	// inputs => fill for grid
	dfs(0, 0);
}

/*
ABC
DXE
FGH
*/
