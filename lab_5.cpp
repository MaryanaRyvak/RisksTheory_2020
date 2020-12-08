#include <iostream>
#include <math.h>

using namespace std;

int n = 3, m = 2;

double findMin(double **f, int k)
{
    double minValue = f[k][0];
    for(int i = 1; i <= m; i++)
    {
        if(minValue > f[k][i])
            minValue = f[k][i];
    }
    return minValue;
}

double* findMax(double *a)
{
    double *result = new double [2];
    result[0] = a[0];
    result[1] = 1;
    for(int i = 1; i <= n; i++)
    {
        if(result[0] < a[i])
         {
            result[0] = a[i];
            result[1] = i+1;
         }
    }
    return result;
}

double criterionBayes( double **f, int k)
{
    double p = 1./3;
    double sum = 0;

    for(int i = 0; i <= n; i++)
    {
        sum += p * f[k][i];
    }
    return sum;
}

double criterionHL( double **f, double b, double l, int k)
{
    return (1 - l) * b + l * findMin(f,k);
}

void printResult(double *HL)
{
    cout << endl;
    for (int i = 0; i <= n; i++)
    {
        cout << "HL" << i+1 << "= " << HL[i] << "  ";
    }
    cout << endl;

}

int main()
{
    int i, j;
    double **F = new double *[4];
    for( i = 0; i < 4; ++i)
        F[i] = new double[3];

    cout << "Enter  elements of matrix F: " << endl;

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            cin >> F[i][j];
        }
    }

//----------------------------------------------
    double B1=0, B2=0, B3=0, B4=0;

    B1 = criterionBayes(F, 0);
    B2 = criterionBayes(F, 1);
    B3 = criterionBayes(F, 2);
    B4 = criterionBayes(F, 3);

    cout << endl;
    cout << "B1=" << B1 << "; " << "B2=" << B2 << "; "  << "B3=" << B3 << "; "  <<"B4=" << B4 << endl;

//----------------------------------------------
    double l = 0.7;
    double *HL = new double [n+1];

    HL[0] = criterionHL(F, B1, l, 0);
    HL[1] = criterionHL(F, B2, l, 1);
    HL[2] = criterionHL(F, B3, l, 2);
    HL[3] = criterionHL(F, B4, l, 3);

    printResult(HL);

    double *result = new double [2];

    result = findMax(HL);

    cout << "According to the criterion of Hodges Lehmann (where lyamda = 0.7), the compromise is the solution x" << result[1];
    cout << endl;

//-----------------------------------------------
    l = 0.5;

    HL[0] = criterionHL(F, B1, l, 0);
    HL[1] = criterionHL(F, B2, l, 1);
    HL[2] = criterionHL(F, B3, l, 2);
    HL[3] = criterionHL(F, B4, l, 3);

    printResult(HL);

    result = findMax(HL);

    cout << "According to the criterion of Hodges Lehmann (where lyamda = 0.5), the compromise is the solution x" << result[1];
    cout << endl;

//------------------------------------------------
    l = 0.3;

    HL[0] = criterionHL(F, B1, l, 0);
    HL[1] = criterionHL(F, B2, l, 1);
    HL[2] = criterionHL(F, B3, l, 2);
    HL[3] = criterionHL(F, B4, l, 3);

    printResult(HL);

    result = findMax(HL);

    cout << "According to the criterion of Hodges Lehmann (where lyamda = 0.3), the compromise is the solution x" << result[1];
    cout << endl;


    delete []F;
    delete []HL;
    return 0;
}

