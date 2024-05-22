#include "../Matrix/Matrix.hpp"

Matrix::Matrix(): rows(0), cols(0) 
{
	data = nullptr;
}


Matrix::Matrix(int32_t row, int32_t column) : rows(row), cols(column) 
{
	data = new double*[rows];
	for (size_t i = 0; i < rows; ++i) {
		data[i] = new double[cols];
		for (size_t j = 0; j < cols; ++j) {
			data[i][j] = 0.0;
		}
	}
}


Matrix::Matrix(const Matrix& rhs) : rows(rhs.rows), cols(rhs.cols) 
{
	data = new double* [rows];
	for (size_t i = 0; i < rows; ++i) {
		data[i] = new double[cols];
		for (size_t j = 0; j < cols; ++j) {
			data[i][j] = 0.0;
		}
	}
}


Matrix::~Matrix() 
{
	for (size_t i = 0; i < rows; ++i) {
		delete[]data[i];
	}
	delete[]data;
}


double Matrix::getValue(int32_t row, int32_t column) const 
{
	if (row >= 0 && row < rows && column >= 0 && column < cols) {
		return data[row][column];
	}
	else {
		std::cerr << "Invalid indices!" << std::endl;
		return 0;
	}
}


void Matrix::setValue(int32_t row, int32_t column, double value) 
{
	if (row >= 0 && row < rows && column >= 0 && column < cols) {
		data[row][column] = value;
	}
	else {
		std::cerr << "Invalid indices!" << std::endl;
	}
}


Matrix& Matrix::operator=(const Matrix& rhs) {
	if (this != &rhs) {
		for (size_t i = 0; i < rows; ++i) {
			delete[] data[i];
		}
		delete[] data;

		rows = rhs.rows;
		cols = rhs.cols;

		data = new double* [rows];
		for (size_t i = 0; i < rows; ++i) {
			data[i] = new double[cols];
			for (size_t j = 0; j < cols; ++j) {
				data[i][j] = rhs.data[i][j];
			}
		}
	}
	return *this;
}


Matrix& Matrix::operator+=(const Matrix& rhs)
{
	if (rows != rhs.rows || cols != rhs.cols) {
		std::cerr << "Error: Matrices must have the same dimensions for addition." << std::endl;
		return *this;
	}

	for (size_t i = 0; i < rows; ++i) {
		for (size_t j = 0; j < cols; ++j) {
			data[i][j] += rhs.data[i][j];
		}
	}
	return *this;
}

	
Matrix& Matrix::operator-=(const Matrix& rhs) 
{
	if (rows != rhs.rows || cols != rhs.cols) {
		std::cerr << "Error: Matrices must have the same dimensions for subtraction." << std::endl;
		return *this;
	}

	for (size_t i = 0; i < rows; ++i) {
		for (size_t j = 0; j < cols; ++j) {
			data[i][j] -= rhs.data[i][j];
		}
	}
	return *this;
}


Matrix& Matrix::operator*=(const double& x)
{
	for (size_t i = 0; i < rows; ++i) {
		for (size_t j = 0; j < cols; ++j) {
			data[i][j] *= x;
		}
	}
	return *this;
}


Matrix& Matrix::operator/=(const double& x) 
{
	for (size_t i = 0; i < rows; ++i) {
		for (size_t j = 0; j < cols; ++j) {
			data[i][j] /= x;
		}
	}
	return *this;
}


Matrix Matrix::operator+(const Matrix& rhs)
{
	if (rows != rhs.rows || cols != rhs.cols) {
		std::cerr << "Error: Matrices must have the same dimensions for subtraction." << std::endl;
		return *this;
	}
	else {
		Matrix result(rows, cols);
		for (size_t i = 0; i < rows; ++i)
			for (size_t j = 0; j < cols; ++j)
				result.data[i][j] = data[i][j] + rhs.data[i][j];

		return result;
	}
}


Matrix Matrix::operator-(const Matrix& rhs)
{
	if (rows != rhs.rows || cols != rhs.cols) {
		std::cerr << "Error: Matrices must have the same dimensions for subtraction." << std::endl;
		return *this;
	}
	else {
		Matrix result(rows, cols);
		for (size_t i = 0; i < rows; ++i)
			for (size_t j = 0; j < cols; ++j)
				result.data[i][j] = data[i][j] - rhs.data[i][j];

		return result;
	}
}


Matrix Matrix::operator*(const Matrix& rhs) {
	if (cols != rhs.rows) {
		std::cout << "Error: Matrices are not compatible for multiplication.\n";
		return *this;
	}

	Matrix result(rows, rhs.cols);
	for (size_t i = 0; i < rows; ++i)
		for (size_t j = 0; j < rhs.cols; ++j)
			for (size_t k = 0; k < cols; ++k)
				result.data[i][j] += data[i][k] * rhs.data[k][j];
	return result;
}


Matrix Matrix::operator*(const double& scalar) 
{
	Matrix result(rows, cols);
	for (size_t i = 0; i < rows; ++i)
		for (size_t j = 0; j < cols; ++j)
			result.data[i][j] = scalar * data[i][j];
	return result;
}


//Matrix Matrix::operator*(const double& scalar) 
//{
//	Matrix result(rows, cols);
//	for (size_t i = 0; i < rows; ++i)
//		for (size_t j = 0; j < cols; ++j)
//			result.data[i][j] = data[i][j] * scalar;
//	return result;
//}


Matrix Matrix::operator/(const double& scalar) 
{
	if (scalar == 0) {
		std::cout << "Error: Division by zero.\n";
		return *this;
	}

	Matrix result(rows, cols);
	for (size_t i = 0; i < rows; ++i)
		for (size_t j = 0; j < cols; ++j)
			result.data[i][j] = data[i][j] / scalar;
	return result;
}

bool Matrix::operator==(const Matrix& rhs) 
{
	if (rows != rhs.rows || cols != rhs.cols) {
		return false;
	}

	for (size_t i = 0; i < rows; ++i)
		for (size_t j = 0; j < cols; ++j)
			if (data[i][j] != rhs.data[i][j])
				return false;

	return true;
}

bool Matrix::operator!=(const Matrix& rhs) 
{
	return !(*this == rhs);
}


std::istream& operator>>(std::istream& is, Matrix& m) {
	for (size_t i = 0; i < m.rows; ++i)
		for (size_t j = 0; j < m.cols; ++j)
			is >> m.data[i][j];
	return is;
}


std::ostream& operator<<(std::ostream& os, const Matrix& m) {
	for (size_t i = 0; i < m.rows; ++i) {
		for (size_t j = 0; j < m.cols; ++j)
			os << m.data[i][j] << ' ';
		os << '\n';
	}
	return os;
}