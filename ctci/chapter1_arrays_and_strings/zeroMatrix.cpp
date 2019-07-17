#include <iostream>
#include <vector>
using namespace std;
//MxN matrix
//need to consider the first row and first column having 0

void zeroMatrix(vector<vector<int>> & matrix,int M, int N){
	// vector<int> row;
	// vector<int> col;
	bool firstrowzero, firstcolzero = false;

	//checking first column
	for(int x=0; x<M; x++){
		if (matrix[x][0] == 0){
			firstcolzero = true;
		}
	}

	//checking first row
	for(int x=0; x<N; x++){
		if (matrix[0][x] == 0){
			firstrowzero = true;
		}
	}

	for(int x=1; x<M; x++){ 
		for(int y=1; y<N; y++){
			if (matrix[x][y] == 0){
				matrix[x][0] = 0;
				matrix[0][y] = 0;
			}
		}
	}
	//make the row 0
	for(int i=1;i<M;i++){
		if (matrix[i][0]==0){
			for(int j=0;j<N;j++){
				matrix[i][j]=0;
			}
		}
	}
	//make the col 0
	for(int i=1;i<N;i++){
		if (matrix[0][i]==0){
			for(int j=0;j<M;j++){
				matrix[j][i]=0;
			}
		}
	}
	if(firstrowzero){
		for(int j=0;j<N;j++){
			matrix[0][j]=0;
		}
	}
	if(firstcolzero){
		for(int j=0;j<M;j++){
			matrix[j][0]=0;
		}
	}


}

int main(){
	int M = 4;
	int N = 4;
	vector<vector<int>> matrix { {0,2,3,4}, {5,6,7,8}, {9,10,0,12}, {13,14,15,16} };

	zeroMatrix(matrix,M,N);

	for(auto row: matrix){
		for(auto val: row){
			cout << val << " ";
		}
		cout << "\n";
	}
	
	return 0;
}