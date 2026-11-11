#include <switch.h>
#include <switch/services/hid.h>
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

    int selected = 0;
    bool inSection = false;

    drawMenu(selected);

    while (appletMainLoop())
    {
        hidScanInput();

        u64 kDown = hidKeysDown(CONTROLLER_P1_AUTO);

        if (kDown & KEY_PLUS)
            break;

        if (!inSection)
        {
            if (kDown & KEY_DOWN)
            {
                selected++;

                if (selected >= MENU_COUNT)
                    selected = 0;

                drawMenu(selected);
            }

            if (kDown & KEY_UP)
            {
                selected--;

                if (selected < 0)
                    selected = MENU_COUNT - 1;

                drawMenu(selected);
            }

            if (kDown & KEY_A)
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
            if (kDown & KEY_B)
            {
                inSection = false;
                drawMenu(selected);
            }
        }

        consoleUpdate(NULL);
    }

    consoleExit(NULL);
    return 0;
}
