// Jay Martinez - 5/12/23
// Activity 2 print my first name out in ASCII characters

#include <iostream>
using namespace std;

int main() {
    //first line
    for(int i = 0; i<61; i++) {
        if(i<20)
            cout<<"#";
        else if(i>30 && i<40)
            cout<<"#";
        else if(i>50 && i<54)
            cout<<"#";
        else if(i>57 && i<61)
            cout<<"#";
        else 
            cout<<" ";
    }
    cout<<endl;

    //second pass
    for(int i = 0; i<61; i++) {
        if(i<20)
            cout<<"#";
        else if(i>31 && i<39)
            cout<<"#";
        else if(i==29 || i==30)
            cout<<"/";
        else if(i==40 || i==41)
            cout<<"\\";
        else if(i>51 && i<54)
            cout<<"#";
        else if(i==51)
            cout<<"\\";
        else if(i>57 && i<60)
            cout<<"#";
        else if(i==60)
            cout<<"/";
        else 
            cout<<" ";
    }
    cout<<endl;

    //third pass
    for(int i = 0; i<61; i++) {
        if(i<20)
            cout<<"#";
        else if(i>29 && i<40)
            cout<<"#";
        else if(i==28 || i==29)
            cout<<"/";
        else if(i==41 || i==42)
            cout<<"\\";
        else if(i>52 && i<54)
            cout<<"#";
        else if(i==52)
            cout<<"\\";
        else if(i>57 && i<59)
            cout<<"#";
        else if(i==59)
            cout<<"/";
        else 
            cout<<" ";
    }
    cout<<endl;

    //third pass
    for(int i = 0; i<61; i++) {
        if(i>7 && i<12)
            cout<<"#";
        else if(i==28 || i==29 || i==30)
            cout<<"#";
        else if(i==40 || i==41 || i==42)
            cout<<"#";
        else if(i==53)
            cout<<"\\";
        else if(i>=54 && i<=57)
            cout<<"#";
        else if(i==58)
            cout<<"/";
        else 
            cout<<" ";
    }
    cout<<endl;


    //fourth - sixth passes
    for(int j = 0; j<2; j++) {
        for(int i = 0; i<61; i++) {
            if(i>7 && i<12)
                cout<<"#";
            else if(i==28 || i==29 || i==30)
                cout<<"#";
            else if(i==40 || i==41 || i==42)
                cout<<"#";
            else if(i>=54 && i<=57)
                cout<<"#";
            else 
                cout<<" ";
        }
        cout<<endl;
    }

    //seventh pass
    for(int i = 0; i<61; i++) {
        if(i>7 && i<12)
            cout<<"#";
        else if(i>=28 && i<=42)
            cout<<"#";
        else if(i>=54 && i<=57)
            cout<<"#";
        else 
            cout<<" ";
    }
    cout<<endl;

    //eight to tenth passes
    for(int j = 0; j<3; j++) {
        for(int i = 0; i<61; i++) {
            if(i>0 && i<12)
                cout<<"#";
            else if(i==28 || i==29 || i==30)
                cout<<"#";
            else if(i==40 || i==41 || i==42)
                cout<<"#";
            else if(i>=54 && i<=57)
                cout<<"#";
            else 
                cout<<" ";
        }
        cout<<endl;
    }
}