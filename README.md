# push_swap

*This project has been created as part of the 42 curriculum by sevyesil.*

## Açıklama

push_swap, 42 müfredatında algoritma ve veri yapıları üzerine odaklanan bir sıralama projesidir. Amaç, verilen tamsayı listesini belirli kurallara ve sınırlı operasyonlara uyarak en az adımda sıralamaktır.

Projede iki adet stack (A ve B) kullanılır ve sadece belirli operasyonlar (swap, push, rotate, reverse rotate) ile sıralama yapılabilir. Bu proje, algoritma tasarımı, optimizasyon, veri yapıları ve C dilinde modüler programlama konularında yetkinlik kazandırmayı hedefler.

**Projenin Hedefleri**

- Algoritma ve optimizasyon becerilerini geliştirmek,
- Stack veri yapısı üzerinde etkin işlem yapabilmek,
- Sıralama algoritmalarını anlamak ve uygulamak,
- Temiz, güvenli ve sürdürülebilir C kodu yazmak.

---

## Talimatlar

Projeyi derlemek için:

```bash
make
```

Bonus (checker) programını derlemek için:

```bash
make bonus
```

Oluşturulan obje dosyalarını silmek için:

```bash
make clean
```

Çıktı dosyalarını ve objeleri silmek için:

```bash
make fclean
```

Projeyi temizleyip yeniden derlemek için:

```bash
make re
```

---

## Kullanım

Programı çalıştırmak için:

```bash
./push_swap [sayılar]
```

Örnek:

```bash
./push_swap 3 2 1 6 5
```

Bonus checker programı için:

```bash
./checker [sayılar]
```

---

## Proje Detayları ve Fonksiyonlar

push_swap projesi, aşağıdaki ana bileşenlerden ve fonksiyonlardan oluşur:

### 1. Stack Operasyonları

- **swap (sa, sb, ss):** Stack’in başındaki iki elemanı değiştirir.
- **push (pa, pb):** Bir elemanı bir stack’ten diğerine taşır.
- **rotate (ra, rb, rr):** Stack’in başındaki elemanı sona taşır.
- **reverse rotate (rra, rrb, rrr):** Stack’in sonundaki elemanı başa taşır.

Bu işlemler, `op_swap.c`, `op_push.c`, `op_rotate.c`, `op_rev_rotate.c` dosyalarında fonksiyonlar olarak bulunur. Her biri, ilgili stack üzerinde doğrudan işlem yapar ve gerektiğinde ekrana uygun komutu yazar.

### 2. Sıralama Algoritmaları

- **sort_simple_and_small.c:** 2-3-5 elemanlı küçük diziler için brute force veya özel algoritmalar içerir. Örneğin, üç eleman için minimum adımda sıralama.
- **sort_medium.c:** Orta büyüklükteki diziler için optimize edilmiş algoritmalar (ör. insertion sort, selection sort varyasyonları).
- **sort_complex.c / sort_complex_utils.c:** Büyük diziler için chunking, partitioning ve radix sort gibi gelişmiş algoritmalar uygulanır. Algoritma seçimi, listenin karışıklık oranına göre otomatik yapılabilir.
- **sort_dispatch.c:** Hangi sıralama algoritmasının kullanılacağını belirler ve ilgili fonksiyonu çağırır.

### 3. Parsing & Validasyon

- **parse_main.c / parse_utils.c:** Komut satırı argümanlarını ayrıştırır, hatalı veya tekrarlı girişleri kontrol eder, stack’leri oluşturur.
- **ft_split.c:** String’i ayırmak için kullanılır.

### 4. Stack Yönetimi ve Yardımcı Fonksiyonlar

- **stack_operations.c:** Stack’e eleman ekleme, çıkarma, boyut hesaplama, serbest bırakma gibi temel işlemler.
- **helper_functions.c:** Girdi kontrolü, hata mesajı, sayısal dönüşüm gibi yardımcı fonksiyonlar.
- **error.c:** Hatalı durumda stack’leri temizler ve programı güvenli şekilde sonlandırır.

### 5. Kontrol Fonksiyonları

- **stack_is_sorted:** Stack’in sıralı olup olmadığını kontrol eder.
- **set_index:** Her elemana sıralama için indeks atar.
- **compute_disorder:** Listenin karışıklık oranını hesaplar ve algoritma seçimini etkiler.

### 6. Checker (Bonus)

- **checker_main_bonus.c ve diğerleri:** push_swap’ın ürettiği komutları okur, verilen input üzerinde uygular ve sonucun doğru olup olmadığını kontrol eder.

---

## Kaynaklar

- 42 push_swap subject dokümanı  
- C Standard Library (man pages)  
- GeeksforGeeks  
- Stack Overflow

---

## AI Kullanımı

Bu proje geliştirilirken yapay zekâ araçları yalnızca kavramsal anlamayı desteklemek ve kod gözden geçirme amacıyla kullanılmıştır. Tüm algoritma tasarımı ve kod yazımı sevyesil tarafından gerçekleştirilmiştir. Proje, 42 akademik dürüstlük kurallarına uygun olarak hazırlanmıştır.

---
