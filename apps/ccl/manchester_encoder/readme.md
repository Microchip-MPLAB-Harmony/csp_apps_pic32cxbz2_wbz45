---
parent: Harmony 3 peripheral library application examples for PIC32CX-BZ2 and WBZ451 family
title: CCL Manchester Encoder
has_children: false
has_toc: false
---

[![MCHP](https://www.microchip.com/ResourcePackages/Microchip/assets/dist/images/logo.png)](https://www.microchip.com)

# CCL Manchester Encoder

This example application shows how to use the CCL peripheral library and generate a Manchester-encoded output.

## Description

This demonstrates a way to generate a Manchester-encoded output using a SPI port and the CCL. The SPI port is sending out a predefined buffer of data in a circular fashion. Data is sent out LSB first, with CCL_OUT being the Manchester-encoded output. Pins are configured such that a logic analyzer can be attached to see the input (MOSI and SCK) and the output (CCL_OUT) simultaneously.

## Downloading and building the application

To clone or download this application from Github, go to the [main page of this repository](https://github.com/Microchip-MPLAB-Harmony/csp_apps_pic32cxbz2_wbz45) and then click **Clone** button to clone this repository or download as zip file.
This content can also be downloaded using content manager by following these [instructions](https://github.com/Microchip-MPLAB-Harmony/contentmanager/wiki).

Path of the application within the repository is **apps/ccl/manchester_encoder/firmware** .

To build the application, refer to the following table and open the project using its IDE.

| Project Name      | Description                                    |
| ----------------- | ---------------------------------------------- |
|wbz451_curiosity.X| MPLABX project for [PIC32CX WBZ451 Curiosity Board](https://www.microchip.com/en-us/development-tool/EA71C53A) |


## Setting up the hardware

The following table shows the target hardware for the application projects.

| Project Name| Board|
|:---------|:---------:|
|wbz451_curiosity.X|[PIC32CX WBZ451 Curiosity Board](https://www.microchip.com/en-us/development-tool/EA71C53A)|


### Setting up [PIC32CX WBZ451 Curiosity Board](https://www.microchip.com/en-us/development-tool/EA71C53A)
- Use jumper from RA8 (SCK pin of mikroBUS connector) To RB1 (AN pin of mikroBUS connector) (This routes SCK signal To CCLIN1)
- RA7 (MOSI pin of mikroBUS connector) has MOSI output
- RB2 (RST pin of mikroBUS connector) has CCL output (CCL_OUT0)
- Connect the Debug USB port on the board to the computer using a micro USB cable


## Running the Application

1. Connect a logic analyzer to MOSI pin
2. Connect a logic analyzer to SCK pin
3. Connect a logic analyzer to the Manchester-encoded output CCL_OUT pin
4. Refer to the following table for pin details:

    |Board| MOSI pin | SCK pin  | CCL_OUT pin |
    |-----|----------|----------|-------------|
    | [PIC32CX WBZ451 Curiosity Board](https://www.microchip.com/en-us/development-tool/EA71C53A) | RA7 | RA8 | RB2 (RST pin on mikrobus socket) |

5. Build and Program the application using its IDE
6. Observe the output on logic analyzer, it should follow the truth table as shown in the following diagram:

    ![output](images/truth_table_manchester_encoder.png)
