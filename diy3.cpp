#include <iostream>
using namespace std;

class Tracer {
private:
    int id;

public:
 
    Tracer(int i) {
        id = i;
        cout << "Tracer " << id << " created" << endl;
    }

   
    ~Tracer() {
        cout << "Tracer " << id << " destroyed" << endl;
    }
};

int main() {
    const int n = 5;

    for (int i = 1; i <= n; i++) {
        Tracer* t = new Tracer(i);


        cout << "Using Tracer " << i << endl;

       
        delete t;
    }

    cout << "Program finished." << endl;

    return 0;
}
