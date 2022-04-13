#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#pragma once
#include <string>
#include <string.h>
#define null NULL
using namespace std;

namespace zich
{

    /**
     * @brief This class represent a matrix.
     * rows: The number of rows in the matrix
     * columns: The number of columns in the matrix
     * matrix: vectors that represent the matrix
     */

    class Matrix
    {
        int rows;
        int columns;
        vector<vector<double>> matrix;

    public:

        /////////////////////////////////Constructors//////////////////////////////

        //A constructor that create a new matrix from the input it gets

        Matrix(const vector<double> &vec_mat, int rows, int cols);

        //A copy constructor

        Matrix(const Matrix &mat);

        //A constructor which create new 0x0 empty matrix

        Matrix();

        ~Matrix(){;}

        /////////////////////////////////Support functions//////////////////////////////

        /**
         * @brief Set the Empty matrix
         * This function support the non parameter constructor by creating an empty matrix with the
         * wanted size if and only if the input is valid.
         * @param rows The wanted number of rows
         * @param cols The wanted number of columns
         */

        void setEmpty(int rows, int cols);

        /**
         * @brief Check if matrix of the input size can be used with operators
         * This function check if the inputs equals this matrix rows and columns
         * @param rows input row number
         * @param cols output row number
         * @return true A matrix from this size is from the same order as this matrix
         * @return false A matrix from this size is not from the same order
         */

        bool OrderCheck(int rows, int cols) const;

        int getRows() const;

        int getColumns() const;

        double getComponent(unsigned int row, unsigned int col) const;

        void setComponent(unsigned int row, unsigned int col, double component);

        /**
         * @brief Calculate the sum of the components of this matrix
         */

        double sum() const;

        /////////////////////////////////Static support functions//////////////////////////////

        /**
         * @brief Check if the inputs are valid
         * This function get input that meant to construct a new matrix and check if its valid
         * @param rows the number of rows in the matrix
         * @param cols the number of columns in the matrix
         * @param vec_mat a vector that represent the matrix
         */

        static void input_check(int rows, int cols, const vector<double> &vec_mat)
        {
            //The row number have to be a positive number
            if (rows <= 0)
            {
                std::__throw_invalid_argument("The number of rows have to be a positive integer");
            }

            //The row number have to be a positive number
            if (cols <= 0)
            {
                cout << cols;
                std::__throw_invalid_argument("The number of columns have to be a positive integer");
            }
            unsigned int components = (unsigned int)(rows * cols);

            //The size of the vector has to equals the product of rows and columns, otherwise it
            //will not contain the corrent number of components in the future matrix
            if (components != (int)vec_mat.size())
            {
                std::__throw_invalid_argument("Cannot create a matrix since the number of components in the input is not equal to rows X columns");
            }
        }

        /**
         * @brief Round double number with precision of 2
         * @param num the input number
         * @return string A string that represent the input number with precision of 2
         */

        static string round_to_string(double num)
        {
            string s_num = to_string(num);
            unsigned int start = 0;
            unsigned int end = s_num.size();
            end = s_num.find('.', start);
            return s_num.substr(start, end);
        }

        /**
         * @brief Split the input into rows
         * This function support the input operator. it receives the input matrix, and split it
         * to a vector of string by the delimeter ", "
         * @param input The input matrix
         * @return vector<string> string rows of the matrix
         */

        static vector<string> splitToRows(string &input)
        {
            unsigned int start = 0;
            unsigned int end = input.length();
            vector<string> vec;
            string token;

            //while there are more occurences of ", "
            while (input.find(", ", start) != string::npos)
            {
                //get the index of ','
                end = input.find(", ", start);
                //trim only the row and save it into token
                token = input.substr(start, end - start);
                vec.push_back(token);
                //advance start for the first index after the occurence of ", "
                start = end + 2;
            }
            //add the last row to the matrix
            token = input.substr(start);
            vec.push_back(token);
            return vec;
        }

