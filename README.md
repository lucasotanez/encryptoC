# encryptoC
Password encryption and decryption software for writing/storing passwords safely. Repo includes a C++ library with global scope string encryption functions.

## Instructions on password encryption and decryption for personal use:
### 1. Compile both encryption files with:
```
g++ encrypto1.cpp -o encrypt
g++ decrypto1.cpp -o decrypt
```

### 2. Input password into encrypter like so to receive encrypted string:
```
./encrypt MyPassword@123
```
OR
```
./encrypt [Enter]
MyPassword@123

### 3. Input encrypted string into decrypter to receive password:
```
./decrypt [Enter]
HsgjKm3EEIAD6]NOP2xJtzOS14f
```
