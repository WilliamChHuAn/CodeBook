// Binary Indexed Tree
// Build: O(NlogN)
// Space: O(N)
// update: O(logN)
// Cal Interval Sum: O(logN)
const int N = 10000000;
int t[N + 1]; // 第零格無作用，數列從第一項到第 N 項
// 快速求出最低位的 bit (1)
int lower_bit(int n){
    return n & -n;
}
// value[1] + value[2] + ... + value[n]
int sum(int n){
    int s = 0;
    while (n > 0){
        s = s + t[n];
        n = n - lower_bit(n);
    }
    return s;
}
// value[n] = value[n] + d
void add(int n, int d){
    while (n <= N){
        t[n] = t[n] + d;
        n = n + lower_bit(n);
    }
}
// value[a] + value[a+1] + ... + value[b]
int query(int a, int b){
    if (a > b){
        swap(a, b);
    }
    return sum(b) - sum(a - 1);
}