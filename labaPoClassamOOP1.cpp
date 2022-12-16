#include <iostream>

class device {
public:
    bool isTurn = false;
    int volume = 0;
    int screenBrightness=0;
    void TurnOnOff(bool &isTurn){
        isTurn = !isTurn;
    }
    void ChangeVolume(int &volume, int volumeChange){
        volume += volumeChange;
    }
private:
    int seria;
};

class Computer :public device {
public:
    int cost; //стоимость компьютера
    void TurnOnOffComputer(bool& isTurn) {
        TurnOnOff(isTurn);
        if (isTurn) {
            std::cout << "Computer is on!\n";
        }
        else std::cout << "Computer is off :(\n";
    }
    void ShowVolume(int volume) {
        std::cout << volume;
    }
    friend void ChangeScreenBrightness(int& screenBrightness, int change);
    
private:
    int size[3];
};

bool operator < (Computer comp1, Computer comp2)
{
    return comp1.cost < comp2.cost;
}

void ChangeScreenBrightness(int& screenBrightness, int change) {
    screenBrightness += change;
}

class Laptop {
public:
    bool isFold = true;
    friend Computer;
    void UnFoldLaptop(bool& isFold) {
        isFold = !isFold;

    }
private:

};

int main()
{
    Computer honor;
    honor.TurnOnOffComputer(honor.isTurn);
    honor.TurnOnOffComputer(honor.isTurn);
    honor.ChangeVolume(honor.volume, 15);
    honor.ShowVolume(honor.volume);
}


