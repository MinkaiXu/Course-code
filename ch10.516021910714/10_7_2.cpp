#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template <class T>
T findBigK(T a[], int size, int k)
{
    priority_queue<T, vector<T>, greater<T>> q;
    for (int i = 0; i < size; i++)
        if (q.size() < k)
            q.push(a[i]);
        else if (q.top() < a[i])
        {
            q.pop();
            q.push(a[i]);
        }
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
/*方便起见，这里使用STL里的priority_queue
O(NlogK)的算法：
建立最小二叉堆存放前K大的数，遍历原数组，如果当前访问到的元素比堆顶元素大，就取出堆顶，并把当前元素加进堆里。
保持二叉堆总成员为K，最后取出堆顶元素即为第K大。
每次操作堆O(logK)，最多N次，共O(NlogK)。*/