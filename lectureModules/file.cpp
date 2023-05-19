#include "file.hpp"

namespace std1 {
    void myFunction(int myVal){
        cout << "inFunc-Entering " << myVal << " " << &myVal << endl;
        myVal = 200;
        cout << "inFunc-Leaving " << myVal << " " << &myVal << endl;
    }

    void myFunction(const int myVal[]){
        cout << "inFunc-Entering " << myVal[0] << " " << &myVal[0] << endl;
        //myVal[0] = 200;
        cout << "inFunc-Leaving " << myVal[0] << " " << &myVal[0] << endl;
    }
}

namespace std2 {
    void myFunction(int myVal, string Def){
        cout << "inFunc-Entering "<<Def<<":" << myVal << " " << &myVal << endl;
        myVal = 200;
        cout << "inFunc-Leaving "<<Def<<":" << myVal << " " << &myVal << endl;
    }
}
