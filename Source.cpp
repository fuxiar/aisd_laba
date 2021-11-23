#include <locale.h>
#include <conio.h>
#include <iostream>
#include <ostream>
#include "Matrix.h"
using namespace std;

int get_key()
{
    int key = _getch();
    if ((key == 0) || (key == 224))
        key = _getch();
    return key;
}

int menu1()
{
    cout << "\nКласс Матрицы.\n\n"
        "1 - Посмотреть/изменить исследуемые матрицы.\n"
        "2 - Сложение матриц\n"
        "3 - Разность матриц\n"
        "4 - Произведение матриц\n"
        "5 - Умножение матрицы на скаляр\n"
        "6 - Деление матрицы на скаляр\n"
        "7 - Вычисление следа матрицы\n\n"
        "Выход: Esc";


    while (true)
    {
        int key = get_key();
        if ((key == 27) || (key > '0' && key <= '7'))
            return key;
    }
}

int menu2()
{
    cout << "\n\n";
    cout << "Продолжить: Enter";
    while (true)
    {
        int key = get_key();
        if (key == 13) return key;
    }
}

int menu3()
{
    cout << "1 - да\n2 - нет";
    while (true)
    {
        int key = get_key();
        if (key == '1' || key == '2') return key;
    }
}

//input control

//double
bool double_control(char* xn)
{
    char* tmp = xn;
    int zap_p = 0;
    const char mask[] = ".-1234567890";
    int checker = 0;
    while (*tmp)
    {
        if (strchr(mask, *tmp)) checker++;
        tmp++;
    }
    if (checker != strlen(xn))
        return false;
    if (checker == 0)
        return false;

    if (*xn == '-' && *(xn + 1) == '\0')
    {
        return false;
    }
    if ((*xn == ','))
        return false;

    tmp = xn;
    while (*tmp)
    {
        if ((*tmp == ','))
        {
            zap_p++;
        }
        if ((*(tmp + 1) == '-') || (*tmp == '\0'))
        {
            return false;
        }
        tmp++;
    }
    if (zap_p > 1) return false;
    return true;
}

double double_checker()
{
    char n_data[64];
    while (true) {
        gets_s(n_data);
        bool check = double_control(n_data);
        if (check == true) break;
        else
        {
            cout << "  Неверный формат данных! Повторите попытку: ";
        }
    }
    double data = (double)atof(n_data);
    return data;
}

//int
bool int_control(char* xn)
{
    char* tmp = xn;
    int zap_p = 0;
    const char mask[] = "-1234567890";
    int checker = 0;
    while (*tmp)
    {
        if (strchr(mask, *tmp)) checker++;
        tmp++;
    }
    if (checker != strlen(xn))
        return false;
    if (checker == 0)
        return false;

    if (*xn == '-' && *(xn + 1) == '\0')
    {
        return false;
    }
    if ((*xn == ','))
        return false;

    tmp = xn;
    while (*tmp)
    {
        if ((*tmp == ','))
        {
            zap_p++;
        }
        if ((*(tmp + 1) == '-') || (*tmp == '\0'))
        {
            return false;
        }
        tmp++;
    }
    if (zap_p > 1) return false;
    return true;
}

int int_checker()
{
    char n_data[64];
    while (true) {
        gets_s(n_data);
        bool check = int_control(n_data);
        if (check == true) break;
        else
        {
            printf("  Неверный формат данных! Повторите попытку: ");
        }
    }
    int data = (int)atoi(n_data);
    return data;
}

Matrix operator * (double h, Matrix matrix);
Matrix operator / (double h, Matrix matrix);
std::ostream& operator << (std::ostream& s, const Matrix& matrix);

int main() {
    setlocale(LC_ALL, "");

    Matrix A(2, 2), B(2, 2), C(2, 2);
    A(0, 0) = 1;
    A(0, 1) = 2;
    A(1, 0) = 3;
    A(1, 1) = 4;

    B(0, 0) = 1;
    B(0, 1) = 2;
    B(1, 0) = 3;
    B(1, 1) = 4;

    Matrix jajaja(A);
    cout << jajaja;
    while (true) {
        system("cls");
        int m1 = menu1();
        switch (m1) {
        case 27: return 0;
        case 49: {
            system("cls");
            cout << "\tИсследуемые матрицы:\n\n";
            cout << "A:\n" << A << endl;
            cout << "B:\n" << B;

            cout << "\n\nХотите изменить матрицы?" << endl;
            int m3 = menu3();
            switch (m3) {
            case 49: {
                system("cls");
                cout << "\n--------Задание матрицы А--------" << endl;
                A.EnterMatrix();

                cout << "\n--------Задание матрицы B--------" << endl;
                B.EnterMatrix();

                break;
            }
            case 50: {
                break;
            }
            }

            break;
        }
        case 50: {
            system("cls");
            cout << "\tСложение матриц.\n\n";
            bool check = 0;
            try {
                C = A + B;
                check = 1;
            }
            catch (const char* message) {
                cout << message;
            }

            if (check) {
                cout << "A + B:\n\n" << endl;
                cout << A << "\n +\n\n" << B << "\n = \n\n";
                cout << A + B;
            }

            break;
        }
        case 51: {
            system("cls");
            cout << "\tРазность матриц.\n\n";
            bool check = 0;
            try {
                C = A - B;
                check = 1;
            }
            catch (const char* message) {
                cout << message;
            }

            if (check) {
                C = A - B;
                cout << "A - B:\n\n" << endl;
                cout << A << "\n -\n\n" << B << "\n = \n\n";
                cout << C;
            }

            break;
        }
        case 52: {
            system("cls");
            cout << "\tУмножение матриц.\n\n";
            bool check = 0;
            try {
                C = A * B;
                check = 1;
            }
            catch (const char* message) {
                cout << message;
            }

            if (check) {
                C = A * B;
                cout << "A * B:\n\n" << endl;
                cout << A << "\n *\n\n" << B << "\n = \n\n";
                cout << C;
            }

            break;
        }
        case 53: {
            system("cls");
            cout << "\tУмножение матрицы на скаляр.\n\n";
            double a;
            cout << "Введите значение (скаляр): ";
            a = double_checker();
            cout << "A * a:\n\n" << endl;
            cout << A << "\n *\n\n " << a << "\n\n = \n\n";
            C = A * a;
            cout << C;

            break;
        }
        case 54: {
            system("cls");
            cout << "\tДеление матрицы на скаляр.\n\n";
            double a;
            cout << "Введите значение (скаляр): ";
            a = double_checker();
            //  cin.get();
            cout << "A \ a:\n\n" << endl;
            cout << A << "\n /\n\n " << a << "\n\n = \n\n";
            C = A / a;
            cout << C;

            break;
        }
        case 55: {
            system("cls");
            cout << "\tВычисление следа матрицы.\n\n";
            cout << "Tr(A) = " << A.tr();
            break;
        }

        }
        while (true)
        {
            int m2 = menu2();
            if (m2 == 13) break;
        }
    }
}