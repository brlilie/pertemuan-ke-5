
#include<iostream>
using namespace std;

class Mahasiswa{
     private:
       string nama;
    public:
      void setNama(string nama){
        this->nana=nama;
      }

      string getNama(){
         return nama;
      }
};

int main(){
    Mahasiswa Mhs;
     Mhs.setNama("Reza");
     cout<<Mhs.getNama();
}