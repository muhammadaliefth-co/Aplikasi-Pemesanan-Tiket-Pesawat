
// ==========================================
// FILE: pemesanan.c
// FUNGSI: Membuat dan menampilkan riwayat pemesanan
// ==========================================

#include <stdio.h>
#include <string.h>
#include "pemesanan.h"
#include "penerbangan.h"
#include "kursi.h"
#include "file.h"

#define MAKS_PEMESANAN 500
#define MAKS_PENERBANGAN 100

// ==========================================
// MEMBUAT PEMESANAN
// ==========================================

void buatPemesanan(void) {
    Penerbangan daftarPenerbangan[MAKS_PENERBANGAN];
    Pemesanan daftarPemesanan[MAKS_PEMESANAN];

    int jumlahPenerbangan = bacaDataPenerbangan(
        daftarPenerbangan,
        MAKS_PENERBANGAN
    );

    int jumlahPemesanan = bacaDataPemesanan(
        daftarPemesanan,
        MAKS_PEMESANAN
    );

    if (jumlahPenerbangan <= 0) {
        printf("Tidak ada penerbangan yang tersedia.\n");
        return;
    }

    if (jumlahPemesanan < 0 || jumlahPemesanan >= MAKS_PEMESANAN) {
        printf("Data pemesanan gagal dibaca atau kapasitas penuh.\n");
        return;
    }

    printf("\n===== PEMESANAN TIKET =====\n");

    tampilkanPenerbangan();

    int idPenerbangan;
    int indeksPenerbangan = -1;

    printf("Masukkan ID penerbangan: ");
    scanf("%d", &idPenerbangan);
    getchar();

    for (int i = 0; i < jumlahPenerbangan; i++) {
        if (daftarPenerbangan[i].id == idPenerbangan) {
            indeksPenerbangan = i;
            break;
        }
    }

    if (indeksPenerbangan == -1) {
        printf("ID penerbangan tidak ditemukan.\n");
        return;
    }

    Pemesanan baru;

    baru.idPemesanan = 1;

    for (int i = 0; i < jumlahPemesanan; i++) {
        if (daftarPemesanan[i].idPemesanan >= baru.idPemesanan) {
            baru.idPemesanan = daftarPemesanan[i].idPemesanan + 1;
        }
    }

    baru.idPenerbangan = idPenerbangan;
    baru.totalHarga = daftarPenerbangan[indeksPenerbangan].harga;

    printf("Nama penumpang: ");
    fgets(baru.namaPenumpang, sizeof(baru.namaPenumpang), stdin);
    baru.namaPenumpang[strcspn(baru.namaPenumpang, "\n")] = '\0';

    if (strlen(baru.namaPenumpang) == 0) {
        printf("Nama penumpang tidak boleh kosong.\n");
        return;
    }

    tampilkanKursi(idPenerbangan);

    printf("\nPilih nomor kursi: ");
    scanf("%4s", baru.nomorKursi);

    if (!pilihKursi(idPenerbangan, baru.nomorKursi)) {
        printf("Pemesanan dibatalkan.\n");
        return;
    }

    daftarPemesanan[jumlahPemesanan] = baru;

    if (!simpanDataPemesanan(daftarPemesanan, jumlahPemesanan + 1)) {
        printf("Gagal menyimpan pemesanan. Hubungi admin untuk pemeriksaan status kursi.\n");
        return;
    }

    printf("\n===== PEMESANAN BERHASIL =====\n");
    printf("ID Pemesanan : %d\n", baru.idPemesanan);
    printf("Nama         : %s\n", baru.namaPenumpang);
    printf("ID Pesawat   : %d\n", baru.idPenerbangan);
    printf("Nomor Kursi  : %s\n", baru.nomorKursi);
    printf("Total Harga  : Rp%d\n", baru.totalHarga);
}

// ==========================================
// MENAMPILKAN HISTORI PEMESANAN
// ==========================================

void tampilkanHistoriPemesanan(void) {
    Pemesanan daftar[MAKS_PEMESANAN];

    int jumlah = bacaDataPemesanan(daftar, MAKS_PEMESANAN);

    if (jumlah < 0) {
        printf("Gagal membaca histori pemesanan.\n");
        return;
    }

    if (jumlah == 0) {
        printf("Belum ada pemesanan.\n");
        return;
    }

    printf("\n");
    printf("====================================================================\n");
    printf("                       HISTORI PEMESANAN                            \n");
    printf("====================================================================\n");

    printf("%-8s %-22s %-12s %-10s %-12s\n",
           "ID", "NAMA", "PENERBANGAN", "KURSI", "HARGA");

    printf("--------------------------------------------------------------------\n");

    for (int i = 0; i < jumlah; i++) {
        printf("%-8d %-22s %-12d %-10s Rp%-10d\n",
               daftar[i].idPemesanan,
               daftar[i].namaPenumpang,
               daftar[i].idPenerbangan,
               daftar[i].nomorKursi,
               daftar[i].totalHarga);
    }

    printf("====================================================================\n");
}
