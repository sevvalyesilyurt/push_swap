# push_swap - 42 Project

## 📌 Proje Hakkında
Bu proje, iki stack (yığın) ve kısıtlı bir komut seti kullanarak verileri en az hamleyle sıralamayı hedefleyen bir algoritma projesidir. 
**42 Kocaeli** bünyesinde bir grup çalışması olarak geliştirilmiştir.

Amacımız, C dilinde veri yapılarını (Stack) yönetmek ve zaman karmaşıklığını (O-notation) optimize ederek en verimli sıralama algoritmasını uygulamaktır.

## 👥 Ekip Üyeleri
Bu proje aşağıdaki geliştiriciler tarafından ortaklaşa hazırlanmıştır:
* [Şevval Yeşilyurt](https://github.com/sevvalyesilyurt)
* [Ahmet Elman](https://github.com/ahmet-elman)

## 🛠️ Kullanılan Komutlar
Algoritma sadece şu operasyonları kullanabilir:
- `sa`, `sb`, `ss` (Swap)
- `pa`, `pb` (Push)
- `ra`, `rb`, `rr` (Rotate)
- `rra`, `rrb`, `rrr` (Reverse Rotate)

## 🚀 Kurulum ve Kullanım

Projeyi klonladıktan sonra kök dizinde şu komutu çalıştırın:
make

Programı test etmek için:
./push_swap 3 2 5 1 4

# PROJE 8 PARÇAYA AYRILDI:

`parse`
Argümanları alma, flag ayırma, sayı doğrulama, split, duplicate kontrolü.

`stack`
Stack oluşturma, erişim, free ve temel yardımcılar.

`ops`
Push_swap operasyonlarının gerçek implementasyonu ve operation emit mantığı.

`analysis`
Disorder hesabı, indexing, istatistik, strategy seçimi.

`sort`
simple, medium, complex, adaptive ve small sort.

`bench`
--bench çıktısı ve operasyon istatistikleri.

`bonus`
checker tarafı.

`utils`
hata, atol, yardımcı fonksiyonlar.

# KAYNAKLAR

[CS 1332 Data Structures & Algorithms Visualization Tool](https://csvistool.com/)

[Push_Swap Turk algorithm explained in 6 steps](https://pure-forest.medium.com/push-swap-turk-algorithm-explained-in-6-steps-4c6650a458c0)

