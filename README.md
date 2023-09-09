# Rinha
Este projeto está sendo feito pelo [@astahjmo](https://github.com/astahjmo) e [@NiumXp](https://github.com/NiumXp) para a [rinha de compilers](https://github.com/aripiprazole/rinha-de-compiler), transpilamos a AST em JSON para C.

### Como transpilamos uma *Closure* para C?
Uma *closure* é uma função que contêm [variáveis livres](https://stackoverflow.com/questions/21855838/what-are-free-and-bound-variables). Ou seja, as variáveis livres não dependem da função, mas é usada por ela, o que em C podemos representar da seguinte maneira usando uma `struct`:
```c
typedef struct
{
    refs fvars; // Variáveis livres
    void *func; // Endereço para a função
} Closure;
```
A ideia do tipo `refs` é armazenar N-endereços das variáveis livres usadas pela `func`:
```c
typedef uint64_t*   ref;
typedef ref *       refs;
// Ou
typedef uint64_t**   refs;
```
Talvez isso se torne problemático quando precisarmos armazenar valores primitivos como `1` ou `1.2`, por exemplo.

Vamos ver um exemplo de como ficaria uma *closure* simples transpilada:
```
let adder = fn (x) => { fn (y) => { x + y } };
let addTwo = adder(2);
let result = addTwo(3);
print(result)  // 5
```
```c
int adder_closure(refs r, int y)
{
    int x = *((int*)r[0]);  // Resolve a variável livre de `x`
    return y + x;
}

Closure *adder(int x)
{
    ref     r[1] = { (ref)&x };
    Closure c = { ref, adder_closure };  // Imagine que aqui há um malloc;
    return &c;
}

int main(void)
{
    Closure addTwo = adder(2);
    int result = ((int (*)(refs, int))addTwo.func)(3);
    printf("%d\n", (int)i);
}
```
