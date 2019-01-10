#ifndef NEW_MATRIX_H
#define NEW_MATRIX_H


class New_Matrix
{
public:
    New_Matrix(int, int);
    New_Matrix(int, int, float);
    ~New_Matrix();
    float get_value(int, int);
    void set_value(int, int, float);
    New_Matrix & transp();
    int Rank();
    New_Matrix & operator*(New_Matrix &);
    New_Matrix & operator+(New_Matrix &);
    New_Matrix & operator= (New_Matrix &);
    int N,M;
//    void  resize_to(int, int);
protected:
    float ** matrix;

};

#endif // NEW_MATRIX_H
