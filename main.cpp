#include <iostream>
#include <fstream>
#include <filesystem>
#include "windows.h"

void CreacionDeArchivos(int cant);
int ConteoDeArchivosDeDirectorio();
void listarArchivosDeDirectorio();
void MostrarDetalles();
int cant;
using namespace std;
int main() {


    cout << "Cuantos archivos quiere crear \n";
    cin >> cant;
    CreacionDeArchivos(cant);
    cout << ConteoDeArchivosDeDirectorio();
    cout << endl;
    listarArchivosDeDirectorio();
    MostrarDetalles();
    return 0;

}

void CreacionDeArchivos(int cant) {
    string nombreArchivo="file";
    int i= cant;
    for(i=1; i <= cant; i++){
        ofstream file;
        file.open("C:\\Users\\andre\\Documents\\Par\\" + nombreArchivo + to_string(i) +".txt");
        file.close();
    }
    cout<<"Archivos creados : " + to_string(i);
}


void listarArchivosDeDirectorio(){
    WIN32_FIND_DATA findFileData;
    HANDLE          hFind;
    hFind = FindFirstFile("C:\\Users\\andre\\Documents\\Par\\", &findFileData);

    if (hFind == INVALID_HANDLE_VALUE)
        cout << "Ruta incorrecta";
    else
    {
        cout << findFileData.cFileName << '\n'; //El primer archivo
        // Listamos todos los archivos

        while (FindNextFile(hFind, &findFileData) != 0)
            cout << findFileData.cFileName << '\n';
    }
}

int ConteoDeArchivosDeDirectorio(){
    WIN32_FIND_DATA findFileData;
    HANDLE          hFind;
    int cantidadDeArchivos=0;
    hFind = FindFirstFile("C:\\Users\\andre\\Documents\\Par\\", &findFileData);

    if (hFind == INVALID_HANDLE_VALUE)
        cout << "Ruta incorrecta";
    else
        while (FindNextFile(hFind, &findFileData)!=0){
            cantidadDeArchivos=cantidadDeArchivos+1;}
    return cantidadDeArchivos-1;
}
void MostrarDetalles(){
    filesystem::directory_iterator directoryIterator("C:\\Users\\andre\\Documents\\Par\\");
    for (const auto& entry : directoryIterator) {
        if (!filesystem::is_directory(entry.status())) {
            cout << entry.path().filename() << " "
                 << file_size(entry.path()) << std::endl;
        }
    }
}
