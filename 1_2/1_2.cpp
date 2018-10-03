#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;

int sum(int n);

int main()
{
    cout << "Note that: The file storage location in the code needs to be modified!! due to running on different computers."
         << endl
         << "The data set of N is in file 'input.txt'." << endl;

    int datalen = 0;
    int num[100], sum_of_n[100];

    ifstream infile;
    infile.open("C:/Users/84566/Desktop/data structure/Data-structure/1_2/input.txt");
    while (!infile.eof())
        infile >> num[datalen++];
    infile.close();

    for (int i = 0; i < datalen; i++)
    {
        sum_of_n[i] = sum(num[i]);
        cout << ". ";
    }

    ofstream fout;
    fout.open("C:/Users/84566/Desktop/data structure/Data-structure/1_2/output.txt"); //创建一个.txt的文件
    for (int i = 0; i < datalen; i++)                                                 //将变量的值写入文件
        fout << "The sum of (1-2+3-4+...+/-N) for N=" << num[i] << " is: " << sum_of_n[i] << endl;
    fout.close(); //关闭文件

    cout << endl
         << "The result of the sum has been saved in file 'output.txt'." << endl;

    system("pause");
    return 0;
}

int sum(int n)
{
    if ((n % 2) == 0)
        return -n / 2;
    else
        return (n + 1) / 2;
}