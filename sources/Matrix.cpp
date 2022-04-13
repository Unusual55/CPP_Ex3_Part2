#include "Matrix.hpp"
#include <string>
#include <vector>
#include <iterator>
#include <initializer_list>
using namespace std;
using namespace zich;

Matrix::Matrix(const vector<double> &vec_mat, int rows, int cols)
{
    //Check if the input is valid
    input_check(rows, cols, vec_mat);

    //Set the bounds of the matrix
    this->rows = rows;
    this->columns = cols;

    //Build the matrix using the vector
    for (unsigned int i = 0; i < rows; i++)
    {
        vector<double> row;
        for (unsigned int j = 0; j < columns; j++)
        {
            unsigned int component_index = i * (unsigned int)columns + j;
            row.push_back(vec_mat[component_index]);
        }
        matrix.push_back(row);
    }
}

Matrix::Matrix(const Matrix &mat)
{
    //Set the bounds of the matrix
    this->rows = mat.rows;
    this->columns = mat.columns;
    
    //Set the matrix and copy the rows
    for (unsigned int i = 0; i < rows; i++)
    {
        vector<double> row;
        for (unsigned int j = 0; j < columns; j++)
        {
            row.push_back(mat.matrix[i][j]);
        }
        this->matrix.push_back(row);
    }
}

Matrix::Matrix()
{
    this->rows = 0;
    this->columns = 0;
}

void Matrix::setEmpty(int rows, int cols)
{
    //Check if the inputs are valid
    if (rows <= 0 || cols <= 0)
    {
        std::__throw_invalid_argument("row or column argument is invalid");
    }

    //Set the bounds of the matrix
    this->columns = cols;
    this->rows = rows;

    //Fill the matrix with 0
    for (unsigned int i = 0; i < (unsigned int)rows; i++)
    {
        vector<double> row;
        for (unsigned int j = 0; j < columns; j++)
        {
            row.push_back(0);
        }
        this->matrix.push_back(row);
    }
}

double Matrix::sum() const
{
    double sum = 0;
    for (unsigned int i = 0; i < rows; i++)
    {
        for (unsigned int j = 0; j < columns; j++)
        {
            //Sum the values of the matrix
            sum += this->matrix[i][j];
        }
    }
    return sum;
}

bool Matrix::OrderCheck(int rows, int cols) const
{
    //return true if the rows and columns are equal, otherwise fasle
    return (this->rows == rows) && (this->columns == cols);
}

int Matrix::getRows() const
{
    return this->rows;
}

int Matrix::getColumns() const
{
    return this->columns;
}

double Matrix::getComponent(unsigned int row, unsigned int col) const
{
    if (row < 0 || row > this->rows)
    {
        std::__throw_invalid_argument("The row doesn't exist");
    }
    if (col < 0 || col > this->columns)
    {
        std::__throw_invalid_argument("The row doesn't exist");
    }
    return matrix.at((unsigned int)row).at((unsigned int)col);
}

void Matrix::setComponent(unsigned int row, unsigned int col, double component)
{
    if (row < 0 || row > this->rows)
    {
        std::__throw_invalid_argument("The row doesn't exist");
    }
    if (col < 0 || col > this->columns)
    {
        std::__throw_invalid_argument("The row doesn't exist");
    }
    matrix.at((unsigned int)row)[(unsigned int)col] = component;
}

Matrix Matrix::operator-() const
{
    //Create a copy
    Matrix ret = Matrix(*this);
    for (unsigned int i = 0; i < rows; i++)
    {
        for (unsigned int j = 0; j < columns; j++)
        {
            //Negate the sign of each component
            ret.matrix[i][j] = -(this->matrix[i][j]);
        }
    }
    return ret;
}

Matrix Matrix::operator+() const
{
    //Create a copy without changing the sign of the components
    Matrix ret = Matrix(*this);
    return ret;
}

Matrix Matrix::operator+(int scale) const
{
    //Create a copy of the matrix
    Matrix ret = Matrix(*this);
    for (unsigned int i = 0; i < ret.getRows(); i++)
    {
        for (unsigned int j = 0; j < ret.getColumns(); i++)
        {
            //Increase each component in the copied matrix by scale
            ret.matrix[i][j] += scale;
        }
    }
    return ret;
}

Matrix zich::operator+(int scale, const Matrix &mat)
{
    //Create a copy of the matrix
    Matrix ret = Matrix(mat);
    for (unsigned int i = 0; i < ret.getRows(); i++)
    {
        for (unsigned int j = 0; j < ret.getColumns(); i++)
        {
            //Increase each component in the copied matrix by scale
            ret.matrix[i][j] += scale;
        }
    }
    return ret;
}

