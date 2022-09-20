#include <iostream>
//Tenemos 10 nodos y 31 enlaces
using namespace std;

string estados[10] = {"Aguascalientes ","Durango        ","Guanajato      ","Hidalgo        ","Jalisco        ","Nayarit        ","Puebla         ","San Luis Potosi","Veracruz       ","Zacatecas      "};
//#define INF 999//Definimos infinito para usarlo en nuesta matrix de adyacencia
int nodos, sourceNode;  //Variables globales

//Matrices como variables globales
float mLibreTiempo[10][10] = {
        {0,999,187,999,239,999,999,205,999,122},
        {999,0,999,999,999,594,999,999,999,223},
        {187,999,0,337,289,999,999,158,999,999},
        {999,999,337,0,999,999,163,354,267,999},
        {239,999,289,999,0,259,683,999,999,999},
        {999,594,999,999,259,0,999,999,999,999},
        {999,999,999,283,683,999,0,999,354,999},
        {205,999,158,354,999,999,999,0,999,141},
        {999,999,999,267,999,999,354,999,0,999},
        {122,223,999,999,999,999,999,141,999,0} };
float mLibreDistancia[10][10] = {
        {0,9999,191,9999,262,9999,9999,240,9999,126},
        {9999,0,9999,9999,9999,583,9999,9999,9999,292},
        {191,9999,0,369,283,9999,9999,193,9999,9999},
        {9999,9999,369,0,9999,9999,164,434,298,9999},
        {262,9999,283,9999,0,242,762,9999,9999,9999},
        {9999,583,9999,9999,242,0,9999,9999,9999,9999},
        {9999,9999,9999,164,762,9999,0,9999,188,9999},
        {240,9999,193,434,9999,9999,9999,0,9999,192.830},
        {9999,9999,9999,298,9999,9999,188,9999,0,9999},
        {126,292,9999,9999,9999,9999,9999,192.830,9999,0} };
float mCuotaDistancia[10][10] = {
        {0,9999,185.28,9999,217,9999,9999,205,9999,125.36},
        {9999,0,9999,9999,9999,459.32,9999,9999,9999,301.54},
        {185.28,9999,0,365,284.35,9999,9999,190,9999,9999},
        {9999,9999,365,0,9999,9999,147,424,278,9999},
        {217,9999,284.35,9999,0,206.62,658.22,9999,9999,9999},
        {9999,459.32,9999,9999,206.62,0,9999,9999,9999,9999},
        {9999,9999,999,147,658.22,9999,0,9999,169,9999},
        {205,9999,190,424,9999,9999,9999,0,9999,9999},
        {9999,9999,9999,278,9999,9999,169,9999,0,9999},
        {125.36,301.54,9999,9999,9999,9999,9999,9999,9999,0} };
float mCuotaTiempo[10][10] = {
        {0,999,110,999,166,999,999,136,999,101},
        {999,0,999,999,999,256,999,999,999,205},
        {110,999,0,260,289,999,999,152,999,999},
        {999,999,260,0,999,999,119,312,208,999},
        {166,999,169,999,0,128,369,999,999,999},
        {999,256,999,999,128,0,999,999,999,999},
        {999,999,999,119,369,999,0,999,137,999},
        {136,999,152,312,999,999,999,0,999,999},
        {999,999,999,208,999,999,137,999,0,999},
        {101,205,999,999,999,999,999,999,999,0} };
float mCuotaCosto[10][10] = {
        {0,9999,329,9999,543.0,9999,9999,101,9999,41},
        {9999,0,9999,9999,9999,1353.0,9999,9999,9999,61},
        {329,9999,0,419,572.0,9999,9999,24,9999,9999},
        {9999,9999,419,0,9999,9999,244,300,723,9999},
        {543.0,9999,572.0,9999,0,274.0,9999,9999,9999,9999},
        {9999,1353.0,9999,9999,274.0,0,9999,9999,9999,9999},
        {9999,9999,9999,244,1370.0,9999,0,9999,723,9999},
        {101,9999,24,300,9999,9999,9999,0,9999,9999},
        {9999,9999,9999,723,9999,9999,723,9999,0,9999},
        {41,61,9999,9999,9999,9999,9999,9999,9999,0} };

