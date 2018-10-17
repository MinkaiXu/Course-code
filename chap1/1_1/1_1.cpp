#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;

bool isprime(int n);

int main()
{
    cout << "Note that: The file storage location in the code needs to be modified!! due to running on different computers."
         << endl
         << "The data set is in file 'input.txt'." << endl;

    int datalen = 0;
    int num[100], flag[100];

    ifstream infile;
    infile.open("C:/Users/84566/Desktop/data structure/Data-structure/chap1/1_1/input.txt");
    while (!infile.eof())
        infile >> num[datalen++];
    infile.close();

    for (int i = 0; i < datalen; i++)
    {
        flag[i] = isprime(num[i]);
        cout << ". ";
    }

    ofstream fout;
    fout.open("C:/Users/84566/Desktop/data structure/Data-structure/chap1/1_1/output.txt"); //创建一个.txt的文件
    for (int i = 0; i < datalen; i++)                                                 //将变量的值写入文件
    {
        fout << num[i];
        if (flag[i] == 1)
            fout << " is a prime number." << endl;
        else
            fout << " is not a prime number." << endl;
    }
    fout.close(); //关闭文件

    cout << endl
         << "The result has been saved in file 'output.txt'." << endl;

    system("pause");
    return 0;
}

bool isprime(int n)
{
    if (n <= 1)
        return false;
    if (n == 2)
        return true;
    if (n % 2 == 0)
        return false;
    for (int i = 3; i <= sqrt(n) + 1; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}