#include "HugeInteger.h"`
using namespace std;

int main() {
    HugeInteger n1("1399");
    HugeInteger n2("19");

    cout << "n1: "; n1.print(); cout << endl;
    cout << "n2: "; n2.print(); cout << endl;

   
    HugeInteger n3 = n1 + n2;
    cout << "n1 + n2 = "; n3.print(); cout << endl; 

	HugeInteger n7 = n1.multiply(n1, n2);
	cout << "n1 * n2 = "; n7.print(); cout << endl;


    HugeInteger n4("100");
    HugeInteger n5("1");
    HugeInteger n6 = n4 - n5;
    cout << "100 - 1 = "; n6.print(); cout << endl;


    HugeInteger c1("21");
    HugeInteger c2("19");
    if (c1.isGreaterThan(c1, c2)) {
        cout << "21 > 19: ÕıÈ·" << endl;
    }
    else {
        cout << "21 > 19: ´íÎó" << endl;
    }

    return 0;
}