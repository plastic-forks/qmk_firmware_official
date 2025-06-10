# zkforge/ph60_multi

> Note:
>
> -   forked from phdesign/ph60/multi
> -   source commit: `802a199bbd5dc5a533d912b1e508a84d1de08724`

![PromoImage](https://i.imgur.com/sUwC9mk.jpg)

A 60% multi-layout supported keyboard PCB with open source keyboard case.

-   Keyboard Maintainer: [Team PHDesign](https://github.com/ph-design)
-   Hardware Supported: PH60/Multi PCB
-   Hardware Availability:
    -   Store: https://e.tb.cn/h.6VMjUgWZkUGwq26?tk=oVyAeD6uPS2
    -   GitHub Repo: https://github.com/ph-design/PH60/tree/Rev.2/PCB_Rev2/Multi

Make example for this keyboard (after setting up your build environment):

    make zkforge/ph60_multi:default

Flashing example for this keyboard:

    make zkforge/ph60_multi:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

-   **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
-   **Physical reset button**: Briefly press the button on the back of the PCB - some may have pads you must short instead
