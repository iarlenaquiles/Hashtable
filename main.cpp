#include <iostream>
#include "hashtable.h"
#include "item.h"
using namespace std;

int main(){
    hashtable<string> hash(2);

    hash.insert(1, "boi");
    hash.insert(11, "bia");
    hash.insert(21, "hj");
    hash.insert(10, "hhd");
    hash.insert(111, "shr");
    hash.insert(30, "boina");
    hash.insert(45, "hf");
    hash.insert(20, "teste");
    hash.insert(80, "mari");
    //    hash.insert(400, "ut");
    //    hash.insert(800, "itu");
    //    hash.insert(0, "messias");
    //    hash.insert(480, "antoin");
    hash.show();
    //cout << hash.get(11) << endl;
    // hash.erase(1);
    //hash.insert(1, "fd");
    cout << hash.size() << endl;
    // cout << hash.exist(111) << endl;
    cout << hash.maxQ() << endl;
    hash.show();
    return 0;
}
