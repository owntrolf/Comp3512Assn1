//

// Created by Owntrolf on 2018-10-11.
//

#include "matrix.hpp"

//3 Default constructor for 1x1 matrix at 0
matrix::matrix()
{
    double2d.resize(1);
    double2d[0].resize(1);
    double2d[0][0] = 0;
}

//4 for n x n matrix at 0
matrix::matrix(int n)
{
    double2d.resize(n);
    for(int i = 0; i < n; i++)
    {
        double2d[i].resize(n);

        //set to 0.0
        for(int i2 = 0; i2 < n; i2++)
        {
            double2d[i][i2] = 0.0;
        }
    }
}

//5 2 integers for r x c size matrix
matrix::matrix(int r, int c)
{
    double2d.resize(r);
    for(int i = 0; i < r; i++)
    {
        double2d[i].resize(c);
        for(int i2 = 0; i2 < c; i2++)
        {
            double2d[i][i2] = 0.0;
        }
    }
}

//6 array of double and the size of array
matrix::matrix(double* inArr, int size)
{
    int squrt = sqrt(size);
    if(squrt*squrt == size)
    {
        int counter = 0;
        double2d.resize(squrt);
        for(int i = 0; i < squrt; i++)
        {
            double2d[i].resize(squrt);
            for(int i2 = 0; i2 < squrt; i2++)
            {
                double2d[i][i2] = inArr[counter];
                counter++;
            }
        }
    }
}

//7 3 param mutator
void matrix::set_value(int r, int c, double value)
{
    if(r < 0 || c < 0 || r > double2d.size() || c > double2d[0].size())
    {
        throw "Out of range exception";
        //throw exception
    }
    double2d[r][c] = value;
}

//8 2 param getter
double matrix::get_value(int r, int c)
{
    if(r < 0 || c < 0 || r > double2d.size() || c > double2d[0].size())
    {
        throw "Out of range exception";
        //throw exception
    }
    return double2d[r][c];
}

//9 clear function
void matrix::clear()
{
    for(int i = 0; i < double2d.size(); i++)
    {
        for(int i2 = 0; i2 < double2d[0].size(); i2++)
        {
            double2d[i][i2] = 0.0;
        }
    }
}

//10
matrix::~matrix()
{
    for(int i = 0; i < double2d.size(); i++)
    {
        double2d[i].clear();
    }
    double2d.clear();
}

//11
std::ostream& operator<<(std::ostream& os, matrix inMatrix)
{
    //os << "hi";
    std::vector<std::vector<double>> double2d = inMatrix.double2d;

    for(int i = 0; i < double2d.size(); i++)
    {
        for (int i2 = 0; i2 < double2d[i].size(); i2++)
        {
            os << double2d[i][i2] << " ";
        }
        os << std::endl;
    }
    return os;
}

bool operator==(matrix matrix1, matrix matrix2)
{
    if(matrix1.double2d.size() != matrix2.double2d.size())
        return false;
    if(matrix1.double2d[0].size() != matrix2.double2d[0].size())
        return false;
    for(int i = 0; i < matrix1.double2d.size(); i++)
    {
        for(int i2 = 0; i2 < matrix1.double2d[0].size(); i2++)
        {
            if(matrix1.double2d[i][i2]!=matrix2.double2d[i][i2])
            {
                return false;
            }
        }
    }

    return true;
}

bool operator!=(matrix matrix1, matrix matrix2)
{
    return !(matrix1==matrix2);
}

//pre increment ++
matrix& operator++(matrix& matrix1)
{
    for(int i = 0; i < matrix1.double2d.size(); i++)
    {
        for(int i2 = 0; i2 < matrix1.double2d[i].size(); i2++)
        {
            matrix1.double2d[i][i2] += 1;
        }
    }

    return matrix1;
}

//Post increment ++
matrix operator++(matrix& matrix1, int)
{
    matrix temp(matrix1);
    for(int i = 0; i < matrix1.double2d.size(); i++)
    {
        for(int i2 = 0; i2 < matrix1.double2d[i].size(); i2++)
        {
            matrix1.double2d[i][i2] += 1;
        }
    }
    return temp;
}

//pre increment --
matrix& operator--(matrix& matrix1)
{
    for(int i = 0; i < matrix1.double2d.size(); i++)
    {
        for(int i2 = 0; i2 < matrix1.double2d[i].size(); i2++)
        {
            matrix1.double2d[i][i2] -= 1;
        }
    }

    return matrix1;
}

//Post increment --
matrix operator--(matrix& matrix1, int)
{
    matrix temp(matrix1);
    for(int i = 0; i < matrix1.double2d.size(); i++)
    {
        for(int i2 = 0; i2 < matrix1.double2d[i].size(); i2++)
        {
            matrix1.double2d[i][i2] -= 1;
        }
    }
    return temp;
}

