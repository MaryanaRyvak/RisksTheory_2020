#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int XA_1,XA_2,XB_1,XB_2;
    float PA_1,PA_2,PB_1,PB_2;
    double MA,MB,VA,VB,SihmaA,SihmaB,CVA,CVB;
    cout << "Enter the profit and its probability of the first result (with multiple supply) of the firm in this city:" << endl;
    cin >> XA_1 >> PA_1;
    cout << "Enter the profit and its probability of the second result (with single supply) of the firm in this city:" << endl;
    cin >> XA_2 >> PA_2;
    cout << endl;

    cout << "Enter the profit and its probability of the first result(with multiple supply) of the firm from another city:" << endl;
    cin >> XB_1 >> PB_1;
    cout << "Enter the profit and its probability of the second result (with single supply) of the firm from another city:" << endl;
    cin >> XB_2 >> PB_2;
    cout << endl;

    MA = PA_1 * XA_1 + PA_2 * XA_2;
    MB = PB_1 * XB_1 + PB_2 * XB_2;

    if (MA > MB)
        cout << "Maximum expected profit is at the firm in this city( because MA > MB: "<< MA << " > " << MB <<" )";
    else
        cout << "Maximum expected profit is at the firm from another city( because MA < MB: "<< MA << " < " << MB <<" )";
    cout << endl;

    VA = PA_1 * pow((XA_1 - MA),2) + PA_2 * pow((XA_2 - MA),2);
    VB = PB_1 * pow((XB_1 - MB),2) + PB_2 * pow((XB_2 - MB),2);

    SihmaA = sqrt(VA);
    SihmaB = sqrt(VB);
    cout << "                   A            B" <<endl;
    cout << "Variation X      " << VA << "   " << VB << endl;
    cout << "RMS deviation X  " << SihmaA << "   " << SihmaB << endl;
    cout << endl;

    if (SihmaA < SihmaB)
        cout << "The smallest value of variation and RMS deviation is at the firm in this city. ";
    else
        cout << "The smallest value of variation and RMS deviation is at the firm from another city.";
    cout << endl;
    cout << "That's the degree of risk is the least here!" << endl;

    CVA = SihmaA / MA;
    CVB = SihmaB / MB;

    cout << endl;
    cout << "Coefficient of variation of the firm in this city (A): " << CVA << endl;
    cout << "Coefficient of variation of the firm in another city (B): " << CVB << endl;
    cout << endl;

    if (CVA < CVB)
        cout << "The smallest coefficient of variation is at the firm in this city. ";
    else
        cout << "The smallest coefficient of variation is at the firm from another city.";
    cout << endl;
    cout << "Recommend choosing this firm!" << endl;


    return 0;
}
