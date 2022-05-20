#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
using namespace std;

const int nr_p = 2;
const string filename = "rubrica3.txt";

struct Persona{
    string nome;
    string cognome;
    string numero_tel;
}p[nr_p];

void riempiStruct(){
    for(int i = 0; i < nr_p; i++){
        cout << "--------------------" << endl;
        cout << "Persona Nr." << i+1 << endl;
        cout << "Nome: ";
        cin >> p[i].nome;
        cout << "Cognome: ";
        cin >> p[i].cognome;
        cout << "Telefono: ";
        cin >> p[i].numero_tel;
        if(i == nr_p-1){
            cout << "--------------------" << endl;
        }
    }
}

void writeInFile(){
    fstream file;
    file.open(filename.c_str(), ios::out);
    if(file.is_open()){
        for(int i = 0; i < nr_p; i++){
            file << p[i].nome;
            file << " ";
            file << p[i].cognome;
            file << " ";
            file << p[i].numero_tel;
            file << " ";
            file << endl;
        }
        file.close();
    }
}

void readFromFile(){
    fstream file;
    file.open(filename.c_str(), ios::in);
    if(file.is_open()){
        string line;
        while(getline(file, line)){
            cout << line << endl;
        }
        file.close();
    }
}

int main(){
    riempiStruct();
    writeInFile();
    readFromFile();
}
