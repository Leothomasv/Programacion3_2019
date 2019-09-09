#include<iostream>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;


class node
{
public:
	node* below; //pointer to node in next row and same column
	node* next; //pointer to node in next column and same row
	int val; //value of current node

	node(int n, node* nr = NULL, node* nc = NULL)
	{
		this->val = n;
		this->next = nc;
		this->below = nr;
	}
};

class Matrix
{
public:

	node* head; //Top left value of matrix. (0,0) value of matrix.
	node* cursor; //Can point to any node in matrix. used to perform Reading and writing in a matrix.
	int rows = 0;//Number of rows in the matrix.
	int cols = 0;//Number of columns in matrix.

	//default constructer. Initializes empty matrix
	Matrix()
	{
		this->head = NULL;
	}

	//Parameterized constructer. Inizialies matrix full of zeros of provided size and column
	Matrix(int r, int c)
	{
		this->head = NULL;
		for (int i = 0; i < r; i++)
		{
			this->addNewRow();
		}
		for (int i = 0; i < c - 1; i++)
		{
			this->addNewCol();
		}
	}

	//Helper function. Moves Cursor to first row of last column
	void moveToLastCol()
	{
		cursor = head;
		while (cursor->next != NULL)
		{
			cursor = cursor->next;
		}
	}

	//Helper function. Moves cursor to first column of last row
	void moveToLastRow()
	{
		cursor = head;
		while (cursor->below != NULL)
		{
			cursor = cursor->below;
		}
	}

	//Moves cursor to provided rows and columns. returns true of paramaterized are within bounds. returns false if parameters are out of bounds
	bool moveCursorTo(int r, int c)
	{
		cursor = head;
		for (int i = 0; i < r; i++)
		{
			if (cursor->below != NULL)
			{
				cursor = cursor->below;
			}
			else
			{
				cout << "Index out of bound error" << endl;
				cursor = head;
				return false;
			}
		}

		for (int i = 0; i < c; i++)
		{
			if (cursor->next != NULL)
			{
				cursor = cursor->next;
			}
			else
			{
				cout << "Index out of bound error" << endl;
				cursor = head;
				return false;
			}
		}
		return true;
	}

	//Adds a new Row in existing matrix. If matrix is empty, adds a value.
	void addNewRow(int n = 0)
	{
		if (head == NULL)
		{
			head = new node(n);
			rows = 1;
			cols = 1;
		}
		else
		{
			moveToLastRow();
			node* temp = cursor;

			temp->below = new node(n);
			while (temp->next != NULL)
			{
				temp = temp->next;
				temp->below = new node(0);
			}

			temp = cursor;

			while (temp->next != NULL)
			{
				temp->below->next = temp->next->below;
				temp = temp->next;
			}
			rows++;

		}

	}

	//Adds a new column in existing matrix. If matrix is empty, it adds a value.
	void addNewCol(int n = 0)
	{
		if (head == NULL)
		{
			head = new node(n);
			rows = 1;
			cols = 1;
		}
		else
		{
			moveToLastCol();
			node* temp = cursor;

			temp->next = new node(n);
			while (temp->below != NULL)
			{
				temp = temp->below;
				temp->next = new node(0);
			}

			temp = cursor;

			while (temp->below != NULL)
			{
				temp->next->below = temp->below->next;
				temp = temp->below;
			}
			cols++;

		}

	}

	//displays matrix on console
	void drawMatrix()
	{
		node* temp = head;

		while (temp != NULL)
		{
			node* temp2 = temp;
			while (temp2 != NULL)
			{
				cout << temp2->val << " ";
				temp2 = temp2->next;
			}
			cout << endl;
			temp = temp->below;
		}

	}

	//Assign value val at row r and coloumn c of matrix. If r and c are within bounds, return true. otherwise returns false.
	bool assignValueAt(int r, int c, int val)
	{
		if (moveCursorTo(r, c))
		{
			cursor->val = val;
			return true;
		}
		cout << "Index out of bounds. Unable to assign value" << endl;
		return false;
	}

