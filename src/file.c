// ==========================================
// FILE: file.c
// FUNGSI: Membaca dan menyimpan seluruh data aplikasi
// ==========================================

#include <stdio.h>
#include "file.h"

// ==========================================
// DATA PENERBANGAN
// ==========================================

int bacaDataPenerbangan(Penerbangan daftar[], int kapasitas) {
    FILE *file = fopen("data/penerbangan.txt", "r");

    if (file == NULL) {
        return -1;
    }

    int jumlah = 0;

    while (jumlah < kapasitas) {
        int hasil = fscanf(
            file,
            "%d|%49[^|]|%49[^|]|%49[^|]|%9[^|]|%d",
            &daftar[jumlah].id,
            daftar[jumlah].maskapai,
            daftar[jumlah].asal,
            daftar[jumlah].tujuan,
            daftar[jumlah].waktu,
            &daftar[jumlah].harga
        );

        if (hasil == EOF) {
            break;
        }

        if (hasil != 6) {
            fclose(file);
            return -1;
        }

        jumlah++;

        int karakter;
        while ((karakter = fgetc(file)) != '\n' && karakter != EOF) {
        }
    }

    fclose(file);
    return jumlah;
}

int simpanDataPenerbangan(const Penerbangan daftar[], int jumlah) {
    FILE *file = fopen("data/penerbangan.txt", "w");

    if (file == NULL) {
        return 0;
    }

    for (int i = 0; i < jumlah; i++) {
        fprintf(
            file,
            "%d|%s|%s|%s|%s|%d\n",
            daftar[i].id,
            daftar[i].maskapai,
            daftar[i].asal,
            daftar[i].tujuan,
            daftar[i].waktu,
            daftar[i].harga
        );
    }

    fclose(file);
    return 1;
}

// ==========================================
// DATA KURSI
// ==========================================

int bacaDataKursi(Kursi daftar[], int kapasitas) {
    FILE *file = fopen("data/kursi.txt", "r");

    if (file == NULL) {
        return -1;
    }

    int jumlah = 0;

    while (jumlah < kapasitas) {
        int hasil = fscanf(
            file,
            "%d|%4[^|]|%14s",
            &daftar[jumlah].idPenerbangan,
            daftar[jumlah].nomorKursi,
            daftar[jumlah].status
        );

        if (hasil == EOF) {
            break;
        }

        if (hasil != 3) {
            fclose(file);
            return -1;
        }

        jumlah++;
    }

    fclose(file);
    return jumlah;
}

int simpanDataKursi(const Kursi daftar[], int jumlah) {
    FILE *file = fopen("data/kursi.txt", "w");

    if (file == NULL) {
        return 0;
    }

    for (int i = 0; i < jumlah; i++) {
        fprintf(
            file,
            "%d|%s|%s\n",
            daftar[i].idPenerbangan,
            daftar[i].nomorKursi,
            daftar[i].status
        );
    }

    fclose(file);
    return 1;
}

// ==========================================
// DATA PEMESANAN
// ==========================================

int bacaDataPemesanan(Pemesanan daftar[], int kapasitas) {
    FILE *file = fopen("data/histori_pemesanan.txt", "r");

    if (file == NULL) {
        return -1;
    }

    int jumlah = 0;

    while (jumlah < kapasitas) {
        int hasil = fscanf(
            file,
            "%d|%49[^|]|%d|%4[^|]|%d",
            &daftar[jumlah].idPemesanan,
            daftar[jumlah].namaPenumpang,
            &daftar[jumlah].idPenerbangan,
            daftar[jumlah].nomorKursi,
            &daftar[jumlah].totalHarga
        );

        if (hasil == EOF) {
            break;
        }

        if (hasil != 5) {
            fclose(file);
            return -1;
        }

        jumlah++;

        int karakter;
        while ((karakter = fgetc(file)) != '\n' && karakter != EOF) {
        }
    }

    fclose(file);
    return jumlah;
}

int simpanDataPemesanan(const Pemesanan daftar[], int jumlah) {
    FILE *file = fopen("data/histori_pemesanan.txt", "w");

    if (file == NULL) {
        return 0;
    }

    for (int i = 0; i < jumlah; i++) {
        fprintf(
            file,
            "%d|%s|%d|%s|%d\n",
            daftar[i].idPemesanan,
            daftar[i].namaPenumpang,
            daftar[i].idPenerbangan,
            daftar[i].nomorKursi,
            daftar[i].totalHarga
        );
    }

    fclose(file);
    return 1;
}
