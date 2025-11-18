#include <stdio.h>
#include <string.h>
#include <stdlib.h> // untuk system()

// Fungsi untuk membersihkan layar (Windows & Linux)
void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int main() {
    int menu;
    char ulang;

    do {
        clearScreen();
        printf("=====================================================\n");
        printf("|   TOOLKIT LENGKAP ASISTEN LABORATORIUM ELEKTRO    |\n");
        printf("=====================================================\n");
        printf("|                                                   |\n");
        printf("|- - - - - - Verifikasi Rangkaian Elektrik - - - - -|\n");
        printf("|1. Kalkulator Hukum Ohm                            |\n");
        printf("|2. Kalkulator Daya Listrik                         |\n");
        printf("|3. Kalkulator Resistor Seri                        |\n");
        printf("|4. Kalkulator Resistor Paralel                     |\n");
        printf("|                                                   |\n");
        printf("|- - - - - - - Utilitas Sistem Digital - - - - - - -|\n");
        printf("|5. Desimal -> Biner / Oktal / Heksadesimal         |\n");
        printf("|6. Biner -> Desimal                                |\n");
        printf("|7. Oktal -> Desimal                                |\n");
        printf("|8. Heksadesimal -> Desimal                         |\n");
        printf("|                                                   |\n");
        printf("|9. Keluar                                          |\n");
        printf("=====================================================\n");
        printf("Pilih menu (1-9): ");
        scanf("%d", &menu);

        if (menu == 1) {
            float V, I, R;
            int pilihan;
            clearScreen();
            printf("--- Kalkulator Hukum Ohm ---\n");
            printf("|Hitung:                   |\n");
            printf("|1. Tegangan (V)           |\n");
            printf("|2. Arus (I)               |\n");
            printf("|3. Hambatan (R)           |\n");
            printf("----------------------------\n");
            printf("Piih: ");
            scanf("%d", &pilihan);

            if (pilihan == 1) {
                printf("Masukkan nilai Arus (I) dalam Ampere: ");
                scanf("%f", &I);
                printf("Masukkan nilai Hambatan (R) dalam Ohm: ");
                scanf("%f", &R);
                V = I * R;
                printf("Tegangan (V) = %.2f Volt\n", V);
            } 
            else if (pilihan == 2) {
                printf("Masukkan nilai Tegangan (V) dalam Volt: ");
                scanf("%f", &V);
                printf("Masukkan nilai Hambatan (R) dalam Ohm: ");
                scanf("%f", &R);
                I = V / R;
                printf("Arus (I) = %.2f Ampere\n", I);
            } 
            else if (pilihan == 3) {
                printf("Masukkan Tegangan (V) dalam Volt: ");
                scanf("%f", &V);
                printf("Masukkan Arus (I) dalam Ampere: ");
                scanf("%f", &I);
                R = V / I;
                printf("Hambatan (R) = %.2f Ohm\n", R);
            } 
            else {
                printf("Pilihan tidak valid.\n");
            }
        }

        else if (menu == 2) {
            float V, I, P;
            clearScreen();
            printf("--- Kalkulator Daya Listrik ---\n");
            printf("Masukkan nilai Tegangan (V): ");
            scanf("%f", &V);
            printf("Masukkan nilai Arus (I): ");
            scanf("%f", &I);
            P = V * I;
            printf("Daya (P) = %.2f Watt\n", P);
        }

        else if (menu == 3) {
            int n;
            float total=0, R;
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

        else if (menu == 4) {
            int n;
            float total=0, R;
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

        else if (menu == 5) {
            int desimal;
            clearScreen();
            printf("--- Konversi dari Desimal ---\n");
            printf("Masukkan bilangan desimal: ");
            scanf("%d", &desimal);

            int biner[32], i = 0, n = desimal;
            while (n > 0) {
                biner[i] = n %2;
                n /= 2;
                i++;
            }
            printf("Biner: ");
            for (int j = i - 1; j >= 0; j--) printf("%d", biner[j]);

            printf("\nOktal: %o", desimal);
            printf("\nHeksadesimal: %X\n", desimal);
        }

        else if (menu == 6) {
            long long biner;
            int desimal = 0, i = 0, sisa;
            clearScreen();
            printf("--- Konversi Biner ke Desimal ---\n");
            printf("Masukkan bilangan biner: ");
            scanf("%lld", &biner);

            while (biner != 0) {
                sisa = biner % 10;
                desimal += sisa * pow(2, i);
                biner /= 10;
                ++i;
            }
            printf("Hasil Desimal: %d\n", desimal);
        }

        else if (menu == 7) {
            int oktal, desimal = 0, i = 0, sisa;
            clearScreen();
            printf("--- Konversi Oktal ke Desimal ---\n");
            printf("Masukkan bilangan oktal: ");
            scanf("%d", &oktal);

            while (oktal != 0) {
                sisa = oktal % 10;
                desimal += sisa * pow(8, i);
                oktal /= 10;
                ++i;
            }
            printf("Hasil Desimal: %d\n", desimal);
        }

        else if (menu == 8) {
            char heksa[20];
            int desimal = 0;
            clearScreen();
            printf("--- Konversi Heksadesimal ke Desimal ---\n");
            printf("Masukkan bilangan heksadesimal: ");
            scanf("%s", heksa);

            for (int i = 0; heksa[i] != '\0'; i++) {
                char c = heksa[i];
                int nilai;
                if (c >= '0' && c <= '9')
                    nilai = c - '0';
                else if (c >= 'A' && c <= 'F')
                    nilai = c - 'A' + 10;
                else if (c >= 'a' && c <= 'f')
                    nilai = c - 'a' + 10;
                else {
                    printf("Input tidak valid!\n");
                    desimal = -1;
                    break;
                }
                if (desimal >= 0)
                    desimal = desimal * 16 + nilai;
            }

            if (desimal >= 0)
                printf("Hasil Desimal: %d\n", desimal);
        }

        else if (menu == 9) {
            clearScreen();
            printf("Terima kasih telah menggunakan toolkit ini!\n");
            break;
        }

        else {
            printf("Pilihan tidak valid!\n");
        }

        printf("\ningin kembali ke menu utama? (y/n): ");
        scanf(" %c", &ulang);

        if (ulang != 'y' && ulang != 'Y') {
            printf("\nTerima kasih telah menggunakan toolkit ini!\n");
            break;
        }

    } while (1);

    return 0;
}
