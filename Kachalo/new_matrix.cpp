#include "new_matrix.h"
#include "square_matrix.h"
#include "stdlib.h"
#include "cmath"

void GetMatr(int **mas, int **p, int i, int j, int m) {
  int ki, kj, di, dj;
  di = 0;
  for (ki = 0; ki<m - 1; ki++) {
    if (ki == i) di = 1;
    dj = 0;
    for (kj = 0; kj<m - 1; kj++) {
      if (kj == j) dj = 1;
      p[ki][kj] = mas[ki + di][kj + dj];
    }
  }
}
int det_mat(int **mas, int m) {
    int i, j, d, k, n;
    int **p;
    p = new int*[m];
    for (i = 0; i<m; i++)
      p[i] = new int[m];
    j = 0; d = 0;
    k = 1;
    n = m - 1;
    if (m == 1) {
      d = mas[0][0];
      return(d);
    }
    if (m == 2) {
      d = mas[0][0] * mas[1][1] - (mas[1][0] * mas[0][1]);
      return(d);
    }
    if (m>2) {
      for (i = 0; i<m; i++) {
        GetMatr(mas, p, i, 0, m);
        d = d + k * mas[i][0] * det_mat(p, n);
        k = -k;
      }
    }
    for(int i=0; i < m;i++)
    return(d);
  }
int l_min(int a, int b){
    if(a>=b)return b;else return a;
}

int rang_mat(float* A[], int i, int j){
    int r = 0;
    int q = 1;
    while(q<=l_min(i,j)){
        int **B = new int*[q];
        for(int w=0;w<q;w++) B[w] = new int[q];
        for(int a=0;a<(i-(q-1));a++){
            for(int b=0;b<(j-(q-1));b++){
                for(int c=0;c<q;c++){
                    for(int d=0;d<q;d++){
                        B[c][d] = A[a+c][b+d];
                    }
                }
                if(!(det_mat(B,q)==0)){
                    r = q;
                }
            }
        }
        q++;
    }
 return r;
}
void Get_matr(float **matr, int n, int **temp_matr, int indRow, int indCol)
{
    int ki = 0;
    for (int i = 0; i < n; i++){
        if(i != indRow){
            for (int j = 0, kj = 0; j < n; j++){
                if (j != indCol){
                    temp_matr[ki][kj] = matr[i][j];
                    kj++;
                }
            }
            ki++;
        }
    }
}

float New_Matrix::get_value(int n, int m){
    return matrix[n][m];
}
void New_Matrix::set_value(int n, int m, float data){
    matrix[n][m] = data;
}
New_Matrix & New_Matrix :: transp(){
    float a[M][N];
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            a[j][i] = matrix[i][j];
    for (int i=0; i<N; i++) delete [] matrix[i];
    delete [] matrix;
    int swap;
    matrix = new float *[M];
       for (int i = 0; i < M; i++){
           matrix[i] = new float [N];
           for(int j=0;j<N;j++)
                matrix[i][j] = a[i][j];
       }

       swap = N;
       N=M;
       M=swap;
}
int New_Matrix::Rank(){
   return rang_mat(matrix,N,M);
}
New_Matrix & New_Matrix ::operator+(New_Matrix & mx2){
   for(int i =0; i<N;i++)
       for(int j=0;j<M;j++)
           matrix[i][j] = matrix [i][j] + mx2.get_value(i,j);
   return *this;

}
New_Matrix & New_Matrix::operator*(New_Matrix & mx2){
    New_Matrix C(N,mx2.M);
    for(int i = 0; i < N; i++)
        for(int j = 0; j < mx2.M; j++)
            for(int k = 0; k < M; k++)
                C.set_value(i,j,C.get_value(i,j)+(matrix[i][k]) *(mx2.get_value(k,j)));
    mx2 = C;
   return mx2;
}
New_Matrix & New_Matrix :: operator=(New_Matrix & mx2){
    for (int i=0; i<N; i++) delete [] matrix[i];
    delete [] matrix;
    N=mx2.N;
    M=mx2.M;
    matrix = new float *[N];
       for (int i = 0; i < N; i++)
           matrix[i] = new float [M];
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
           matrix[i][j] = mx2.get_value(i,j);
    return *this;
}
sqar_matrix & sqar_matrix :: obratnaya(){
    int n=N, det;
        int **matr = new int * [N];
        float **obr_matr = new float*[N];
        for(int i = 0; i < n; i++){
            matr[i] = new int[n];
            obr_matr[i] = new float[n];
        }
        for (int i=0; i< N; i++)
            for(int j=0;j<N;j++){
                matr[i][j]= matrix[i][j];
            }
        det = det_mat(matr, N);
        if(det!= 0){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    int m = n - 1;
                    int **temp_matr = new int * [m];
                    for(int k = 0; k < m; k++)
                        temp_matr[k] = new int[m];
                    Get_matr(matrix, n, temp_matr, i, j);
                    obr_matr[i][j] = pow(-1.0, i + j + 2) * det_mat(temp_matr, m) / det;
                    for (int i=0; i<m; i++) delete [] temp_matr[i];
                    delete [] temp_matr;
                }
            }
            for (int i=0; i< N; i++)
                for(int j=0;j<N;j++){
                    matrix[i][j]= obr_matr[i][j];
                }
        }
        return *this;
}
New_Matrix::New_Matrix(int n, int m)
{
    N=n; M=m;
    matrix = new float *[N];
       for (int i = 0; i < N; i++){
           matrix[i] = new float [M];
           for(int j=0;j<M;j++)
               matrix[i][j]=0;
       }
}
New_Matrix::New_Matrix(int n, int m, float data)
{
    N=n; M=m;
    matrix = new float *[N];
       for (int i = 0; i < N; i++){
           matrix[i] = new float [M];
           for(int j=0;j<M;j++)
               matrix[i][j]=data;
       }
}
New_Matrix :: ~New_Matrix(void){
    for (int i=0; i<N; i++) delete [] matrix[i];
    delete [] matrix;
}
int sqar_matrix :: DET(){
    int **matr = new int * [N];
    for(int i = 0; i < N; i++)
        matr[i] = new int[N];
        for (int i=0; i< N; i++)
            for(int j=0;j<N;j++)
                matr[i][j]= matrix[i][j];
    return det_mat(matr, N);
}
