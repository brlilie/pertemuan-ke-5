#include<iostream>
using namespace std;

class Mahasiswa{
    public:
            string nama, npm;
            void perkenalan(){
                cout<<"Nama: "<<nama<<endl;
                cout<<"Npm: "<<npm;
            }
};

int main(){
    Mahasiswa mhs;
    cin>>mhs.nama;
    cin>>mhs.npm;

    mhs.perkenalan();
}