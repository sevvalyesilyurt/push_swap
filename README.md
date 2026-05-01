# push_swap

*This project has been created as part of the 42 curriculum by sevyesil, ahelman.*

## Açıklama

push_swap, verilen bir dizi sayıyı iki yığın (stack A ve stack B) kullanarak, sadece izin verilen hareketlerle sıralamayı hedefleyen bir projedir.

Her sayı önce stack A içine alınır. Programın işi bu sayıları küçükten büyüğe sıralamak için gerekli hamleleri bulmak ve ekrana yazmaktır.

---

## Talimatlar

Projeyi derlemek için:

```bash
make
```

Programı çalıştırmak için:

```bash
./push_swap 3 2 1 6 5
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

## Fonksiyonlar ve Anlatımları

Aşağıdaki bölümde proje içindeki her ana fonksiyonun ne yaptığını basit bir dille anlattım. Başlangıçtan sona kadar, programın nasıl çalıştığını adım adım takip edebilirsiniz.

### 1. Ana Akış ve Strateji Seçimi

- **main:**
  - Programın başlangıç noktasıdır.
  - Argüman yoksa hemen çıkar.
  - `parse_main` ile girilen sayıları okur ve stack A’ya koyar.
  - Zaten sıralı ise programı bitirir.
  - Verilen girişin karışıklığını hesaplar, uygun stratejiyi seçer, indeksler atar ve son olarak `sort_dispatch` ile sıralamaya geçer.

- **compute_disorder:**
  - Stack A içindeki sayı çiftlerini karşılaştırır.
  - Kaç tane yanlış sıra (a>b) olduğunu sayar ve bu değeri toplam çift sayısına böler.
  - Elde edilen oran, girişin ne kadar karışık olduğunu gösterir.

- **select_strategy:**
  - `ADAPTIVE` modu seçilmişse, `compute_disorder` sonucuna göre hangi algoritmanın kullanılacağına karar verir.
  - Az karışıksa basit, orta karışıksa orta, çok karışıksa karmaşık strateji seçer.

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

- **size_node:**
  - Verilen stack’in kaç eleman içerdiğini döndürür.

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
  - 3 veya daha az sayı varsa küçük sıralama algoritmasını doğrudan kullanır.
  - Seçilen stratejiye göre `sort_simple`, `sort_medium` veya `sort_complex` çağırır.

### 6. Küçük Boyutlu Sıralama

- **sort_small:**
  - Tam olarak 3 elemanlı bir stack’i sıralar.
  - Üç sayı için en az hamleyle doğru sıra elde edilir.
  - Belirli koşullara göre `sa`, `ra` veya `rra` hamlelerini kullanır.

- **sort_simple:**
  - 4 veya 5 elemanlı dizilerde kullanılır.
  - En küçük elemanı en üste getirip `pb` ile B’ye gönderir.
  - A boşalana kadar devam eder, sonra B’den yeniden `pa` ile geri alır.
  - Bu yöntem, küçük diziler için güvenli ve hızlıdır.

### 7. Orta Boy Sıralama

- **sort_medium:**
  - Orta büyüklükte dizilerde `sqrt(n)` yaklaşımı kullanır.
  - A’dan B’ye gruplar halinde değerler taşır.
  - Taşınan değerlerin bir kısmını B’de döndürerek daha iyi yerleşme sağlar.
  - Sonra B’den en büyük elemanı bulur, doğru yere getirir ve `pa` ile A’ya geri taşır.

- **push_chunks_to_b:**
  - A’daki küçük değerleri parça parça B’ye gönderir.
  - Aynı zamanda B’deki bazı sayıları `rb` ile döndürerek doğru yere yerleşmelerini sağlar.

- **push_back_to_a:**
  - B’deki en büyük sayıyı bulur ve onu A’ya geri getirir.
  - En büyük sayıya en az hamleyle ulaşmak için `rb` veya `rrb` kullanır.

### 8. Karmaşık Sıralama

- **sort_complex:**
  - İlk olarak A’dan 3 eleman dışındaki tüm sayıları B’ye gönderir.
  - A’daki 3 elemanı `sort_small` ile sıralar.
  - Sonra B’deki her eleman için en iyi hedef pozisyon ve maliyet hesaplanır.
  - En düşük toplam maliyete sahip eleman `do_cheapest` ile A’ya geri gönderilir.
  - Son olarak A’yı tamamen sıralı hale getirmek için `final_rotate` yapılır.

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

## Kaynaklar

- 42 push_swap subject dokümanı  
- C Standard Library (man pages)  
- GeeksforGeeks  
- Stack Overflow

---

## AI Kullanımı

Bu proje geliştirilirken yapay zekâ araçları; kavramsal anlamayı desteklemek, sahte (pseudo) kod oluşturmak, hata ayıklama süreçlerinde yardımcı olmak ve selection sort, chunk tabanlı sıralama ve Türk algoritması gibi sıralama yaklaşımlarını anlamak amacıyla kullanılmıştır. Tüm kod yazımı sevyesil ve ahelman tarafından gerçekleştirilmiştir. Proje, 42 akademik dürüstlük kurallarına uygun olarak hazırlanmıştır.

---