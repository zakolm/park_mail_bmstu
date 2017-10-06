#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "matrix.h"
#define OK 0

/*
 *���������� ���������� �� ����������� �������� ����� ��������� ���������� ���������:
 *���������������� ������� �� ������� �����.
 *������ �������� ������ � ������ � �� �����������.
 *� ������ ������ ����� �������� ���������� ����� �������; �� ������ � ���������� �������� �������;
 *� ����������� ������� ����� �������� �������� ����� ����� ������� (�� ����� ������ ������� �� ����� ������ �����).
 *� �������� ����������� ������������� ������� � ������ ��������� ������������ ��������� ������ ������������ �����.
 *������� �������� �� ������ �������� �� ������������� ������� � ����� � � ������!
 *�.�. ��� ������ � �������� ������ ���� ����������� � ������������ � ��������� �������:
 *double get_elem(void *matr, int row, int col), ������� ���������� �������� �������� ������� �� ��� ��������,
 *void set_elem(void *matr, int row, int col, double elem), ������� ������������� �������� �������� ������� �� ��� ��������
 */

Matrix* transp(Matrix* matrix) {
	int col = get_cols(matrix);
	int row = get_rows(matrix);
	Matrix* result;
	result = create_matrix(col, row);
	if ( !result ) {
		return NULL;
	}
	
	for ( int i = 0; i < col; ++i ) {
		for ( int j = 0; j < row; ++j ) {
			set_elem(result, i, j, get_elem(matrix, j, i));
		}
	}
	
	return result;
}

void print_matrix(const Matrix* matrix) {
	for ( int i = 0; i < matrix->rows; ++i ) {
		for ( int j = 0; j < matrix->columns; ++j ) {
			printf("%f ", matrix->data[i][j]);
		}
		printf("\n");
	}
}

int main(int argc, char** argv) {
	if ( argc != 2 ) {
		printf("%s\n", strerror(EIO));
		printf("Run program this way: ");
		printf("./example.exe <name file>\n");
		return EIO;
	}

	FILE *file = fopen(argv[1], "r");
	if( !file ) {
		printf("%s", strerror(errno));
		return errno;
	}

	Matrix* matrix;
	matrix = create_matrix_from_file(file);
	if ( !matrix ) {
		printf("%s\n", strerror(ENOMEM));
		return ENOMEM;
	}

	print_matrix(matrix);
	matrix = transp(matrix);
	if ( !matrix ) {
		printf("%s\n", strerror(ENOMEM));
		return ENOMEM;
	}
	printf("\n\n");
	print_matrix(matrix);

	free_matrix(matrix);
	fclose(file);

	return OK;
}
