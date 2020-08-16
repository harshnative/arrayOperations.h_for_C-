#ifndef MATRIXOPERATIONS_H
#define MATRIXOPERATIONS_H

#include<iostream>
#include<vector>
#include<string.h>

using namespace std;

class Matrix
{
	public :

        //documentaion is given along with the func defination
        
        //remember currently the matrix operations are on integer data type 
        //you can change the matrix operation data type by changing function datatype like vector <vector <int>> transposeMatrix() to vector <vector <double>> transposeMatrix() 
		
        
		// function to transpose a passed matrix
		// returns a new transposed matrix
		vector <vector <int>> transposeMatrix(vector <vector <int>> v)
		{
			vector <vector <int>> toReturn;

			for(int i=0 ; i<v.size() ; i++)
			{
				vector <int> temp;
				for(int j=0 ; j<v[i].size() ; j++)
				{
					temp.push_back(v[j][i]);
				}
				toReturn.push_back(temp);
				temp.clear();
			}

			return toReturn;
		}



		// returns a vector of 2d array inputted by user
		vector <vector <int>> input2dArray(int row , int coloumn)
		{
			vector<vector<int>> a;
			for(int i=0;i<row;i++)
			{	
				vector<int> temp;
				for(int j=0;j<coloumn;j++)
				{
					int b;
					cin>>b;
					temp.push_back(b);
				}
				a.push_back(temp);
				temp.clear();	
			}
			return a;
		}



		// prints the 2d vector array passed to it seperated by sep
		void printMatrix(vector <vector <int>> v , string sep = " ")
		{
			for(int i=0 ; i<v.size() ; i++)
			{
				for(int j=0 ; j<v[i].size() ; j++)
				{
					cout<<v[i][j]<<sep;
				}
				cout<<endl;
			}
		}
};


class SpecialMatrix
{
	public :


		// returns a 1d array from the diagonal type matrix to reduce space usage
		// i == j 
		vector <int> diagonalMatrix(vector <vector <int>> v)
		{
			vector<int> toReturn;

			for(int i=0 ; i<v.size() ; i++)
			{
				for(int j=0 ; j<v[i].size() ; j++)
				{
					if(i==j)
					{
						toReturn.push_back(v[i][j]);
					}
				}
			}

			return toReturn;
		}




		int doModeOfInteger(int integer)
		{
			if(integer < 0)
			{
				integer = integer * (-1);
			}
			
			return integer;
		}




		// returns a 1d array from the tridiagonal type matrix to reduce space usage
		// | i - j | > 1
		// mapping = 0 for row wise , 1 for coloumn vise , 2 for diagonal vise
		vector <int> triDiagonalMatrix(vector <vector <int>> v , int mapping = 0)
		{
			vector<int> toReturn;

			if(mapping == 0)
			{
				for(int i=0 ; i<v.size() ; i++)
				{
					for(int j=0 ; j<v[i].size() ; j++)
					{
						if(doModeOfInteger((i - j)) <= 1)
						{
							toReturn.push_back(v[i][j]);
						}
					}
				}
			}
			else
			if(mapping == 1)
			{
				vector <vector <int>> transposed;
				Matrix matrixObj;

				transposed = matrixObj.transposeMatrix(v);

				for(int i=0 ; i<transposed.size() ; i++)
				{
					for(int j=0 ; j<transposed[i].size() ; j++)
					{
						if(doModeOfInteger((i - j)) <= 1)
						{
							toReturn.push_back(transposed[i][j]);
						}
					}
				}
			}

			else
			if(mapping == 2)
			{
				// below main diagonal
				for(int i=0 ; i<v.size() ; i++)
				{
					for(int j=0 ; j<v[i].size() ; j++)
					{
						if(i == (j+1))
						{
							toReturn.push_back(v[i][j]);
						}
					}
				}

				// main diagonal
				for(int i=0 ; i<v.size() ; i++)
				{
					for(int j=0 ; j<v[i].size() ; j++)
					{
						if(i == j)
						{
							toReturn.push_back(v[i][j]);
						}
					}
				}

				// above main diagonal

				for(int i=0 ; i<v.size() ; i++)
				{
					for(int j=0 ; j<v[i].size() ; j++)
					{
						if(i == (j-1))
						{
							toReturn.push_back(v[i][j]);
						}
					}
				}
			}

			else
			{
				throw "please pass a valid mapping to triDiagonal function";			
			}
			

			return toReturn;
		}
};
#endif