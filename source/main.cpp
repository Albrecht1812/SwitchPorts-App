#include <switch.h>
#include <cstdio>

int main(int argc, char* argv[])
{
    consoleInit(NULL);

    // Configure controller input
    padConfigureInput(1, HidNpadStyleSet_NpadStandard);

    // Initialize the controller
    PadState pad;
    padInitializeDefault(&pad);

    printf("================================\n");
    printf("          SWITCHPORTS\n");
    printf("================================\n\n");

    printf("Welcome to SwitchPorts!\n\n");

    printf("1. Browse Games\n");
    printf("2. Categories\n");
    printf("3. Search Games\n");
    printf("4. Downloads\n");
    printf("5. Favourites\n");
    printf("6. Settings\n\n");

    printf("Press + to exit.\n");

    while (appletMainLoop())
    {
        // Read controller input
        padUpdate(&pad);

        u64 kDown = padGetButtonsDown(&pad);

        // Exit when PLUS is pressed
        if (kDown & HidNpadButton_Plus)
            break;

        consoleUpdate(NULL);
    }

    consoleExit(NULL);

    return 0;
}
