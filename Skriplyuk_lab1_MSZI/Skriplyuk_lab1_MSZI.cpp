// Skriplyuk_lab1_MSZI.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
using namespace std;

void Skriplyuk_encryption(string password, string output_file, string input_file)
{
    char sym;
    ofstream output;
    ifstream input;
    output.open(output_file + ".txt", ios::out);
    input.open(input_file + ".txt", ios::in);
    int number = 0;
    while (true)
    {
        input.get(sym);
        if (input.eof()) break;
        output << (unsigned char)(sym + password[number]);
        if (number % password.length() == 0) number = 0;
        else number++;
    }
}

void Skriplyuk_decryption(string password, string output_file, string input_file)
{
    char sym;
    ofstream output;
    ifstream input;
    output.open(output_file + ".txt", ios::out);
    input.open(input_file + ".txt", ios::in);
    int number = 0;
    while (true)
    {
        input.get(sym);
        if (input.eof()) break;
        output << (unsigned char)(sym - password[number]);
        if (number % password.length() == 0) number = 0;
        else number++;
    }
}

void Skriplyuk_files_and_password(string& password, string& input_file, string& output_file)
{
    cout << "Введите название входного файла: ";
    cin >> input_file;
    cout << "Введите название выходного файла: ";
    cin >> output_file;
    cout << "Введите пароль: ";
    cin >> password;
}
int main()
{
    setlocale(LC_ALL, "Russian");
    string password, input_file, output_file;
    cout << "Введите 1 - зашифровать файл; 2 - расшифровать файл" << endl;
    int command;
    cin >> command;
    switch (command)
    { 
    case 1:
    {
        Skriplyuk_files_and_password(password, input_file, output_file);
        Skriplyuk_encryption(password, output_file, input_file);
        break;
    }
    case 2:
    {
        Skriplyuk_files_and_password(password, input_file, output_file);
        Skriplyuk_decryption(password, output_file, input_file);
        break;
    }
    }
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
