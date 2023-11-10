#include <iostream>
#include <cstddef>
#include <vector>

using namespace std;


    struct Matrix {
 // двумерный массив с данными.
  int** data_=nullptr;
 // количество столбцов
  size_t n_ = 0u;
 // количество строк
  size_t m_ = 0u;
};

// Создает заполненную нулями матрицу n x m.
void Construct(Matrix& out, size_t n, size_t m)
{
    out.n_=n;
    out.m_=m;
    out.data_=new int*[n];
    for (size_t i=0;i<n;++i)
    {
        out.data_[i]=new int[m];
    }
    for (size_t i=0;i<n;++i)
    {
        for(size_t j=0; j<m;++j)
        {
            out.data_[i][j]=0;
        }
    }
    return;
}
// Освобождает выделенную память.
void Destruct(Matrix& in)
{
   for (size_t i=0; i<in.n_;++i)
   {
      delete  in.data_[i];
   }
   return;
}


// Создает копию матрицы |matrix|.
Matrix Copy(const Matrix& matrix)
{
    Matrix matrix_copy;
    Construct(matrix_copy,matrix.n_,matrix.m_);
    for (size_t i=0;i<matrix.n_;++i)
    {
        for(size_t j=0;j<matrix.m_;++j)
        {
            matrix_copy.data_[i][j]=matrix.data_[i][j];
        }
    }
    return matrix_copy;
}
// Возвращает сумму двух матриц.
// Если операция невозможна - вернуть пустую матрицу
Matrix Add(const Matrix& a, const Matrix& b)
{
    if ((a.m_==b.m_)&&(a.n_==b.m_))
    {
        Matrix matrix_res;
        Construct(matrix_res,a.n_,a.m_);
        for (size_t i=0;i<a.n_;++i)
    {
        for(size_t j=0;j<a.m_;++j)
        {
            matrix_res.data_[i][j]=a.data_[i][j]+b.data_[i][j];
        }
    }
    return matrix_res;
    }
    return Matrix();
}
// Возвращает разницу двух матриц.
// Если операция невозможна - вернуть пустую матрицу
Matrix Sub(const Matrix& a, const Matrix& b)
{
    if ((a.m_==b.m_)&&(a.n_==b.m_))
    {
        Matrix matrix_res;
        Construct(matrix_res,a.n_,a.m_);
        for (size_t i=0;i<a.n_;++i)
    {
        for(size_t j=0;j<a.m_;++j)
        {
            matrix_res.data_[i][j]=a.data_[i][j]-b.data_[i][j];
        }
    }
    return matrix_res;
    }
    return Matrix();
}
// Возвращает произведение двух матриц.
// Если операция невозможна - вернуть пустую матрицу
Matrix Mult(const Matrix& a, const Matrix& b)
{
   if ((a.m_==b.m_)&&(a.n_==b.m_))
    {
        Matrix matrix_um;
        Construct(matrix_um,a.n_,a.m_);
        for (size_t i=0;i<a.n_;++i)
    {
        for(size_t j=0;j<a.m_;++j)
        {
            for(size_t k=0;k<a.n_;++k)
            {
                matrix_um.data_[i][j]+=a.data_[i][j]*b.data_[i][j];
            }
        }
    }
    return matrix_um;
    }
    return Matrix();
}

// Транспонирование матрицы.
void Transposition(Matrix&x)
{
    Matrix matrix_res;
    Construct(matrix_res,x.n_,x.m_);
    for(size_t i=0;i<matrix_res.n_;++i)
    {
        for (size_t j=0; j<matrix_res.m_;++j)
        {
            matrix_res.data_[i][j]=x.data_[i][j];
        }
    }
    x.n_=matrix_res.n_;
    x.m_=matrix_res.m_;
    Construct(x,x.n_,x.m_);
    for(size_t i=0;i<matrix_res.n_;++i)
    {
        for (size_t j=0; j<matrix_res.m_;++j)
        {
            x.data_[i][j]=matrix_res.data_[j][i];
        }
    }
    Destruct(matrix_res);

}

int main()
{
    Matrix m1;
    Construct(m1,3,3);
    for(size_t i=0;i<3;++i)
    {
        for(size_t j=0;j<3;++j)
        {
            m1.data_[i][j]=rand();
        }
    }
    Matrix m2;
    Construct(m2,3,3);
    for(size_t i=0;i<3;++i)
    {
        for(size_t j=0;j<3;++j)
        {
            m2.data_[i][j]=rand();
        }
    }
    m1=Add(m1,m2);
    for(size_t i=0;i<3;++i)
    {
        for(size_t j=0;j<3;++j)
        {
            cout<<m1.data_[i][j]<<"\t";

        }cout<<"\n";
    }

    return 0;
}
