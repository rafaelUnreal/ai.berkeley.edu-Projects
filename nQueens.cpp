#include <iostream>
#include <string>
#include <cstdlib>

//Backtracking based on http://www.geeksforgeeks.org/backtracking-set-3-n-queen-problem/
//Author: Rafael Pinheiro - Sao Paulo
//
using std::cout;
using std::cin; 
using std::endl;

class nQueen{

private:
int N;
int** nQueenMatrix;

public:

nQueen(int value){

  this->N = value;
  allocateMatrix();
  loadMatrix();
  cout<< "Printing board before solution" << endl;
  this->printSolution();
  cout<<"\n";
  solveNQueen(this->nQueenMatrix,0);
}


~nQueen(){


}

void printSolution(){

	for(int i=0;i<this->N; i++){
		for(int j=0;j<this->N;j++){
			cout << "|" <<  nQueenMatrix[i][j];
			
		}
		cout << "|";
		cout << "\n";
	
	}

}

bool is_Safe(int **matrix, int row, int col){

int i,j;
	//Check row on left
	for(i=0;i<col;i++){
		if(matrix[row][i])
		   return false;
	}
	
	//Check Upper Diagonal
	for(i=row,j=col; i>=0 && j >=0; i--,j--){
		if(matrix[i][j])	
		   return false;

	}
	for(i=row,j=col;i<this->N && j>=0; i++,j--){
		if(matrix[i][j])
		  return false;

	}
	


	//Check lower Diagonal
	
	return true;
}

bool solveNQueen(int **matrix,int col){

//Base Case	
if(col >= this->N)
	return true;

for(int i=0;i<this->N; i++){

	if(is_Safe(matrix,i,col)){
		matrix[i][col] = 1;

	
	
	if( solveNQueen(matrix,col+1))
		return true;

	matrix[i][col] = 0;
	}

}

return false;

}

void allocateMatrix(){

int** matrix = new int*[this->N];

for(int i=0; i<N; i++)
	matrix[i] = new int[this->N];		

nQueenMatrix = matrix;
}

void loadMatrix(){

for(int i=0;i<this->N;i++){
	for(int j=0;j<this->N;j++){

	nQueenMatrix[i][j]=0;

	}
}



}




};



int main(int argc, char *argv[]){

nQueen queen(atoi(argv[1]));
queen.printSolution();








}

