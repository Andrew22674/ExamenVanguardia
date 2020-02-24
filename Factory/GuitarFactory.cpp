#include <iostream>
using namespace std;

#include "Guitar.cpp"
class GuitarFactory{
    public:
        static Guitar * createGuitar(int type){
            Guitar * guitar = NULL;

            switch(type){
                case 1:{
                    guitar = new ElectricGuitar;
                    break;
                }
                case 2:{
                    guitar = new AcousticGuitar;
                    break;
                }
                case 3:{
                    guitar = new EAGuitar;
                    break;
                }
                default:{
                    cout << "not valid" << endl;
                    return NULL;
                }
            }
            guitar -> getParts();
            guitar -> assembleParts();
            guitar -> applyPaint();
            guitar -> finishingDetails();
            guitar -> prepareForPackaging();

            return guitar;
        }
};

