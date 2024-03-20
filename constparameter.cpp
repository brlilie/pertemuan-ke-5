//dengan parameter

#include<iostream>
using namespace std;

class Mahasiswa(){
    public:
           string nama, npm;
           Mahasiswa(string nama, string x){
            this->nama=nama;
            this->npm = x;
           }
};

int main(){
    Mahasiswa Mhs("Reza","2117");

    cout<<"Nama: "<<Mhs.nama<<endl;
    cout<<"Npm: "
}