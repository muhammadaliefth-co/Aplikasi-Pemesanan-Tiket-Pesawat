
// ==========================================
// FILE: pemesanan.h
// FUNGSI: Struktur data dan deklarasi modul pemesanan
// ==========================================

#ifndef PEMESANAN_H
#define PEMESANAN_H

typedef struct {
    int idPemesanan;
    char namaPenumpang[50];
    int idPenerbangan;
    char nomorKursi[5];
    int totalHarga;
} Pemesanan;

void buatPemesanan(void);
void tampilkanHistoriPemesanan(void);

#endif
