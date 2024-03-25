// initailly matrix store direct path from one edge to other if there exist one otherwise INF
// matrix stores min path from one vertex to other
// if for any cell it's value < 0 then there exist a negative cycle

void floyd_warshall(vector<vector<int>> matrix)
{
    int n = matrix.size();
    for (int via = 0; via < n; via++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                matrix[i][j] = min(matrix[i][j], matrix[i][via] + matrix[via][j]);
            }
        }
    }
}