#include <switch.h>
#include <cstdio>

const char* menuItems[] = {
    "Browse Games",
    "Categories",
    "Search Games",
    "Downloads",
    "Favourites",
    "Settings"
};

const int MENU_COUNT = 6;

void drawMenu(int selected)
{
    consoleClear();

    printf("================================\n");
    printf("          SWITCHPORTS\n");
    printf("================================\n\n");

    printf("Welcome to SwitchPorts!\n\n");

    for (int i = 0; i < MENU_COUNT; i++)
    {
        if (i == selected)
            printf("  > %s <\n", menuItems[i]);
        else
            printf("    %s\n", menuItems[i]);
    }

    printf("\n--------------------------------\n");
    printf("D-PAD: Navigate\n");
    printf("A: Select\n");
    printf("B: Back\n");
    printf("PLUS: Exit\n");
}

int main(int argc, char* argv[])
{
    consoleInit(NULL);

    // Configure controller
    padConfigureInput(1, HidNpadStyleSet_NpadStandard);

    PadState pad;
    padInitializeDefault(&pad);

    int selected = 0;
    bool inSection = false;

    drawMenu(selected);

    while (appletMainLoop())
    {
        padUpdate(&pad);

        u64 kDown = padGetButtonsDown(&pad);

        if (kDown & HidNpadButton_Plus)
            break;

        if (!inSection)
        {
            if (kDown & HidNpadButton_Down)
            {
                selected++;

                if (selected >= MENU_COUNT)
                    selected = 0;

                drawMenu(selected);
            }

            if (kDown & HidNpadButton_Up)
            {
                selected--;

                if (selected < 0)
                    selected = MENU_COUNT - 1;

                drawMenu(selected);
            }

            if (kDown & HidNpadButton_A)
            {
                inSection = true;

                consoleClear();

                printf("================================\n");
                printf("          SWITCHPORTS\n");
                printf("================================\n\n");

                printf("%s\n\n", menuItems[selected]);

                printf("This section is coming soon!\n\n");
                printf("Press B to return to the menu.");
            }
        }
        else
        {
            if (kDown & HidNpadButton_B)
            {
                inSection = false;
                drawMenu(selected);
            }
        }

        consoleUpdate(NULL);
    }

    consoleExit();
    return 0;
}
