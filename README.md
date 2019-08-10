A tools to analyze the RA2 mix file header.

How to compile (msys2):
```
g++ -c -BUILDING_BLOWFISH_DLL blowfish.cpp
g++ -shared -o blowfish.dll blowfish.o -Wl,--out-implib,libblowfish.a
g++ -c wskeycalu.cpp
g++ -o wskeycalu.exe wskeycalu.o -L. -lblowfish
```
Encrypted header:
    body_size = (file_count * 12 + 6) / 8 + ceil(file_count * 12 + 6) % 8) * 8 + 4 + 80 + *20(if has checksum)*

Reference: http://xhp.xwis.net/documents/MIX_Format.html