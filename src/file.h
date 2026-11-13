
// ==========================================
// FILE: file.h
// FUNGSI: Deklarasi seluruh fungsi baca dan simpan data
// ==========================================

#ifndef FILE_H
#define FILE_H

#include "penerbangan.h"
#include "kursi.h"
#include "pemesanan.h"

int bacaDataPenerbangan(Penerbangan daftar[], int kapasitas);
int simpanDataPenerbangan(const Penerbangan daftar[], int jumlah);

int bacaDataKursi(Kursi daftar[], int kapasitas);
int simpanDataKursi(const Kursi daftar[], int jumlah);

int bacaDataPemesanan(Pemesanan daftar[], int kapasitas);
int simpanDataPemesanan(const Pemesanan daftar[], int jumlah);

#endif
