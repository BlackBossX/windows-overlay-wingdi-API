#include <stdio.h>
#include <windows.h>

    HDC hdc;
    int main(){
        printf("Crosshair Printing...\n");

    DISPLAY_DEVICE dd;
    dd.cb = sizeof(dd);
    DEVMODE dm;

    int i = 0;
    while (EnumDisplayDevices(NULL, i, &dd, 0)) {
        printf("Display %d: %s\n", i + 1, dd.DeviceName);

        if (EnumDisplaySettings(dd.DeviceName, ENUM_CURRENT_SETTINGS, &dm)) {
            printf("  Resolution: %dx%d @ %d Hz\n", dm.dmPelsWidth, dm.dmPelsHeight, dm.dmDisplayFrequency);
            printf("  Bits per pixel: %d\n", dm.dmBitsPerPel);
        }

        if (dd.StateFlags & DISPLAY_DEVICE_ACTIVE)
            printf("  Status: Active\n");

        if (dd.StateFlags & DISPLAY_DEVICE_PRIMARY_DEVICE)
            printf("  Status: Primary Monitor\n");

        printf("\n");
        i++;

        hdc = CreateDC("DISPLAY1", NULL, NULL, NULL);
        // EnumDisplayMonitors(NULL, NULL, MonitorEnumProc, 0);


       hdc = GetDC(NULL);
        SetViewportOrgEx(hdc, 200, 500, NULL);
        HBRUSH hbrush = CreateSolidBrush(RGB(255, 0, 0));
        SelectObject(hdc, hbrush);


        while (1)
        {
            Rectangle(hdc, 100, 100, 500, 300);
        }
    
    }
}