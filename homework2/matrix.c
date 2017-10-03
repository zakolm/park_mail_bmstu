#include "matrix.h"

Matrix* create_matrix(int row, int col) {
	// ����� ��-��
	Matrix *matrix = malloc(sizeof(*matrix));
	if ( !matrix ) {
		return NULL;
	}
	// ��������� ������ + �������� ������ ��� ������� �� ���������.
	matrix->columns = col; matrix->rows = row;
	matrix->data = malloc(sizeof(matrix->data)*row);
	if ( !matrix ) {
		return NULL;
	}
	// �������� ������ �� ��� ��������.
	for ( int i = 0; i < row; ++i ) {
		matrix->data[i] = malloc(sizeof(matrix->data)*col);
		if ( !matrix ) {
			return NULL;
		}
	}

	return matrix;
}

Matrix* create_matrix_from_file(FILE* file) {
	int row, col;
	fscanf(file,"%d",&row); fscanf(file,"%d",&col);

	Matrix *matrix = create_matrix(row, col);
	if ( !matrix ) {
		return NULL;
	}
	// ��������� \n ��� ��������� �� ����� �����
	while( fgetc(file) != '\n' && !feof(file) );
	if (feof(file)) {
		return NULL;
	}

	row = 0; col = 0;
	while( !feof(file) ) {
		// ���� ����� �������� �� �������������, �� ��������� ������ � ������ ������.
		if ( (row+1) > matrix->rows ) {
			return NULL;
		}
		int numbers_count_in_line = count_numbers_in_line(file);
		if ( numbers_count_in_line != matrix->columns ) {
			return NULL;
		}

		for ( col = 0; col < matrix->columns; ++col ){
			double scan_item;
			fscanf(file, "%lf", &scan_item);
			set_elem(matrix, row, col, scan_item);
		}
		while( fgetc(file) != '\n' && !feof(file) );

		row++;
	}

	return matrix;
}

void free_matrix(Matrix* matrix) {
	for ( int i = 0; i < matrix->rows; ++i ) {
		free(matrix->data[i]);
	}
	free(matrix->data);
	free(matrix);
}

static int count_numbers_in_line(FILE *file) {
	long address = ftell(file);
	int count = 0;
	char item, prev_item = 0;

	while (!feof(file) && (item = fgetc(file)) != '\n') {
		if (!isspace(item)) {
			if (prev_item == 0 || isspace(prev_item)) {
				count++;
			}
		}
		prev_item = item;
	}
	fseek(file, address, SEEK_SET);

	return count;
}

double get_elem(Matrix* matrix, int row, int col) {
	return matrix->data[row][col];
}

void set_elem(Matrix* matrix, int row, int col, double val) {
	matrix->data[row][col] = val;
}

int get_rows(Matrix* matrix) {
	return matrix->rows;
}

int get_cols(Matrix* matrix) {
	return matrix->columns;
}
