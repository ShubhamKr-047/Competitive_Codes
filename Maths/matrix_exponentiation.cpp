/*

ans matrix stores the final result (TC :- dim^3 * log(pow))
to calculate nth fibonacci number
take 1st matrix as [0 1] and 2nd matrix ans |0 1|
                                            |1 1|

[F1 F2] * |0 1|^(n - 1) = [Fn Fn+1]
          |1 1|

*/

vector<vector<int>> matrix_multiplication(int &dim, vector<vector<int>> &a, vector<vector<int>> &b)
{
    vector<vector<int>> mul(dim, vector<int> (dim, 0));
    for (int i = 0; i < dim; i++) 
    {
        for (int j = 0; j < dim; j++) 
        {
            for (int k = 0; k < dim; k++) 
            {
                mul[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return mul;
}

void matrix_exponentiation(int &dim, int &pw, vector<vector<int>> &mat, vector<vector<int>> &ans)
{
    int i = 0, j = 0;
    while (i < dim) ans[i][j] = 1, i++, j++;
    while (pw) 
    {
        if (pw & 1LL) ans = matrix_multiplication(dim, ans, mat);
        mat = matrix_multiplication(dim, mat, mat);;
        pw >>= 1LL;
    }
}

void solve()
{
    int dim, pw;
    cin >> dim >> pw;
    vector<vector<int>> mat(dim, vector<int> (dim));
    vector<vector<int>> ans(dim, vector<int> (dim, 0));
    for (auto &it : mat) cin >> it;
    matrix_exponentiation(dim, pw, mat, ans);
    for (auto &it : ans) cout << it;
}