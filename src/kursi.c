
// ==========================================
// FILE: kursi.c
// FUNGSI: Mengelola data dan status kursi pesawat
// ==========================================

#include <stdio.h>
#include <string.h>
#include "kursi.h"
#include "file.h"

#define MAKS_KURSI 500

// ==========================================
// MENAMPILKAN KURSI
// ==========================================

void tampilkanKursi(int idPenerbangan) {
    Kursi daftar[MAKS_KURSI];

    int jumlah = bacaDataKursi(daftar, MAKS_KURSI);

    if (jumlah <= 0) {
        printf("Data kursi tidak tersedia.\n");
        return;
    }

    printf("\n===== DENAH KURSI PENERBANGAN %d =====\n", idPenerbangan);
    printf("TERSEDIA = dapat dipilih | TERISI = sudah dipesan\n\n");

    for (int baris = 1; baris <= 4; baris++) {
        for (int kolom = 0; kolom < 4; kolom++) {
            char nomor[5];
            snprintf(nomor, sizeof(nomor), "%c%d", 'A' + kolom, baris);

            int ditemukan = 0;

            for (int i = 0; i < jumlah; i++) {
                if (daftar[i].idPenerbangan == idPenerbangan &&
                    strcmp(daftar[i].nomorKursi, nomor) == 0) {

                    printf("%s [%s]\t",
                           daftar[i].nomorKursi,
                           daftar[i].status);

                    ditemukan = 1;
                    break;
                }
            }

            if (!ditemukan) {
                printf("%s [TIDAK ADA]\t", nomor);
            }
        }

        printf("\n");
    }
}

// ==========================================
// MEMILIH KURSI
// ==========================================

int pilihKursi(int idPenerbangan, char nomorKursi[]) {
    Kursi daftar[MAKS_KURSI];

    int jumlah = bacaDataKursi(daftar, MAKS_KURSI);

    if (jumlah <= 0) {
        return 0;
    }

    for (int i = 0; i < jumlah; i++) {
        if (daftar[i].idPenerbangan == idPenerbangan &&
            strcmp(daftar[i].nomorKursi, nomorKursi) == 0) {

            if (strcmp(daftar[i].status, "TERSEDIA") != 0) {
                printf("Kursi sudah terisi atau tidak tersedia.\n");
                return 0;
            }

            strcpy(daftar[i].status, "TERISI");

            if (simpanDataKursi(daftar, jumlah)) {
                return 1;
            }

            printf("Gagal menyimpan status kursi.\n");
            return 0;
        }
    }

    printf("Nomor kursi tidak ditemukan.\n");
    return 0;
}

// ==========================================
// MEMBUAT 16 KURSI UNTUK PENERBANGAN BARU
// ==========================================

int buatKursiPenerbangan(int idPenerbangan) {
    Kursi daftar[MAKS_KURSI];

    int jumlah = bacaDataKursi(daftar, MAKS_KURSI);

    if (jumlah < 0 || jumlah + 16 > MAKS_KURSI) {
        return 0;
    }

    for (int i = 0; i < jumlah; i++) {
        if (daftar[i].idPenerbangan == idPenerbangan) {
            return 0;
        }
    }

    for (int baris = 1; baris <= 4; baris++) {
        for (int kolom = 0; kolom < 4; kolom++) {
            int indeks = jumlah++;

            daftar[indeks].idPenerbangan = idPenerbangan;

            snprintf(
                daftar[indeks].nomorKursi,
                sizeof(daftar[indeks].nomorKursi),
                "%c%d",
                'A' + kolom,
                baris
            );

            strcpy(daftar[indeks].status, "TERSEDIA");
        }
    }

    return simpanDataKursi(daftar, jumlah);
}

// ==========================================
// MENGHAPUS KURSI PENERBANGAN
// ==========================================

void hapusKursiPenerbangan(int idPenerbangan) {
    Kursi daftar[MAKS_KURSI];

    int jumlah = bacaDataKursi(daftar, MAKS_KURSI);

    if (jumlah < 0) {
        return;
    }

    int jumlahBaru = 0;

    for (int i = 0; i < jumlah; i++) {
        if (daftar[i].idPenerbangan != idPenerbangan) {
            daftar[jumlahBaru] = daftar[i];
            jumlahBaru++;
        }
    }

    simpanDataKursi(daftar, jumlahBaru);
}