	//Moves cursor to next coloumn from current position. If Cursor is already in last coloumn, returns false, otherwise returns true.
	bool moveToNextCol()
	{
		if (cursor->next != NULL)
		{
			cursor = cursor->next;
			return true;
		}
		return false;
	}

	//Moves cursor to next row from current position. If Cursor is already in last row, returns false, otherwise returns true.
	bool moveToNextRow()
	{
		if (cursor->below != NULL)
		{
			cursor = cursor->below;
			return true;
		}
		return false;
	}

	//Assigns value to current position of cursor
	void assignToCurrentPosition(int val)
	{
		cursor->val = val;
	}

	//returns value of current cursor position
	int getCurrentValue()
	{
		return cursor->val;
	}

	//Moves cursor to head (0,0) (top left) of matrix
	void moveCursorToHead()
	{
		cursor = head;
	}

	//Returns value at row r and coloumn c of matrix. If parameters are out of bounds, return -1
	int getValueAt(int r, int c)
	{
		if (moveCursorTo(r, c))
		{
			return getCurrentValue();
		}
		cout << "Index out of bounds, unable to retrieve value" << endl;
		return -1;
	}


};

//Reads matrix from the file with filename as parameter.
Matrix ReadMatrixFromFile(string fileName)
{
	//Try to open file and check if it can be read.
	ifstream ifile(fileName);

	if (!ifile.good())
	{
		cout << "An Error Occured Opening the file, Exiting the program." << endl;
		exit(0);
	}

	Matrix m;

	//Read first line of file(first row of matrix) and load it into memory
	string line;
	getline(ifile, line);
	stringstream ss(line);

	while (!ss.eof())
	{
		int n;
		ss >> n;
		m.addNewCol(n);
	}

	//Read remaining lines and check if they have the same number of entries(number of columns) in matrix. 
	while (!ifile.eof())
	{
		m.addNewRow();
		m.moveToLastRow();
		getline(ifile, line);
		stringstream ss2(line);
		int count = 0;
		while (!ss2.eof())
		{
			int n;
			ss2 >> n;
			m.assignToCurrentPosition(n);
			m.moveToNextCol();
			count++;
			if (count > m.cols)
			{
				//Show error if entries in a line are more than entries of first line.
				cout << "Invalid Matrix Format. Returning Empty Matrix." << endl;
				return Matrix();
			}
		}
		if (count < m.cols)
		{
			//shows error if entries in a line are less than entries of first line.
			cout << "Invalid Matrix Format. Returning Empty Matrix." << endl;
			return Matrix();
		}
	}

	//close the file.
	ifile.close();

	return m;

}

//saves matrix m in the file with name of 'filename' parameter
void SaveMatrixToFile(string filename, Matrix m)
{
	//create file of provided name
	ofstream odata(filename);

	//write all values of matrix in the file.
	for (int i = 0; i < m.rows; i++)
	{
		for (int j = 0; j < m.cols; j++)
		{
			odata << m.getValueAt(i, j);
			if (j != m.cols - 1)
			{
				odata << " ";
			}
		}
		if (i != m.rows - 1)
		{
			odata << endl;
		}
	}

	//close the file
	odata.close();
}

//Perform addition of 2 matrices
Matrix AddMatrices(Matrix m1, Matrix m2)
{
	//check if matrices have same rows and columns.
	if (m1.rows != m2.rows || m1.cols != m2.cols)
	{
		cout << "Incompatible matrices. Addition Not Possible, Empty Matrix Returned" << endl;
		return Matrix();
	}
	else
	{
		//Perform addition. Store result into a new matrix m and return it.
		Matrix m(m1.rows, m1.cols);
		for (int i = 0; i < m1.rows; i++)
		{
			for (int j = 0; j < m1.cols; j++)
			{
				m1.moveCursorTo(i, j);
				m2.moveCursorTo(i, j);

				m.assignValueAt(i, j, m1.getCurrentValue() + m2.getCurrentValue());
			}
		}
		return m;
	}
}

