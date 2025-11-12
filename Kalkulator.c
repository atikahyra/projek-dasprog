
#include <stdio.h>

int main() {
    int MenuUtama;
    
    do {
        printf ("\n=== TOOLKIT LENGKAP ASISTEN LABORATORIUM ELEKTRO ===\n");
        printf ("1. Hukum Ohm\n");
        printf ("2. Daya Listrik\n");
        printf ("3. Resistor Seri\n");
        printf ("4. Resistor Paralel\n");
        printf ("5. Konfrensi Desimal --> Biner/Oktal/Heksadesimal\n");
        printf ("6. Konfrensi Biner --> Desimal\n");
        printf ("7. Konfrensi Oktal --> Desimal\n");
        printf ("4. keluar (akhiri program)\n");
        printf ("Pilih Kalkulatar (1-4) = ");
        scanf ("%d" , &MenuUtama);
          
        if (MenuUtama == 1) {
            float V, I, R;
            printf ("Masukkan nilai I = ");
            scanf ("%d", &I);
            printf ("Masukan niali R = ");
            scanf ("%d", &R);
            V = I*R;
            printf ("Nilai Tegangan = %.2f Volt\n", V);
        }
        
        else if (MenuUtama == 2) {
            float V, I, P;
            printf ("Masukkan nilai V = ");
            scanf ("%d", &V);
            printf ("Masukan niali I = ");
            scanf ("%d", &I);
            P = V*I;
            printf ("Nilai Daya Listrik = %.2f Watt\n", P);
        }
        else if (MenuUtama == 3) {
            int n;
            float H = 0.0, total = 0.0;
            printf ("Jumlah Resistor = ");
            scanf ("%d", &n);
            for (int i = 1; i <= n; i++) {
                printf ("Masukkan nilai reisitor ke-%d = ", i);
                scanf ("%f", &H);
                total += H;
        }
                printf ("\Total hambatan seri = %.2f ohm\n", total);
            
        }
        else if (MenuUtama == 4) {
            int n;
            float P, total = 0.0;
            printf ("\nJumlah Resistor = ");
            scanf ("%d", &n);

            for (int i = 1; i <= n; i++) {
                printf ("\nMasukkan nilai reisitor ke-%d = ", i);
                scanf ("%f", &P);

                if (P == 0) {
                    printf ("nilai resistor tidak boleh 0\n");
                    i--;
                    continue;
                }
                total = total + (1.0/P);
        }
        if (total !=0)
            printf ("\n Total hambatan paralel = %.2f ohm\n", 1.0/total);
        else 
            printf ("\n tidak bisa di hitung\n");
        
            printf ("\nTerimakasih\n");
        }
        else
            printf ("Pilihan tidak ada di menu\n");
        }
        
    }while (MenuUtama != 4);
    
    return 0;
        }
            