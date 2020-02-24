
using namespace std;
class Phone{
    string model;
    string cpu;
    string gpu;
    string camera;
    string screen;
    int mem;

public:
    Phone(string phonemodel): model{phonemodel} {

    }
    void setCPU(string cpuType){
        cpu = cpuType;
    }
    void setGPU(string gpuType){
        gpu = gpuType;
    }
    void setCamera(string cameraType){
        camera = cameraType;
    }
    void setMemory(int memType){
        mem = memType;
    }
    void setScreen(string screenType){
        screen = screenType;
    }

    void showPhone(){
        cout << "Phone model: " << model << endl
        << "CPU: " << cpu << endl
        << "GPU: " << gpu << endl
        << "Camera: " << camera << endl
        << "Memory: " << mem << endl
        << "Screen: " << screen << endl;
    }


};