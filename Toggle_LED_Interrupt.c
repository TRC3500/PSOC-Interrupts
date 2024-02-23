#include "project.h"
CY_ISR(MyCustomISR) // This is the ISR
{
    Pin_4_Write(~Pin_4_Read()); // Toggle the LED status then return
}

int main(void)
{
    CyGlobalIntEnable;    // Enable global interrupts.
    isr_1_ClearPending(); // Cancel any pending isr_1 interrupts

    isr_1_StartEx(MyCustomISR); // Enable the interrupt service routine
    for (;;)
    {
        // Normally there would be some useful code here
    }
}
