
// ==========================================
// FILE: penerbangan.h
// FUNGSI: Struktur data dan deklarasi modul penerbangan
// ==========================================

#ifndef PENERBANGAN_H
#define PENERBANGAN_H

typedef struct {
    int id;
    char maskapai[50];
    char asal[50];
    char tujuan[50];
    char waktu[10];
    int harga;
} Penerbangan;

void tampilkanPenerbangan(void);
void tambahPenerbangan(void);
void ubahPenerbangan(void);
void hapusPenerbangan(void);

#endif
