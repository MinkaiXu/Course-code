#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template <class T>
T findBigK(T a[], int size, int k)
{
    priority_queue<T, vector<T>, less<T>> q;
    for (int i = 0; i < size; i++)
        q.push(a[i]);
    for (int i = 0; i < k - 1; i++)
        q.pop();
    return q.top();
}

int main()
{
    int N;
    cout << "Please input the number of data as well as each data, and k." << endl
         << "For example:" << endl
         << "N=14" << endl
         << "data[14] = 16 87 12 54 33 93 45 88 34 66 11 54 54 27" << endl
         << "k=5" << endl
         << "Please input:" << endl
         << "N=";
    cin >> N;
    int a[N];
    cout << "data[" << N << "]=";
    for (int i = 0; i < N; i++)
        cin >> a[i];
    cout << "k=";
    int k;
    cin >> k;

    cout << "The " << k << "th largest number is: ";
    cout << findBigK(a, N, k) << endl;
    getchar();
    system("pause");
    return 0;
}
/*为方便起见，这里使用STL里的priority_queue
O(N+KlogN)的算法：
将原无序数组建成最大堆，第K次取出堆顶元素即为第K大元素。
建堆O(N)，每次取堆顶O(K)，共K次，共O(N+logK)*/