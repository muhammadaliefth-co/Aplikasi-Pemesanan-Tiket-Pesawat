# ✈️ Aplikasi Pemesanan Tiket Pesawat

Aplikasi Pemesanan Tiket Pesawat merupakan aplikasi berbasis **console** yang dikembangkan menggunakan bahasa pemrograman **C**. Aplikasi ini dirancang untuk membantu proses pengelolaan penerbangan dan pemesanan tiket secara sederhana.

## 📑 Daftar Isi

- [📌 Fitur Aplikasi](#-fitur-aplikasi)
  - [1. Penumpang](#1-penumpang)
  - [2. Admin](#2-admin)
- [🛠️ Teknologi yang Digunakan](#️-teknologi-yang-digunakan)
- [📁 Struktur Folder](#-struktur-folder)
- [📄 Penjelasan Modul](#-penjelasan-modul)
- [💾 Penyimpanan Data](#-penyimpanan-data)
  - [Data Penerbangan](#data-penerbangan)
  - [Data Kursi](#data-kursi)
  - [Riwayat Pemesanan](#riwayat-pemesanan)
- [🚀 Cara Menjalankan Program](#-cara-menjalankan-program)
  - [1. Clone Repository](#1-clone-repository)
  - [2. Masuk ke Folder Project](#2-masuk-ke-folder-project)
  - [3. Compile Program](#3-compile-program)
  - [4. Jalankan Program](#4-jalankan-program)
- [👨‍💻 Pengembang](#-pengembang)
- [🎯 Tujuan Pengembangan](#-tujuan-pengembangan)

---

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
- File TXT sebagai media penyimpanan data

## 📁 Struktur Folder

```text
Aplikasi-Pemesanan-Tiket-Pesawat/
│
├── src/
│   ├── main.c
│   ├── penerbangan.c
│   ├── kursi.c
│   ├── pemesanan.c
│   └── file.c
│
├── header/
│   ├── penerbangan.h
│   ├── kursi.h
│   ├── pemesanan.h
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

### Keterangan Folder

- **`src/`** → berisi file program utama dengan ekstensi `.c`.
- **`header/`** → berisi header file dengan ekstensi `.h` yang digunakan untuk deklarasi struktur dan fungsi.
- **`data/`** → berisi file TXT yang digunakan sebagai penyimpanan data aplikasi.
- **`.gitignore`** → menentukan file atau folder yang tidak perlu disimpan ke repository Git.
- **`README.md`** → dokumentasi proyek.

## 📄 Penjelasan Modul

| File | Fungsi |
|---|---|
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

Aplikasi menggunakan file **TXT** untuk menyimpan data agar informasi tetap tersedia ketika program dijalankan kembali.

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

Pastikan Git sudah terpasang, kemudian jalankan:

```bash
git clone https://github.com/muhammadaliefth-co/Aplikasi-Pemesanan-Tiket-Pesawat.git
```

### 2. Masuk ke Folder Project

```bash
cd Aplikasi-Pemesanan-Tiket-Pesawat
```

### 3. Compile Program

Pastikan **GCC Compiler** sudah terpasang.

Karena header file berada di folder `header/`, gunakan opsi `-Iheader` saat melakukan compile:

```bash
gcc -Iheader src/main.c src/penerbangan.c src/kursi.c src/pemesanan.c src/file.c -o aplikasi
```

Keterangan:

- `-Iheader` → memberitahu GCC untuk mencari header file di folder `header/`.
- `src/main.c` → file program utama.
- `src/penerbangan.c` → modul penerbangan.
- `src/kursi.c` → modul kursi.
- `src/pemesanan.c` → modul pemesanan.
- `src/file.c` → modul pengelolaan file.
- `-o aplikasi` → menghasilkan file executable bernama `aplikasi`.

### 4. Jalankan Program

**Jika menggunakan Git Bash:**

```bash
./aplikasi.exe
```

**Jika menggunakan PowerShell di Visual Studio Code:**

```powershell
.\aplikasi.exe
```

**Jika menggunakan Command Prompt (CMD):**

```cmd
aplikasi.exe
```

> **Catatan:** Jalankan program dari **folder utama project** `Aplikasi-Pemesanan-Tiket-Pesawat` agar aplikasi dapat menemukan file penyimpanan yang berada di dalam folder `data/`.

## 👨‍💻 Pengembang

Proyek ini dikembangkan oleh:

1. **Muhammad Alif Alfatah** — `26071206601`
2. **Muhammad Zaidan Nabil** — `26071103624`
3. **Imam Akbar Ramadhan** — `26071101400`
4. **Tengku Suci Firdana** — `26071207843`

**Program Studi:** Teknik Informatika - A  
**Fakultas:** Teknik

## 🎯 Tujuan Pengembangan

Proyek ini dibuat sebagai penerapan pembelajaran pemrograman bahasa C, khususnya:

- Penggunaan fungsi.
- Penggunaan struktur data (`struct`).
- Modular programming.
- Penggunaan header file.
- Penggunaan array.
- Penggunaan perulangan.
- Pengolahan file (*file handling*).

---

**Project:** Aplikasi Pemesanan Tiket Pesawat  
**Language:** C  
**Application Type:** Console Application