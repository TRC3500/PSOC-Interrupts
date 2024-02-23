#include "project.h"

CY_ISR(MyCustomISR) // This is the first ISR
{
    for (int i = 0; i < 10; i++) // Flash LED 5 times at 1 Hz
    {
        Pin_4_Write(~Pin_4_Read()); // Toggle the LED status then return
        CyDelay(500);
    }
}
CY_ISR(MyCustomISR1) // This is the second ISR
{
    for (int i = 0; i < 10; i++) // Flash LED 5 times at 2 Hz
    {
        Pin_5_Write(~Pin_5_Read()); // Toggle the LED status then return
        CyDelay(250);
    }
}
CY_ISR(MyCustomISR2) // This is the third ISR
{
    for (int i = 0; i < 10; i++) // Flash LED 5 times at 4 Hz
    {
        Pin_6_Write(~Pin_6_Read()); // Toggle the LED status then return
        CyDelay(125);
    }
}

int main(void)
{
    CyGlobalIntEnable;    // Enable global interrupts.
    isr_1_ClearPending(); // Cancel any pending isr_1 interrupts
    isr_2_ClearPending(); // Cancel any pending isr_2 interrupts
    isr_3_ClearPending(); // Cancel any pending isr_3 interrupts

    isr_1_StartEx(MyCustomISR);  // Enable isr_1
    isr_2_StartEx(MyCustomISR1); // Enable isr_2
    isr_3_StartEx(MyCustomISR2); // Enable isr_3
    for (;;)
    {
        // Normally there would be some useful code here
    }
}
