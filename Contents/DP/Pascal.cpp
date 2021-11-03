// init：f(i, 0) = f(i, i) = 1
// tren：f(i, j) = f(i - 1, j) + f(i - 1, j - 1)
#define N 30
int dp[N][N];
void Pascal_Traingle(void){
    for(int i = 0; i < N; i++){
        dp[i][0] = dp[i][i] = 1;
        for(int j = 1; j < i; j++){
            dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
        }
    }
}