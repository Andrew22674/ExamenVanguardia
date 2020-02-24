#include "Phone.cpp"

using namespace std;
class PhoneBuilder{
    protected:
        Phone * _phone;
    public:
        virtual void buildPhoneType() = 0;
        virtual void assembleCPU() = 0;
        virtual void assembleGPU() =0;
        virtual void assembleCamera() =0;
        virtual void assembleMemory() = 0;
        virtual void assembleScreen() = 0;

        Phone* getPhone(){
            return _phone;
        }
};

class Note10Builder: public PhoneBuilder{
    public: 
    void buildPhoneType(){
        _phone = new Phone("Note 10");
    }
    void assembleCPU(){
        _phone -> setCPU("octa-core cpu");
    }
    void assembleGPU(){
        _phone -> setGPU("adreno 640");
    }
    void assembleCamera(){
        _phone -> setCamera("quad camera");
    }
    void assembleMemory(){
        _phone -> setMemory(512);
    }
    void assembleScreen(){
        _phone -> setScreen("AMOLED 6.3 inch 1080x2280");
    }
};

class GalaxyA10Builder: public PhoneBuilder{
    public: 
    void buildPhoneType(){
        _phone = new Phone("Galaxy A50");
    }
    void assembleCPU(){
        _phone -> setCPU("octa-core cpu");
    }
    void assembleGPU(){
        _phone -> setGPU("mali-g72");
    }
    void assembleCamera(){
        _phone -> setCamera("triple camera");
    }
    void assembleMemory(){
        _phone -> setMemory(128);
    }
    void assembleScreen(){
        _phone -> setScreen("AMOLED 6.4 inch 1080x2340");
    }
};
