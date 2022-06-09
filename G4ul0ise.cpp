#include <windows.h>

typedef int (__cdecl *ivM)(LPCTSTR say);

int main(void) {
  HINSTANCE DLL;
  ivM m0m;

  DLL = LoadLibrary("hwf.dll");

  if (DLL != NULL) {
    
    m0m = (ivM) GetProcAddress(DLL, "mommy");
    
    while(1){
		if (m0m != NULL) {
			(m0m) ("Die M0m");
			(m0m) ("Die M0m");
		}
	}
	
	BOOL Flib = FreeLibrary(DLL);
  
  }

  return EXIT_SUCCESS;
}
