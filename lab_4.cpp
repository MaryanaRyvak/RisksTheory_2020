#include <iostream>

using namespace std;

int findMaxelem(double **a, int column, int n)
{
    double maxelem = a[0][column];
    int maxindex = 0;

    for (int i=1; i<=n; i++){
        if (a[i][column] > maxelem){
            maxelem = a[i][column];
            maxindex = i;
           }
    }
    return maxindex;
}

void exchangeRows(double **a,double *f,int index1,int m,int n)
{
    double temp = 0;
    for (int i = 0; i<=n; i++){
        temp = a[index1][i];
        a[index1][i] = a[m][i];
        a[m][i] = temp;
    }
    temp = f[index1];
    f[index1] = f[m];
    f[m] = temp;
}

void methodGaussian(double **a,double *f,int k,int n)
{

    double d;
    int j, i;

        for (j = k - 1; j >= 0; j--){
            d = a[j][n-k] / a[k][n-k];
            for (i = n-k; i <= n; i++){
                a[j][i] = a[j][i] - d * a[k][i];
            }
            f[j] = f[j] - d * f[k];
        }
}


int main()
{
    int m1=10, m2=20, m3=50, s1=2, s2=10, s3=20;
    float ro12=0, ro13=0, ro23=-0.6;
    int i, j, n = 3;
    /*cin >> m1;
    cin >> m2;
    cin >> m3;
    cin >> s1;
    cin >> s2;
    cin >> s3;
    cin >> ro12;
    cin >> ro13;
    cin >> ro23;*/

    double **s = new double *[3];
    for( i = 0; i < 3; ++i)
        s[i] = new double[3];

    s[0][0] = s1 * s1;
    s[0][1] = s[1][0] = s1 * s2 * ro12;
    s[0][2] = s[2][0] = s1 * s3 * ro13;
    s[1][1] = s2 * s2;
    s[1][2] = s[2][1] = s2 *s3 * ro23;
    s[2][2] = s3 * s3;

    double **a = new double *[n+1];
    for( i = 0; i < n+1; ++i)
        a[i] = new double[n+1];

    double *f = new double[n+1];
    f[0] = f[1] = f[2] = 0;
    f[3] = 1;

    for ( i = 0; i < n; ++i){
        for ( j = 0; j < n; ++j){
            a[i][j] = 2 * s[i][j];
        }
    }
    for ( i = 0; i < n; ++i){
            a[i][3] = 1;
            a[3][i] = 1;
    }
    a[3][3] = 0;

    cout<<endl;

    for ( i = 0; i <= n; ++i){
        for ( j = 0; j <= n; ++j){
            cout << "\t" << a[i][j];
        }
        cout<<endl;
    }


    int m = n, maxindex;
    for (int column = 0; column <= n-1; ++column){
        maxindex = findMaxelem (a, column, m);
        if (maxindex != m)
            exchangeRows (a, f, maxindex, m, n);
        methodGaussian (a, f, m, n);
        m--;
    }
    double *x = new double [n+1];
    x[3]=f[0]/a[0][3];
    x[2]=(f[1]-a[1][3]*x[3])/a[1][2];
    x[1]=(f[2]-a[2][3]*x[3]-a[2][2]*x[2])/a[2][1];
    x[0]=(f[3]-a[3][3]*x[3]-a[3][2]*x[2]-a[3][1]*x[1])/a[3][0];

    cout << "Results: " << endl;
    for( i = 0; i < n; ++i)
        cout << "x[" << i+1 << "]=" << x[i] << " " << endl;

    delete[]f;
    delete[]a;
    delete[]x;
    return 0;
}

//----------------------------------------------------------
    int = 5;
    double **b = new double *[m];
    for( i = 0; i < m; ++i)
        b[i] = new double[m];

    for ( i = 0; i < n; ++i){
        for ( j = 0; j < n; ++j){
            b[i][j] = a[i][j];
        }
    }

    a[0][4] = a[4][0] = 10;
    a[1][4] = a[4][1] = 20;
    a[2][4] = a[4][2] = 50;
    a[3][4] = a[4][3] = 0;
    a[4][4]=0


  /* for( i = 0; i < n; ++i) //ÿêùî â³äºìíå
        if(x[i] < 0){
            k = i;
            for(j = 0)
                a[][]
        }
   n=;
   */