void addCamino() {
    int opc, origen, destino;
    float dist, t, precio;
    bool valido = true;
    do {
        cout << endl << "Va a agregar un camino de una carretera libre o de cuota?" << endl;
        cout << "Ingrese su opcion: 1)libre. 2)Cuota" << endl;
        cin >> opc;
        if (opc >= 1 && opc <= 2) {
            switch (opc) {
            case 1: {
                cout << endl << "Eligio crear una nueva carretera libre" << endl;
                cout << "Ingrese por favor el origen de la nueva carretera " << endl;
                cin >> origen;
                cout << "Ingrese por favor el destino de la nueva carretera " << endl;
                cin >> destino;
                cout << "Ingrese por favor la distancia en km que tiene esta nueva carretera " << endl;
                cin >> dist;
                cout << "Ingrese por favor el tiempo en horas que tiene esta nueva carretera (Ejemplo de formato aceptado 2.50 2 horas con 50 minutos)" << endl;
                cin >> t;

                mLibreTiempo[origen][destino] = t;
                mLibreTiempo[destino][origen] = t;
                mLibreDistancia[origen][destino] = dist;
                mLibreDistancia[destino][origen] = dist;

                cout << endl << "Matriz de adyacencia libre con tiempo" << endl;
                for (int i = 0; i < 10; i++) {
                    for (int j = 0; j < 10; j++) {
                        cout << mLibreTiempo[i][j] << " ";
                    }
                    cout << endl;
                }
                cout << endl << "Matriz de adyacencia libre con distancia" << endl;
                for (int i = 0; i < 10; i++) {
                    for (int j = 0; j < 10; j++) {
                        cout << mLibreDistancia[i][j] << " ";
                    }
                    cout << endl;
                }

                break;
            }
            case 2: {
                cout << endl << "Eligio crear una nueva carretera de cuota" << endl;
                cout << "Ingrese por favor el origen de la nueva carretera " << endl;
                cin >> origen;
                cout << "Ingrese por favor el destino de la nueva carretera " << endl;
                cin >> destino;
                cout << "Ingrese por favor la distancia en km que tiene esta nueva carretera " << endl;
                cin >> dist;
                cout << "Ingrese por favor el tiempo en horas que tiene esta nueva carretera (Ejemplo de formato aceptado 2.50 2 horas con 50 minutos)" << endl;
                cin >> t;
                cout << "Ingrese por favor el precio total de las casetas " << endl;
                cin >> precio;

                mLibreTiempo[origen][destino] = t;
                mLibreTiempo[destino][origen] = t;
                mLibreDistancia[origen][destino] = dist;
                mLibreDistancia[destino][origen] = dist;
                mCuotaCosto[origen][destino] = precio;
                mCuotaCosto[destino][origen] = precio;

                cout << endl << "Matriz de adyacencia de cuota con distancia" << endl;
                for (int i = 0; i < 10; i++) {
                    for (int j = 0; j < 10; j++) {
                        cout << mCuotaDistancia[i][j] << " ";
                    }
                    cout << endl;
                }
                cout << endl << "Matriz de adyacencia de cuota con tiempo" << endl;
                for (int i = 0; i < 10; i++) {
                    for (int j = 0; j < 10; j++) {
                        cout << mCuotaTiempo[i][j] << " ";
                    }
                    cout << endl;
                }
                cout << endl << "Matriz de adyacencia de cuota con Costo" << endl;
                for (int i = 0; i < 10; i++) {
                    for (int j = 0; j < 10; j++) {
                        cout << mCuotaCosto[i][j] << " ";
                    }
                    cout << endl;
                }

                break;
            }

            }//end switch
            valido = true;
        }
        else {
            cout << "Ingrese una opcion valida " << endl;
            valido = false;
        }
    } while (valido == false);

}