Matrix Matrix::operator+(double scale) const
{
    //Create a copy of the matrix
    Matrix ret = Matrix(*this);
    for (unsigned int i = 0; i < this->rows; i++)
    {
        for (unsigned int j = 0; j < this->columns; j++)
        {
            //Increase each component in the copied matrix by scale
            ret.matrix[i][j] += scale;
        }
    }
    return ret;
}

Matrix zich::operator+(double scale, const Matrix &mat)
{
    //Create a copy of the matrix
    Matrix ret = Matrix(mat);
    for (unsigned int i = 0; i < ret.getRows(); i++)
    {
        for (unsigned int j = 0; j < ret.getColumns(); j++)
        {
            //Increase each component in the copied matrix by scale
            ret.matrix[i][j] += scale;
        }
    }
    return ret;
}

Matrix Matrix::operator+(const Matrix &mat) const
{
    //Check if the input matrix is valid
    if (!OrderCheck(mat.rows, mat.columns))
    {
        std::__throw_invalid_argument("The matrixes are not from the same order");
    }
    //Create an empty matrix which its bounds equals this matrix
    Matrix ret = Matrix();
    ret.setEmpty(rows, columns);
    for (unsigned int i = 0; i < rows; i++)
    {
        for (unsigned int j = 0; j < columns; j++)
        {
            //Set the components
            ret.matrix[i][j] = mat.matrix[i][j] + this->matrix[i][j];
        }
    }
    return ret;
}

Matrix Matrix::operator-(const Matrix &mat) const
{
    //Create an empty matrix which its bounds equals this matrix
    if (!OrderCheck(mat.rows, mat.columns))
    {
        std::__throw_invalid_argument("The matrixes are not from the same order");
    }
    Matrix ret = Matrix(*this);
    for (unsigned int i = 0; i < rows; i++)
    {
        for (unsigned int j = 0; j < columns; j++)
        {
            //Set the components
            ret.matrix[i][j] = this->matrix[i][j] - mat.matrix[i][j];
        }
    }
    return ret;
}

Matrix Matrix::operator-(int scale) const
{
    //Create a copy of the matrix
    Matrix ret = Matrix(*this);
    for (unsigned int i = 0; i < ret.getRows(); i++)
    {
        for (unsigned int j = 0; j < ret.getColumns(); j++)
        {
            //Set the components
            ret.matrix[i][j] -= scale;
        }
    }
    return ret;
}

Matrix zich::operator-(int scale, const Matrix &mat)
{
    //Create a copy of the matrix
    Matrix ret = Matrix(mat);
    for (unsigned int i = 0; i < ret.getRows(); i++)
    {
        for (unsigned int j = 0; j < ret.getColumns(); j++)
        {
            //Set the components
            ret.matrix[i][j] = scale - ret.matrix[i][j];
        }
    }
    return ret;
}

Matrix Matrix::operator-(double scale) const
{
    //Create a copy of the matrix
    Matrix ret = Matrix(*this);
    for (unsigned int i = 0; i < ret.getRows(); i++)
    {
        for (unsigned int j = 0; j < ret.getColumns(); j++)
        {
            //Reduce the scale from the copied matrix components
            ret.matrix[i][j] -= scale;
        }
    }
    return ret;
}

Matrix zich::operator-(double scale, const Matrix &mat)
{
    //Create a copy of the matrix
    Matrix ret = Matrix(mat);
    for (unsigned int i = 0; i < ret.getRows(); i++)
    {
        for (unsigned int j = 0; j < ret.getColumns(); j++)
        {
            //Reduce the scale from the copied matrix components
            ret.matrix[i][j] = scale - ret.matrix[i][j];
        }
    }
    return ret;
}

Matrix Matrix::operator+=(const Matrix &mat)
{
    //Check if the bounds of the input matrix is valid for this operator
    if (!OrderCheck(mat.rows, mat.columns))
    {
        std::__throw_invalid_argument("The matrixes are not from the same order");
    }
    for (unsigned int i = 0; i < rows; i++)
    {
        for (unsigned int j = 0; j < columns; j++)
        {
            //Increase the components by the suitable component from the input matrix
            this->matrix[i][j] += mat.matrix[i][j];
        }
    }
    return *this;
}

Matrix Matrix::operator-=(const Matrix &mat)
{
    //Check if the bounds of the input matrix is valid for this operator
    if (!OrderCheck(mat.rows, mat.columns))
    {
        std::__throw_invalid_argument("The matrixes are not from the same order");
    }
    for (unsigned int i = 0; i < rows; i++)
    {
        for (unsigned int j = 0; j < columns; j++)
        {
            //Decrease the components by the suitable component from the input matrix
            this->matrix[i][j] -= mat.matrix[i][j];
        }
    }
    return *this;
}

