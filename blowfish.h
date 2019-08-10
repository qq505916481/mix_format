#ifndef BLOWFISH_DLL_H
#define BLOWFISH_DLL_H

#ifdef __cplusplus
extern "C" {
#endif

#ifdef BUILDING_BLOWFISH_DLL
#define BLOWFISH_DLL __declspec(dllexport)
#else
#define BLOWFISH_DLL __declspec(dllimport)
#endif

#ifdef __cplusplus
}
#endif

using namespace std;

typedef unsigned char byte;
typedef unsigned short word;
typedef unsigned long dword;

typedef dword t_bf_p[18];
typedef dword t_bf_s[4][256];

class BLOWFISH_DLL Cblowfish
{
public:
    void set_key(const byte* key, int cb_key);
    void encipher(dword& xl, dword& xr) const;
    void encipher(const void* s, void* d, int size) const;
    void decipher(dword& xl, dword& xr) const;
    void decipher(const void* s, void* d, int size) const;
private:
    inline dword S(dword x, int i) const;
    inline dword bf_f(dword x) const;
    inline void ROUND(dword& a, dword b, int n) const;

    t_bf_p m_p;
    t_bf_s m_s;
};

#endif  // BLOWFISH_DLL_H