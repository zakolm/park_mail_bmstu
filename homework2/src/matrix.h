#ifndef __MATRIX__H__
#define __MATRIX__H__

#include <stdio.h>

typedef struct Matrix {
    int rows;
    int columns;
    double **data;
} Matrix;

Matrix* create_matrix_from_file(FILE* file);
Matrix* create_matrix(int row, int col);
void free_matrix(Matrix* matrix);
double get_elem(Matrix* matrix, int row, int col);
void set_elem(Matrix* matrix, int row, int col, double val);
int get_rows(Matrix* matrix);
int get_cols(Matrix* matrix);

#endif //__MATRIX__H__
