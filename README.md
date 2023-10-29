<div align="center">

# ft_printf
#### *Çünkü ft_putnbr() and ft_putstr() yeterli değil*

[![forthebadge](https://forthebadge.com/images/badges/no-ragrets.svg)](https://forthebadge.com)
</div>

[42 Okulunun](https://42.fr/en/homepage/) 'printf()' projesi, Hedef, çeşitli format belirleyicilerini (c, s, p, d, i, u, x, X ve % gibi) ele alabilen printf işlevinin basitleştirilmiş bir sürümünü yeniden oluşturmaktır.

## Prototip

```c
int ft_printf(const char *str, ...);
```

## Desteklenen format belirticileri

| Format | Output |
| :-------: | ---- |
| `%c` | Tek bir karakter yazdırır |
| `%s` | String yazdırır |
| `%p` | Hexadecimal formatta basılmış bir pointer yazdırır |
| `%d` | Decimal sayı yazdırır |
| `%i` | İnteger sayı yazdırır |
| `%u` | Unsigned sayılar yazdırır |
| `%x` | Hexadecimal tabanda küçük harflerle bir sayı yazdırır |
| `%X` | Hexadecimal tabanda büyük harflerle bir sayı yazdırır |
| `%%` | Tek '%' karakteri yazdırır |

## Makefile Kuralları

Makefile, 'libftprintf.a' adında bir kütüphane oluşturur. Aşağıdaki kurallar bulunmak zorunda:
* `make`
* `make all`
* `make clean`
* `make fclean`
* `make re`

## Neden Format Değişkenini Kullanmak Zorundayız?

Önemli: Önce projeyi inceleyip ardında burayı okumanı tavsiye ederim.

Şöyle açıklayayım olayı. Örneğin
```c
ft_printf("%d, %c", 572, 'A');
```
bu şekilde fonksiyonunuzu çalıştırdınız. Fonksiyonunuz 4 sayısını return edecek çünkü 4 karakter yazdırdık. Format değişkenini kullanmadan direk rtn değişkeninde yazılan karakter sayısını tuttuğumuzu düşünelim. Ortaya şöyle bir senaryo çıkacatır. 

Diyelim ki printf fonksiyonumuz 572 sayısını başarılı şekilde yazdı. rtn değerimiz 3 oldu ama 'A' karakterini yazdırırken hata olduğunu ve -1 döndüğünü düşünelim rtn değerimiz 3'tü 'A' karakterinde yazdırma esnasında hata olduğu için -1 döndü. rtn bu durumda 3 + (-1) = 2 oldu. Ancak hata durumunda bizim -1 döndürmemiz gerekiyordu. rtn'de önceden sayı var olduğu için onunla toplanmış oldu.

Bu yüzden sonucu önce geçici bir değişkende (format) tutup -1 gelip gelmediğini kontrol etmeliyiz. -1 gelmedi ise rtn'ye eklemeliyiz.

Umarım açıklayıcı olmuştur bunun haricinde takılacağınızı düşündüğüm her yere yorum satırları ile açıklama yaptım. Kolay gelsin.

