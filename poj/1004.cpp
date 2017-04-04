#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char *argv[])
{
    float sum = 0;
    float input = 0;
    while(cin >> input) {
        sum += input;
    }
    cout << "$" << fixed << setprecision(2) << sum / 12.0 << endl;
    //cout << "$";
    //cout << fixed << setprecision(2) << sum / 12.0 << endl;
    return 0;
}
