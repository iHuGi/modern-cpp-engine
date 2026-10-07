#include <iostream>
#include <climits> // Often taught alongside sizeof to show MIN/MAX values

using namespace std;

int main() {
    cout << "====== sizeof Operator Reference ======" << endl;
    cout << "char: " << sizeof(char) << " bytes." << endl;
    cout << "int: " << sizeof(int) << " bytes." << endl;
    cout << "unsigned int: " << sizeof(unsigned int) << " bytes." << endl;
    cout << "short: " << sizeof(short) << " bytes." << endl;
    cout << "long: " << sizeof(long) << " bytes." << endl;
    cout << "long long: " << sizeof(long long) << " bytes." << endl;

    cout << "\n====== Floating Point Types ======" << endl;
    cout << "float: " << sizeof(float) << " bytes." << endl;
    cout << "double: " << sizeof(double) << " bytes." << endl;

    cout << "\n====== Using sizeof with Variables ======" << endl;
    int test_score {95};
    double temperature {98.6};
    
    // You can use sizeof on the variable name itself, not just the type!
    cout << "test_score variable is " << sizeof(test_score) << " bytes." << endl;
    cout << "temperature variable is " << sizeof(temperature) << " bytes." << endl;

    return 0;
}