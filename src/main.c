
// ==========================================
// FILE: main.c
// FUNGSI: Menu utama aplikasi pemesanan tiket pesawat
// ==========================================

#include <stdio.h>
#include "penerbangan.h"
#include "kursi.h"
#include "pemesanan.h"

// ==========================================
// MENU PENUMPANG
// ==========================================

void menuPenumpang(void) {
    int pilihan;

    do {
        printf("\n");
        printf("========================================\n");
        printf("             MENU PENUMPANG             \n");
        printf("========================================\n");
        printf("1. Lihat daftar penerbangan\n");
        printf("2. Lihat kursi penerbangan\n");
        printf("3. Pesan tiket\n");
        printf("4. Lihat histori pemesanan\n");
        printf("0. Kembali\n");
        printf("========================================\n");
        printf("Pilih menu: ");

        if (scanf("%d", &pilihan) != 1) {
            printf("Input harus berupa angka.\n");
            while (getchar() != '\n');
            pilihan = -1;
            continue;
        }

        switch (pilihan) {
            case 1:
                tampilkanPenerbangan();
                break;

            case 2: {
                int id;
                printf("Masukkan ID penerbangan: ");
                scanf("%d", &id);
                tampilkanKursi(id);
                break;
            }

            case 3:
                buatPemesanan();
                break;

            case 4:
                tampilkanHistoriPemesanan();
                break;

            case 0:
                printf("Kembali ke menu utama.\n");
                break;

            default:
                printf("Pilihan tidak tersedia.\n");
        }

    } while (pilihan != 0);
}

// ==========================================
// MENU ADMIN
// ==========================================

void menuAdmin(void) {
    int pilihan;

    do {
        printf("\n");
        printf("========================================\n");
        printf("               MENU ADMIN               \n");
        printf("========================================\n");
        printf("1. Lihat daftar penerbangan\n");
        printf("2. Tambah penerbangan\n");
        printf("3. Ubah penerbangan\n");
        printf("4. Hapus penerbangan\n");
        printf("5. Lihat histori pemesanan\n");
        printf("6. Lihat kursi penerbangan\n");
        printf("0. Kembali\n");
        printf("========================================\n");
        printf("Pilih menu: ");

        if (scanf("%d", &pilihan) != 1) {
            printf("Input harus berupa angka.\n");
            while (getchar() != '\n');
            pilihan = -1;
            continue;
        }

        switch (pilihan) {
            case 1:
                tampilkanPenerbangan();
                break;

            case 2:
                tambahPenerbangan();
                break;

            case 3:
                ubahPenerbangan();
                break;

            case 4:
                hapusPenerbangan();
                break;

            case 5:
                tampilkanHistoriPemesanan();
                break;

            case 6: {
                int id;
                printf("Masukkan ID penerbangan: ");
                scanf("%d", &id);
                tampilkanKursi(id);
                break;
            }

            case 0:
                printf("Kembali ke menu utama.\n");
                break;

            default:
                printf("Pilihan tidak tersedia.\n");
        }

    } while (pilihan != 0);
}

// ==========================================
// PROGRAM UTAMA
// ==========================================

int main(void) {
    int pilihan;

    do {
        printf("\n");
        printf("========================================\n");
        printf("       APLIKASI PEMESANAN TIKET         \n");
        printf("                PESAWAT                 \n");
        printf("========================================\n");
        printf("1. Masuk sebagai Penumpang\n");
        printf("2. Masuk sebagai Admin\n");
        printf("0. Keluar\n");
        printf("========================================\n");
        printf("Pilih peran: ");

        if (scanf("%d", &pilihan) != 1) {
            printf("Input harus berupa angka.\n");
            while (getchar() != '\n');
            pilihan = -1;
            continue;
        }

        switch (pilihan) {
            case 1:
                menuPenumpang();
                break;

            case 2:
                menuAdmin();
                break;

            case 0:
                printf("Terima kasih telah menggunakan aplikasi.\n");
                break;

            default:
                printf("Pilihan tidak tersedia.\n");
        }

    } while (pilihan != 0);

    return 0;
}
