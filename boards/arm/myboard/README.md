# myboard Board

`myboard` board is used to demonstrate how to create custom boards. It is
in fact a simplified version of the b_u585i_iot02a board, so the
`example-application` can be run on that development kit when using
`myboard`.

Note: if the board your building an aplpication for already is supported inside
Zephyr, it is not necessary to create this custom board. Using a overlay file
in the app directory will be sufficient to enable the necessary devicetree
settings in that case.
