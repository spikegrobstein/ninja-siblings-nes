.segment "CODE"

setup_background:
  ; first nametable, start by clearing to empty
  lda $2002 ; reset latch
  lda #$20
  sta $2006
  lda #$00
  sta $2006

  ; empty nametable
  ;
  ldy #30 ; 30 rows
  :
    ldx #32 ; 32 columns
    :
      lda #$54 ; load offset value F0 into a
      sta $2007
      dex
      bne :-
    bne :--


  ; draw the floor
  ; we want 5 layers at the bottom, from row 25-30
  ; lda #$85 ; #$85 is the brick
  ; ldy #25
  ; :
    ; ldx #0
    ; :
      ; pha
      ; jmp ppu_address_tile
      ; pla
      ; sta $2007
      ; inx
      ; cpx #32
      ; bne :-
    ; iny
    ; cpy #30
    ; bne :--
  ; done drawing floor

  ; set all attributes to 0
  ldx #64 ; 64 bytes
  :
    sta $2007
    dex
    bne :-


  ; second nametable, fill with simple pattern
  lda #$24
  sta $2006
  lda #$00
  sta $2006
  lda #$00
  ldy #30
  :
    ldx #32
    :
      sta $2007
      clc
      adc #1
      and #3
      dex
      bne :-
    clc
    adc #1
    and #3
    dey
    bne :--
  ; 4 stripes of attribute
  lda #0
  ldy #4
  :
    ldx #16
    :
      sta $2007
      dex
      bne :-
    clc
    adc #%01010101
    dey
    bne :--
  rts


.segment "RODATA"
background_layout:
;1
.byte $24,$24,$24,$24,$24,$24,$24,$24,$00,$00,$24,$24,$24,$24,$24,$24  ;;row 1
.byte $24,$24,$24,$26,$24,$24,$24,$24,$00,$01,$24,$24,$24,$24,$24,$24  ;;all sky
;2
.byte $24,$24,$24,$27,$24,$24,$24,$24,$02,$03,$24,$24,$24,$24,$24,$24  ;;row 2
.byte $24,$24,$24,$28,$24,$24,$24,$24,$04,$05,$24,$24,$24,$24,$24,$24  ;;all sky
;3
.byte $24,$24,$24,$29,$45,$45,$24,$24,$06,$07,$45,$45,$45,$45,$24,$24  ;;row 3
.byte $24,$24,$24,$28,$24,$24,$24,$24,$08,$09,$24,$24,$53,$54,$24,$24  ;;some brick tops

