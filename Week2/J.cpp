#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<vector<int>> Matrix;


Matrix normalize_rows(const Matrix &mat) {
    Matrix res = mat;
    for (int i = 0; i < res.size(); ++i) {
        sort(res[i].begin(), res[i].end());
    }
    sort(res.begin(), res.end());
    return res;
}


Matrix normalize_cols(const Matrix &mat) {
    int n = mat.size(), m = mat[0].size();
    Matrix transposed(m, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            transposed[j][i] = mat[i][j];
    return normalize_rows(transposed);
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        Matrix a(n, vector<int>(m));
        Matrix b(n, vector<int>(m));

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                cin >> a[i][j];

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                cin >> b[i][j];

        Matrix rows_a = normalize_rows(a);
        Matrix rows_b = normalize_rows(b);

        Matrix cols_a = normalize_cols(a);
        Matrix cols_b = normalize_cols(b);

        if (rows_a == rows_b && cols_a == cols_b)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