matrix& matrix::operator=(const matrix& matrix2)
{
    swap(this, matrix2, this->double2d.size(), this->double2d[0].size());
}

void swap(matrix* matrix1, matrix matrix2, int sizex, int sizey)
{
    for(int i = 0; i < sizex; i++)
    {
        for(int i2 = 0; i2 < sizey; i2++)
        {
            matrix1->set_value(i,i2, matrix2.get_value(i,i2));
        }
    }
}

matrix& operator+=(matrix& matrix1, matrix matrix2)
{

    if(matrix1.double2d.size() != matrix2.double2d.size())
        throw "Array size not matching";
    if(matrix1.double2d[0].size() != matrix2.double2d[0].size())
        throw "Array size not matching";
    for(int i = 0; i < matrix1.double2d.size(); i++)
    {
        for(int i2 = 0; i2 < matrix1.double2d[i].size(); i2++)
        {
            matrix1.double2d[i][i2] += matrix2.double2d[i][i2];
        }
    }
    return matrix1;
}

matrix& operator+(matrix& matrix1, matrix matrix2)
{

    if(matrix1.double2d.size() != matrix2.double2d.size())
        throw "Array size not matching";
    if(matrix1.double2d[0].size() != matrix2.double2d[0].size())
        throw "Array size not matching";
    for(int i = 0; i < matrix1.double2d.size(); i++)
    {
        for(int i2 = 0; i2 < matrix1.double2d[i].size(); i2++)
        {
            matrix1.double2d[i][i2] += matrix2.double2d[i][i2];
        }
    }
    return matrix1;
}

matrix& operator-=(matrix& matrix1, matrix matrix2)
{

    if(matrix1.double2d.size() != matrix2.double2d.size())
        throw "Array size not matching";
    if(matrix1.double2d[0].size() != matrix2.double2d[0].size())
        throw "Array size not matching";
    for(int i = 0; i < matrix1.double2d.size(); i++)
    {
        for(int i2 = 0; i2 < matrix1.double2d[i].size(); i2++)
        {
            matrix1.double2d[i][i2] -= matrix2.double2d[i][i2];
        }
    }
    return matrix1;
}

matrix& operator-(matrix& matrix1, matrix matrix2)
{

    if(matrix1.double2d.size() != matrix2.double2d.size())
        throw "Array size not matching";
    if(matrix1.double2d[0].size() != matrix2.double2d[0].size())
        throw "Array size not matching";
    for(int i = 0; i < matrix1.double2d.size(); i++)
    {
        for(int i2 = 0; i2 < matrix1.double2d[i].size(); i2++)
        {
            matrix1.double2d[i][i2] -= matrix2.double2d[i][i2];
        }
    }
    return matrix1;
}

matrix& operator*(matrix& matrix1, matrix matrix2)
{
    if(matrix1.double2d[0].size() != matrix2.double2d.size())
        throw "Array size not matching";

    matrix newMatrix = matrix(matrix1.double2d.size(), matrix2.double2d[0].size());

    //std::cout << matrix1;

    for(int i = 0; i < matrix1.double2d.size(); i++)
    {
        for(int i2 = 0; i2 < matrix2.double2d[0].size(); i2++)
        {
            double sum = 0;
            for(int i3 = 0; i3 < matrix2.double2d.size(); i3++)
            {
                sum += matrix1.double2d[i][i3] * matrix2.double2d[i3][i2];
            }
            newMatrix.set_value(i,i2,sum);
        }
    }
    //std::cout << newMatrix;
    matrix1.double2d.resize(matrix1.double2d.size());
    for(int i = 0; i<matrix1.double2d.size(); i++)
    {
        matrix1.double2d[i].resize(matrix2.double2d[0].size());
    }
    matrix1 = newMatrix;
    return matrix1;
}

matrix& operator*=(matrix& matrix1, matrix matrix2)
{
    if(matrix1.double2d[0].size() != matrix2.double2d.size())
        throw "Array size not matching";

    matrix newMatrix = matrix(matrix1.double2d.size(), matrix2.double2d[0].size());

    //std::cout << matrix1;

    for(int i = 0; i < matrix1.double2d.size(); i++)
    {
        for(int i2 = 0; i2 < matrix2.double2d[0].size(); i2++)
        {
            double sum = 0;
            for(int i3 = 0; i3 < matrix2.double2d.size(); i3++)
            {
                sum += matrix1.double2d[i][i3] * matrix2.double2d[i3][i2];
            }
            newMatrix.set_value(i,i2,sum);
        }
    }
    //std::cout << newMatrix;
    matrix1.double2d.resize(matrix1.double2d.size());
    for(int i = 0; i<matrix1.double2d.size(); i++)
    {
        matrix1.double2d[i].resize(matrix2.double2d[0].size());
    }
    matrix1 = newMatrix;
    return matrix1;
}



