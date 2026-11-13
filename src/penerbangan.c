
// ==========================================
// FILE: penerbangan.c
// FUNGSI: Menampilkan dan mengelola penerbangan
// ==========================================

#include <stdio.h>
#include <string.h>
#include "penerbangan.h"
#include "file.h"
#include "kursi.h"

#define MAKS_PENERBANGAN 100

// ==========================================
// INPUT TEKS
// ==========================================

void inputTeks(char teks[], int ukuran) {
    int karakter;

    fgets(teks, ukuran, stdin);
    teks[strcspn(teks, "\n")] = '\0';

    if (strchr(teks, '\n') == NULL) {
        while ((karakter = getchar()) != '\n' && karakter != EOF) {
        }
    }
}

// ==========================================
// MENAMPILKAN DAFTAR PENERBANGAN
// ==========================================

void tampilkanPenerbangan(void) {
    Penerbangan daftar[MAKS_PENERBANGAN];

    int jumlah = bacaDataPenerbangan(daftar, MAKS_PENERBANGAN);

    if (jumlah <= 0) {
        printf("\nData penerbangan tidak tersedia atau gagal dibaca.\n");
        return;
    }

    printf("\n");
    printf("==========================================================================\n");
    printf("                           DAFTAR PENERBANGAN                            \n");
    printf("==========================================================================\n");

    printf("%-5s %-20s %-15s %-15s %-8s %-12s\n",
           "ID", "MASKAPAI", "ASAL", "TUJUAN", "JAM", "HARGA");

    printf("--------------------------------------------------------------------------\n");

    for (int i = 0; i < jumlah; i++) {
        printf("%-5d %-20s %-15s %-15s %-8s Rp%-10d\n",
               daftar[i].id,
               daftar[i].maskapai,
               daftar[i].asal,
               daftar[i].tujuan,
               daftar[i].waktu,
               daftar[i].harga);
    }

    printf("==========================================================================\n");
}

// ==========================================
// MENAMBAHKAN PENERBANGAN
// ==========================================

void tambahPenerbangan(void) {
    Penerbangan daftar[MAKS_PENERBANGAN];

    int jumlah = bacaDataPenerbangan(daftar, MAKS_PENERBANGAN);

    if (jumlah < 0 || jumlah >= MAKS_PENERBANGAN) {
        printf("Data gagal dibaca atau kapasitas penerbangan penuh.\n");
        return;
    }

    Penerbangan baru;

    printf("\n=== TAMBAH PENERBANGAN ===\n");

    printf("ID penerbangan: ");
    scanf("%d", &baru.id);
    getchar();

    for (int i = 0; i < jumlah; i++) {
        if (daftar[i].id == baru.id) {
            printf("ID penerbangan sudah digunakan.\n");
            return;
        }
    }

    printf("Nama maskapai: ");
    inputTeks(baru.maskapai, sizeof(baru.maskapai));

    printf("Kota asal: ");
    inputTeks(baru.asal, sizeof(baru.asal));

    printf("Kota tujuan: ");
    inputTeks(baru.tujuan, sizeof(baru.tujuan));

    printf("Waktu penerbangan: ");
    inputTeks(baru.waktu, sizeof(baru.waktu));

    printf("Harga tiket: ");
    scanf("%d", &baru.harga);

    if (baru.harga <= 0) {
        printf("Harga harus lebih dari 0.\n");
        return;
    }

    daftar[jumlah] = baru;

    if (!simpanDataPenerbangan(daftar, jumlah + 1)) {
        printf("Gagal menyimpan penerbangan.\n");
        return;
    }

    if (!buatKursiPenerbangan(baru.id)) {
        printf("Penerbangan tersimpan, tetapi pembuatan kursi gagal.\n");
        return;
    }

    printf("Penerbangan berhasil ditambahkan.\n");
}

// ==========================================
// MENGUBAH PENERBANGAN
// ==========================================

void ubahPenerbangan(void) {
    Penerbangan daftar[MAKS_PENERBANGAN];

    int jumlah = bacaDataPenerbangan(daftar, MAKS_PENERBANGAN);

    if (jumlah <= 0) {
        printf("Data penerbangan tidak tersedia.\n");
        return;
    }

    int id;
    int ditemukan = 0;

    tampilkanPenerbangan();

    printf("Masukkan ID penerbangan yang ingin diubah: ");
    scanf("%d", &id);
    getchar();

    for (int i = 0; i < jumlah; i++) {
        if (daftar[i].id == id) {
            ditemukan = 1;

            printf("Nama maskapai baru: ");
            inputTeks(daftar[i].maskapai, sizeof(daftar[i].maskapai));

            printf("Kota asal baru: ");
            inputTeks(daftar[i].asal, sizeof(daftar[i].asal));

            printf("Kota tujuan baru: ");
            inputTeks(daftar[i].tujuan, sizeof(daftar[i].tujuan));

            printf("Waktu baru: ");
            inputTeks(daftar[i].waktu, sizeof(daftar[i].waktu));

            printf("Harga baru: ");
            scanf("%d", &daftar[i].harga);

            if (daftar[i].harga <= 0) {
                printf("Harga tidak valid. Perubahan dibatalkan.\n");
                return;
            }

            break;
        }
    }

    if (!ditemukan) {
        printf("Penerbangan tidak ditemukan.\n");
        return;
    }

    if (simpanDataPenerbangan(daftar, jumlah)) {
        printf("Data penerbangan berhasil diubah.\n");
    } else {
        printf("Gagal menyimpan perubahan.\n");
    }
}

// ==========================================
// MENGHAPUS PENERBANGAN
// ==========================================

void hapusPenerbangan(void) {
    Penerbangan daftar[MAKS_PENERBANGAN];

    int jumlah = bacaDataPenerbangan(daftar, MAKS_PENERBANGAN);

    if (jumlah <= 0) {
        printf("Data penerbangan tidak tersedia.\n");
        return;
    }

    int id;
    int ditemukan = -1;

    tampilkanPenerbangan();

    printf("Masukkan ID penerbangan yang ingin dihapus: ");
    scanf("%d", &id);

    for (int i = 0; i < jumlah; i++) {
        if (daftar[i].id == id) {
            ditemukan = i;
            break;
        }
    }

    if (ditemukan == -1) {
        printf("Penerbangan tidak ditemukan.\n");
        return;
    }

    for (int i = ditemukan; i < jumlah - 1; i++) {
        daftar[i] = daftar[i + 1];
    }

    if (simpanDataPenerbangan(daftar, jumlah - 1)) {
        hapusKursiPenerbangan(id);
        printf("Penerbangan berhasil dihapus.\n");
    } else {
        printf("Gagal menghapus penerbangan.\n");
    }
}
