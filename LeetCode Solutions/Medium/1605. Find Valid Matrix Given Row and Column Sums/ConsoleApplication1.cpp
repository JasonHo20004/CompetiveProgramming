// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

//Version 1: 
vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
	int rows = rowSum.size();
	int cols = colSum.size();
	int cur_row, cur_col = 0;

    vector<vector<int>> matrix(rows, vector<int>(cols, 0));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int value = min(rowSum[i], colSum[j]);
            matrix[i][j] = value;
            rowSum[i] -= value;
            colSum[j] -= value;
        }
    }

    return matrix;
	
}

//Version 2: Greedy 2 Pointers
vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
    int m = rowSum.size();
    int n = colSum.size();
    vector<vector<int>> matrix(m, vector<int>(n, 0));

    int i = 0, j = 0;
    while (i < m && j < n) {
        int value = min(rowSum[i], colSum[j]);
        matrix[i][j] = value;
        rowSum[i] -= value;
        colSum[j] -= value;

        if (rowSum[i] == 0) ++i;
        if (colSum[j] == 0) ++j;
    }

    return matrix;
}


int main()
{

}