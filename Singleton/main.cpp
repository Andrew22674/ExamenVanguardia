
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Game {
    static Game* instance;
    //el usuario tiene 10 intentos para pegarle al objetivo
    //tiene que adiviniar la coord x y la coord y en donde está el objetivo
    //si la dificultad es facil, se pueden ingresar numeros desde 0 a 5, si es dificil, desde 0 a 10
    int projectiles = 10;
    double coordLat = 0.0;
    double coordLong = 0.0;
    int xPos = 5, yPos = 5;
    bool hit = false;//determina si le han disparado al objetivo
    bool end = false;//controla el fin del juego
    string diff = "e";

    //get random coordinate


    // Private constructor
    Game() {

        
    }

public:
    static Game* getInstance() {
        if (!instance)
            instance = new Game;
        return instance;
    }

    void shoot(int x, int y) {
        setCoords(x, y);
        if (this->projectiles >= 1) {
            this->projectiles -= 1;
            cout << "shooting at (" << this->coordLat << ", " << this->coordLong << ")" << endl;
            if (coordLat == xPos and coordLong == yPos) {
                cout << "target hit" << endl;
                this->hit = true;
            }
            else {
                cout << "missed target" << endl;
                helper(x, y);

            }
        }


    }

    void helper(int x, int y) {
        //<-- significa que el usuario tiene que disminuir el valor de x o y, --> es aumentar
        if (x > xPos && y > yPos) {
            cout << "x <--, y <--" << endl;
        }
        else if (x > xPos && y < yPos) {
            cout << "x <--, y -->" << endl;
        }
        else if (x == xPos && y > yPos) {
            cout << "x correct, y <--" << endl;
        }
        else if (x == xPos && y < yPos) {
            cout << "x correct, y -->" << endl;
        }
        else if (x < xPos && y < yPos) {
            cout << "x -->, y -->" << endl;
        }
        else if (y > yPos&& x < xPos) {
            cout << "x -->, y <--" << endl;
        }
        else if (y == yPos && x > xPos) {
            cout << "x <--, y correct" << endl;
        }
        else if (y == yPos && x < xPos) {
            cout << "x -->, y correct" << endl;
        }
    }

    int remainingShots() {
        return this->projectiles;
    }

    bool validRange(int x, int y) {
        if (diff == "e") {
            return (x >= 0 && x <= 5 && y >= 0 && y <= 5);
        } 
        else {
            return (x >= 0 && x <= 10 && y >= 0 && y <= 10);
        }
    }


    double getLat() {
        return this->coordLat;
    }

    double getLong() {
        return this->coordLong;
    }
  
    void reset() {
        
        this->hit = false;
        //this->end = false;

    }


    bool targetHit() {
        return this->hit;
    }

    bool gameOver() {
        if(projectiles == 0)
            cout << "No more projectiles remaining" << endl;
        return this->projectiles >= 1;
    }

    bool gameEnd() {
        return (gameOver() && targetHit());
    }


    void setCoords(double coordLat, double coordLong) {
        this->coordLat = coordLat;
        this->coordLong = coordLong;
    }

    void difficulty(string s) {
        if (s == "h") {
            diff = "h";
            xPos = rand() % 11;
            yPos = rand() % 11;
            projectiles = 7;
        }
        else {
            diff = "e";
            xPos = rand() % 6;
            yPos = rand() % 6;
            projectiles = 10;

        }
        //cout << xPos << ", " << yPos << endl;
    }
};


Game* Game::instance = 0;

int main() {
    srand(time(NULL));
    Game* s = s->getInstance();
    int x, y;
    bool cont = true;
    string diff;
    string yn;
    while (cont) {
        cout << "select difficulty: [e/h] " << endl;
        cin >> diff;
        s->difficulty(diff);
        while (s->targetHit() == false && s->gameOver()) {
            cout << "Ingrese coordenada x: " << endl;
            while (!(cin >> x)) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Input inválido" << endl;
            }
            cout << "Ingrese coordenada y:" << endl;
            while (!(cin >> y)) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Input inválido" << endl;
            }
            while (s->validRange(x, y) == false) {
                cout << "Rango inválido de coordenadas" << endl;
                cout << "Ingrese coordenada x: " << endl;
                cin >> x;
                cout << "Ingrese coordenada y:" << endl;
                cin >> y;
            }
            s->shoot(x, y);
        }
        cout << "desea seguir jugando? [s/n]" << endl;
        cin >> yn;
        //cout << yn;
        if (yn == "n") {
            cont = false;
        }
        else {
            s->reset();
        }
    }
    return 0;
}