Matrix Matrix::operator*(double scale) const
{
    //Create empty copy of the matrix
    Matrix ret;
    ret.setEmpty(rows, columns);
    for (unsigned int i = 0; i < rows; i++)
    {
        for (unsigned int j = 0; j < columns; j++)
        {
            //Multiply the component by the scale
            ret.matrix[i][j] += scale * matrix[i][j];
        }
    }
    return ret;
}

Matrix Matrix::operator*=(int scale)
{
    for (unsigned int i = 0; i < rows; i++)
    {
        for (unsigned int j = 0; j < columns; j++)
        {
            //Multiply the component by the scale
            this->matrix[i][j] *= scale;
        }
    }
    return *this;
}

Matrix Matrix::operator*(int scale) const
{
    //Create an empty copy
    Matrix ret;
    ret.setEmpty(rows, columns);
    for (unsigned int i = 0; i < rows; i++)
    {
        for (unsigned int j = 0; j < columns; j++)
        {
            //Multiply the component by the scale
            ret.matrix[i][j] += scale * matrix[i][j];
        }
    }
    return ret;
}

Matrix Matrix::operator*=(double scale)
{
    for (unsigned int i = 0; i < rows; i++)
    {
        for (unsigned int j = 0; j < columns; j++)
        {
            //Multiply the component by the scale
            this->matrix[i][j] *= scale;
        }
    }
    return *this;
}

Matrix Matrix::operator*=(const Matrix &mat)
{
    //Check if the input matrix bounds are valid
    if(this->columns!=mat.rows){
        std::__throw_invalid_argument("Cannot multiply marixes from different orders");
    }
    //Keep the result in a temportal matrix
    Matrix temp = *this * mat;
    //Reset this matrix bounds
    this->rows = temp.rows;
    this->columns = temp.columns;
    this->matrix.clear();
    for(unsigned int i = 0; i<temp.rows;i++){
        vector<double> vec_row;
        for(unsigned int j = 0; j<temp.rows;j++){
            //Copy the values from the result to this matrix
            vec_row.push_back(temp.matrix[i][j]);
        }
        this->matrix.push_back(vec_row);
    }
    return *this;
}

Matrix Matrix::operator*(const Matrix &mat) const
{
    //Check if the bounds of the input matrix are valid
    if (this->columns != mat.getRows())
    {
        std::__throw_invalid_argument("Cannot multiply the matrixes since the coulumns of the first isn't equals the second's row number.");
    }
    //Create an empty matrix in the needed size
    Matrix ret = Matrix();
    ret.setEmpty(this->rows, mat.getColumns());
    for (unsigned int i = 0; i < this->rows; i++)
    {
        for (unsigned int j = 0; j < mat.getColumns(); j++)
        {
            for (unsigned int k = 0; k < this->columns; k++)
            {
                //Multiply the wanted components
                ret.matrix[i][j] += this->matrix[i][k] * mat.matrix[k][j];
            }
        }
    }
    return ret;
}

Matrix& Matrix::operator++()
{
    for (unsigned int i = 0; i < rows; i++)
    {
        for (unsigned int j = 0; j < columns; j++)
        {
            //Increase each component by 1
            this->matrix[i][j] += 1;
        }
    }
    return *this;
}

Matrix Matrix::operator--()
{
    for (unsigned int i = 0; i < rows; i++)
    {
        for (unsigned int j = 0; j < columns; j++)
        {
            //Decrease each component by 1
            this->matrix[i][j] -= 1;
        }
    }
    return *this;
}

Matrix Matrix::operator++(int)
{
    //Create a copy of the matrix
    Matrix next =Matrix(*this);
    //Increase this matrix by 1
    ++*this;
    //Return the copy of the matrix
    return next;
}

Matrix Matrix::operator--(int)
{
    //Create a copy of the matrix
    Matrix next =Matrix(*this);
    //Decrease this matrix by 1
    --*this;
    //Return the copy of the matrix
    return next;
}

