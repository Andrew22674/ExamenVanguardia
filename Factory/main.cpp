#include <iostream>
using namespace std;

#include "GuitarFactory.cpp"
int main(){

    int type;
    while(1){
        cout << "Ingrese tipo de guitarra que quiere crear: " << endl;
        cout << "1: Electric guitar" << endl;
        cout << "2: Acoustic guitar" << endl;
        cout << "3: Electro acoustic guitar" << endl;
        cin >> type;
        if(!type){
            break;
        }
        Guitar *g = GuitarFactory::createGuitar(type);
        if(g){
            g -> showDetails();
            delete g;
        }

    }
    return 0;
};