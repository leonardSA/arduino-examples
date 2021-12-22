;; File              : blink-interrupt.s
;; Author            : leonardSA <leonard.stephenauguste@gmail.com>
;; Date              : 23.11.2021
;; Last Modified Date: 23.11.2021
;; Last Modified By  : leonardSA <leonard.stephenauguste@gmail.com>

.nolist
.include	"../../asm-include/m328Pdef.inc"

; F_CPU = 16MHz and PRESCALER = 2^10
.equ	COUNTER_HI = HIGH(16000000 >> 10) 
.equ	COUNTER_LO = LOW(16000000 >> 10)

; on reset go to main
.org	0x0000
 		rjmp MAIN

; TIMER1_COMPA interrupt vector addr
.org 	OC1Aaddr        
 		rjmp	BLINK_ISR

.list
		rjmp	MAIN

MAIN:	; CONFIGURE LED PIN (9)
		; select PORTB1 for DDRB
		ldi		r16, (1 << DDB1)
		out 	DDRB, r16	
		; CONFIGURE TIMER
		; set counter
		ldi		r17, 	COUNTER_HI
		sts		OCR1AH, r17
		ldi		r17, 	COUNTER_LO
		sts		OCR1AL, r17
		; reset timer 1 cc reg A
		ldi		r17,	0x0
		sts 	TCCR1A, r17
		; set CTC mode 
		ldi		r17,	(1 << WGM12)
		sts		TCCR1B, r17
		; set prescaler to 1024
		ldi		r17,	(1 << CS10)
		sts 	TCCR1B, r17
		ldi		r17,	(1 << CS12)
		sts 	TCCR1B, r17
		; set timer mask interrupt
		ldi 	r17, 	(1 << OCIE1A)
		sts 	TIMSK1, r17
		; enable global interrupt
		bset	SREG_I
		rjmp 	LOOP

LOOP:
;  ____________
; < Such empty >
;  ------------
;         \   ^__^
;          \  (oo)\_______
;             (__)\       )\/\
;                 ||----w |
;                 ||     ||
 		rjmp 	LOOP
	
BLINK_ISR:
		; toggle led
		ldi		r18, 	(1 << PORTB1)
		in		r19, 	PORTB
		eor		r19, 	r18
 		out		PORTB, 	r19
		; return from interrupt
 		reti
