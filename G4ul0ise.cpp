#include <windows.h>

using namespace std;

typedef int (__cdecl *ivM)(LPCTSTR say);
FARPROC HookedAddr;
char Obytes[5];

int __stdcall Uhook(LPCTSTR say){
	HINSTANCE DLL;
	ivM pepe;
	
	WriteProcessMemory(GetCurrentProcess(), (LPVOID)HookedAddr, Obytes, 5, 0);
	
	DLL = LoadLibraryA("hwf.dll");
	
	pepe = (ivM) GetProcAddress(DLL, "mommy");
	
	return (pepe) ("Hooked By FuryM3m0ry");
}

void Ahook(void){
		HINSTANCE dllA;
		DWORD *OffSet;
		char p[5];
		p[5] = {0};
		DWORD src;
		DWORD dst;
		
		dllA = LoadLibraryA("hwf.dll");
		HookedAddr = GetProcAddress(dllA, "mommy");
		
		ReadProcessMemory(GetCurrentProcess(), (LPCVOID)HookedAddr, Obytes, 5, 0);
		
		//UhookAddr = &Uhook;
		
		
		src = (DWORD)HookedAddr+5;
		dst = (DWORD)((VOID *)&Uhook);
		OffSet = (DWORD*)(dst - src);
		
		memcpy(p, "\xE9", 1);
		memcpy(p+1, &OffSet, 4);
		
		WriteProcessMemory(GetCurrentProcess(), (LPVOID)HookedAddr, p, 5, 0);
		
}

int main(void) {
	HINSTANCE DLL;
	ivM m0m;

	DLL = LoadLibrary("hwf.dll");
    
    m0m = (ivM) GetProcAddress(DLL, "mommy");
    
	(m0m)("Die M0m");
	
	Ahook();
	
	(m0m)("Die M0m");

	return 0;
}
