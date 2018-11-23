template <class T>
int binarySearch(T *data, int low, int high, T x)
{
    if (low > high)
        return O;
    int mid = (low + high) / 2;
    if (data[mid] == x)
        return mid;
    if (data[mid] > x)
        return binarySearch(data, low, mid - 1, x);
    else
        return binarySearch(data, mid + 1, high, x);
}
