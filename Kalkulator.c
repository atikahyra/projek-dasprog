#include <stdio.h>
#include <stdlib.h>

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void kalkulatorOhm() {
    float V, I, R;
    int pilihan;
    clearScreen();

    printf("--- Kalkulator Hukum Ohm ---\n");
    printf("1. Hitung Tegangan (V)\n");
    printf("2. Hitung Arus (I)\n");
    printf("3. Hitung Hambatan (R)\n");
    printf("Pilih: ");
    scanf("%d", &pilihan);

    switch (pilihan) {
        case 1:
            printf("Masukkan Arus (I): ");
            scanf("%f", &I);
            printf("Masukkan Hambatan (R): ");
            scanf("%f", &R);
            printf("Tegangan (V) = %.2f Volt\n", I * R);
            break;

        case 2:
            printf("Masukkan Tegangan (V): ");
            scanf("%f", &V);
            printf("Masukkan Hambatan (R): ");
            scanf("%f", &R);
            printf("Arus (I) = %.2f Ampere\n", V / R);
            break;

        case 3:
            printf("Masukkan Tegangan (V): ");
            scanf("%f", &V);
            printf("Masukkan Arus (I): ");
            scanf("%f", &I);
            printf("Hambatan (R) = %.2f Ohm\n", V / I);
            break;

        default:
            printf("Pilihan tidak valid.\n");
    }
}

void kalkulatorDaya() {
    float V, I;
    clearScreen();

    printf("--- Kalkulator Daya Listrik ---\n");
    printf("Masukkan Tegangan (V): ");
    scanf("%f", &V);
    printf("Masukkan Arus (I): ");
    scanf("%f", &I);

    printf("Daya (P) = %.2f Watt\n", V * I);
}

void resistorSeri() {
    int n;
    float total = 0, R;
    clearScreen();

    printf("--- Kalkulator Resistor Seri ---\n");
    printf("Masukkan jumlah resistor: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        printf("Resistor ke-%d (Ohm): ", i);
        scanf("%f", &R);
        total += R;
    }

    printf("Total Hambatan Seri = %.2f Ohm\n", total);
}

void resistorParalel() {
    int n;
    float total = 0, R;
    clearScreen();

    printf("--- Kalkulator Resistor Paralel ---\n");
    printf("Masukkan jumlah resistor: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        printf("Resistor ke-%d (Ohm): ", i);
        scanf("%f", &R);

        if (R == 0) {
            printf("Resistor tidak boleh 0!\n");
            i--;
            continue;
        }
        total += 1.0 / R;
    }

    if (total != 0)
        printf("Total Hambatan Paralel = %.2f Ohm\n", 1.0 / total);
    else
        printf("Tidak dapat dihitung.\n");
}

void konversiDesimal() {
    int desimal, n;

    clearScreen();
    printf("--- Konversi dari Desimal ---\n");
    printf("Masukkan bilangan desimal: ");
    scanf("%d", &desimal);

    int biner[41], b = 0;
    n = desimal;

    if (n == 0) biner[b++] = 0;
    else {
        while (n > 0) {
            biner[b++] = n % 2;
            n /= 2;
        }
    }

    printf("Biner: ");
    for (int j = b - 1; j >= 0; j--) printf("%d", biner[j]);

    // OKTAL
    int oktal[41], o = 0;
    n = desimal;

    if (n == 0) oktal[o++] = 0;
    else {
        while (n > 0) {
            oktal[o++] = n % 8;
            n /= 8;
        }
    }

    printf("\nOktal: ");
    for (int j = o - 1; j >= 0; j--) printf("%d", oktal[j]);

    // HEKSA
    char heksa[41];
    int h = 0;
    n = desimal;

    if (n == 0) heksa[h++] = '0';
    else {
        while (n > 0) {
            int sisa = n % 16;
            if(sisa < 10){
                heksa[h++] = sisa + '0';
            }
            else{
                heksa[h++] = (sisa-10) + 'A';
            }
            n /= 16;
        }
    }

    printf("\nHeksadesimal: ");
    for (int j = h - 1; j >= 0; j--) printf("%c", heksa[j]);

    printf("\n");
}

void binerKeDesimal() {
    long long biner;
    int desimal = 0, sisa, pangkat = 1;

    clearScreen();
    printf("--- Konversi Biner ke Desimal ---\n");
    printf("Masukkan bilangan biner: ");
    scanf("%lld", &biner);
 
    while (biner != 0) {
        sisa = biner % 10;
        desimal += sisa * pangkat;
        pangkat = 2;
        biner /= 10;
    }

    printf("Hasil Desimal: %d\n", desimal);
}

void oktalKeDesimal() {
    int oktal, desimal = 0, pangkat = 1, sisa;

    clearScreen();
    printf("--- Konversi Oktal ke Desimal ---\n");
    printf("Masukkan bilangan oktal: ");
    scanf("%d", &oktal);

    while (oktal != 0) {
        sisa = oktal % 10;
        desimal += sisa * pangkat;
        pangkat *= 8;
        oktal /= 10;
    }

    printf("Hasil Desimal: %d\n", desimal);
}

void heksaKeDesimal() { 
    char hex[41];
    int desimal = 0;

    clearScreen();
    printf("--- Konversi Heksadesimal ke Desimal ---\n");
    printf("Masukkan bilangan heksadesimal: ");
    scanf("%s", hex);

    for (int i = 0; hex[i] != '\0'; i++) {
        char c = hex[i];
        int nilai;

        if (c >= '0' && c <= '9') nilai = c - '0';
        else if (c >= 'A' && c <= 'F') nilai = c - 'A' + 10;
        else if (c >= 'a' && c <= 'f') nilai = c - 'a' + 10;
        else {
            printf("Input tidak valid!\n");
            return;
        }
        desimal = desimal * 16 + nilai;
    }

    printf("Hasil Desimal: %d\n", desimal);
}

int main() {
    int menu;
    char ulang;

    do {
        clearScreen();
        printf("=====================================================\n");
        printf("|   TOOLKIT LENGKAP ASISTEN LABORATORIUM ELEKTRO    |\n");
        printf("=====================================================\n");
        printf("| 1. Kalkulator Hukum Ohm                           |\n");
        printf("| 2. Kalkulator Daya Listrik                        |\n");
        printf("| 3. Kalkulator Resistor Seri                       |\n");
        printf("| 4. Kalkulator Resistor Paralel                    |\n");
        printf("| 5. Desimal -> Biner / Oktal / Heksadesimal        |\n");
        printf("| 6. Biner -> Desimal                               |\n");
        printf("| 7. Oktal -> Desimal                               |\n");
        printf("| 8. Heksadesimal -> Desimal                        |\n");
        printf("| 9. Keluar                                         |\n");
        printf("=====================================================\n");
        printf("Pilih menu (1-9): ");
        scanf("%d", &menu);

        switch (menu) {
            case 1: kalkulatorOhm(); break;
            case 2: kalkulatorDaya(); break;
            case 3: resistorSeri(); break;
            case 4: resistorParalel(); break;
            case 5: konversiDesimal(); break;
            case 6: binerKeDesimal(); break;
            case 7: oktalKeDesimal(); break;
            case 8: heksaKeDesimal(); break;
            case 9:
                clearScreen();
                printf("Terima kasih telah menggunakan toolkit ini!\n");
                return 0;
            default:
                printf("Pilihan tidak valid!\n");
        }

        printf("\nKembali ke menu utama? (y/n): ");
        scanf(" %c", &ulang);

    } while (ulang == 'y' || ulang == 'Y');

    return 0;
}