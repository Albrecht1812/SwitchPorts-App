#include <switch.h>
#include <cstdio>

int main(int argc, char* argv[])
{
    consoleInit(NULL);

    printf("================================\n");
    printf("       SWITCHPORTS\n");
    printf("================================\n\n");

    printf("Welcome to SwitchPorts!\n\n");

    printf("1. Browse Games\n");
    printf("2. Categories\n");
    printf("3. Search Games\n");
    printf("4. Downloads\n");
    printf("5. Favourites\n");
    printf("6. Settings\n\n");

    printf("Application starting...\n");

    while (appletMainLoop())
    {
        consoleUpdate(NULL);
        hidScanInput();

        u64 kDown = hidKeysDown(CONTROLLER_P1_AUTO);

        if (kDown & KEY_PLUS)
            break;
    }

    consoleExit(NULL);
    return 0;
}
