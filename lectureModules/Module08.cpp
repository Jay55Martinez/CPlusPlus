#include <iostream>
#include <bitset>
using namespace std;

int main() {

    int mv = 10;
    cout<< hex << mv <<endl;
    cout<< oct << mv <<endl;
    cout<< dec << mv <<endl;
    bitset<8>mv2(mv);
    cout<<mv2<<endl;
    cout<<boolalpha<<(mv & 0xff)<<endl;
    cout<<hex<<(0xfa & 0xf0)<<endl;

    bitset<8>mv3(16);
    cout<< hex <<(16) << endl;
    cout<< hex <<(16<<2) <<endl;
    mv3 = 16<<2;
    cout<<mv3<<endl;

    unsigned int i = -1;
    cout<< hex << i << endl;
    bitset<32>mv4(i);
    cout<<mv4<<endl;
    return EXIT_SUCCESS;
}