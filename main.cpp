#include <iostream>
#include <string.h>
using namespace std;
void print_matrix (int **Matrix, int m, int n) {
    if (Matrix==nullptr) cout << "Matrix is empty" << endl;
    else {
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) cout<< Matrix[i][j] << " ";
            cout << endl;
        }
    }
}
void deleting_Matrix (int **Matrix, int &m, int &n) {
    if (Matrix!=nullptr) {
        for (int i=0; i<m; i++) delete [] Matrix[i];
        delete [] Matrix;
    }
}
void Menu (int **Matrix, int &m, int &n) {
    int choise;
    string exit;
    while ((exit != "y") && (exit != "yes") && (exit != "Y") && (exit != "Yes") &&
            (exit != "YES")) {
        cout << "Select one of the operations:" << endl;
        cout << "1.Print the matrix" << endl;
        cout << "2.Sum the matrix" << endl;
        cout << "3.Multiply the matrix" << endl;
        cout << "4.Transpose the matrix" << endl;
        cout << "5.Save to the file" << endl;
        cout << "6.Download from the file" << endl;
        cout << "7.Sort the matrix" << endl;
        cin >> choise;
        switch (choise) {
        case 1:
            print_matrix ( Matrix, m, n);
            break;
        }
    }
}

int main (int argc, char *argv []) {
    string m_str, n_str;
    int m, n, integer1;
    int k=0;
    int **Matrix;
    if (argc==1) {
        m=n=0;
        Matrix = nullptr;
    } else {
        while (argv[1][k]!= 'x') {
            m_str = m_str + argv[1][k];
            k++;
        }
        k++;
        while (k != strlen(argv[1])) {
            n_str = n_str + argv[1][k];
            k++;
        }
        k=0;
        m = atoi (m_str.c_str());
        n = atoi (n_str.c_str());
        Matrix = new int *[m];
        for (int i=0; i<m; i++) Matrix[i]= new int [n];
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++)
                Matrix[i][j]= 0;
        }
        if (argc == 2) { } else {
            if (argc == 3) {
                string matrix_array;
                matrix_array = argv[2];
                string integer_str;
                for (int i=0; i<m; i++) {
                    for (int j=0; j<n; j++) {
                        if (k < matrix_array.length()) {
                            for (int z = k; z < matrix_array.length(); z++) {
                                if (matrix_array[z] == ',') {
                                    k++;
                                    break;
                                }
                                integer_str = integer_str + matrix_array[z];
                                k++;
                            }
                            if (integer_str != "") {
                                integer1 = atoi(integer_str.c_str());
                                Matrix[i][j] = integer1;
                            }
                            integer_str = "";
                        }
                    }
                }

            } else {
                int z = 2;
                for (int i=0; i< m; i++) {
                    for (int j=0; j<n; j++) {
                        if (z < argc) {
                            integer1 = atoi(argv[z]);
                            Matrix[i][j] = integer1;
                            z++;
                        }
                    }
                }
            }
        }
    }
    Menu (Matrix, m,n);
    deleting_Matrix (Matrix, m,n);
}