//Subtract matrix m2 from m1 i.e (m1-m2)
Matrix SubtractMatrices(Matrix m1, Matrix m2)
{
	//Check to see if matrices have same number of rows and columns
	if (m1.rows != m2.rows || m1.cols != m2.cols)
	{
		cout << "Incompatible matrices. Subtraction Not Possible, Empty Matrix Returned" << endl;
		return Matrix();
	}
	else
	{
		Matrix m(m1.rows, m1.cols);

		//Perform subtraction. Store result into a new matrix m and return it
		for (int i = 0; i < m1.rows; i++)
		{
			for (int j = 0; j < m1.cols; j++)
			{
				m1.moveCursorTo(i, j);
				m2.moveCursorTo(i, j);

				m.assignValueAt(i, j, m1.getCurrentValue() - m2.getCurrentValue());
			}
		}
		return m;
	}
}

Matrix MultiplyMatrices(Matrix m1, Matrix m2)
{
	//Check for compatible dimensions of matrices for multiplication.
	if (m1.cols != m2.rows)
	{
		cout << "Incompatible matrices. Multiplication Not Possible, empty matrix returned" << endl;
		return Matrix();
	}
	else
	{
		//Initialize new matrix with rows of m1 and columns of m2, the dimensions of the should be resulting matrix.
		Matrix m(m1.rows, m2.cols);

		//Perform multiplication. store result in matrix m and return it
		for (int i = 0; i < m1.rows; i++)
		{
			for (int j = 0; j < m2.cols; j++)
			{
				m.moveCursorTo(i, j);
				for (int k = 0; k < m1.cols; k++)
				{
					m1.moveCursorTo(i, k);
					m2.moveCursorTo(k, j);
					m.assignToCurrentPosition(m.getCurrentValue() + (m1.getCurrentValue() * m2.getCurrentValue()));
				}
			}
		}

		return m;
	}
}

//Calculate Cofactor matrix of matrix m according to entry of row p and column q
//Helper funciton used to calculate determinant of matrix in Laplace method.
Matrix getCofactor(Matrix m, int p, int q)
{
	int i = 0, j = 0;
	Matrix temp(m.rows - 1, m.cols - 1);

	for (int row = 0; row < m.rows; row++)
	{
		for (int col = 0; col < m.rows; col++)
		{
			if (row != p && col != q)
			{
				temp.assignValueAt(i, j++, m.getValueAt(row, col));
				if (j == m.rows - 1)
				{
					j = 0;
					i++;
				}
			}
		}
	}

	return temp;
}

//Calculate Determinant of matrix.
int GetMatrixDeterminant(Matrix m)
{
	if (m.rows != m.cols)
	{
		cout << "Matrix is not a square Matrix, cannot calculate determinant" << endl;
		return -1;
	}
	else
	{
		if (m.rows == 1)
		{
			return m.getValueAt(0, 0);
		}
		else if (m.rows == 2)
		{
			int res = (m.getValueAt(0, 0)*m.getValueAt(1, 1));
			res -= (m.getValueAt(0, 1)*m.getValueAt(1, 0));
			return res;
		}
		else if (m.rows == 3)
		{
			int res = (m.getValueAt(0, 0)*m.getValueAt(1, 1)*m.getValueAt(2, 2));
			res += (m.getValueAt(0, 1)*m.getValueAt(1, 2)*m.getValueAt(2, 0));
			res += (m.getValueAt(1, 0)*m.getValueAt(2, 1)*m.getValueAt(0, 2));

			int res2 = (m.getValueAt(0, 2)*m.getValueAt(1, 1)*m.getValueAt(2, 0));
			res2 += (m.getValueAt(0, 1)*m.getValueAt(1, 0)*m.getValueAt(2, 2));
			res2 += (m.getValueAt(1, 2)*m.getValueAt(2, 1)*m.getValueAt(0, 0));

			return (res - res2);
		}
		else
		{
			//Recursive calls to Determinant function with cofactor parameter.
			//Laplace method.
			int res = 0;
			int sign = 1;
			for (int i = 0; i < m.rows; i++)
			{
				Matrix temp = getCofactor(m, 0, i);
				res += (sign*m.getValueAt(0, i)*GetMatrixDeterminant(temp));
				sign = -1 * sign;
			}
			return res;
		}
		/*else
		{
			cout << "Error: Dimensions more than 3x3" << endl;
			return -1;
		}*/
	}
}