bool Matrix::operator==(const Matrix &mat) const
{
    //Check id the bounds of the input matrix are valid
    if (!OrderCheck(mat.rows, mat.columns))
    {
        std::__throw_invalid_argument("The matrixes are not from the same order");
    }
    for (unsigned int i = 0; i < rows; i++)
    {
        for (unsigned int j = 0; j < columns; j++)
        {
            //Check if components are equal, if not, return false
            if (this->matrix[i][j] != mat.matrix[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

bool Matrix::operator!=(const Matrix &mat) const
{
    //Check id the bounds of the input matrix are valid
    if (!OrderCheck(mat.rows, mat.columns))
    {
        std::__throw_invalid_argument("The matrixes are not from the same order");
    }
    return !(*this==mat);
}

bool Matrix::operator<(const Matrix &mat) const
{
    //Check id the bounds of the input matrix are valid
    if (!OrderCheck(mat.rows, mat.columns))
    {
        std::__throw_invalid_argument("The matrixes are not from the same order");
    }
    return this->sum() < mat.sum();
}

bool Matrix::operator<=(const Matrix &mat) const
{
    //Check id the bounds of the input matrix are valid
    if (!OrderCheck(mat.rows, mat.columns))
    {
        std::__throw_invalid_argument("The matrixes are not from the same order");
    }
    return this->sum() <= mat.sum();
}

bool Matrix::operator>(const Matrix &mat) const
{
    //Check id the bounds of the input matrix are valid
    if (!OrderCheck(mat.rows, mat.columns))
    {
        std::__throw_invalid_argument("The matrixes are not from the same order");
    }
    return this->sum() > mat.sum();
}

bool Matrix::operator>=(const Matrix &mat) const
{
    //Check id the bounds of the input matrix are valid
    if (!OrderCheck(mat.rows, mat.columns))
    {
        std::__throw_invalid_argument("The matrixes are not from the same order");
    }
    return this->sum() >= mat.sum();
}

Matrix zich::operator*(int scale, const Matrix &mat)
{
    //Create empty matrix from the needed order
    Matrix ret;
    ret.setEmpty(mat.getRows(), mat.getColumns());
    for (unsigned int i = 0; i < mat.getRows(); i++)
    {
        for (unsigned int j = 0; j < mat.getColumns(); j++)
        {
            //Set their value as the components of this matrix multiplied by the input scale
            ret.setComponent(i, j, (scale * mat.getComponent(i, j)));
        }
    }
    return ret;
}

Matrix zich::operator*(double scale, const Matrix &mat)
{
    //Create empty matrix from the needed order
    Matrix ret;
    ret.setEmpty(mat.getRows(), mat.getColumns());
    for (unsigned int i = 0; i < mat.getRows(); i++)
    {
        for (unsigned int j = 0; j < mat.getColumns(); j++)
        {
            //Set their value as the components of this matrix multiplied by the input scale
            ret.setComponent(i, j, (scale * mat.getComponent(i, j)));
        }
    }
    return ret;
}

ostream &zich::operator<<(ostream &output, const Matrix &mat)
{
    //Create the output string
    string str;
    for (unsigned int i = 0; i < mat.getRows(); i++)
    {
        //If the index is more than zero, which means its the second row or above, add \n
        if(i>0){
            str += "\n";
        }
        //add "[" in the start of each row
        str += "[";
        
        for (unsigned j = 0; j < mat.getColumns(); j++)
        {
            //add space before the components after we already added the first component in the row
            if(j>0){
                str += " ";
            }
            //Add the number to the string
            double number = mat.getComponent(i, j);
            str += Matrix::round_to_string(number);
        }
        //add "]" to end the row
        str += "]";
    }
    output << str;
    return output;
}

istream &zich::operator>>(istream &is, Matrix &mat)
{
    //Setting the default size of the matrix
    int rows = -1;
    int cols = -1;
    string input;

    //Get the input from the user
    getline(is, input);

    //Split the input to the future rows in the matrix by the delimiter ", "
    vector<string> string_rows = Matrix::splitToRows(input);

    //Set the number of rows in the matrix
    rows = (int)string_rows.size();

    //Set the first row in order to define the number of columns in the matrix
    string str = string_rows[0];
    vector<double> first_row = Matrix::splitRowToVector(str);
    cols = (int)first_row.size();
    vector<vector<double>> vec_mat;
    vec_mat.push_back(first_row);
    vector<double> vec_row;

    //After the number of column defined, all of the rows have to match it

    for (int i = 1; i < (int)string_rows.size(); i++)
    {
        vec_row = Matrix::splitRowToVector(string_rows[(unsigned int)i]);
        if (cols != (int)vec_row.size())
        {
            std::__throw_invalid_argument("The number of components in the rows have to be equal");
        }
        vec_mat.push_back(vec_row);
    }

    //Set the values of the new matrix and return

    mat.rows = rows;
    mat.columns = cols;
    mat.matrix = vec_mat;
    return is;
}