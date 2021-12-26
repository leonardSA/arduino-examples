;; File              : light-switch-interrupt.s
;; Author            : leonardSA <leonard.stephenauguste@gmail.com>
;; Date              : 23.11.2021
;; Last Modified Date: 25.11.2021
;; Last Modified By  : leonardSA <leonard.stephenauguste@gmail.com>

.nolist
.include	"../../asm-include/m328Pdef.inc"

; F_CPU = 16MHz and PRESCALER = 2^10
.equ	COUNTER_HI = HIGH(16000000 >> 10) 
.equ	COUNTER_LO = LOW(16000000 >> 10)

; on reset go to main
.org	0x0000
 		rjmp MAIN

; INT0 interrupt vector addr
.org 	INT0addr        
 		rjmp	BLINK_ISR

.list
		rjmp	MAIN

MAIN:	; CONFIGURE LED PIN (9)
		; select PORTB1 for DDRB
		ldi		r16,    (1 << DDB1)
		out 	DDRB,   r16	
		; CONFIGURE EXT INT0
		; enable ext interrupt 0
		ldi 	r16,    (1 << INT0)
		sts		EIMSK,  r16
		; conifgure to trigger on rising edge
		ldi		r16,    (1 << ISC00 | 1 << ISC01)
		sts		EICRA,  r16
		; enable global interrupt
		bset	SREG_I
		rjmp 	LOOP

LOOP:
;  _____
; < Nop >
;  -----
; 		\   ^__^
; 		 \  (oo)\_______
; 			(__)\       )\/\
; 				||----w |
; 				||     ||
        nop
 		rjmp 	LOOP
	
BLINK_ISR:
		; toggle led
		ldi		r18, 	(1 << PORTB1)
		in		r19, 	PORTB
		eor		r19, 	r18
 		out		PORTB, 	r19
		; return from interrupt
 		reti
