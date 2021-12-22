;; File              : blink.s
;; Author            : leonardSA <leonard.stephenauguste@gmail.com>
;; Date              : 11.11.2021
;; Last Modified Date: 11.11.2021
;; Last Modified By  : leonardSA <leonard.stephenauguste@gmail.com>

.nolist        ; do not include defs in listing file
.include    "../../asm-include/m328Pdef.inc"
.list        ; include code

        rjmp    MAIN        ; relative jump to main

MAIN:   ldi     r16, 0x02   ; load immediate - can only use High Adress (r16-r31)
        sts     0x25, r16   ; store direct to SRAM: set PORTB1 in PORTB
        ldi     r16, 0x02   ; load immediate
        out     DDRB, r16   ; store direct: select PORTB1 for DDRB
        rjmp    LOOP        ; relative jump to LOOP

LOOP:   call    DELAY_1_S   ; wait 1 second
        ldi     r16, 0x02   ; turn led on
        sts     0x25, r16
        call    DELAY_1_S   ; wait 1 second
        ldi     r16, 0x00   ; turn led off
        sts     0x25, r16    
        rjmp    LOOP

DELAY_1_S: ; 100 * 40 000 * 4 = 16 * 10e6 cycles = 1 second
    ldi     r17, 100    ; outer loop counter
outer:
    ; ZH and ZL = r31 and r30 for word size reg
    ldi        ZH, HIGH(40000)
    ldi        ZL, LOW(40000)
inner:
    sbiw    ZL,1    ; sub immediate from word
    brne    inner   ; branch if nequal
    dec     r17     ; decrement 
    brne    outer    
    ret
