#gcc rop.c -o rop -m32 -no-pie -fno-stack-protector -s -static

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

enum BOOL
{
    FALSE,
    TRUE
};

void gadgets()
{
    asm("int $0x80");
    asm("ret");

    asm("movl %esi, (%edi)");
    asm("ret");
    
    asm("pop %eax");
    asm("ret");

    asm("pop %ebx");
    asm("ret");

    asm("pop %ecx");
    asm("ret");

    asm("pop %edx");
    asm("ret");

    asm("pop %esi");
    asm("ret");

    asm("pop %edi");
    asm("ret");

    asm("pop %ebp");
    asm("ret");

    asm("pop %esp");
    asm("ret");
}

size_t myStrlen(char* str)
{
    size_t length = 0;

    for(int i = 0 ; str[i] != 0 ; i++)
        length++;

    return length;
}

enum BOOL myStrcmp(char* str1, char* str2, int direction)
{
    int diff = 0;
    int length1 = myStrlen(str1);

    if(length1 != myStrlen(str2))
        return FALSE;

    for(int i = 0 ; i < length1 ; i++)
        diff += str1[i] - str2[i];
    
    switch(direction)
    {
        case 1:
            if(diff != length1)
                return FALSE;
            return TRUE;
        case -1:
            if(diff != -length1)
                return FALSE;
            return TRUE;
    }

    if(diff != 0)
        return FALSE;
    return TRUE;
}

void myStrcpy(char* dst, char* src)
{
    for(int i = 0 ; i < src[i] != 0 ; i++)
        dst[i] = src[i];
}

void ZeroMemory(void* mem, size_t length)
{
    for(int i = 0 ; i < length ; i++)
        *((unsigned char*)mem + i) = 0;
}

void myExit()
{
    printf("\nTry again :p\n");
    exit(0);
}

int GetPassword(int bullshit1, int bullshit2, int bullshit3, int bullshit4, char* buffer, size_t length)
{
    char buffer2[8] = {0};
    do
    {
        int a, b, c = 0;

        //password : cDgzwKvJLdGTBmZpaWeg
                     
        fgets(buffer, length, stdin);
        buffer[myStrlen(buffer) - 1] = 0;

        printf("Wait a few seconds ... :D\n");

        for(int i = 5 ; i > 0 ; i--)
        {
            printf("[%d] ... \n", i);
            sleep(1);
        }

        if(myStrcmp(buffer, "dEh{xLwKMeHUCn[qbXfh", -1) == FALSE)
        {
            c = 23423;
        }

        if(c == 0)
        {
            printf("Do you really want to hack RSA ({Very} Relatively Secret Agency) ? [YES] | [NO] : ");
            fgets(buffer2, sizeof(buffer2) + 512, stdin);
            printf("OK\n");
        }

    } while(FALSE);

    return 0;
}

int main(int argc, char* argv[])
{
    setbuf(stdout, 0);

    printf("%s", "!!! Hello !!!!\n");
    printf("%s", "Access is strictely reserved to Fornum's users\n");
    printf("%s", "I see that you are determined to fight with us!\n");

    printf("Enter your email address : ");

    //email : arthuro.espegil@ctf.co.il
    char buffer[128] = {0};
    fgets(buffer, sizeof(buffer), stdin);
    buffer[myStrlen(buffer) - 1] = 0;

    if(myStrcmp(buffer, "`qsgtqn-drodfhk?bse-bn-hk", +1) == FALSE)
    {
        myExit();
    }

    printf("Enter your password : ");
    GetPassword(21, 445, 3389, 22, buffer, sizeof(buffer));

    return 0;
}