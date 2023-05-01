///KOD OPARTY NA MATERIALE PANA MIROSŁAWA ZELENTA.
///WERSJA W C++
///ZROBIONE ORYGINALNIE W CODE::BLOCKS.

#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

void sortowanieBabelkowe(int tablica[], int ile) {
    int temp = 0;

    for(int i=1; i<ile; i++) {
        for(int j=ile-1; j>=1; j--) {
            if(tablica[i] < tablica[j-1]) {
                temp = tablica[i];
                tablica[i] = tablica[j];
                tablica[j] = temp;
            }
        }
    }
}

void sortowanieSzybkie(int tablica[], int lewy, int prawy) {
    int pivot=tablica[(lewy+prawy)/2];
    int p,q,temp;
    p=lewy;
    q=prawy;
    do
    {
        while(tablica[p]<pivot) p++;
        while(tablica[q]>pivot) q--;
        if(p<=q)
        {
            temp=tablica[p];
            tablica[p]=tablica[q];
            tablica[q]=temp;
            p++;
            q--;
        }
    }
    while(p<=q);
    if(q>lewy) sortowanieSzybkie(tablica,lewy, q);
    if(p<prawy) sortowanieSzybkie(tablica, p, prawy);
}

int main() {
    int ile;
    clock_t start, stop;
    double czas;

    cout << "Podaj, ile elementow ma ta tablica: ";
    cin >> ile;

    int *tablica;
    tablica = new int [ile];

    int *tablica2;
    tablica2 = new int [ile];

    srand(time(NULL));

    for(int i=0; i<ile; i++) {
        tablica[i] = rand()%100000+1;
        ///cout << tablica[i];
    }

    for(int i=0; i<ile; i++) {
        tablica2[i] = tablica[i];
    }

    /*
        cout<<"Przed posortowaniem: "<<endl;
        for(int i=0; i<ile; i++)
        {
            cout<<tablica2[i]<<" ";
        }
*/

    cout << endl << "Sortuje teraz babelkowo. Prosze czekac!" << endl;

    start = clock();
    sortowanieBabelkowe(tablica, ile);
    stop = clock();
    czas = (double)(stop-start) / CLOCKS_PER_SEC;

    cout << endl << "Czas trwania sortowania tym sposobem: " << czas << "s.";

    cout << endl << endl << "Sortuje teraz szybko. Prosze czekac!" << endl;

    start = clock();
    sortowanieSzybkie(tablica2, 0, ile-1);
    stop = clock();
    czas = (double)(stop-start) / CLOCKS_PER_SEC;

    cout << endl << "Czas trwania sortowania tym sposobem: " << czas << "s.";


    /*
       cout<<"Po posortowaniu: "<<endl;
        for(int i=0; i<ile; i++)
        {
            cout<<tablica[i]<<" ";
        }
*/


    delete [] tablica;
    delete [] tablica2;

    getchar(); getchar();
    return 0;
}
