
#include <iostream> // para: cout
//#include <time.h>   // para: time()
//#include <unistd.h>
//#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>
//#include <string>

using namespace std;

int main() {
    time_t tempo_atual = time (NULL); //time ( &tempo_atual )

    int ano;
    cout << "Entre o ano do nascimento(formato: aaaa): ";
    cin >> ano;
    int mes;
    cout << "Entre o mes do nascimento: ";
    cin >> mes;
    int dia;
    cout << "Entre o dia do nascimento: ";
    cin >> dia;
    
    struct tm * timeinfo = localtime ( &tempo_atual );

    timeinfo->tm_year = ano-1900;
    timeinfo->tm_mon = mes-1;
    timeinfo->tm_mday = dia;
    time_t tempo_data = mktime(timeinfo);

//    cout << asctime(timeinfo) << "\n";
    
    time_t diferenca = difftime(tempo_atual, tempo_data);

    cout << "tempo de vida = " << diferenca << " segundos\n";
    
    return 0;
}