#include <iostream>
#include "Director.cpp"
using namespace std;


int main(){
    Director dir;
    Note10Builder nb;
    GalaxyA10Builder gb;

    Phone *note = dir.createPhone(&nb);
    Phone *galaxy = dir.createPhone(&gb);

    note-> showPhone();
    galaxy -> showPhone();

    delete note;
    delete galaxy;

    return 0;

};
