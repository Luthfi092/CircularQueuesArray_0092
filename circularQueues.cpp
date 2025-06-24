
/** 
 * @mainpage Documentation Circular Queues 
 * 
 * @section Introduction 
 * Project ini merupakan project struktur data
 * menggunakan struktur data queues dengan pendekatan circular arrays.
 * 
 * @section Operations
 * project ini memiliki beberapa operasi antara lain:
 * 1. insert
 * 2. delete
 * 3. display 
 * 
 * @section Cara Penggunaan 
 * berikut beberapa menu yang bisa di gunakan:
 * 1. en queue
 * 2. de queue
 * 3. display
 * 4. exit 
 * 
 * @author Profil
 * nama : (Luthfi alqorni) 
 * nim : (20240140092)
 * kelas : (B) 
 * 
 * @brief 
 * @version 1.0 
 * @date 2025-06-24 
 * 
 * @copyright {luthfi alqorni}@umy.ac.id (c) 2025
 * 
*/





#include <iostream>
using namespace std;
/**
 * @class Queues 
 * @brief class ini operasi lengkap queues
 */


class Queues {
private:
    int FRONT;  ///< variable private front untuk menyimpan posisi depan antrian
    int REAR;   ///< variable private rear untuk menyimpan posisi belakang anterian 
    int FRONT, REAR, max = 5;   ///< variable private max untuk menyimpan ukuran maximum antrian
    int queue_array[5]; //< variable private queue_array untuk menyimpan element array 

public:
/**
 * @brief Construct a new Queues object 
 * set default queues null 
 * with front = -1 and rear = -1
 */
    Queues(){
        FRONT =-1;
        REAR = -1;
    }

    /**
     * @brief method untuk memasukan data dalam antrian 
     * data di masukan dalam variable queue_array 
     */

    void insert() {
        int num;///< variable num untuk meyimpan nilai 
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

    /**
     * @brief method untuk menghapus data dalam antrian
     * data di hapuskan dari dalam variable queue_array
     */

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

       /**
     * @brief method untuk menampilkan data dalam antrian
     * data di tampilkan yang berada di dalam variable queue_array
     */


    void display(){
        int FRONT_position = FRONT;///< variable front_position untuk menandakan posisi element 
        int REAR_position = REAR;///< variable rear_position untuk menandakan posisi element teraakhir

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
    Queues q;///< objek untuk meneggunakan member yang ada pada class queues
    char ch;///< variable ch untuk menyimpan pilihan pada menu yang diberikan 

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