void deleteCamino() {
    int opc, origen, destino;
    float dist, t, precio;
    bool valido = true;
    do {
        cout << endl << "Va a eliminar un camino de una carretera libre o de cuota?" << endl;
        cout << "Ingrese su opcion: 1)libre. 2)Cuota" << endl;
        cin >> opc;
        if (opc >= 1 && opc <= 2) {
            switch (opc) {
            case 1: {
                cout << endl << "Eligio eliminar una nueva carretera libre" << endl;
                cout << "Ingrese por favor el origen de la carretera a eliminar" << endl;
                cin >> origen;
                cout << "Ingrese por favor el destino de la carretera a eliminar" << endl;
                cin >> destino;
                dist = 999;
                t = 999;

                mLibreTiempo[origen][destino] = t;
                mLibreTiempo[destino][origen] = t;
                mLibreDistancia[origen][destino] = dist;
                mLibreDistancia[destino][origen] = dist;
                cout << endl << "Matriz de adyacencia libre con tiempo" << endl;
                for (int i = 0; i < 10; i++) {
                    for (int j = 0; j < 10; j++) {
                        cout << mLibreTiempo[i][j] << " ";
                    }
                    cout << endl;
                }
                cout << endl << "Matriz de adyacencia libre con distancia" << endl;
                for (int i = 0; i < 10; i++) {
                    for (int j = 0; j < 10; j++) {
                        cout << mLibreDistancia[i][j] << " ";
                    }
                    cout << endl;
                }

                break;
            }
            case 2: {
                cout << endl << "Eligio eliminar una nueva carretera de cuota" << endl;
                cout << "Ingrese por favor el origen de la carretera a eliminar " << endl;
                cin >> origen;
                cout << "Ingrese por favor el destino de la carretera a eliminar" << endl;
                cin >> destino;
                t = 999;
                dist = 999;
                precio = 999;

                mLibreTiempo[origen][destino] = t;
                mLibreTiempo[destino][origen] = t;
                mLibreDistancia[origen][destino] = dist;
                mLibreDistancia[destino][origen] = dist;
                mCuotaCosto[origen][destino] = precio;
                mCuotaCosto[destino][origen] = precio;
                cout << endl << "Matriz de adyacencia de cuota con distancia" << endl;
                for (int i = 0; i < 10; i++) {
                    for (int j = 0; j < 10; j++) {
                        cout << mCuotaDistancia[i][j] << " ";
                    }
                    cout << endl;
                }
                cout << endl << "Matriz de adyacencia de cuota con tiempo" << endl;
                for (int i = 0; i < 10; i++) {
                    for (int j = 0; j < 10; j++) {
                        cout << mCuotaTiempo[i][j] << " ";
                    }
                    cout << endl;
                }
                cout << endl << "Matriz de adyacencia de cuota con Costo" << endl;
                for (int i = 0; i < 10; i++) {
                    for (int j = 0; j < 10; j++) {
                        cout << mCuotaCosto[i][j] << " ";
                    }
                    cout << endl;
                }
                break;
            }

            }//end switch
            valido = true;
        }
        else {
            cout << "Ingrese una opcion valida " << endl;
            valido = false;
        }
    } while (valido == false);
}

int minimumDist(float dist[], bool Tset[]) {
    float min = INT_MAX;
    int index;

    for (int i = 0; i < 10; i++) {
        if (Tset[i] == false && dist[i] <= min) {
            min = dist[i];
            index = i;
        }
    }
    return index;
}

