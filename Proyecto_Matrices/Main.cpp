#include<iostream>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;


class node
{
public:
	node* below;
	node* next;
	int val;

	node(int n, node* nr = nullptr, node* nc = nullptr)
	{
		this->val = n;
		this->next = nc;
		this->below = nr;
	}
};

class Matrix
{
public:

	node* head;
	node* cursor;
	int rows = 0;
	int cols = 0;

	Matrix()
	{
		this->head = nullptr;
	}

	Matrix(int r, int c)
	{
		this->head = nullptr;
		for (int i = 0; i < r; i++)
		{
			this->addNewRow();
		}
		for (int i = 0; i < c-1; i++)
		{
			this->addNewCol();
		}
	}

	void moveToLastCol()
	{
		cursor = head;
		while (cursor->next != nullptr)
		{
			cursor = cursor->next;
		}
	}

	void moveToLastRow()
	{
		cursor = head;
		while (cursor->below != nullptr)
		{
			cursor = cursor->below;
		}
	}

	bool moveCursorTo(int r, int c)
	{
		cursor = head;
		for (int i = 0; i < r; i++)
		{
			if (cursor->below != nullptr)
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
			if (cursor->next != nullptr)
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

	void addNewRow(int n = 0)
	{
		if (head == nullptr)
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
			while (temp->next != nullptr)
			{
				temp = temp->next;
				temp->below = new node(0);
			}

			temp = cursor;

			while (temp->next != nullptr)
			{
				temp->below->next = temp->next->below;
				temp = temp->next;
			}
			rows++;

		}

	}

	void addNewCol(int n = 0)
	{
		if (head == nullptr)
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
			while (temp->below != nullptr)
			{
				temp = temp->below;
				temp->next = new node(0);
			}

			temp = cursor;

			while (temp->below != nullptr)
			{
				temp->next->below = temp->below->next;
				temp = temp->below;
			}
			cols++;

		}

	}

	void drawMatrix()
	{
		node* temp = head;

		while (temp != nullptr)
		{
			node* temp2 = temp;
			while (temp2 != nullptr)
			{
				cout << temp2->val << " ";
				temp2 = temp2->next;
			}
			cout << endl;
			temp = temp->below;
		}

	}

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

	bool moveToNextCol()
	{
		if (cursor->next != nullptr)
		{
			cursor = cursor->next;
			return true;
		}
		return false;
	}

	bool moveToNextRow()
	{
		if (cursor->below != nullptr)
		{
			cursor = cursor->below;
			return true;
		}
		return false;
	}

	void assignToCurrentPosition(int val)
	{
		cursor->val = val;
	}

	int getCurrentValue()
	{
		return cursor->val;
	}

	void moveCursorToHead()
	{
		cursor = head;
	}

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


Matrix ReadMatrixFromFile(string fileName)
{
	ifstream ifile(fileName);

	if (!ifile.good())
	{
		cout << "An Error Occured Opening the file, Exiting the program." << endl;
		exit(0);
	}

	Matrix m;

	string line;
	getline(ifile, line);
	stringstream ss(line);

	while (!ss.eof())
	{
		int n;
		ss >> n;
		m.addNewCol(n);
	}

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
				cout << "Invalid Matrix Format. Returning Empty Matrix." << endl;
				return Matrix();
			}
		}
		if (count < m.cols)
		{
			cout << "Invalid Matrix Format. Returning Empty Matrix." << endl;
			return Matrix();
		}
	}

	ifile.close();
	return m;

}

void SaveMatrixToFile(string filename, Matrix m)
{
	ofstream odata(filename);
	
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

	odata.close();
}

Matrix AddMatrices(Matrix m1, Matrix m2)
{
	if (m1.rows != m2.rows || m1.cols != m2.cols)
	{
		cout << "Incompatible matrices. Addition Not Possible, Empty Matrix Returned" << endl;
		return Matrix();
	}
	else
	{
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

Matrix SubtractMatrices(Matrix m1, Matrix m2)
{
	if (m1.rows != m2.rows || m1.cols != m2.cols)
	{
		cout << "Incompatible matrices. Subtraction Not Possible, Empty Matrix Returned" << endl;
		return Matrix();
	}
	else
	{
		Matrix m(m1.rows, m1.cols);
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
	if (m1.cols != m2.rows)
	{
		cout << "Incompatible matrices. Multiplication Not Possible, empty matrix returned" << endl;
		return Matrix();
	}
	else
	{
		Matrix m(m1.rows, m2.cols);

		for (int i = 0; i<m1.rows; i++)
		{
			for (int j = 0; j<m2.cols; j++)
			{
				m.moveCursorTo(i, j);
				for (int k = 0; k<m1.cols; k++)
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
			int res = 0;
			int sign = 1;
			for (int i = 0; i < m.rows; i++)
			{
				Matrix temp = getCofactor(m, 0, i);
				res += (sign*m.getValueAt(0,i)*GetMatrixDeterminant(temp));
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