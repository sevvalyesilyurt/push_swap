*This project has been created as part of the 42 curriculum by sevyesil, ahelman.*

# push_swap


## Açıklama

push_swap, verilen bir dizi sayıyı iki yığın (stack A ve stack B) kullanarak, sadece izin verilen hareketlerle sıralamayı hedefleyen bir projedir.

Her sayı önce stack A içine alınır. Programın işi bu sayıları küçükten büyüğe sıralamak için gerekli hamleleri bulmak ve ekrana yazmaktır.

---

## Talimatlar

Projeyi derlemek için:

```bash
make
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

Programı çalıştırmak için:

```bash
./push_swap 3 2 1 6 5
```
Progrmaı hangi algoritmada çalışmasınıda derlerken seçilebilir:

* `her algoritma kendine özel algoritmasını kullanarak sıralar ve ona göre çıktı verir`

* bench flagi giridiğinizde size çalışan algoritmanın karmaşıklığını oranı (disorder) verir.

* flag girilmediği taktirde adaptive algoritmasıyla ölçülen karmaşıklığa bağlı olarak farklı iç yöntemler seçen uyarlanabilir bir strateji uygular.

* Düşük karmaşıklık: eğer karmaşıklık < 0,2 ise, seçtiğiniz yöntem O(n²) sürede çalışmalıdır.

* Orta karmaşıklık: eğer 0,2 <= karmaşıklık < 0,5 ise, seçtiğiniz yöntem O(n√n) sürede çalışmalıdır.

* Yüksek karmaşıklık : eğer karmaşıklık >= 0,5 ise, seçtiğiniz yöntem O(n log n) sürede çalışmalıdır.

./push_swap --bench --simple 3 2 1 6 5 7 9 8

./push_swap --bench --medium  3 2 1 6 5 7 9 8

./push_swap --bench --complex 3 2 1 6 5 7 9 8
---

## Fonksiyonlar ve Anlatımları

Aşağıdaki bölümde proje içindeki her ana fonksiyonun ne yaptığını basit bir dille anlattık. Başlangıçtan sona kadar, programın nasıl çalıştığını adım adım takip edebilirsiniz.

### 1. Ana Akış ve Strateji Seçimi

- **main:**
  - Programın başlangıç noktasıdır.
  - Argüman yoksa hemen çıkar.
  - `parse_main` ile girilen sayıları okur ve stack A’ya koyar.
  - Zaten sıralı ise programı bitirir.
  - **Veri Analizi:** Verilen girişin "disorder" (düzensizlik) oranını hesaplar.
  - **Strateji Belirleme:** Eğer `--adaptive` flag'i aktifse, hesaplanan orana göre en verimli algoritmayı seçer.
  - Son olarak indeksleme yapar ve `sort_dispatch` ile sıralamaya başlar.

- **compute_disorder:**
  - Dizinin ne kadar "karışık" olduğunu matematiksel olarak ölçer.
  - Stack A'daki tüm eleman çiftlerini (i ve j) karşılaştırır. Eğer `i < j` iken `A[i] > A[j]` ise bu bir "hata" (inversion) kabul edilir.
  - **Formül:** `Hata Sayısı / Toplam Çift Sayısı [n*(n-1)/2]`.
  - Sonuç 0.0 (tamamen sıralı) ile 1.0 (tamamen ters sıralı) arasında bir değerdir. Bu değer algoritma seçiminde kritik rol oynar.

- **select_strategy:**
  - `ADAPTIVE` modu seçildiğinde devreye girer:
    - **Disorder < 0.2:** Dizi zaten büyük oranda sıralıdır. **Simple** (O(n²)) stratejisi en az hamleyi üretir.
    - **0.2 <= Disorder < 0.5:** Orta derece karışıklık. **Medium** (O(n√n)) stratejisi seçilir.
    - **Disorder >= 0.5:** Dizi çok karışıktır. En optimize çözüm olan **Complex** (O(n log n)) stratejisi kullanılır.
- **bench:**
	- Program `--bench` flag’i ile çalıştırıldığında, sıralama işlemi tamamlandıktan sonra performans bilgileri stderr’e yazdırılır.

	- Bu mod, algoritmanın nasıl davrandığını analiz etmek için kullanılır ve normal operasyon çıktısını etkilemez.

	- Gösterilen bilgiler:

	- **disorder:** Giriş verisinin ne kadar karışık olduğunu gösteren oran (0 ile 1 arası)
	- **strategy:** Kullanılan algoritma ve teorik complexity’si
	- **total_ops:** Toplam yapılan operasyon sayısı
	- **operation counts:** Her bir push_swap komutunun kaç kez kullanıldığı

 	Örnek kullanım:

```bash
	- ./push_swap --bench 3 2 1 6 5 7 9 8
