/*******************************************************************************
  Resets (Power) PLIB

  Company
    Microchip Technology Inc.

  File Name
    plib_power.c

  Summary
    Power PLIB Implementation File.

  Description
    This file defines the interface to the DSCTRL peripheral library.
    This library provides access to and control of the associated Resets.

  Remarks:
    None.

*******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2019 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER SOURCED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*******************************************************************************/
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include "plib_power.h"

// *****************************************************************************
// *****************************************************************************
// Section: Power Implementation
// *****************************************************************************
// *****************************************************************************
void POWER_LowPowerModeEnter (POWER_LOW_POWER_MODE mode)
{
    /* unlock system */
    CFG_REGS->CFG_SYSKEY = 0x00000000;
    CFG_REGS->CFG_SYSKEY = 0xAA996655;
    CFG_REGS->CFG_SYSKEY = 0x556699AA;

    switch(mode)
    {
        case LOW_POWER_IDLE_MODE: 
                        CRU_REGS->CRU_OSCCONCLR = CRU_OSCCON_SLPEN_Msk;
                        break;
        case LOW_POWER_SLEEP_MODE:
                        CRU_REGS->CRU_OSCCONSET = CRU_OSCCON_SLPEN_Msk;
                        break;
        case LOW_POWER_DREAM_MODE:
                        CRU_REGS->CRU_OSCCONSET = CRU_OSCCON_SLPEN_Msk | CRU_OSCCON_DRMEN_Msk;
                        break;
        default: 
                        return;
    }

    CFG_REGS->CFG_SYSKEY = 0;

    /* enter into selected low power mode */
    __WFI();
}

