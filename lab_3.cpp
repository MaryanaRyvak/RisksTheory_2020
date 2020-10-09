#include <iostream>
#include <math.h>

using namespace std;
float* findValues (float X[] ,float P[])
{
    int k[3],j=0;
    float minvalue, maxvalue, p=0;
    float *values = new float [3];
    minvalue = X[0];
    maxvalue = X[0];


    for (int i = 1; i < 3; i++ ){
        if (X[i] < minvalue){
            minvalue = X[i];
        }
    }
    for (int i = 1; i < 3; i++ ){
        if (X[i] == minvalue){
            k[j++]=i;
        }
        if (X[i] > maxvalue)
            maxvalue = X[i];
    }

    if (minvalue == X[0]){
        k[j++] = 0;
    }

    for(int i = 0; i < j; i++){
        p += P[k[i]];
    }
    values[0] = p;
    values[1] = minvalue;
    values[2] = maxvalue;

    return values;
}

float expectedWin(float values[])
{
    float p, x1, x2,expectWin;

    p = values[0];
    x1 = values[1];
    x2 = values[2];

    expectWin = p * x1  + (1 - p) * x2;
    return expectWin;
}
float U(float x)
{
    return ((x + 5) * (x + 5))/15;
}
float expectedUsefulness(float values[])
{
    float p, x1, x2,expectUseful;

    p = values[0];
    x1 = values[1];
    x2 = values[2];

    expectUseful = p * U (x1) + (1 - p) * U (x2);
    return expectUseful;
}
int main()
{
    float XA[3],XB[3],XC[3],XD[3];
    float P[3];
    cout << "Enter options for the profits of the first lottery:" << endl;
    cin >> XA[0] >> XA[1] >> XA[2];
    cout << endl;
    cout << "Enter options for the profits of the second lottery:" << endl;
    cin >> XB[0] >> XB[1] >> XB[2];
    cout << endl;
    cout << "Enter options for the profits of the third lottery:" << endl;
    cin >> XC[0] >> XC[1] >> XC[2];
    cout << endl;
    cout << "Enter options for the profits of the fourth lottery:" << endl;
    cin >> XD[0] >> XD[1] >> XD[2];
    cout << endl;
    cout << "Enter probabilities of three options for the profits " << endl;
    cin >> P[0] >> P[1] >> P[2];
    cout << endl;



    cout << "Expected win of the first lottery = " << expectedWin(findValues(XA,P)) << endl;
    cout << "Expected win of the second lottery = " << expectedWin(findValues(XB,P)) << endl;
    cout << "Expected win of the third lottery = " << expectedWin(findValues(XC,P)) << endl;
    cout << "Expected win of the fourth lottery = " << expectedWin(findValues(XD,P)) << endl;

    float *expUsefulness = new float[4];

    expUsefulness[0]=expectedUsefulness(findValues(XA,P));
    expUsefulness[1]=expectedUsefulness(findValues(XB,P));
    expUsefulness[2]=expectedUsefulness(findValues(XC,P));
    expUsefulness[3]=expectedUsefulness(findValues(XD,P));

    cout << endl;
    cout << "Expected usefulness of the first lottery = " << expUsefulness[0] << endl;
    cout << "Expected usefulness of the second lottery = " << expUsefulness[1] << endl;
    cout << "Expected usefulness of the third lottery = " << expUsefulness[2] << endl;
    cout << "Expected usefulness of the fourth lottery = " << expUsefulness[3] << endl;

    int k = 1;
    float result= expUsefulness[0];
    for (int i = 1; i < 4; i++){
        if (expUsefulness[i] > result) {
            result = expUsefulness[i];
            k = i + 1;
        }
    }
    cout << "-----------------------------------------------------------" << endl;
    cout << "Recommend choosing the lottery number " << k <<", because expected usefulness is the biggest here!!!" << endl;

    return 0;
}
