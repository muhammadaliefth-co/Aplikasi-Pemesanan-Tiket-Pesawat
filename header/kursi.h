
// ==========================================
// FILE: kursi.h
// FUNGSI: Struktur data dan deklarasi modul kursi
// ==========================================

#ifndef KURSI_H
#define KURSI_H

typedef struct {
    int idPenerbangan;
    char nomorKursi[5];
    char status[15];
} Kursi;

void tampilkanKursi(int idPenerbangan);
int pilihKursi(int idPenerbangan, char nomorKursi[]);
int buatKursiPenerbangan(int idPenerbangan);
void hapusKursiPenerbangan(int idPenerbangan);

#endif