        /**
         * @brief Create double vector from string vector
         * This function receive a string that represent a row in the matrix, split it by the delimeter
         * " ", parse it to double and add it to the output vector
         * @param input a string that represent a row in the matrix
         * @return vector<double> a valid row in the matrix
         */

        static vector<double> splitRowToVector(string &input)
        {
            vector<double> row;
            unsigned int start = input.find('[', 0)+1;
            if(start!=1){
                std::__throw_invalid_argument("Invalid input format");
            }
            unsigned int end = input.find(']', 0)-1;
            char delim = ' ';
            double num;
            
            //while there are more occurences of ' '
            while (input.find(delim, start) != string::npos)
            {
                end = input.find(delim, start);
                //trim the string and parse the substring into double
                num = std::stod(input.substr(start, end - start));
                row.push_back(num);
                //set start to the first index after the occurence of ' '
                start = end + 1;
            }
            //add the last component to the vector
            num = std::stod(input.substr(start));
            row.push_back(num);
            return row;
        }

        /////////////////////////////////Matrix Operators//////////////////////////////

        ///////////////Operator+//////////////////////////////////////////////////////

        /**
         * @brief Unary plus operator.
         * Negates the values of the matrix
         */

        Matrix operator+() const;

        /**
         * @brief Addition operator
         * This function add the values of the input and this matrix and return a copy of the result
         * @param mat The inout matrix
         * @return Matrix& A reference of the result matrix
         */

        Matrix operator+(const Matrix &mat) const;

        /**
         * @brief Addition of integer
         * Allow to add integers to the matrix
         * @param scale the wanted integer
         * @return Matrix the output
         */

        Matrix operator+(int scale) const;

         /**
         * @brief Addition of doubles
         * Allow to add doubles to the matrix
         * @param scale the wanted doubles
         * @return Matrix the output
         */

        Matrix operator+(double scale) const;

        /**
         * @brief Addition from the left of integers
         * Allow to add integers to the matrix from the left
         * @param scale the wanted int
         * @param mat the matrix which we want to add the double to
         * @return Matrix the output
         */

        friend Matrix operator+(int scale, const Matrix &mat);

         /**
         * @brief Addition from the left of doubles
         * Allow to add doubles to the matrix from the left
         * @param scale the wanted double
         * @param mat the matrix which we want to add the double to
         * @return Matrix the output
         */

        friend Matrix operator+(double scale, const Matrix &mat);

        ///////////////Operator-//////////////////////////////////////////////////////

        /**
         * @brief Unary minus operator
         * Does nothing but returns a copy of the matrix
         */

        Matrix operator-() const;

        /**
         * @brief Substraction operator
         * This function substract the values of the input from this matrix and return a copy of the result
         * @param mat The inout matrix
         * @return Matrix& A reference of the result matrix
         */

        Matrix operator-(const Matrix &mat) const;

         /**
         * @brief Substraction of integer
         * Allow to substract integers from the matrix
         * @param scale the wanted integer
         * @return Matrix the output
         */

        Matrix operator-(int scale) const;

        /**
         * @brief Substraction of doubles
         * Allow to substract doubles from the matrix
         * @param scale the wanted double
         * @return Matrix the output
         */

        Matrix operator-(double scale) const;

        /**
         * @brief Substraction from the left of integers
         * Allow to substract integers from the matrix from the left
         * @param scale the wanted int
         * @param mat the matrix which we want to substract the double from
         * @return Matrix the output
         */

        friend Matrix operator-(int scale, const Matrix &mat);

         /**
         * @brief Substraction from the left of integers
         * Allow to substract integers from the matrix from the left
         * @param scale the wanted int
         * @param mat the matrix which we want to substract the double from
         * @return Matrix the output
         */

        friend Matrix operator-(double scale, const Matrix &mat);

        ///////////////Operator-=//////////////////////////////////////////////////////

        /**
         * @brief -= operator
         * This operator takes another matrix and substract its values from this matrix
         * @param mat The input matrix
         */

