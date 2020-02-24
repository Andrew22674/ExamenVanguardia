#include <iostream>
using namespace std;

class Guitar{
    protected:
        string model;
        double price;
    public:
            virtual void getParts() = 0;
            virtual void assembleParts() = 0;
            virtual void applyPaint() = 0;
            virtual void finishingDetails() = 0;
            virtual void prepareForPackaging() = 0; 
            virtual void showDetails() = 0;
};

class ElectricGuitar : public Guitar{
    void getParts(){
        cout << "gathering electric guitar parts" << endl;
    }
    void assembleParts(){
        cout << "assembling electric guitar parts" << endl;
    }
    void applyPaint(){
        cout << "applying paint to electric guitar" << endl;
    }
    void finishingDetails(){
        cout << "applying finishing details to electric guitar" << endl;
    }
    void prepareForPackaging(){
        model = "EG";
        price = 400;
        cout << "preparing electric guitar for packaging" << endl;
    }
    void showDetails(){
        cout << "Model: " << model << endl;
        cout << "Price: " << price << endl;
    }
};

class AcousticGuitar : public Guitar{
    void getParts(){
        cout << "gathering acoustic guitar parts" << endl;
    }
    void assembleParts(){
        cout << "assembling acoustic guitar parts" << endl;
    }
    void applyPaint(){
        cout << "applying paint to acoustic guitar" << endl;
    }
    void finishingDetails(){
        cout << "applying finishing details to acoustic guitar" << endl;
    }
    void prepareForPackaging(){
        model = "AG";
        price = 300;
        cout << "preparing acoustic guitar for packaging" << endl;
    }
    void showDetails(){
        cout << "Model: " << model << endl;
        cout << "Price: " << price << endl;
    }
};

class EAGuitar : public Guitar{
    void getParts(){
        cout << "gathering electro acoustic guitar parts" << endl;
    }
    void assembleParts(){
        cout << "assembling electro acoustic guitar parts" << endl;
    }
    void applyPaint(){
        cout << "applying paint to electro acoustic guitar" << endl;
    }
    void finishingDetails(){
        cout << "applying finishing details to electro acoustic guitar" << endl;
    }
    void prepareForPackaging(){
        model = "EG";
        price = 350;
        cout << "preparing electro acoustic guitar for packaging" << endl;
    }
    void showDetails(){
        cout << "Model: " << model << endl;
        cout << "Price: " << price << endl;
    }
};