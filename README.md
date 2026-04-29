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

- **swap (sa, sb, ss):**
  - `void op_sa(t_ps *ps)`, `void op_sb(t_ps *ps)`, `void op_ss(t_ps *ps)`
  - Stack’in başındaki iki elemanı değiştirir. `ss` hem A hem B stack’inde aynı anda uygular.
- **push (pa, pb):**
  - `void op_pa(t_ps *ps)`, `void op_pb(t_ps *ps)`
  - Bir elemanı bir stack’ten diğerine taşır. `pa` B’den A’ya, `pb` A’dan B’ye taşır.
- **rotate (ra, rb, rr):**
  - `void op_ra(t_ps *ps)`, `void op_rb(t_ps *ps)`, `void op_rr(t_ps *ps)`
  - Stack’in başındaki elemanı sona taşır. `rr` hem A hem B stack’inde aynı anda uygular.
- **reverse rotate (rra, rrb, rrr):**
  - `void op_rra(t_ps *ps)`, `void op_rrb(t_ps *ps)`, `void op_rrr(t_ps *ps)`
  - Stack’in sonundaki elemanı başa taşır. `rrr` hem A hem B stack’inde aynı anda uygular.

Her fonksiyon, ilgili stack üzerinde doğrudan işlem yapar ve gerektiğinde ekrana uygun komutu yazar.

### 2. Sıralama Algoritmaları

- **sort_simple_and_small.c:**
  - `void sort_simple(t_ps *ps)`: 2-3 elemanlı diziler için brute force sıralama.
  - `void sort_small(t_ps *ps)`: 4-5 elemanlı diziler için optimize edilmiş sıralama.
- **sort_medium.c:**
  - `void sort_medium(t_ps *ps)`: Orta büyüklükteki diziler için insertion sort veya benzeri algoritmalar.
- **sort_complex.c / sort_complex_utils.c:**
  - `void sort_complex(t_ps *ps)`: Büyük diziler için chunking, partitioning ve radix sort gibi gelişmiş algoritmalar.
  - `void push_chunks(t_ps *ps, int chunk_count)`: Diziyi parçalara ayırıp sıralama için kullanılır.
  - `void move_to_b(t_ps *ps, int min, int max)`: Belirli aralıktaki elemanları B stack’ine taşır.
- **sort_dispatch.c:**
  - `void sort_dispatch(t_ps *ps)`: Listenin karışıklık oranına ve boyutuna göre uygun sıralama fonksiyonunu çağırır.

### 3. Parsing & Validasyon

- **parse_main.c / parse_utils.c:**
  - `void parse_main(t_ps *ps, int argc, char **argv)`: Komut satırı argümanlarını ayrıştırır, stack’leri oluşturur.
  - `int parse_flags(t_ps *ps, int argc, char **argv)`: Opsiyonel flag’leri işler.
  - `int is_duplicate(t_node *a, int nbr)`: Tekrarlı girişleri kontrol eder.
  - `long ft_atol(const char *str)`: String’i long’a çevirir, taşma kontrolü yapar.
- **ft_split.c:**
  - `char **ft_split(char const *s, char c)`: String’i ayırmak için kullanılır.

### 4. Stack Yönetimi ve Yardımcı Fonksiyonlar

- **stack_operations.c:**
  - `void stack_add_back(t_node **stack, t_node *new)`: Stack’in sonuna eleman ekler.
  - `void stack_add_front(t_node **stack, t_node *new)`: Stack’in başına eleman ekler.
  - `int stack_size_node(t_node *stack)`: Stack’in boyutunu döndürür.
  - `t_node *stack_last_node(t_node *stack)`: Stack’in sonundaki node’u döndürür.
  - `void free_stack(t_node **node)`: Stack’i serbest bırakır.
- **helper_functions.c:**
  - `int is_number(char *str)`: String’in geçerli bir sayı olup olmadığını kontrol eder.
  - `void print_error(void)`: Hata mesajı basar.
  - `void print_stack(t_node *stack)`: Stack’in içeriğini ekrana basar (debug için).
- **error.c:**
  - `void error_exit(t_ps *ps)`: Hatalı durumda stack’leri temizler ve programı güvenli şekilde sonlandırır.

### 5. Kontrol ve Analiz Fonksiyonları

- **stack_is_sorted:**
  - `int stack_is_sorted(t_node *a)`: Stack’in sıralı olup olmadığını kontrol eder.
- **set_index:**
  - `void set_index(t_node *a)`: Her elemana sıralama için indeks atar.
- **compute_disorder:**
  - `void compute_disorder(t_ps *ps)`: Listenin karışıklık oranını hesaplar ve algoritma seçimini etkiler.

### 6. Checker (Bonus)

- **checker_main_bonus.c ve diğerleri:**
  - `int main(int argc, char **argv)`: push_swap’ın ürettiği komutları okur, verilen input üzerinde uygular ve sonucun doğru olup olmadığını kontrol eder.
  - `void checker_exec(t_ps *ps)`: Komutları uygular.
  - `void checker_parse(t_ps *ps, int argc, char **argv)`: Argümanları ayrıştırır.
  - `void checker_read(t_ps *ps)`: Komutları okur.
  - `void checker_utils(t_ps *ps)`: Yardımcı fonksiyonlar.

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
