#include <iostream>
#include <cmath>

using namespace std;

static const float dec = 50;
static const float pi = 3.141592;

int getYear(float a, float b)
{
    return (int)((1.0 / 2 * pi * (a * a + b * b)) / 50) + 1;
}

int main(int argc, char *argv[])
{
    int n = 0;
    int i;
    float a = 0, b = 0;
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> a >> b;
        cout << "Property " << i + 1 << ":" 
             << " This property will begin eroding in year " 
             << getYear(a, b) << "." << endl;
    }
    cout << "END OF OUTPUT." << endl;
    
    return 0;
}
