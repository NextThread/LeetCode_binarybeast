class ParkingSystem {
public:
    int b, m, s;
    ParkingSystem(int big, int medium, int small) {
        b = big;
        m = medium;
        s = small;
    }
    
    bool addCar(int carType) {
        if(carType == 1) {
            if(b > 0) {
                b -= 1;
                return true;
            }
            else {
                return false;
            }
        }
        if(carType == 2) {
            if(m > 0) {
                m -= 1;
                return true;
            }
            else {
                return false;
            }
        }
        if(carType == 3) {
            if(s > 0) {
                s -= 1;
                return true;
            }
            else {
                return false;
            }
        }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */