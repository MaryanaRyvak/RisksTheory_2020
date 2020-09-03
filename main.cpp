#include <iostream>

using namespace std;

int check (int &value)
{
    while (!(value <= 10) || !(value >= 1))
    {
        cout<<"Wrong value!" << endl;
        cout << "Enter correct value (from 1 to 10)" << endl;
        cin >> value;
    }
}

int main()
{
    float rain, sun, U_f, U_h;
    int   forest_r, forest_s, home_r, home_s;
    cout << "Enter probability of rain (from 0 to 1)" << endl;
    cin >> rain;

    while (!(rain <= 1) || !(rain >= 0))
    {
        cout<<"Wrong value!" << endl;
        cout << "Enter probability of rain (from 0 to 1)" << endl;
        cin >> rain;
    }
    sun = 1 - rain;


    cout << "How do you feel in sunny weather in the forest?(from 1 to 10)" << endl;
    cin >> forest_s;
    check(forest_s);

    cout << "How do you feel in rainy weather in the forest?(from 1 to 10)" << endl;
    cin >> forest_r;
    check(forest_r);

    cout << "How do you feel in sunny weather at home?(from 1 to 10)" << endl;
    cin >> home_s;
    check(home_s);

    cout << "How do you feel in rainy weather at home?(from 1 to 10)" << endl;
    cin >> home_r;
    check(home_r);

    U_f = sun * forest_s + rain * forest_r;
    U_h = sun * home_s + rain * home_r;

    cout << endl;

    cout << "Expected utility:" << endl;
    cout << "Forest - "<< U_f << endl;
    cout << "Home - "<< U_h << endl;

    if (U_f > U_h)
        cout<< "A trip to the forest will be the best solution for you)" << endl;
    else
        cout << "You better stay at home!)" << endl;

    return 0;
}

