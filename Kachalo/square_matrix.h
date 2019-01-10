#ifndef SQUARE_MATRIX_H
#define SQUARE_MATRIX_H
#include "new_matrix.h"

class sqar_matrix : public New_Matrix{
public:
    sqar_matrix(int N ) : New_Matrix(N, N){}
    sqar_matrix & obratnaya();
    int DET();
};

#endif // SQUARE_MATRIX_H