        Matrix operator-=(const Matrix &mat);

        /**
         * @brief += operator
         * This operator takes another matrix and add its values to this matrix
         * @param mat The input matrix
         */

        ///////////////Operator+=//////////////////////////////////////////////////////

        Matrix operator+=(const Matrix &mat);

        /**
         * @brief Pre increment of the matrix
         */

        ///////////////Operator++//////////////////////////////////////////////////////

        Matrix &operator++();

         /**
         * @brief Post increment of the matrix
         */

        Matrix operator++(int scale);

        /**
         * @brief Pre decrement of the matrix
         */

        ///////////////Operator--//////////////////////////////////////////////////////

        Matrix operator--();

        /**
         * @brief Post decrement of the matrix
         */

        Matrix operator--(int scale);

        /**
         * @brief Multiplication Operator
         * This operator take a double scale and multiply the components of the matrix 
         * by it and return a copy of the matrix
         * @param scale The scale
         * @return Matrix& a copy of the result
         */

        ///////////////Operator*//////////////////////////////////////////////////////

        Matrix operator*(double scale) const;

        /**
         * @brief Multiplication Operator
         * This operator take a double scale and multiply the components of the matrix
         * by it and return a copy of the matrix
         * @param scale The scale
         * @return Matrix& a copy of the result
         */

        Matrix operator*(int scale) const;

        /**
         * @brief Multiplication Operator from the left
         * This operator take a int scale and multiply the components of the matrix 
         * by it and return a pointer of the matrix
         * @param scale The scale
         * @return pointer to this matrix
         */

        friend Matrix operator*(int scale, const Matrix &mat);

        /**
         * @brief Multiplication Operator from the left
         * This operator take a double scale and multiply the components of the matrix 
         * by it and return a pointer of the matrix
         * @param scale The scale
         * @return pointer to this matrix
         */

        friend Matrix operator*(double scale, const Matrix &mat);

        /**
         * @brief Multiplication operator
         * This operator multiply the input matrix by this matrix and returns the result matrix
         * @param mat The input matrix
         * @return the result matrix
         */

        Matrix operator*(const Matrix &mat) const;

        ///////////////Operator*=//////////////////////////////////////////////////////

        /**
         * @brief Multiplication Operator
         * This operator take a int scale and multiply the components of the matrix 
         * by it and return a pointer of the matrix
         * @param scale The scale
         * @return pointer to this matrix
         */

        Matrix operator*=(int scale);

        /**
         * @brief Multiplication Operator
         * This operator take a double scale and multiply the components of the matrix 
         * by it and return a pointer of the matrix
         * @param scale The scale
         * @return pointer to this matrix
         */

        Matrix operator*=(double scale);

        /**
         * @brief Multiplication operator
         * This operator multiply the input matrix by this matrix and set the result as this matrix
         * @param mat The input matrix
         * @return Matrix pointer to this matrix
         */

        Matrix operator*=(const Matrix &mat);

        /**
         * @brief Operator ==
         */

        ///////////////Equasion operators == != < <= > >=/////////////////////////////////

        bool operator==(const Matrix &mat) const;

        /**
         * @brief Operator !=
         */

        bool operator!=(const Matrix &mat) const;

        /**
         * @brief Operator <
         */

        bool operator<(const Matrix &mat) const;

        /**
         * @brief Operator <=
         */

        bool operator<=(const Matrix &mat) const;

        /**
         * @brief Operator >
         */

        bool operator>(const Matrix &mat) const;

        /**
         * @brief Operator >=
         */

        bool operator>=(const Matrix &mat) const;

        ///////////////I/O Operators//////////////////////////////////////////////////////

        /**
         * @brief Operator <<
         */

        friend ostream &operator<<(ostream &output, const Matrix &mat);

        /**
         * @brief Operator >>
         */

        friend istream &operator>>(istream &is, Matrix &mat);
    };
};
