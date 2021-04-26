#include <iostream>
using namespace std;
#define N 9
void printsudoku(int arr[N][N]){
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++)
			cout << arr[i][j] << " ";
		cout << endl;
	}
}

bool check(int kotak[N][N], int row,
	int col, int num){

	for (int x = 0; x <= 8; x++) {
		if (kotak[row][x] == num)
			return false;
	}
		
	for (int x = 0; x <= 8; x++) {
		if (kotak[x][col] == num)
			return false;
	}
	
	int nRow = row - row % 3,
		nCol = col - col % 3;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (kotak[i + nRow][j +
				nCol] == num) {
				return false;
			}	
		}
	}
		
	return true;
}

bool Sudoku(int kotak[N][N], int row, int col){
	if (row == N - 1 && col == N)
		return true;

	if (col == N) {
		row++;
		col = 0;
	}

	if (kotak[row][col] > 0) {
		return Sudoku(kotak, row, col + 1);
	}

	for (int num = 1; num <= N; num++){

		if (check(kotak, row, col, num)){
			kotak[row][col] = num;
			if (Sudoku(kotak, row, col + 1))
				return true;
		}
		kotak[row][col] = 0;
	}
	return false;
}

int main(){
	int kotak[N][N] = { { 5, 3, 0, 0, 7, 0, 0, 0, 0 },
					   { 6, 0, 0, 1, 9, 5, 0, 0, 0 },
					   { 0, 9, 8, 0, 0, 0, 0, 6, 0 },
					   { 8, 0, 0, 0, 6, 0, 0, 0, 3 },
					   { 4, 0, 0, 8, 0, 3, 0, 0, 1 },
					   { 7, 0, 0, 0, 2, 0, 0, 0, 6 },
					   { 0, 6, 0, 0, 0, 0, 2, 8, 0 },
					   { 0, 0, 0, 4, 1, 9, 0, 0, 5 },
					   { 0, 0, 0, 0, 8, 0, 0, 7, 9 } };

	if (Sudoku(kotak, 0, 0))
		printsudoku(kotak);
	else
		cout << "no solution" << endl;

	return 0;
}