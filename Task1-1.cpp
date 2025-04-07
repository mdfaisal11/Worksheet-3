#include <iostream>
using namespace std;

class Time {
private:
    int min;
    int hr;

public:
    Time() {
        min = hr = 0;
    }

    Time(int a, int b) {
        hr = a;
        min = b;
    }

    Time operator+(Time T)
    {
        Time temp;
        temp.min = min + T.min;
        int mm = temp.min / 60;
        temp.min = temp.min % 60;
        temp.hr = mm + hr + T.hr;
        return temp;
    }

    void display()
    {
        cout << "hr=" << hr << " min=" << min<< endl;
    }
};

int main()
{
    int a, b, c, d;

    cout << "Enter first time in the form of hr min & min :" << endl;
    cin >> a >> b;

    cout << "Enter second time in the form of hr & min :" << endl;
    cin >> c >> d;

    Time T1(a, b), T2(c, d);
    cout<<"The first time is :";
    T1.display();
    cout<<"The second time is :";
    T2.display();

    Time T3 = T1 + T2;
    cout<<"The sum of first time and second time is :";
    T3.display();

    return 0;
}
