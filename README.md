# 🚦 Arduino Traffic Light 4 Lajur

Proyek ini merupakan simulasi sistem lampu lalu lintas 4 lajur menggunakan Arduino yang dibuat melalui Tinkercad. Sistem dirancang untuk mengatur alur kendaraan secara bergantian dengan logika seperti lampu lalu lintas nyata.

---

## 📌 Fitur Utama
- 4 lajur persimpangan
- Sistem nyala bergantian
- Lampu hijau menyala selama 5 detik
- Lampu kuning:
  - Kedip sebelum hijau (±2 detik)
  - Kedip setelah hijau (3 kali)
- Lampu merah aktif saat lajur lain berjalan
- Menggunakan konsep modularisasi (fungsi)

---

## 🔌 Konfigurasi Pin
| Lajur | Hijau | Kuning | Merah |
|------|------|--------|------|
| 1    | 2    | 3      | 4    |
| 2    | 5    | 6      | 7    |
| 3    | 8    | 9      | 10   |
| 4    | 11   | 12     | 13   |

---

## 🖥️ Desain Rangkaian

Berikut adalah tampilan rangkaian pada Tinkercad:

![Circuit Design](images/Circuit.png)

---

## 🔗 Link Simulasi Tinkercad
Klik link berikut untuk melihat dan menjalankan simulasi:

👉 https://www.tinkercad.com/things/5Ek4kmtJdDc-traffic-light

---

## ⚙️ Cara Menjalankan
1. Buka Arduino IDE / Tinkercad
2. Upload file `.ino`
3. Pastikan rangkaian sesuai dengan konfigurasi pin
4. Jalankan simulasi / upload ke board Arduino

---
