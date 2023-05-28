# K-means
Kısasınav2 nin 2.ödevi

* MAİN 28 AÇIKLAMA *

 1: İlk olarak, gerekli kütüphaneler stdio.h, stdlib.h ve math.h eklenir.
 2: Sabitler tanımlanır. MAKSIMUM_NOKTA sabiti, kümeleme algoritmasında ele alınacak maksimum nokta sayısını belirtir. BANDWIDTH sabiti, her bir noktanın etkileyebileceği alanın yarıçapını belirtir. EPSILON sabiti, merkez değişiminin durma kriteri olarak kullanılan minimum kayma değerini belirtir.
 3: Nokta yapısı tanımlanır. Bu yapı, iki boyutlu bir noktanın x ve y koordinatlarını tutar.
 4: euclideanMesafe fonksiyonu tanımlanır. Bu fonksiyon, iki nokta arasındaki Öklidyen mesafesini hesaplar.
 5: meanShiftKumeleme fonksiyonu tanımlanır. Bu fonksiyon, ortalama kaydırmalı kümeleme algoritmasını uygular.
 6: Ana main fonksiyonu içinde nokta verileri tanımlanır ve meanShiftKumeleme fonksiyonu çağırılır.
 7: Her bir nokta için iteratif olarak merkez güncellemesi yapılır.
 8: Merkez güncellemesi için döngü başlatılır. İlk olarak, kayma değerleri sıfırlanır ve toplam kayma değeri hesaplanır.
 9: Merkezden etkilenen noktaların ağırlıklı toplamı hesaplanır. Her bir nokta için, merkeze olan uzaklık kontrol edilir ve belirli bir yarıçap içinde ise kayma değerleri ve toplam kayma değeri güncellenir.
 10: Yeni merkez hesaplanır. Kayma değerlerinin toplamı, ağırlıklı toplamın bölünmesiyle elde edilir.
 11: Merkez değişimi hesaplanır. Önceki merkez ile yeni merkez arasındaki Öklidyen mesafesi hesaplanır ve toplam kayma değeri olarak atanır.
 12: Merkez değişimi ve iterasyon sayısının kontrolü yapılır. Eğer toplam kayma değeri belirlenen eşik değerinden büyük ve maksimum iterasyon sayısına ulaşılmamışsa döngü devam eder.
 13: Sonuçlar ekrana yazdırılır. Her bir kümeye ait merkez noktaları ve koordinatları görüntülenir.

Not1: Define olarak tanım yapmamızın sebebi define ile tanımlanan sabitler, programda kullanılan tekrar eden değerleri tek bir yerden kontrol etmek ve değiştirmek amacıyla kullanılmıştır. Bu sayede, BANDWIDTH sabiti ile kümeleme algoritmasında kullanılan etki alanının yarıçapı belirlenmiş, EPSILON sabiti ile ise merkez değişiminin durma kriteri olarak kullanılan minimum kayma değeri belirlenmiştir. Bu şekilde, bu değerlerin değiştirilmesi gerektiğinde sadece tanımlanan yerde değişiklik yapılması yeterli olacaktır.Sonuç olarak daha dinamik bir değişken tanımlama kullanılması için define ile tanımladık.

Not2: Bu kodda veri girişi yapılmamıştır. Noktalar sırasıyla: {1.0,1.0}, {1.5,2.0}, {3.0, 4.0}, {5.0, 7.0}, {3.5, 5.0}, {4.5, 5.0}, {3.5, 4.5} şeklinde tanımlanmıştır.

* MAİN 29 AÇIKLAMA *

1: İlk olarak, meanShiftKumeleme fonksiyonu çağrılır ve noktaların kümeleme işlemi başlatılır.
2: Her bir nokta için, başlangıç merkez noktası olarak noktanın kendisi atanır ve eskiMerkez değişkenine kaydedilir.
3: Ardından, bir iterasyon sayaçı (iterasyon) sıfırlanır ve merkez güncellemesi başlar.
4: İç içe döngülerle, her bir nokta için merkezden etkilenen noktaların ağırlıklı toplamı (kaymaX, kaymaY, toplamKayma) hesaplanır.
5: Yeni merkez noktası (yeniMerkez) bu ağırlıklı toplama göre belirlenir.
6: Merkez değişimi hesaplanır ve toplam kayma değeri (toplamKayma) ile eşik değeri (EPSILON) karşılaştırılır. Eğer toplam kayma değeri eşik değerinden büyükse veya maksimum iterasyon sayısı aşılmamışsa, merkez güncelleme işlemi tekrarlanır.
7: Merkez güncelleme işlemi tamamlandıktan sonra, son merkez noktası (eskiMerkez) ekrana yazdırılır. Bu, kümenin merkezini temsil eder.
8: Her bir küme için bu adımlar tekrarlanır ve küme merkezleri sırasıyla ekrana yazdırılır.
Not: Bu kodda veri girişi yapılmaktadır. Nokta sayısı ve koordinatlar kullanıcı tarafından girilmektedir.

* MAİN 29 İÇİN ÖRNEK AÇIKLAMA *

Örneğin {1.0,3.0}, {2.0, 4.0} şeklinde iki nokta girelim;

1: İlk noktaların merkezi olarak kabul edilir ve Kume 1'in merkezi olarak belirlenir: (1.0, 3.0).
2: İkinci nokta, Kume 1'in etki alanına girer, bu nedenle ağırlıklı toplama işlemi yapılır: (1.0 + 2.0, 3.0 + 4.0) = (3.0, 7.0). Ağırlıklı toplamda 2 nokta olduğu için toplam kayma değeri 2'dir.
3: Yeni merkez, ağırlıklı toplamın nokta sayısına bölünmesiyle hesaplanır: (3.0 / 2, 7.0 / 2) = (1.5, 3.5). Bu, Kume 1'in güncellenmiş merkezi olarak belirlenir.
4: Tüm noktaların konumlarındaki değişim ölçülerek, toplam kayma değeri hesaplanır. Bu örnekte, değişim ölçümü olarak Öklidyen mesafesi kullanılır.
5: Toplam kayma değeri belirli bir eşik değerinden büyük olduğu sürece (EPSILON), merkez güncellemesi tekrarlanır.
6: Kume 1'in merkezi artık güncellenmiş bir değere sahiptir: (1.5, 3.5).
7: İkinci nokta, Kume 1'in etki alanına girmediği için ayrı bir küme olarak kabul edilir ve Kume 2'nin merkezi olarak belirlenir: (2.0, 4.0).
8: Bu örnekte iki nokta farklı kümelerde yer aldığı için iki farklı merkez değeri elde edilir: Kume 1 Merkezi (1.5, 3.5) ve Kume 2 Merkezi (2.0, 4.0).

Kaynakça: https://burakbayramli.github.io/dersblog/algs/algs_090_meanshift/ortalama_kaydirma_ile_kumeleme__mean_shift_clustering_.html

          https://www.geeksforgeeks.org/ml-mean-shift-clustering/
