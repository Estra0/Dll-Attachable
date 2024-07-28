# 🛠 Création et Injection de DLL en C++

Ce projet présente un exemple basique de création et d'injection d'une DLL en C++. Une DLL (Dynamic Link Library) est un module contenant des fonctions et des données pouvant être utilisés par d'autres programmes. L'injection de DLL est une technique avancée souvent utilisée pour ajouter des fonctionnalités à une application existante ou pour des tests de sécurité.

## 📋 Fonctionnalités

- **Création de DLL**: Le projet inclut un exemple de code pour créer une DLL qui affiche une boîte de message lorsque la DLL est chargée dans un processus.
- **Point d'entrée de la DLL**: Utilise la fonction `DllMain` pour gérer les événements de chargement et de déchargement de la DLL.
- **Exemple de MessageBox**: Lors du chargement, une boîte de message simple est affichée pour indiquer que la DLL a été injectée.

## 📜 Code Principal

### `DllMain.cpp`

```cpp
#include <windows.h>

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        MessageBox(NULL, L"DLL Injected!", L"Info", MB_OK | MB_ICONINFORMATION);
        break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}
