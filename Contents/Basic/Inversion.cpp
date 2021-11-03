#define L 500010
int arr[L], buf[L];

long long sol(int left, int right){
    if (right - left <= 1){
        return 0;
    }
    int middle = (right + left) / 2;
    long long ans = sol(left, middle) + sol(middle, right);
    int i = left, j = middle, k = left;
    while (i < middle || j < right){
        if (i >= middle){
            buf[k] = arr[j++];
        }
        else if (j >= right){
            buf[k] = arr[i++];
        }
        else{
            if (arr[i] <= arr[j]){
                buf[k] = arr[i++];
            }
            else{
                buf[k] = arr[j++];
                ans += middle - i;
            }
        }
        k++;
    }
    for (int k = left; k < right; k++){
        arr[k] = buf[k];
    }
    return ans;
}