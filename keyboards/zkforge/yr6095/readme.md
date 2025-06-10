# zkforge/yr6095

> Note:
>
> -   forked from yandrstudio/yr6095
> -   source commit: `802a199bbd5dc5a533d912b1e508a84d1de08724`

![yr6095](https://i.imgur.com/k2SVb94h.png)

A 60% multi-layout keyboard (there are 95 keys in total) with 1 RGB in capslock key.
This keyboard use 16mhz HSE and APM32F103CBT6(STM32F103CBT6) as MCU.

-   Keyboard Maintainer: https://github.com/jiaxin96
-   Hardware Supported: yr6095
-   Hardware Availability: [TaoBao-5162](https://item.taobao.com/item.htm?id=678583896604)

Make example for this keyboard (after setting up your build environment):

    make zkforge/yr6095:default

See [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) then the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information.

## Bootloader

Enter the bootloader in 2 ways:

-   **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key which is Escape in this keyboard) and plug in the keyboard
-   **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available.
