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

## Tests

### [printfTester](https://github.com/Tripouille/printfTester)
![tripouille results](./img/tripouille.png)

### [francinette](https://github.com/xicodomingues/francinette/blob/master/testers/printf)
![francinette results](./img/francinette.png)

### [francinette --strict](https://github.com/xicodomingues/francinette/blob/master/testers/printf)
![francinette --strict results](./img/francinette_strict.png)

