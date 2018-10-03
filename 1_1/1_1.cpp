#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;

bool isprime(int n);

int main()
{
    int datalen = 0;
    int num[100], flag[100];

    ifstream infile;
    infile.open("C:/Users/84566/Desktop/data structure/Data-structure/1_1/data.txt");
    while (!infile.eof())
        infile >> num[datalen++];
    infile.close();

    for (int i = 0; i < datalen; i++)
        flag[i] = isprime(num[i]);

    ofstream fout;
    fout.open("C:/Users/84566/Desktop/data structure/Data-structure/1_1/conclution.txt"); //����һ��.txt���ļ�
    for (int i = 0; i < datalen; i++)
        fout << flag[i] << ' '; //��������ֵд���ļ�
    fout.close();               //�ر��ļ�

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