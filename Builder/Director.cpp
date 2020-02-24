
#include "Builder.cpp"

class Director{
    public:
        Phone* createPhone(PhoneBuilder *builder){
            //creamos el celular en este orden especifico
            builder -> buildPhoneType();
            builder -> assembleCPU();
            builder -> assembleGPU();
            builder -> assembleCamera();
            builder -> assembleMemory();
            builder -> assembleScreen();

            return builder -> getPhone();
        }
};