void Dijkstra(float graph[10][10], int src) {
    float dist[10];
    bool Tset[10];

    for (int i = 0; i < 10; i++) {
        dist[i] = INT_MAX;
        Tset[i] = false;
    }

    dist[src] = 0;

    for (int i = 0; i < 10; i++) {
        int m = minimumDist(dist, Tset);

        Tset[m] = true;
        for (int i = 0; i < 10; i++)
        {

            if (!Tset[i] && graph[m][i] && dist[m] != INT_MAX && dist[m] + graph[m][i] < dist[i])
                dist[i] = dist[m] + graph[m][i];
        }
    }
    cout << "Estado\t\tCosto de casetas desde el origen" << endl;
    for (int i = 0; i < 10; i++) { //Printing
        cout << estados[i] << "\t\t\t" << "$ "<<dist[i] << endl;
    }
}

void Dijkstrad(float graph[10][10], int src) {
    float dist[10];
    bool Tset[10];

    for (int i = 0; i < 10; i++) {
        dist[i] = INT_MAX;
        Tset[i] = false;
    }

    dist[src] = 0;

    for (int i = 0; i < 10; i++) {
        int m = minimumDist(dist, Tset);

        Tset[m] = true;
        for (int i = 0; i < 10; i++)
        {

            if (!Tset[i] && graph[m][i] && dist[m] != INT_MAX && dist[m] + graph[m][i] < dist[i])
                dist[i] = dist[m] + graph[m][i];
        }
    }
    cout << "Estado\t\tDistancia desde el origen" << endl;
    for (int i = 0; i < 10; i++) { //Printing
        cout << estados[i] << "\t\t\t" << dist[i] << " km" << endl;
    }
}

void Dijkstrat(float graph[10][10], int src) {
    float dist[10];
    bool Tset[10];

    for (int i = 0; i < 10; i++) {
        dist[i] = INT_MAX;
        Tset[i] = false;
    }

    dist[src] = 0;

    for (int i = 0; i < 10; i++) {
        int m = minimumDist(dist, Tset);

        Tset[m] = true;
        for (int i = 0; i < 10; i++)
        {

            if (!Tset[i] && graph[m][i] && dist[m] != INT_MAX && dist[m] + graph[m][i] < dist[i])
                dist[i] = dist[m] + graph[m][i];
        }
    }
    cout << "Estado\t\tTiempo desde el origen" << endl;
    for (int i = 0; i < 10; i++) { //Printing
        cout << estados[i] << "\t\t\t" << dist[i]/60 << " hrs" << endl;
    }
}

void Displaymenu() {
    cout << "\n\nBienvenidos en este programa usamos grafos para representar estados de la republica Mexicana" << endl;
    cout << "Vamos a usar 10 estados(nodos) los cuales son:\n";
    cout << "0)Aguascalientes\t5)Nayarit\n1)Durango\t\t6)Puebla\n2)Guanajuato\t\t7)San Luis Potosi\n";
    cout << "3)Hidalgo\t\t8)Veracruz\n4)Jalisco\t\t9)Zacatecas\n\n\n";
    cout << "Hay 31 carreteras(enlaces) preestablecidas, hay carreteras de cuota y libre " << endl;
    cout << "Escoja un Parametro de filtro: \n"
        "Por Distancia : 1\n"
        "Por tiempo    : 2\n"
        "Por costo     : 3\n"
        "Agregar Camino: 4\n"
        "Eliminar Camino: 5\n" << endl;
    cout << "Salir     :  0\n" << endl;
}
void MenuDist() {
    cout << "Ha escogido filtrar por distancia\n ";
    cout << "Cual desea que sea el estado Origen?\n ";
    cout << "0)Aguascalientes\t5)Nayarit\n1)Durango\t\t6)Puebla\n2)Guanajuato\t\t7)San Luis Potosi\n";
    cout << "3)Hidalgo\t\t8)Veracruz\n4)Jalisco\t\t9)Zacatecas\n\n\n";
}
void MenuTiemp() {
    cout << "Ha escogido filtrar por tiempo\n ";
    cout << "Cual desea que sea el estado Origen?\n ";
    cout << "0)Aguascalientes\t5)Nayarit\n1)Durango\t\t6)Puebla\n2)Guanajuato\t\t7)San Luis Potosi\n";
    cout << "3)Hidalgo\t\t8)Veracruz\n4)Jalisco\t\t9)Zacatecas\n\n\n";
}
void MenuCost() {
    cout << "Ha escogido filtrar por costo\n ";
    cout << "Cual desea que sea el estado Origen?\n ";
    cout << "0)Aguascalientes\t5)Nayarit\n1)Durango\t\t6)Puebla\n2)Guanajuato\t7)San Luis Potosi\n";
    cout << "3)Hidalgo\t\t8)Veracruz\n4)Jalisco\t\t9)Zacatecas\n\n\n";
}

