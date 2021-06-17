#include <stdio.h>
#include <windows.h>
#include <locale.h>

#pragma warning(disable : 4996)

/******************************************************************************************/
HWND GetNotepadHandle()
{
    HWND hNotepad = NULL;

    if ((hNotepad = FindWindow(L"notepad", NULL)) == NULL)
        return NULL;

    return hNotepad;
}
/******************************************************************************************/
HWND GetEditboxNotepadHandle()
{
    HWND hNotepad = NULL;
    HWND hEdit = NULL;

    if ((hNotepad = GetNotepadHandle()) == NULL)
        return NULL;
    if ((hEdit = FindWindowEx(hNotepad, 0, L"edit", NULL)) == NULL)
        return NULL;

    return hEdit;
}
/******************************************************************************************/
BOOL ReadInNotepad(LPSTR buffer, SIZE_T bufferLength)
{
    LPSTR tmpBuffer = NULL;
    HWND hEditBoxNotepad = NULL;
    INT lengthInHEditboxNotepad = 0;

    if ((hEditBoxNotepad = GetEditboxNotepadHandle()) == NULL)
        return FALSE;

    lengthInHEditboxNotepad = SendMessage(hEditBoxNotepad, WM_GETTEXTLENGTH, 0, 0);

    if ((tmpBuffer = (LPSTR)HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, lengthInHEditboxNotepad + 1)) == NULL)
        return FALSE;

    if (bufferLength <= lengthInHEditboxNotepad + 1)
        SendMessageA(hEditBoxNotepad, WM_GETTEXT, bufferLength - 1, buffer);
    else
        SendMessageA(hEditBoxNotepad, WM_GETTEXT, lengthInHEditboxNotepad + 1, buffer);

    return TRUE;
}
/******************************************************************************************/
BOOL WriteInNotepad(LPSTR buffer)
{
    LPSTR tmpBuffer = NULL;
    HWND hEditBoxNotepad = NULL;
    INT lengthInHEditboxNotepad = 0;

    if ((hEditBoxNotepad = GetEditboxNotepadHandle()) == NULL)
        return FALSE;

    lengthInHEditboxNotepad = SendMessage(hEditBoxNotepad, WM_GETTEXTLENGTH, 0, 0);

    if ((tmpBuffer = (LPSTR)HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, lengthInHEditboxNotepad + 1)) == NULL)
        return FALSE;

    SendMessageA(hEditBoxNotepad, WM_SETTEXT, strlen(buffer), buffer);
    return TRUE;
}
/******************************************************************************************/
HRESULT sha256(LPSTR PlainTextPassword, LPSTR hashString)
{
    HCRYPTPROV CryptProvider = NULL;
    HCRYPTHASH HashPointer = NULL;

    LPCSTR salt = "Daniel-ZEITOUN";

    LPSTR PlainTextPasswordWithSalt = NULL;

    PlainTextPasswordWithSalt = (LPSTR)HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, strlen(PlainTextPassword) + strlen(salt) + 1);

    if (PlainTextPasswordWithSalt == NULL)
        return E_FAIL;

    strcat(PlainTextPasswordWithSalt, PlainTextPassword);
    strcat(PlainTextPasswordWithSalt, salt);

    if (CryptAcquireContext(&CryptProvider, NULL, NULL, PROV_RSA_AES, CRYPT_VERIFYCONTEXT) == FALSE)
    {
        return(E_FAIL);
    }

    if (CryptCreateHash(CryptProvider, CALG_SHA_256, 0, 0, &HashPointer) == FALSE)
    {
        CryptReleaseContext(CryptProvider, 0);
        return(E_FAIL);
    }

    if (CryptHashData(HashPointer, (BYTE*)PlainTextPasswordWithSalt, (DWORD)strlen(PlainTextPasswordWithSalt), 0) == FALSE)
    {
        CryptDestroyHash(HashPointer);
        CryptReleaseContext(CryptProvider, 0);
        return(E_FAIL);
    }

    BYTE HashBytes[32] = { 0 };
    DWORD HashSize = 32;

    if (CryptGetHashParam(HashPointer, HP_HASHVAL, HashBytes, &HashSize, 0) == FALSE)
    {
        CryptDestroyHash(HashPointer);
        CryptReleaseContext(CryptProvider, 0);
        return(E_FAIL);
    }

    char* Hex = "0123456789abcdef";
    //char HashString[65] = { 0 };

    for (int Count = 0; Count < 32; Count++)
    {
        hashString[Count * 2] = Hex[HashBytes[Count] >> 4];
        hashString[(Count * 2) + 1] = Hex[HashBytes[Count] & 0xF];
    }

    CryptDestroyHash(HashPointer);
    CryptReleaseContext(CryptProvider, 0);

    HeapFree(GetProcessHeap(), HEAP_NO_SERIALIZE, PlainTextPasswordWithSalt);

    return(S_OK);
}
/******************************************************************************************/
CHAR GetRandomFromString(LPSTR string)
{
    return string[rand() % (strlen(string))];
}
VOID okok(LPDWORD ok)
{
    (*ok)--;
    printf("\tMhh ... OK!\n");
}
VOID koko()
{
    printf("\tOh no ...\n");
}
/******************************************************************************************/
int main(int argc, char* argv[])
{
    srand(time(NULL));
    CHAR colorCommand[16] = { 0 };
    strcat(colorCommand, "COLOR ");

    for (DWORD i = 0; i < 2; i++)
        colorCommand[strlen("COLOR ") + i] = GetRandomFromString("0123456789ABCDEF");

    setlocale(LC_ALL, "");
    system(colorCommand);


    printf("############################## CTF ##############################\n");
    printf("#-------------------- Created By [CENSORED] --------------------#\n");
    printf("#---------- This program is the property of [CENSORED] ---------#\n");
    printf("|---------------------------------------------------------------|\n\n");

    printf("“Never watch a problem by only one window,\n");
    printf("there are other ways to solve it,\n");
    printf("but to achieve it, it's important to take notes.”\n");
    printf("Richard BRODIE\n\n\n");

    CHAR notepadBuffer[1000000] = { 0 };
    ReadInNotepad(notepadBuffer, sizeof(notepadBuffer));

    LPSTR line = strtok(notepadBuffer, "\r\n");
    DWORD ok = 4;
    BOOL whoOk = FALSE;
    BOOL whatOk = FALSE;
    BOOL usernameOk = FALSE;
    BOOL passwordOk = FALSE;
    CHAR hashString[256] = { 0 };

    LPCWSTR bullshit = L"aHR0cDovL3JzYS5mb3JudW0udWs=";
    CHAR b[32] = { 0 };
    wsprintf(b, L"%ls", bullshit);
    //wprintf(L"%ls\n", b);

    printf("-------------------------------------\n");

    for (DWORD i = 0; line != NULL; i++)
    {
        LPCSTR helpCmd = "--help";
        LPCSTR aboutCmd = "--about";
        LPCSTR hashCmd = "--hash:";
        LPCSTR flagCmd = "--flag";
        LPCSTR whoCmd = "--who:";
        LPCSTR whatCmd = "--what:";
        LPCSTR usernameCmd = "--username:";
        LPCSTR passwordCmd = "--password:";

        printf("Command:[%s]\n", line);

        if (!strncmp(line, helpCmd, strlen(helpCmd)))
        {
            printf("\t--help        --> prints this help\n");
            printf("\t--about       --> ???\n");
            printf("\t--hash:arg    --> generates salted sha256 hash of arg\n");
            printf("\t--flag        --> ???\n");
            printf("\t... do you know any other arguments ? ...\n\n");
        }
        else if (!strncmp(line, aboutCmd, strlen(aboutCmd)))
        {
            printf("\tMhhhhh ... About who ? ... About what ? Go out!\n");
        }
        else if (!strncmp(line, hashCmd, strlen(hashCmd)))
        {
            ZeroMemory(hashString, sizeof(hashString));
            sha256(line + strlen(hashCmd), hashString);
            printf("\t[%s]:[hash is in your notepad bro]\n", line + strlen(hashCmd), hashString);
            WriteInNotepad(hashString);
            //MessageBoxA(GetNotepadHandle(), hashString, "--hash", MB_ICONINFORMATION);
            //printf("\t[%s]:[%s]\n", line + strlen(hashCmd), hashString);
        }
        else if (!strncmp(line, flagCmd, strlen(flagCmd)))
        {
            if (ok > 0)
            {
                /*CHAR buffer[1024] = { 0 };
                sprintf(buffer, "Remaining arguments before the flag = %d\n", ok);
                MessageBoxA(NULL, buffer, "<http://fornum.uk>", MB_ICONERROR);*/
                printf("\t%d remaining arguments\n", ok);
            }
            else
            {
                printf("\tAll arguments are here.\n\tFlag is : FLAG{saltedSha256(who:what:username:password)}\n");
                MessageBoxA(GetNotepadHandle(), "Flag is : FLAG{saltedSha256(who:what:username:password)}", "--flag", MB_ICONINFORMATION);
                /*CHAR buffer[1024] = { 0 };
                sprintf(buffer, "All arguments are here.\nflag is : sha256(who:what:username:password)\n");
                MessageBoxA(NULL, buffer, "<http://fornum.uk>", MB_ICONINFORMATION);*/
            }
        }
        else if (!strncmp(line,whoCmd, strlen(whoCmd)))
        {
            if (whoOk)
                printf("\tAlready validated\n");
            else if (!strcmp(line, "--who:Itsik Mantin"))
            {
                whoOk = TRUE;
                okok(&ok);
            }
            else
                koko();
        }
        else if (!strncmp(line, whatCmd, strlen(whatCmd)))
        {
            if (whatOk)
                printf("\tAlready validated\n");
            if (!strcmp(line, "--what:Relatively Secret Agency"))
            {
                whatOk = TRUE;
                okok(&ok);
            }
            else
                koko();
        }
        else if (!strncmp(line, usernameCmd, strlen(usernameCmd)))
        {
            if (usernameOk)
                printf("\tAlready validated\n");
            ZeroMemory(hashString, sizeof(hashString));
            sha256(line + strlen(usernameCmd), hashString);

            if (!strcmp(hashString, "b92a9f4819c52edaf09159780066ed3b4cea0c4d8c52ce9261a4ae4f31e375fd"))
            {
                usernameOk = TRUE;
                okok(&ok);
            }
            else
                koko();
        }
        else if (!strncmp(line, passwordCmd, strlen(passwordCmd)))
        {
            if (passwordOk)
                printf("\tAlready validated\n");
            ZeroMemory(hashString, sizeof(hashString));
            sha256(line + strlen(passwordCmd), hashString);

            if (!strcmp(hashString, "592dda37fe16d2aa2f21050c40d8ddee9e252428757b1cededf4ec808e2128cf"))
            {
                passwordOk = TRUE;
                okok(&ok);
            }
            else
                koko();
        }
        else
            printf("\tUnknown command : use --help\n");

        line = strtok(NULL, "\r\n");
    }

    if (ok > 0 && GetNotepadHandle())
    {
        MessageBoxA(GetNotepadHandle(), "Sorry for your notepad ...", "<3", MB_ICONINFORMATION);
        WriteInNotepad("Do you really want the flag ?\r\nLook further than that\r\nTry harder!!!!!!!!!!!\r\n<3\r\n");
    }

    printf("-------------------------------------\n");

    return 0;
}