```
### 2. Girdi Okuma ve Kontrol

- **parse_main:**
  - Komut satırı argümanlarını tek tek inceler.
  - `--bench`, `--adaptive`, `--simple`, `--medium`, `--complex` gibi flagleri işler.
  - Her argümanı `parse_split` ile boşluk bazlı ayırır ve sayı olarak işler.

- **parse_flags:**
  - Argümanların başında `--` ile başlayan özel seçenekler varsa bunları okur.
  - Hatalı bir seçenek varsa `error_exit` ile programı sonlandırır.

- **parse_split:**
  - Bir argüman içindeki boşluklarla ayrılmış sayıları ayırır.
  - Örneğin, `"3 2 1"` gibi bir argümanı üç ayrı sayıya böler.

- **parse_free_split:**
  - `ft_split` tarafından oluşturulan dinamik diziyi serbest bırakır.
  - Bellek sızıntısını önler.

- **ps_validate_string_control:**
  - Bir string’in geçerli bir sayı formatında olup olmadığını kontrol eder.
  - `+`, `-` işaretleri ve sadece rakam içermesi gerektiğini denetler.

- **parse_numbers:**
  - Geçerli bir sayı olduğundan emin olur.
  - `ft_atol` ile sayıya çevirir ve `int` sınırları içinde olup olmadığını kontrol eder.
  - Aynı sayının tekrar girilip girilmediğini kontrol eder.
  - Yeni sayıyı stack A’nın sonuna ekler.

### 3. Veri Yapısı Yardımcıları

- **new_node:**
  - Yeni bir stack düğümü oluşturur.
  - İçine sayı ve varsayılan değerler atar.

- **last_node:**
  - Bir stack’in son düğümünü bulur.
  - Son düğüme ekleme yapılırken kullanılır.

- **add_front:**
  - Yeni bir düğümü stack’in başına ekler.

- **add_back:**
  - Yeni bir düğümü stack’in sonuna ekler.

- **free_stack:**
  - Bir stack içindeki tüm düğümleri serbest bırakır.
  - Program sonunda veya hata durumunda belleği temizler.

### 4. String ve Sayı Dönüşümleri

- **ft_split:**
  - Bir string’i verilen karaktere göre parçalara ayırır.
  - Örneğin, "1 2 3" ifadesini `"1"`, `"2"`, `"3"` olarak ayırır.

- **word_len:**
  - Bir kelimenin uzunluğunu hesaplar.
  - `ft_split` içinde kullanılır.

- **free_split:**
  - `ft_split` ile ayrılan belleği temizler.

- **str_add:**
  - `ft_split` içinde her bir kelimeyi ayırıp yeni diziye kopyalar.

- **ft_strcmp:**
  - İki string’i karşılaştırır.
  - Karakter karakter kontrol ederek farklılık varsa sonucu döndürür.

- **ft_atol:**
  - String’i `long` değere çevirir.
  - İşaret ve boşlukları hesaba katar.

### 5. Sıralama ve Kontrol Fonksiyonları

- **stack_is_sorted:**
  - Stack A’nın sıralı olup olmadığını kontrol eder.
  - Eğer tüm elemanlar artan sıradaysa `1`, değilse `0` döner.

- **set_index:**
  - Her düğüme, değerinin dizideki sırasını gösteren bir indeks atar.
  - Bu indeksler sıralama algoritmalarında daha kolay kıyaslama yapmayı sağlar.

- **set_position:**
  - Her düğümün stack içindeki o anki pozisyonunu (`pos`) hesaplar.
  - Daha sonra maliyeti (`cost`) hesaplamak için kullanılır.

- **find_min_pos:**
  - Stack A’da en küçük sayının hangi pozisyonda olduğunu bulur.
  - Küçük sıralama algoritmalarında kullanılır.

- **find_max_pos:**
  - Stack B’de en büyük sayının hangi pozisyonda olduğunu bulur.
  - Orta boy sıralamada, B’den A’ya geri taşımak için kullanılır.

- **sort_dispatch:**
  - Hangi sıralama fonksiyonunun kullanılacağına karar verir.
  - 5 veya daha az sayı varsa küçük sıralama algoritmasını doğrudan kullanır.
  - Seçilen stratejiye göre `sort_simple`, `sort_medium` veya `sort_complex` çağırır.

### 6.Simple ve Küçük Boyutlu Sıralama

- **sort_small:**
  - Tam olarak 5 ve daha az elemanlı bir stack’i sıralar.
  - Küçük sayılar için en az hamleyle doğru sıra elde edilir.
  - Belirli koşullara göre `sa`, `ra` veya `rra` hamlelerini kullanır.

- **sort_simple:**
  - **Mantık (Selection Sort):** Stack A'daki en küçük elemanı sürekli bulup en üste getirir (ra/rra) ve B'ye atar (pb).
  - Stack A tamamen boşaldığında veya sıralı hale geldiğinde, B'dekileri geri çeker (pa).
  - **Neden kullanılır?** Bu sıralama; %80'i sıralı olan büyük dizilerde, karmaşık hesaplamalara girmeden en az hamleyle çözüme ulaşabilir.

### 7. Medium Sıralama

- **sort_medium:**
  - **Mantık (Square Root Decomposition):** Diziyi `sqrt(n)` büyüklüğünde sanal parçalara (chunk) böler.
  - **A'dan B'ye Geçiş:** Sadece o anki "chunk" içinde kalan indeksleri B'ye gönderir. Eğer gönderilen sayı chunk'ın küçük yarısındaysa B'yi döndürerek (`rb`) B içinde bir ön-sıralama yapar. Bu, B'den geri dönerken işi kolaylaştırır.
  - **B'den A'ya Geçiş:** B'deki en büyük elemanı bulur, en kısa yoldan (ra/rra kararı) tepeye getirir ve A'ya geri iter.
  - **Performans:** O(n√n) karmaşıklığındadır, 100-500 arası sayılarda dengeli bir performans sunar.

- **push_chunks_to_b:**
  - A'daki elemanları indekslerine göre gruplayarak B'ye taşır, B'yi bir "kum saati" yapısına sokar.

- **push_back_to_a:**
  - B'deki elemanları en büyükten başlayarak optimize rotasyonlarla A'ya geri taşır.

### 8. Karmaşık Sıralama

- **sort_complex:**
  - **Mantık (Mechanical Turk / Greedy Algorithm):** En gelişmiş algoritmamızdır. 
  - **Hazırlık:** A'da sadece 3 eleman kalana kadar her şeyi B'ye iter. A'daki 3 elemanı `sort_small` ile sıralar.
  - **Maliyet Analizi:** B'deki her bir eleman için:
    1. A'da nereye girmesi gerektiğini bulur (`target_pos`).
    2. O elemanı B'nin üstüne getirme maliyeti + A'daki hedef yerini en üste getirme maliyetini hesaplar.
  - **Açgözlü Seçim:** Toplam hamle sayısı (maliyet) en düşük olan elemanı seçer ve `rr`/`rrr` (ortak döndürme) optimizasyonlarını kullanarak A'ya taşır.
  - **Sonuç:** O(n log n) gibi çalışır ve özellikle 500+ sayılarda çok düşük hamle sayıları (genelde < 5500) elde eder.

- **set_target_pos:**
  - B’deki her elemanın A’daki hedef pozisyonunu belirler.
  - Hangi A elemanının önüne gelecekse o pozisyonu hedef alır.

- **set_cost:**
  - Her B elemanı için A ve B üzerindeki hamle maliyetini hesaplar.
  - `cost_a` ve `cost_b` değerleri, rotasyonların kaç kez yapılacağını gösterir.

- **get_target_pos:**
  - B’deki bir eleman için A’da en uygun hedef pozisyonu bulur.
  - Eğer uygun bir hedef yoksa, A’daki en küçük sayının pozisyonunu seçer.

- **do_cheapest:**
  - B’deki elemanlar arasında en az toplam maliyetli elemanı seçer.
  - `do_rotate` ile gerekli döndürmeleri yapar ve sonra `pa` ile A’ya taşır.

- **rotate_stack:**
  - Belirtilen maliyete göre A veya B stack’ini yukarı (`ra`/`rb`) veya aşağı (`rra`/`rrb`) döndürür.

- **do_rotate:**
  - Hem A hem B aynı yönde dönüyorsa `rr` veya `rrr` kullanarak işlemleri birleştirir.
  - Bu sayede toplam hamle sayısını azaltır.

- **final_rotate:**
  - A’yı son kez döndürerek en küçük sayının en üste gelmesini sağlar.
  - Böylece sonuç tam olarak sıralı hale gelir.

### 9. Adım Adım Hareket Fonksiyonları

- **sa / sb / ss:**
  - `sa`: A stack’inin en üstündeki iki sayıyı değiştirir.
  - `sb`: B stack’inin en üstündeki iki sayıyı değiştirir.
  - `ss`: Hem A hem B’de aynı anda swap yapar.

- **pa / pb:**
  - `pa`: B’den A’ya bir sayı taşır.
  - `pb`: A’dan B’ye bir sayı taşır.
  - Bu fonksiyonlar `push_node` adında ortak bir yardımcı fonksiyona dayanır.

- **ra / rb / rr:**
  - `ra`: A stack’inde en üstteki sayıyı en alta gönderir.
  - `rb`: B stack’inde aynı işlemi yapar.
  - `rr`: Hem A hem B’de aynı anda rotate yapar.

- **rra / rrb / rrr:**
  - `rra`: A stack’inde en alttaki sayıyı en üste çıkarır.
  - `rrb`: B stack’inde aynı işlemi yapar.
  - `rrr`: Hem A hem B’de aynı anda reverse rotate yapar.

### 10. Hata ve Bellek Yönetimi

- **error_exit:**
  - Hatalı girdi veya tekrar eden sayı durumunda çağrılır.
  - A ve B stack’lerini temizler ve ekrana `Error` yazar.
  - Programı derhal sonlandırır.

---
## Katkılar

- sevyesil:
  - Parsing ve input validation
  - Simple ve Medium ve complex algoritmalar
  - Complex algoritma (cost / greedy)
  - makefile ve yardımcı fonksiyonlar
  

- ahelman:
  - Simple ve Medium ve complex algoritmalar
  - Adaptive strategy ve disorder hesaplama
  - Stack operasyonları ve yardımcı fonksiyonları
  - Benchmark sistemi

## Kaynaklar

- 42 push_swap subject dokümanı  
- C Standard Library (man pages)  
- GeeksforGeeks  
- Stack Overflow
- CS 1332 Data Structures & Algorithms Visualization Tool
- w3schools

---

## AI Kullanımı

Bu proje geliştirilirken yapay zekâ araçları; kavramsal anlamayı desteklemek, akış diyagramı oluşturmak, hata ayıklama süreçlerinde yardımcı olmak ve selection sort, chunk tabanlı sıralama ve Türk algoritması gibi sıralama yaklaşımlarını anlamak amacıyla kullanılmıştır. Tüm kod yazımı sevyesil ve ahelman tarafından gerçekleştirilmiştir. Proje, 42 akademik dürüstlük kurallarına uygun olarak hazırlanmıştır.

---