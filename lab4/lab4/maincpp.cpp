/*1. Каждый элемент aij матрицы A(m, n) заменить суммой элементов подматрицы A’(i, j),
расположенной в левом верхнем углу матрицы A.
Входную матрицу следует читать из файла in.txt
(первые два числа в файле – размерности матрицы, далее – элементы матрицы),
матрицу - результат следует записывать в файл out.txt
(первые два числа в файле – размерности матрицы, далее – элементы матрицы).
Автор Ларенкова Альбина
13501 / 4
*/


#include <iostream>
#include <fstream>
#include <iomanip>
#include <locale.h>
using namespace std;
//заполнение массива из файла.
void read(int m, int n, int **mat){
	int i, j;
	ifstream fin("in.txt");						// Проверка на существование не требуется т.к. в случае отсутствия файла ошибка будет выдана до запуска функции.
	fin >> i >> j;
	while (!fin.eof()){
		for (i = 0; i < m; i++){
			for (j = 0; j < n; j++){
				fin >> mat[i][j];
			}
		}
	}
	fin.close();
}
//запись массива в файл
void write(int m, int n, int **mat){
	ofstream fout("out.txt");                  // Проверка на существование не требуется т.к. в случае отсутствия файл будет создан.
	int i, j;

	fout << m << "  " << n << endl;
	for (i = 0; i < m; i++){
		for (j = 0; j < n; j++){
			fout << setw(4) << mat[i][j] << " ";
		}
		fout << endl;
	}
	fout.close();
}
//преобразования в массиве
void change(int m, int n, int **mat){
	int i, j, a, b;

	int **arr;
	arr = new int*[m];
	for (i = 0; i < m; i++)
		arr[i] = new int[n];
	int c = 0;
	for (i = 0; i < m; i++){
		for (j = 0; j < n; j++){
			for (a = 0; a <= i; a++){
				for (b = 0; b <= j; b++){
					c = c + mat[a][b];
				}
			}
			arr[i][j] = c;
			c = 0;
		}
	}

	for (i = 0; i < m; i++)
	for (j = 0; j < n; j++)
		mat[i][j] = arr[i][j];

	for (i = 0; i < m; i++)
		delete[] arr[i];
	delete[] arr;

}

int main(void){
	ifstream fin("in.txt");
	if (fin.is_open()) {         // Проверка на существование файла.
	int  n, m, i;
	fin >> m >> n;
	int **mat;
	mat = new int*[m];
	for (i = 0; i < m; i++)
		mat[i] = new int[n];
								// Вызов функций.
	read(m, n, mat);
	change(m, n, mat);
	write(m, n, mat);
								// Очистка памяти.
	fin.close();
	for (i = 0; i < m; i++)
		delete[] mat[i];
	delete[] mat;
	return 0;
	}
	else {						// Вывод ошибки в случае, если файл отсутствует.
		cout << "Error opening file" << endl;
		system("pause");
	}
}
