#include <iostream> 
#include <vector> 

using std::cout;
using std::vector;
using std::cin;

void Calculate();

int main()
{
	Calculate();
	return 0;
}

void Calculate() {
	//get number input
	int numVariables;
	cout << "How many Variables: ";
	cin >> numVariables;
	int** matrix = new int*[numVariables];
	for (int i = 0; i < numVariables; ++i)
		matrix[i] = new int[numVariables + 1];
	for (int i = 0; i < numVariables; i++) {
		for (int j = 0; j < numVariables + 1; j++) {
			if (j < numVariables) {
				cout << i + 1 << " equation " << "give the coefficent of the " << j + 1 << " Variables: ";
				cin >> matrix[i][j];
			}
			else {
				cout << "give the answer to the " << i + 1 << " equation: ";
				cin >> matrix[i][j];
			}
		}
	}

	//zero the matrix

	for (int l = 0; l < numVariables - 1; l++) {
		for (int i = l + 1; i < numVariables; i++) {   
			if (matrix[l][l] == 0) {
				int *temp = matrix[l];
				matrix[l] = matrix[l + 1];
				matrix[l + 1] = temp;
			}
			float divider = matrix[i][l] / matrix[l][l];
			for (int j = l; j < numVariables + 1; j++) {
				matrix[i][j] -= (divider * matrix[l][j]);
			}
			cout << "\n\n";
			for (int i = 0; i < numVariables; i++) {
				cout << "\n";
				for (int j = 0; j < numVariables + 1; j++) {
					cout << matrix[i][j] << ", ";
				}
			}
		}
	}

	//solve the equations
	vector<float> varResults;
	for (int i = 0; i < numVariables; i++) {
		varResults.push_back(1);
	}
	bool isNoSolution = false;
	for (int i = numVariables - 1; i >= 0; i--) {
		varResults[(numVariables - 1) - i] = matrix[i][numVariables];
		for (int j = numVariables - 1; j >= 0; j--) {
			if (matrix[i][j] != 0) {
				if (i != j) {
					varResults[(numVariables - 1) - i] -= matrix[i][j] * varResults[(numVariables - 1) - j];
				}
				else {
					varResults[(numVariables - 1) - i] /= matrix[i][j];
				}
			}
			if (i == j && matrix[i][j] == 0) {
				isNoSolution = true;
				cout << "\n\n" << i << ", " << j << "\n";
			}
		}
	}
	
	
	cout << "\n\nThe answers are: ";
	if (isNoSolution) {
		cout << "no Solution";
	}
	else {
		for (int i = numVariables - 1; i >= 0; i--) {
			if (i == numVariables - 1) {
				cout << varResults[i];
			}
			else {
				cout << ", " << varResults[i];
			}
		}
	}

	char again;
	cout << "\ndo you have another equation: y for yes, n for no\n";
	cin >> again;
	if (again == 'y') {
		for (int i = 0; i < 35; i++) {
			cout << "\n";
		}
		Calculate();
	}
} 
