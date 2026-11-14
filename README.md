# ✈️ Aplikasi Pemesanan Tiket Pesawat

Aplikasi Pemesanan Tiket Pesawat merupakan aplikasi berbasis console yang dikembangkan menggunakan bahasa pemrograman C. Aplikasi ini dirancang untuk membantu proses pengelolaan penerbangan dan pemesanan tiket secara sederhana.

## 📌 Fitur Aplikasi

### 1. Penumpang
- Melihat daftar penerbangan.
- Melihat informasi penerbangan.
- Melihat ketersediaan kursi.
- Memilih penerbangan.
- Memilih nomor kursi.
- Melakukan pemesanan tiket.
- Melihat riwayat pemesanan.

### 2. Admin
- Melihat daftar penerbangan.
- Menambahkan data penerbangan.
- Mengubah data penerbangan.
- Menghapus data penerbangan.
- Mengelola data kursi.
- Melihat riwayat pemesanan.

## 🛠️ Teknologi yang Digunakan

- Bahasa pemrograman C
- GCC Compiler
- Visual Studio Code
- Git
- GitHub
- File TXT digunakan sebagai media penyimpanan data

## 📁 Struktur Folder

```text
Aplikasi-Pemesanan-Tiket-Pesawat/
│
├── src/
│   ├── main.c
│   ├── penerbangan.c
│   ├── penerbangan.h
│   ├── kursi.c
│   ├── kursi.h
│   ├── pemesanan.c
│   ├── pemesanan.h
│   ├── file.c
│   └── file.h
│
├── data/
│   ├── penerbangan.txt
│   ├── kursi.txt
│   └── histori_pemesanan.txt
│
├── .gitignore
└── README.md
```

## 📄 Penjelasan Modul

| `main.c` | Mengatur menu utama aplikasi. |
| `penerbangan.c` | Mengelola data penerbangan. |
| `penerbangan.h` | Deklarasi struktur dan fungsi penerbangan. |
| `kursi.c` | Mengelola data dan pemilihan kursi. |
| `kursi.h` | Deklarasi struktur dan fungsi kursi. |
| `pemesanan.c` | Mengelola proses pemesanan tiket. |
| `pemesanan.h` | Deklarasi struktur dan fungsi pemesanan. |
| `file.c` | Mengatur pembacaan dan penyimpanan data. |
| `file.h` | Deklarasi fungsi pengelolaan file. |

## 💾 Penyimpanan Data

Aplikasi menggunakan file TXT untuk menyimpan data agar informasi tetap tersedia ketika program dijalankan kembali.

### Data Penerbangan

File: `data/penerbangan.txt`

Format: 

```text
ID|Maskapai|Asal|Tujuan|Waktu|Harga
```

### Data Kursi

File: `data/kursi.txt`

Format:

```text
IDPenerbangan|NomorKursi|Status
```

### Riwayat Pemesanan

File: `data/histori_pemesanan.txt`

Format:

```text
IDPemesanan|NamaPenumpang|IDPenerbangan|NomorKursi|TotalHarga
```

## 🚀 Cara Menjalankan Program

### 1. Clone Repository

```bash
git clone https://github.com/muhammadaliefth-co/Aplikasi-Pemesanan-Tiket-Pesawat.git
```

### 2. Masuk ke Direktori Proyek

```bash
cd Aplikasi-Pemesanan-Tiket-Pesawat
```

### 3. Compile Program

Pastikan GCC sudah terpasang.

```bash
gcc src/main.c src/penerbangan.c src/kursi.c src/pemesanan.c src/file.c -o aplikasi
```

### 4. Jalankan Program

Untuk Windows menggunakan Git Bash:

```bash
./aplikasi.exe
```

Untuk Linux:

```bash
./aplikasi
```

**Catatan:** Jalankan program dari direktori utama proyek agar aplikasi dapat menemukan file penyimpanan di dalam folder `data`.

## 👨‍💻 Pengembang

Proyek ini dikembangkan oleh:

1. **Muhammad Alif Alfatah** — `26071206601`
2. **Muhammad Zaidan Nabil** — `26071103624`
3. **Imam Akbar Ramadhan** — `26071101400`
4. **Tengku Suci Firdana** — `26071207843`

**Program Studi:** Teknik Informatika  
**Fakultas:** Teknik

## 🎯 Tujuan Pengembangan

Proyek ini dibuat sebagai penerapan pembelajaran pemrograman bahasa C, khususnya:

- Penggunaan fungsi.
- Penggunaan struktur data (`struct`).
- Modular programming.
- Penggunaan header file.
- Penggunaan Array
- Penggunaan Perulangan
- Pengolahan file (file handling).
---

**Project:** Aplikasi Pemesanan Tiket Pesawat  
**Language:** C  
**Application Type:** Console Application