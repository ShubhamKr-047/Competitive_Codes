int merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    int cnt = 0;
    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            cnt += (mid - left + 1);
            right++;
        }
    }
    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }
    for (int i = low; i <= high; i++)  arr[i] = temp[i - low];
    return cnt;
}

int mrege_sort(vector<int> &arr, int low, int high)
{
    int cnt = 0;
    if (low >= high) return cnt;
    int mid = (low + high) / 2 ;
    cnt += mrege_sort(arr, low, mid);
    cnt += mrege_sort(arr, mid + 1, high);
    cnt += merge(arr, low, mid, high);
    return cnt;
}

int count_inversions(vector<int>&a, int n)
{
    return mrege_sort(a, 0, n - 1);
}