//User Interface
//Takes input from users and calls required functions to perform actions.
void showMainMenu()
{
	system("cls");
	cout << "Select an Operation" << endl << endl;

	cout << "1. Matrix Addition\n2. Matrix Subtraction\n3. Matrix Multiplication\n4. Matrix Determinant" << endl;
	char c;
	cin >> c;

	if (c == '1')
	{
		cout << "Enter File Name of Matrix 1" << endl;
		string n1;
		cin.clear();
		cin.ignore();
		getline(cin, n1);
		Matrix m1 = ReadMatrixFromFile(n1);

		cout << "Enter File Name of Matrix 2" << endl;
		string n2;
		getline(cin, n2);
		Matrix m2 = ReadMatrixFromFile(n2);

		Matrix m = AddMatrices(m1, m2);
		m.drawMatrix();

		cout << "Enter 1 to save matrix, enter anything else to go back to menu" << endl;
		if (cin.fail())
		{
			cin.clear();
		}
		cin >> c;
		cin.ignore();
		if (c == '1')
		{
			cout << "Enter output file name" << endl;
			string fname;
			getline(cin, fname);
			SaveMatrixToFile(fname, m);
		}


	}
	else if (c == '2')
	{
		cout << "Enter File Name of Matrix 1" << endl;
		string n1;
		cin.clear();
		cin.ignore();
		getline(cin, n1);
		Matrix m1 = ReadMatrixFromFile(n1);

		cout << "Enter File Name of Matrix 2" << endl;
		string n2;
		getline(cin, n2);
		Matrix m2 = ReadMatrixFromFile(n2);

		Matrix m = SubtractMatrices(m1, m2);
		m.drawMatrix();

		cout << "Enter 1 to save matrix, enter anything else to go back to menu" << endl;
		if (cin.fail())
		{
			cin.clear();
		}
		cin >> c;
		cin.ignore();
		if (c == '1')
		{
			cout << "Enter output file name" << endl;
			string fname;
			getline(cin, fname);
			SaveMatrixToFile(fname, m);
		}

	}
	else if (c == '3')
	{
		cout << "Enter File Name of Matrix 1" << endl;
		string n1;
		cin.clear();
		cin.ignore();
		getline(cin, n1);
		Matrix m1 = ReadMatrixFromFile(n1);

		cout << "Enter File Name of Matrix 2" << endl;
		string n2;
		getline(cin, n2);
		Matrix m2 = ReadMatrixFromFile(n2);

		Matrix m = MultiplyMatrices(m1, m2);
		m.drawMatrix();

		cout << "Enter 1 to save matrix, enter anything else to go back to menu" << endl;
		if (cin.fail())
		{
			cin.clear();
		}
		cin >> c;
		cin.ignore();
		if (c == '1')
		{
			cout << "Enter output file name" << endl;
			string fname;
			getline(cin, fname);
			SaveMatrixToFile(fname, m);
		}
	}
	else if (c == '4')
	{
		cout << "Enter File Name of Matrix 1" << endl;
		string n1;
		cin.clear();
		cin.ignore();
		getline(cin, n1);

		Matrix m1 = ReadMatrixFromFile(n1);

		int det = GetMatrixDeterminant(m1);
		cout << "Determinant is " << det << endl;
		system("pause");
	}
	else
	{
		cout << "Invalid Input :(" << endl;
		system("pause");

	}
	showMainMenu();
}




int main()
{
	showMainMenu();

	return 0;
}