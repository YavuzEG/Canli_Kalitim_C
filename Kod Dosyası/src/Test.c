#include "Habitat.h"

int main() {
    Habitat habitat = { .satir = 0, .sutun = 0 }; 

    VeriAta(&habitat, "Veri.txt");

    printf("Okunan matris:\n");
    VeriYaz(&habitat); 


    printf("İslemin baslamasi icin herhangi bir tusa basin");
    getchar();
    system("cls");
    VeriYe(&habitat);
    VeriYaz(&habitat);
    Kazanan(&habitat);
    Temizle(&habitat);
    return 0;
}