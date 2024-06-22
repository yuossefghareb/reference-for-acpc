// 2d prefix sum
for (int i = 1; i <= N; i++)
{
    for (int j = 1; j <= N; j++)
    {
        prefix[i][j] = forest[i][j] + prefix[i - 1][j] +
                       prefix[i][j - 1] - prefix[i - 1][j - 1];
    }
}

for (int q = 0; q < Q; q++)
{
  int x1, x2, y1, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  cout << prefix[x2][y2] - prefix[x1 - 1][y2] -prefix[x2][y1 - 1] +prefix[x1 - 1][y1 - 1]<< '\n';
}
