#include <iostream>
using namespace std;

//CircularQueueArray_4NIMBelakang

class Queues {
    int FRONT, REAR, max = 5;
    int queue_array[5];

public:
    Queues(){
        FRONT =-1;
        REAR = -1;
    }

    void insert() {
        int num;
        cout << "Enter a number: ";
        cin >> num;
        cout << endl;

        //cek apakah antrian penuh
          if (FRONT == -1) {
            FRONT = 0;
            REAR = 0;

          }
        
          else {
            //jika REAR berada di posisi terakhir array, kembali ke awal array
            if (REAR == max - 1)
            REAR = 0;
            else 
            REAR = REAR + 1;

          }
          queue_array[REAR] = num;

    }

    void remove () {
        //cek apakah antrian kosong
        if (FRONT == -1){
            cout << "Queue underflow\n";
            return;
        }
        cout << "\nThe element deleted from the queue is: " << queue_array[FRONT] << "\n";

        //cek jika antrian hanya memiliki satu elemen
        if (FRONT == REAR ){
            FRONT = -1;
            REAR = -1;
        }
        else {
            //jika elemen yang dihapus berada diposisi terakhir array
            if (FRONT == max - 1)
            FRONT = 0;
            else 
            FRONT = FRONT + 1;
        }
    }

    


    void display(){
        int FRONT_position = FRONT;
        int REAR_position = REAR;

        //cek apakah antrian kosong
        if (FRONT == -1)  {
            cout << "Queue is empty\n";
            return;
        }

        cout << "\nElement in the queue are...\n";

        //jika FRONT_position <= REAR_position
        // iterasi dari FRONT HINGGA REAR
        if (FRONT_position <= REAR_position){
            while (FRONT_position <= REAR_position){
                cout << queue_array[FRONT_position] << "  ";
                FRONT_position++;
            }
            cout << endl;
        }
        else {
        //jika FRONT_position < REAR_position
        // iterasi dari FRONT HINGGA REAR

        while (FRONT_position <= max -1) {
            cout << queue_array[FRONT_position] << "  ";
            FRONT_position++;
        }

        FRONT_position = 0;
        
        // Iterasi dari awal array hingga REAR
        while (FRONT_position <= REAR_position){
            cout << queue_array[FRONT_position] << "  ";
            FRONT_position++;
        }
        cout << endl;


        }
    }
};


int main(){
    Queues q;
    char ch;

    while (true){
        try{
            cout << "Menu" << endl;
            cout << "1. Implemen insert operation" << endl;
            cout << "2. Implemen delete operation" << endl;
            cout << "3. Display values" << endl;
            cout << "4. Exit" << endl;
            cout << "Enter your choice (1-4): ";
            cin >> ch;
            cout << endl;
            
            switch (ch) {
                case '1':{
                    q.insert();
                    break;
                }
                case '2':{
                    break;
                }
                case '3':{
                    break;
                }
                case '4':{
                    return 0;
                }
                default: {
                    cout << "Invalid option!!" << endl;
                    break;
                }
            }

        }
      catch (exception& e) {
            cout << "Check for the values entered." << endl;
        }
      
    }
    return 0; 
}