# Corth 

A simple math expression interpreter via a stack based memory approach in c. 

## Examples
```console 
30 30 + . 
    prints 60 

100 100 - . 
    prints 0 
```

The dot operator prints values to the standard output.

```console
30 30 30 30 + + + . prints 120 
```
Because 
```
    30 30 30 30 + + + . = ((30 (30 (30 30 +) +) +) .)
                        = ((30 (30 60 +) +) .)
                        = ((30 90 +) .)
                        = (120 .)
                        = 120
```

## Build

```console
cc main.c -o main 
.\main 
```
or 
```console
gcc main.c -o main
.\main
```