int main() {
    int principal = 0;
    do {
        Displaymenu();

        int distan = 0;
        int tiempp = 0;
        int cossto = 0;
        int libreocuot = 0;

        cin >> principal;
        switch (principal) {
        case 1://filtrar por distancia
            cout << "Cuota :1\n"
                "Libre :2\n" << endl;
            cin >> libreocuot;
            switch (libreocuot) {
            case 1:
                MenuDist();
                cin >> distan;

                switch (distan) {
                case 0://Ags
                    Dijkstrad(mCuotaDistancia, 0);
                    break;
                case 1://Dur
                    Dijkstrad(mCuotaDistancia, 1);
                    break;
                case 2://Gto
                    Dijkstrad(mCuotaDistancia, 2);
                    break;
                case 3://Hid
                    Dijkstrad(mCuotaDistancia, 3);
                    break;
                case 4://Jal
                    Dijkstrad(mCuotaDistancia, 4);
                    break;
                case 5://Nayarit
                    Dijkstrad(mCuotaDistancia, 5);
                    break;
                case 6://Puebla
                    Dijkstrad(mCuotaDistancia, 6);
                    break;
                case 7://SLP
                    Dijkstrad(mCuotaDistancia, 7);
                    break;
                case 8://Ver
                    Dijkstrad(mCuotaDistancia, 8);
                    break;
                case 9://Zac
                    Dijkstrad(mCuotaDistancia, 9);
                    break;
                }
                break;

            case 2:
                MenuDist();
                cin >> distan;
                switch (distan) {
                case 0://Ags
                    Dijkstrad(mLibreDistancia, 0);
                    break;
                case 1://Dur
                    Dijkstrad(mLibreDistancia, 1);
                    break;
                case 2://Gto
                    Dijkstrad(mLibreDistancia, 2);
                    break;
                case 3://Hid
                    Dijkstrad(mLibreDistancia, 3);
                    break;
                case 4://Jal
                    Dijkstrad(mLibreDistancia, 4);
                    break;
                case 5://Nayarit
                    Dijkstrad(mLibreDistancia, 5);
                    break;
                case 6://Puebla
                    Dijkstrad(mLibreDistancia, 6);
                    break;
                case 7://SLP
                    Dijkstrad(mLibreDistancia, 7);
                    break;
                case 8://Ver
                    Dijkstrad(mLibreDistancia, 8);
                    break;
                case 9://Zac
                    Dijkstrad(mLibreDistancia, 9);
                    break;
                }
                break;

            }
            break;

        case 2://filtrar por tiempo
            cout << "Cuota :1\n"
                "Libre :2\n" << endl;
            cin >> libreocuot;
            switch (libreocuot) {
            case 1:
                MenuTiemp();
                cin >> tiempp;

                switch (tiempp) {
                case 0://Ags
                    Dijkstrat(mCuotaTiempo, 0);
                    break;
                case 1://Dur
                    Dijkstrat(mCuotaTiempo, 1);
                    break;
                case 2://Gto
                    Dijkstrat(mCuotaTiempo, 2);
                    break;
                case 3://Hid
                    Dijkstrat(mCuotaTiempo, 3);
                    break;
                case 4://Jal
                    Dijkstrat(mCuotaTiempo, 4);
                    break;
                case 5://Nayarit
                    Dijkstrat(mCuotaTiempo, 5);
                    break;
                case 6://Puebla
                    Dijkstrat(mCuotaTiempo, 6);
                    break;
                case 7://SLP
                    Dijkstrat(mCuotaTiempo, 7);
                    break;
                case 8://Ver
                    Dijkstrat(mCuotaTiempo, 8);
                    break;
                case 9://Zac
                    Dijkstrat(mCuotaTiempo, 9);
                    break;
                }
                break;

            case 2:
                MenuTiemp();
                cin >> tiempp;
                switch (tiempp) {
                case 0://Ags
                    Dijkstrat(mLibreTiempo, 0);
                    break;
                case 1://Dur
                    Dijkstrat(mLibreTiempo, 1);
                    break;
                case 2://Gto
                    Dijkstrat(mLibreTiempo, 2);
                    break;
                case 3://Hid
                    Dijkstrat(mLibreTiempo, 3);
                    break;
                case 4://Jal
                    Dijkstrat(mLibreTiempo, 4);
                    break;
                case 5://Nayarit
                    Dijkstrat(mLibreTiempo, 5);
                    break;
                case 6://Puebla
                    Dijkstrat(mLibreTiempo, 6);
                    break;
                case 7://SLP
                    Dijkstrat(mLibreTiempo, 7);
                    break;
                case 8://Ver
                    Dijkstrat(mLibreTiempo, 8);
                    break;
                case 9://Zac
                    Dijkstrat(mLibreTiempo, 9);
                    break;
                }
                break;

            }
            break;

        case 3://filtrar por costo
            cout << "Costo :1\n"
                "Sin Costo :2\n" << endl;
            cin >> libreocuot;
            switch (libreocuot) {
            case 1:
                MenuCost();
                cin >> cossto;

                switch (cossto) {
                case 0://Ags
                    Dijkstra(mCuotaCosto, 0);
                    break;
                case 1://Dur
                    Dijkstra(mCuotaCosto, 1);
                    break;
                case 2://Gto
                    Dijkstra(mCuotaCosto, 2);
                    break;
                case 3://Hid
                    Dijkstra(mCuotaCosto, 3);
                    break;
                case 4://Jal
                    Dijkstra(mCuotaCosto, 4);
                    break;
                case 5://Nayarit
                    Dijkstra(mCuotaCosto, 5);
                    break;
                case 6://Puebla
                    Dijkstra(mCuotaCosto, 6);
                    break;
                case 7://SLP
                    Dijkstra(mCuotaCosto, 7);
                    break;
                case 8://Ver
                    Dijkstra(mCuotaCosto, 8);
                    break;
                case 9://Zac
                    Dijkstra(mCuotaCosto, 9);
                    break;
                }
                break;

            case 2:
                cout << "Las carreteras libres no tienen costo" << endl;
                break;
            }//end switch libre cuota
        case 4:
            addCamino();

            cout << "\n\nImpresion de la matriz libre con tiempo despues de agregar un camino\n\n";
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                    cout << mLibreTiempo[i][j] << " ";
                }
                cout << endl;
            }
            break;
        case 5:
            deleteCamino();
            cout << "\n\nImpresion de la matriz libre con tiempo despues de eliminar un camino\n\n";
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                    cout << mLibreTiempo[i][j] << " ";
                }
                cout << endl;
            }
            break;
            
        case 0:
            cout << "¿Esta seguro que quiere salir?" << endl;
            cout << "0)Para salir. Cualquier otro numero para no salir" << endl;
            cin >> principal;
            break;
        }//end switch principal
    }while (principal != 0);

    return 0;
}