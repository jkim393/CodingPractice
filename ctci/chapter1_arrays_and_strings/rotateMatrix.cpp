#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void rotateMatrix(vector<vector<int>> & matrix,int N){
	for(int x=0; x< N/2; x++){ //number of layers 2
		for(int y=x; y<N-1-x; y++){ //positions 0~3, 0~1
			swap(matrix[x][y],matrix[N-1-y][x]);//top switch with left
			swap(matrix[x][y],matrix[y][N-1-x]);//top switch with right
			swap(matrix[y][N-1-x],matrix[N-1-x][N-1-y]);//
		}
	}	
}

// 0,0 with N-1,0   	//i,j      N-1-j,  i
// 0,0 with 0,N-1	 	//i,j      j,      N-1-i
// 0,N-1 with N-1, N-1 //i,N-1-i  N-1-i   N-1-j

// 0,1 with N-2,0      //i,j
// 0,1 with 1,N-1
// 1,N-1 with N-1, N-2

// 0,2 with N-3,0
// 0,2 with 2, N-1
// 2,N-1 with N-1, N-3

//vector version
int main(){
	int N = 4;
	//cin >> N;
	//vector<vector<int>> matrix(N, vector<int>(N,0));
	
	vector<vector<int>> matrix { {1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16} };

	rotateMatrix(matrix,N);

	for(auto row: matrix){
		for(auto val: row){
			cout << val << " ";
		}
		cout << "\n";
	}
	
	return 0;
}


//solution from someone https://github.com/careercup/CtCI-6th-Edition-cpp/blob/master/Ch%201.Arrays%20And%20Strings/7.Rotate_matrix/7.rotate_matrix.cpp
void helper_transpose(int **matrix, int N)
{
	for( int i = 0; i < N; ++i ) {
		for( int j = i+1; j < N; ++j ) {
			if ( i != j ) {
				std::swap(matrix[i][j], matrix[j][i]);
			}
		}
	}
}

void helper_reverse( int * row, int N ) {
	for ( int i = 0; i < N/2; ++i ) {
		std::swap(row[i], row[N-i-1]);
	}
}

void rotate1(int ** matrix, int N) {
	//transpose matrix
	helper_transpose(matrix, N);
	// reverse each row
	for ( int i = 0; i < N; ++i ) {
		helper_reverse(matrix[i], N);
	}
}


void rotate2( int ** matrix, int N ) {
	for( int i = 0; i < N/2; ++i ) {
		for( int j = i; j < N-i-1; ++j ) {
				int temp = matrix[i][j];
				matrix[i][j] = matrix[j][N-i-1];
				matrix[j][N-i-1] = matrix[N-i-1][N-j-1];
				matrix[N-i-1][N-j-1]= matrix[N-j-1][i];
				matrix[N-j-1][i] = temp;
		}
	}
}

void printMatrix( int ** matrix, int N) {
	for ( int i = 0; i < N; ++i ) {
		for( int j = 0; j < N; ++j ) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}


int main() {
	int N;
	std::cout << "Enter N for NxN matrix:";
	std::cin >> N;
	int ** matrix = new int*[N];
	for ( int i = 0; i < N; ++i ) {
		matrix[i] = new int[N];
	}

	for ( int i = 0; i < N; ++i) {
		for ( int j = 0; j < N; ++j ) {
			std::cin >> matrix[i][j];
		}
	}

	std::cout << "Rotated matrix by 90 (clockwise):\n";
	rotate1(matrix, N);
	printMatrix(matrix, N);

	std::cout << "Rotated matrix again by 90(anticlockwise):\n";
	rotate2(matrix, N);
	printMatrix(matrix, N);
	return 0;
}