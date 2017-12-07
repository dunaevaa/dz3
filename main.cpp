#include <iostream>
#include <string>
#include <cstring>
#include <locale>
#include <cstdlib>
using namespace std;

void print_Matrix (int **Matrix, int m, int n) {
    if (Matrix == nullptr) cout << "Matrix is empty" << endl;
    else {
          for (int i=0; i<m; i++) {
               for (int j=0; j<n; j++)
                    cout << Matrix[i][j] << " ";
		cout << endl;
            }
    }
}    
void deleting_Matrix (int **Matrix, int &m, int &n) {
    if (Matrix != nullptr) {
        for (int i=0; i<m; i++) delete [] Matrix[i];
        delete [] Matrix;
    }
}

void menu() {
     cout << "Выберите одну из операций" << endl;
     cout << "1.Вывести матрицу" << endl;
     cout << "2.Сложить матрицу" << endl;
     cout << "3.Умножить матрицу" << endl;
     cout << "4.Транспонировать матрицу" << endl;
     cout << "5.Сохранить в файл" << endl;
     cout << "6.Загрузить из файла" << endl;
     cout << "7.Сортировать матрицу" << endl;
     cout << "8.Завершить работу программы" << endl;
}
     
int main (int argc, char *argv[]) {
    setlocale (LC_ALL, "Russia");
    string str1, str2;
    int m, n, int1;
    int a=0;
    int **Matrix;
    if (argc == 1) {
        m=n=0;
        Matrix = nullptr;
    } else {
            while (argv[1][a] != 'x') {
                   str1 += argv[1][a];
                   a++;
            }
            a++;
            while (a != strlen(argv[1])) {
                   str2 += argv[1][a];
                   a++;
            }
            a=0;
            m = atoi (str1.c_str());
            n = atoi (str2.c_str());
            Matrix = new int *[m];
            for (int i=0; i<m; i++)
                 Matrix[i] = new int [n];
            for (int i=0; i<m; i++) {
                for (int j=0; j<n; j++)
                     Matrix[i][j] = 0;
            }
            if (argc == 2) {} 
            else {
                    if (argc == 3) {
                        string m_array;
                        m_array = argv[2];
                        string int1_str;
                        for (int i=0; i<m; i++) {
                            for (int j=0; j<n; j++) {
                                if (a < m_array.length()) {
                                    for (int b = a; b < m_array.length(); b++) {
                                        if (m_array[b] == ',') {
                                            a++;
                                            break;
                                        }
                                        int1_str += m_array[b];
                                        a++;
                                    }
                                    if (int1_str != "") {
                                        int1 = atoi (int1_str.c_str());
                                        Matrix[i][j] = int1;
                                    }
                                    int1_str = "";
                                }
                            }
                        
                        }
                    } else {
                            int b = 2;
                            for (int i=0; i<m; i++) {
                                for (int j=0; j<n; j++) {
                                    if (b < argc) {
                                                   int1 = atoi (argv[b]);
                                                   Matrix[i][j] = int1;
                                                   b++;
                                    }
                                }
                            }
                        }
            }
    menu ();
    int choise = 0;
    cin >> choise;
    switch (choise) {
                    case 1: print_Matrix (Matrix, m, n);
    }

 }  
deleting_Matrix (Matrix, m, n);
}
